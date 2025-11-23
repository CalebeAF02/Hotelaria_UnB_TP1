//
// Created by caleb on 18/11/2025.
//

#include "ControladoraPersistenciaQuarto.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaQuarto::inserir(const Quarto &quarto) {
        IO::Println(to_string(quarto.getHotelID()));
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();

        const char *sql = "INSERT INTO quartos (numero, capacidade, dinheiro, ramal, hotel_id) VALUES (?, ?, ?, ?, ?);";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cout << "Erro ao preparar INSERT: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, quarto.getNumero().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, quarto.getCapacidade());
        sqlite3_bind_int(stmt, 3, quarto.getDiaria());
        sqlite3_bind_text(stmt, 4, quarto.getRamal().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, quarto.getHotelID());

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            cout << "Erro ao executar INSERT: " << sqlite3_errmsg(db) << endl;
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return true;
    }

    bool ControladoraPersistenciaQuarto::atualizar(const int &id, const Quarto &quarto) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;

        const char *sql =
                "UPDATE quartos SET numero = ?, capacidade = ?, dinheiro = ?, ramal = ? WHERE id = ?;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar atualizacao: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return false;
        }
        sqlite3_bind_text(stmt, 1, quarto.getNumero().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, quarto.getCapacidade());
        sqlite3_bind_int(stmt, 3, quarto.getDiaria());
        sqlite3_bind_text(stmt, 4, quarto.getRamal().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, id);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();

        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaQuarto::excluir(const int &id) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "DELETE FROM quartos WHERE id = ?;";
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

    vector<QuartoDTO> ControladoraPersistenciaQuarto::listar() {
        vector<QuartoDTO> lista;

        SistemaSessao &sessao = SistemaSessao::getInstance();

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return lista;

        sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, numero, capacidade, dinheiro, ramal, hotel_id FROM quartos WHERE hotel_id = ?;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return lista;
        }

        sqlite3_bind_int(stmt, 1, sessao.getHoteleId());

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
            string numero = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            int capacidade = reinterpret_cast<int>(sqlite3_column_int(stmt, 2));
            int dinheiro = reinterpret_cast<int>(sqlite3_column_int(stmt, 3));
            string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            int hotel_id = reinterpret_cast<int>(sqlite3_column_int(stmt, 5));

            QuartoDTO *quartoObj = new QuartoDTO(id, numero, capacidade, dinheiro, ramal, hotel_id);

            lista.push_back(*quartoObj);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<QuartoDTO> ControladoraPersistenciaQuarto::pesquisar(const int &id) {
        optional<QuartoDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql =
                "SELECT id, numero, capacidade, dinheiro, ramal, hotel_id FROM quartos WHERE id = ? LIMIT 1;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return nullopt;
        }

        sqlite3_bind_int(stmt, 1, id);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
            string numero = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            int capacidade = reinterpret_cast<int>(sqlite3_column_int(stmt, 2));
            int dinheiro = reinterpret_cast<int>(sqlite3_column_int(stmt, 3));
            string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            int hotel_id = reinterpret_cast<int>(sqlite3_column_int(stmt, 5));

            dto = QuartoDTO(id, numero, capacidade, dinheiro, ramal, hotel_id);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }

    int ControladoraPersistenciaQuarto::getQuantidadeDeQuartosDoHotel(int hotel_id) {
        return BancoDeDados::CONTAGEM_INTEIRO("quartos", "hotel_id", hotel_id);
    }
}