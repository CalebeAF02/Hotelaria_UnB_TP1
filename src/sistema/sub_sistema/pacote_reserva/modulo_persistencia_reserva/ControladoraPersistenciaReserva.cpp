//
// Created by caleb on 19/11/2025.
//

#include "ControladoraPersistenciaReserva.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    static void bindText(sqlite3_stmt *stmt, int idx, const string &val) {
        sqlite3_bind_text(stmt, idx, val.c_str(), -1, SQLITE_STATIC);
    }

    bool ControladoraPersistenciaReserva::inserir(const Reserva &reserva) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        const char *sql =
                "INSERT INTO reservas (email_hospede, chegada, partida, dinheiro, quarto_id) "
                "VALUES (?, ?, ?, ?, ?);";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        string email_hospede = "";
        bindText(stmt, 1, email_hospede);
        bindText(stmt, 2, reserva.getChegada().toString());
        bindText(stmt, 3, reserva.getPartida().toString());
        sqlite3_bind_int(stmt, 4, reserva.getDinheiro());

        sqlite3_bind_int(stmt, 5, 0);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaReserva::atualizar(const int &id, const Reserva &reserva) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        const char *sql =
                "UPDATE reservas SET chegada = ?, partida = ?, dinheiro = ? WHERE id = ?;";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        bindText(stmt, 1, reserva.getChegada().toString());
        bindText(stmt, 2, reserva.getPartida().toString());
        sqlite3_bind_int(stmt, 3, reserva.getDinheiro());
        sqlite3_bind_int(stmt, 4, id);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaReserva::excluir(const int &id) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "DELETE FROM reservas WHERE id = ?;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_int(stmt, 1, id);;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return true;
    }

    vector<ReservaDTO> ControladoraPersistenciaReserva::listar() {
        vector<ReservaDTO> lista;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return lista;

        sqlite3 *db = banco.getConexao();

        // Filtrar por hotel atual da sessão (reservas de quartos desse hotel)
        SistemaSessao &sessao = SistemaSessao::getInstance();
        int hotelId = sessao.getHoteleId();

        const char *sql =
                "SELECT r.id, r.chegada, r.partida, r.dinheiro, r.quarto_id "
                "FROM reservas r "
                "WHERE r.quarto_id IN (SELECT id FROM quartos WHERE hotel_id = ?);";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return lista;
        }

        sqlite3_bind_int(stmt, 1, hotelId);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            string chegada = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string partida = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            int dinheiro = sqlite3_column_int(stmt, 3);
            int quarto_id = sqlite3_column_int(stmt, 4);

            ReservaDTO dto(id, chegada, partida, dinheiro, /*codigo*/ "", quarto_id);
            lista.push_back(dto);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<ReservaDTO> ControladoraPersistenciaReserva::pesquisar(const int &id) {
        optional<ReservaDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();
        const char *sql =
                "SELECT id, chegada, partida, dinheiro, quarto_id "
                "FROM reservas WHERE id = ? LIMIT 1;";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return nullopt;
        }

        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int idRes = sqlite3_column_int(stmt, 0);
            string chegada = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string partida = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            int dinheiro = sqlite3_column_int(stmt, 3);
            int quarto_id = sqlite3_column_int(stmt, 4);

            dto = ReservaDTO(idRes, chegada, partida, dinheiro, /*codigo*/ "", quarto_id);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }
}