//
// Created by caleb on 01/11/2025.
//

#include "../../include/sistema/banco/BancoDeDados.hpp"

namespace Hotelaria {
    sqlite3 *BancoDeDados::getConexao() const {
        return db;
    }

    bool BancoDeDados::abrindoConexao() {
        //_________________________ABRE CONEXÂO_______________________________
        int rc = sqlite3_open("hotel.db", &db);
        if (rc != SQLITE_OK) {
            cerr << "\nErro ao abrir banco: " << sqlite3_errmsg(db) << endl;
            return false;
        }
        char *mensagemErro = nullptr;
        sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, &mensagemErro);

        //ConsoleFormatter::MostrarSeparadorCategoria("Banco aberto com sucesso!");

        return true;
        //_________________________------------_______________________________
    }

    bool BancoDeDados::fechandoConexao() {
        //_________________________FECHA CONEXÂO_______________________________
        if (db) {
            sqlite3_close(db);
            db = nullptr;
            //ConsoleFormatter::MostrarSeparadorCategoria("Conexao com o banco encerrada com sucesso!");
            return true;
        }

        cerr << "\nNenhuma conexao ativa para fechar.\n";
        return false;
        //_________________________------------_______________________________
    }

    void BancoDeDados::iniciar() {
        if (!abrindoConexao())
            return;

        // Comandos SQL para criar cada tabela
        tabelaGerente(db);
        tabelaHospede(db);
        tabelaHotel(db);
        tabelaQuarto(db);
        tabelaReserva(db);
        tabelaSolicitacoesDeHospedagem(db);

        fechandoConexao();
    };

    void BancoDeDados::tabelaGerente(sqlite3 *db) {
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS gerentes (
            id      INTEGER PRIMARY KEY AUTOINCREMENT,
            nome    TEXT NOT NULL DEFAULT '',
            email   TEXT UNIQUE NOT NULL DEFAULT '',
            ramal   TEXT NOT NULL DEFAULT '',
            senha   TEXT NOT NULL DEFAULT ''
        );
    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'gerentes': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'gerentes' criada com sucesso!" << endl;
        }
    }

    void BancoDeDados::tabelaHospede(sqlite3 *db) {
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS hospedes (
            id          INTEGER PRIMARY KEY AUTOINCREMENT,
            nome        TEXT NOT NULL DEFAULT '',
            email       TEXT NOT NULL UNIQUE DEFAULT '',
            endereco    TEXT NOT NULL DEFAULT '',
            cartao      TEXT NOT NULL DEFAULT ''
        );
    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'hospedes': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'hospedes' criada com sucesso!" << endl;
        }
    }

    void BancoDeDados::tabelaHotel(sqlite3 *db) {
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS hoteis (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome       TEXT DEFAULT '' NOT NULL,
            endereco   TEXT DEFAULT '' NOT NULL,
            telefone   TEXT DEFAULT '' NOT NULL,
            codigo     TEXT DEFAULT '' NOT NULL UNIQUE,
            gerente_id INTEGER NOT NULL DEFAULT 0,

            FOREIGN KEY (gerente_id) REFERENCES gerentes(id)
        );

    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'hoteis': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'hoteis' criada com sucesso!" << endl;
        }
    }

    void BancoDeDados::tabelaQuarto(sqlite3 *db) {
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS quartos (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            numero      TEXT NOT NULL DEFAULT '',
            capacidade  INTEGER NOT NULL DEFAULT 0,
            dinheiro    INTEGER NOT NULL DEFAULT 0,
            ramal       TEXT NOT NULL DEFAULT '',
            hotel_id    INTEGER NOT NULL DEFAULT 0,

            FOREIGN KEY (hotel_id) REFERENCES hoteis(id)
        );
    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'quartos': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'quartos' criada com sucesso!" << endl;
        }
    }

    void BancoDeDados::tabelaReserva(sqlite3 *db) {
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS reservas (
            id              INTEGER PRIMARY KEY AUTOINCREMENT,
            email_hospede   TEXT,
            chegada         TEXT NOT NULL DEFAULT '',
            partida         TEXT NOT NULL DEFAULT '',
            dinheiro        INTEGER NOT NULL DEFAULT 0,
            quarto_id       INTEGER NOT NULL DEFAULT 0,

            FOREIGN KEY (quarto_id) REFERENCES quartos(id)
        );
    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'reservas': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'reservas' criada com sucesso!" << endl;
        }
    }

    void BancoDeDados::tabelaSolicitacoesDeHospedagem(sqlite3 *db) {
        // Comando SQL para criar a tabela
        const char *sql = R"(
        CREATE TABLE IF NOT EXISTS solicitacoes_hospedagem (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            chegada         TEXT NOT NULL,
            partida         TEXT NOT NULL,
            status          INTEGER NOT NULL,
            motivo_recusa   TEXT,
            hospede_id      INTEGER NOT NULL DEFAULT 0,
            hotel_id        INTEGER NOT NULL DEFAULT 0,
            quarto_id       INTEGER NOT NULL DEFAULT 0,

            FOREIGN KEY (hospede_id) REFERENCES hospedes(id),
            FOREIGN KEY (hotel_id) REFERENCES hoteis(id),
            FOREIGN KEY (quarto_id) REFERENCES quartos(id)

        );
    )";

        char *mensagemErro = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &mensagemErro);

        if (rc != SQLITE_OK) {
            cerr << "\nErro ao criar tabela 'solicitacoes_hospedagem': " << mensagemErro << endl;
            sqlite3_free(mensagemErro);
        } else {
            //cout << "\nTabela 'solicitacoes_hospedagem' criada com sucesso!" << endl;
        }
    }

    bool BancoDeDados::EXISTE_TABELA_VALOR(string tabela, string coluna, string valor) {
        bool existe = false;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return false;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        string sql = "SELECT COUNT(*) FROM " + tabela + " WHERE " + coluna + " = ? ;";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return false;
        }

        sqlite3_bind_text(stmt, 1, valor.c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            int count = sqlite3_column_int(stmt, 0);
            if (count > 0) {
                existe = true;
            }
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return existe;
    }

    int BancoDeDados::CONTAGEM_STRING(string tabela, string coluna, string valor) {
        int quantidade = 0;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return quantidade;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        string sql = "SELECT COUNT(*) FROM " + tabela + " WHERE " + coluna + " = ? ;";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return quantidade;
        }

        sqlite3_bind_text(stmt, 1, valor.c_str(), -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            quantidade = sqlite3_column_int(stmt, 0);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return quantidade;
    }

    int BancoDeDados::CONTAGEM_INTEIRO(string tabela, string coluna, int valor) {
        int quantidade = 0;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return quantidade;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        string sql = "SELECT COUNT(*) FROM " + tabela + " WHERE " + coluna + " = ? ;";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return quantidade;
        }

        sqlite3_bind_int(stmt, 1, valor);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            quantidade = sqlite3_column_int(stmt, 0);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return quantidade;
    }

    int BancoDeDados::CONTAGEM_INTEIRO_DUPLO(string tabela, string coluna1, int valor1, string coluna2, int valor2) {
        int quantidade = 0;

        BancoDeDados banco;
        if (!banco.abrindoConexao())
            return quantidade;

        sqlite3 *db = banco.getConexao();


        sqlite3_stmt *stmt = nullptr;
        string sql = "SELECT COUNT(*) FROM " + tabela + " WHERE " + coluna1 + " = ? AND " + coluna2 + " = ?;";
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(stmt);
            banco.fechandoConexao();
            return quantidade;
        }

        sqlite3_bind_int(stmt, 1, valor1);
        sqlite3_bind_int(stmt, 2, valor2);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            quantidade = sqlite3_column_int(stmt, 0);
        }

        sqlite3_finalize(stmt);
        banco.fechandoConexao();
        return quantidade;
    }
}