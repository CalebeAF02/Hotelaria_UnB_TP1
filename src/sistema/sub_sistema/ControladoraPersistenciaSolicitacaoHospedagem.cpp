//
// Created by caleb on 26/10/2025.
//

#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"


namespace Hotelaria {
    static const char *DB_PATH = "hotel.db";

    void ControladoraPersistenciaSolicitacaoHospedagem::salvar(const SolicitacaoHospedagem &status) {
        BancoDeDados banco;

        if (!banco.abrindoConexao())
            return;

        sqlite3 *db = banco.getConexao();

        const char *sql = R"(
        INSERT INTO solicitacoes_hospedagem (
            email_hospede, id_hotel, id_quarto,
            chegada, partida, status, motivo_recusa
        ) VALUES (?, ?, ?, ?, ?, ?, ?);
    )";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, status.getHospedeId());
        sqlite3_bind_int(stmt, 2, status.getHotelId());
        sqlite3_bind_int(stmt, 3, status.getQuartoId());
        sqlite3_bind_text(stmt, 4, status.getChegada().toString().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, status.getPartida().toString().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 6, EnumConversor::StatusSolicitacaoHospedagemParaInteiro(status.getStatus()));
        sqlite3_bind_text(stmt, 7, status.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();
    }

    void ControladoraPersistenciaSolicitacaoHospedagem::atualizar(const SolicitacaoHospedagem &status) {
        sqlite3 *db;
        sqlite3_open(DB_PATH, &db);

        const char *sql = R"(
        UPDATE solicitacoes_hospedagem
        SET status = ?, motivo_recusa = ?
        WHERE codigo = ?;
    )";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, EnumConversor::StatusSolicitacaoHospedagemParaInteiro(status.getStatus()));
        sqlite3_bind_text(stmt, 2, status.getMotivoRecusa().c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }

    vector<SolicitacaoHospedagem> ControladoraPersistenciaSolicitacaoHospedagem::buscarPorEmail(const string &id) {
        sqlite3 *db;
        sqlite3_open(DB_PATH, &db);

        const char *sql = R"(
        SELECT id, chegada, partida, status, motivo_recusa, hospede_id, hotel_id, quarto_id,
        FROM solicitacoes_hospedagem
        WHERE hospede_id = ?;
    )";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, id.c_str(), -1, SQLITE_STATIC);

        vector<SolicitacaoHospedagem> lista;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            string hospede_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            string hotel_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string quarto_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            string chegadaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            string partidaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            StatusSolicitacaoHospedagem status = EnumConversor::InteiroParaStatusSolicitacaoHospedagem(
                sqlite3_column_int(stmt, 5));
            string motivo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6));

            lista.emplace_back(
                Data(chegadaStr),
                Data(partidaStr),
                status,
                motivo,
                stoi(hospede_id),
                stoi(hotel_id),
                stoi(quarto_id)
            );
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return lista;
    }

    vector<SolicitacaoHospedagem> ControladoraPersistenciaSolicitacaoHospedagem::buscarPorStatus(int statusFiltro) {
        sqlite3 *db;
        sqlite3_open(DB_PATH, &db);

        const char *sql = R"(
        SELECT id, chegada, partida, status, motivo_recusa, email_hospede, id_hotel, id_quarto,
        FROM solicitacoes_hospedagem
        WHERE status = ?;
    )";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, statusFiltro);

        vector<SolicitacaoHospedagem> lista;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            string id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            string chegadaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string partidaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            StatusSolicitacaoHospedagem status = EnumConversor::InteiroParaStatusSolicitacaoHospedagem(
                sqlite3_column_int(stmt, 4));
            string motivo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            string hospede_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));
            string hotel_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6));
            string quarto_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7));

            lista.emplace_back(

                Data(chegadaStr),
                Data(partidaStr),
                status,
                motivo,
                stoi(hospede_id),
                stoi(hotel_id),
                stoi(quarto_id)
            );
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return lista;
    }
}
