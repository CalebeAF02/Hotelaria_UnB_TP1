//
// Created by caleb on 01/11/2025.
//

#include "ControladoraPersistenciaHotel.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaHotel::inserir(const Hotel &hotel) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();

        const char *sql = "INSERT INTO hoteis (nome, endereco, telefone, codigo, gerente_id) VALUES (?, ?, ?, ?, ?);";

        sqlite3_stmt *stmt = nullptr;
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cout << "Erro ao preparar INSERT: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, hotel.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, hotel.getEndereco().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, hotel.getTelefone().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, hotel.getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, hotel.getGerenteId());

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

    bool ControladoraPersistenciaHotel::atualizar(const int &id, const Hotel &hotel) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;

        const char *sql =
                "UPDATE hoteis SET nome = ?, endereco = ?, telefone = ?, codigo = ? WHERE id = ?;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar atualizacao: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return false;
        }
        sqlite3_bind_text(stmt, 1, hotel.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, hotel.getEndereco().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, hotel.getTelefone().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, hotel.getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, id);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        banco.fechandoConexao();

        return rc == SQLITE_DONE;
    }

    bool ControladoraPersistenciaHotel::excluir(const int &id) {
        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();
        sqlite3_stmt *stmt = nullptr;
        const char *sql = "DELETE FROM hoteis WHERE id = ?;";
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


    vector<HotelDTO> ControladoraPersistenciaHotel::listar() {
        vector<HotelDTO> lista;

        SistemaSessao &sessao = SistemaSessao::getInstance();

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return lista;

        sqlite3 *db = banco.getConexao(); // metodo que retorna o ponteiro db


        sqlite3_stmt *stmt = nullptr;
        const char *sql = "SELECT id, nome, endereco, telefone, codigo, gerente_id FROM hoteis WHERE gerente_id = ?;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return lista;
        }

        sqlite3_bind_int(stmt, 1, sessao.getGerenteId());

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
            string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string endereco = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            string telefone = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            string codigo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            int gerente_id = reinterpret_cast<int>(sqlite3_column_int(stmt, 5));

            HotelDTO *hotelObj = new HotelDTO(id, nome, endereco, telefone, codigo, gerente_id);

            lista.push_back(*hotelObj);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return lista;
    }

    optional<HotelDTO> ControladoraPersistenciaHotel::pesquisar(const int &id) {
        optional<HotelDTO> dto = nullopt;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return nullopt;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        const char *sql =
                "SELECT id, nome, endereco, telefone, codigo,gerente_id FROM hoteis WHERE id = ? AND gerente_id = ? LIMIT 1;";
        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
            banco.fechandoConexao();
            return nullopt;
        }

        SistemaSessao &sessao = SistemaSessao::getInstance();

        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_int(stmt, 2, sessao.getGerenteId());

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
            string nome = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            string endereco = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            string telefone = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            string codigo = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
            int gerente_id = reinterpret_cast<int>(sqlite3_column_int(stmt, 5));

            dto = HotelDTO(id, nome, endereco, telefone, codigo, gerente_id);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return dto;
    }


    bool ControladoraPersistenciaHotel::existeCodigo(const string &codigo) {
        return BancoDeDados::EXISTE_TABELA_VALOR("hoteis", "codigo", codigo);
    }

    int ControladoraPersistenciaHotel::getQuantidadeDeHoteisDoGerente(int gerente_id) {
        return BancoDeDados::CONTAGEM_INTEIRO("hoteis", "gerente_id", gerente_id);
    }
}