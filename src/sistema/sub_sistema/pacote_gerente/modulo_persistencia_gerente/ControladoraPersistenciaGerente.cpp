//
// Created by caleb on 16/10/2025.
//

#include "ControladoraPersistenciaGerente.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaGerente::inserir(const Gerente &gerente) {
        if (existeEmail(gerente.getEmail())) {
            return false;
        }

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "INSERT INTO gerentes (nome, email, ramal, senha) VALUES (?, ?, ?, ?);";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, gerente.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, gerente.getSenha().c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();

        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaGerente::autenticar(const string &email, const string &senha) {
        BancoDeDados banco;

        if (email.empty() || senha.empty())
            return false;

        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;

        const char *sql = "SELECT COUNT(*) FROM gerentes WHERE email = ? AND senha = ? LIMIT 1;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_STATIC);

        bool statusAutenticacao = false;
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int quantidade = sqlite3_column_int(stmt, 0);
            if (quantidade > 0) {
                statusAutenticacao = true;
            }
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return statusAutenticacao;
    }

    bool ControladoraPersistenciaGerente::atualizar(const Email &emailAntigo, const Gerente &gerente) {
        if (emailAntigo.getValor() != gerente.getEmail()) {
            if (existeEmail(gerente.getEmail())) {
                return false;
            }
        }
        BancoDeDados banco;
        if (!banco.abrindoConexao()) {
            return false;
        }

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;

        const char *sql = "UPDATE gerentes SET nome = ?, email = ?, ramal = ?, senha = ? WHERE email = ?;";

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, gerente.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, gerente.getSenha().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, emailAntigo.getValor().c_str(), -1, SQLITE_STATIC);


        rc = sqlite3_step(stmt);

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaGerente::excluir(const int &id) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "DELETE FROM gerentes WHERE id = ?;";
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

    vector<GerenteDTO> ControladoraPersistenciaGerente::listar() {
        vector<GerenteDTO> lista;

        BancoDeDados banco;
        if (!banco.abrindoConexao()) {
            return lista;
        }

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, email, ramal FROM gerentes;";

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
            const char *ramal_ptr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

            string nome = nome_ptr ? nome_ptr : "";
            string email = email_ptr ? email_ptr : "";
            string ramal = ramal_ptr ? ramal_ptr : "";

            GerenteDTO gerenteObj(id, nome, email, ramal);

            lista.push_back(gerenteObj);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<GerenteDTO> ControladoraPersistenciaGerente::pesquisarPorID(const int &id) {
        optional<GerenteDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, email, ramal FROM gerentes WHERE id = ? LIMIT 1;";
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
            string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

            dto = GerenteDTO(idRes, nome, email, ramal);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }


    optional<GerenteDTO> ControladoraPersistenciaGerente::pesquisarPorEmail(const string email) {
        optional<GerenteDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, ramal FROM gerentes WHERE email = ? LIMIT 1;";
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
            string ramal = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

            dto = GerenteDTO(idRes, nome, email, ramal);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }


    bool ControladoraPersistenciaGerente::existeEmail(const string &email) {
        return BancoDeDados::EXISTE_TABELA_VALOR("gerentes", "email", email);
    }
}