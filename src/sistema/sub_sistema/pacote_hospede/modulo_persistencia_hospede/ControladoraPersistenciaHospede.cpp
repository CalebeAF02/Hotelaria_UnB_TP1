//
// Created by caleb on 16/10/2025.
//

#include "ControladoraPersistenciaHospede.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaHospede::inserir(const Hospede &hospede) {
        if (existeEmail(hospede.getEmail())) {
            return false;
        }

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "INSERT INTO hospedes (nome, email, endereco, cartao) VALUES (?, ?, ?, ?);";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, hospede.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, hospede.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, hospede.getEndereco().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, hospede.getCartao().c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();

        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaHospede::atualizar(const Email &emailAntigo, const Hospede &hospede) {
        if (emailAntigo.getValor() != hospede.getEmail()) {
            if (existeEmail(hospede.getEmail())) {
                return false;
            }
        }
        BancoDeDados banco;
        if (!banco.abrindoConexao()) {
            return false;
        }

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;

        const char *sql = "UPDATE hospedes SET nome = ?, email = ?, endereco = ?, cartao = ? WHERE email = ?;";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, hospede.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, hospede.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, hospede.getEndereco().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, hospede.getCartao().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, emailAntigo.getValor().c_str(), -1, SQLITE_STATIC);


        rc = sqlite3_step(stmt);

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaHospede::excluir(const int &id) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "DELETE FROM hospedes WHERE id = ?;";
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


    vector<HospedeDTO> ControladoraPersistenciaHospede::listar() {
        vector<HospedeDTO> lista;

        BancoDeDados banco;
        if (!banco.abrindoConexao()) {
            return lista;
        }

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, email, endereco, cartao FROM hospedes;";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return lista;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);

            const char *nome_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            const char *email_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            const char *endereco_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            const char *cartao_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));

            string nome = nome_ptr ? nome_ptr : "";
            string email = email_ptr ? email_ptr : "";
            string endereco = endereco_ptr ? endereco_ptr : "";
            string cartao = cartao_ptr ? cartao_ptr : "";

            HospedeDTO hospedeObj(id, nome, email, endereco, cartao);

            lista.push_back(hospedeObj);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<HospedeDTO> ControladoraPersistenciaHospede::pesquisar(const int &id) {
        optional<HospedeDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, email, endereco, cartao FROM hospedes WHERE id = ? LIMIT 1;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return nullopt;
        }

        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int idRes = sqlite3_column_int(stmt, 0);
            string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            string endereco = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            string cartao = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));

            dto = HospedeDTO(idRes, nome, email, endereco, cartao);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }

    optional<HospedeDTO> ControladoraPersistenciaHospede::pesquisarPorEmail(const string email) {
        optional<HospedeDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, endereco, cartao FROM hospedes WHERE email = ? LIMIT 1;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return nullopt;
        }

        sqlite3_bind_text(stmt, 1, email.c_str(), -1, nullptr);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int idRes = sqlite3_column_int(stmt, 0);
            string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string endereco = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            string cartao = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

            dto = HospedeDTO(idRes, nome, email, endereco, cartao);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }

    bool ControladoraPersistenciaHospede::existeEmail(const string &email) {
        return BancoDeDados::EXISTE_TABELA_VALOR("hospedes", "email", email);
    }
}