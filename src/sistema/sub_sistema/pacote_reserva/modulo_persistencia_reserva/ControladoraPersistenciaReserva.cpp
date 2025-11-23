//
// Created by caleb on 19/11/2025.
//

#include "ControladoraPersistenciaReserva.hpp"

namespace Hotelaria {
    bool ControladoraPersistenciaReserva::inserir(const Reserva &reserva) {
        // Ainda não Implementado
        return true;
    }

    bool ControladoraPersistenciaReserva::autenticar(const string &email, const string &senha) {
        // Ainda não Implementado
        return true;
    }

    vector<ReservaDTO> ControladoraPersistenciaReserva::listar() {
        vector<ReservaDTO> lista;
        return lista;
    }

    optional<ReservaDTO> ControladoraPersistenciaReserva::pesquisar(const int &id) {
        return nullopt;
    }

    bool ControladoraPersistenciaReserva::atualizar(const int &id, const Reserva &reserva) {
        return true;
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
}