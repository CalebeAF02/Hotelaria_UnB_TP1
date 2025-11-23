//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoGerente.hpp"

namespace Hotelaria {
    void ControladoraServicoGerente::setControladoraPersistencia(InterfacePersistenciaGerente *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoGerente::criar(const Gerente &gerente) {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->inserir(gerente);
    }

    bool ControladoraServicoGerente::editar(const Email &emailAntigo, const Gerente &gerenteAtualizado) {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->atualizar(emailAntigo, gerenteAtualizado);
    }

    bool ControladoraServicoGerente::remover(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->excluir(id);
    }

    vector<GerenteDTO> ControladoraServicoGerente::listarTodos() {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->listar();
    }

    optional<GerenteDTO> ControladoraServicoGerente::pesquisar(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->pesquisarPorID(id);
    }

    optional<GerenteDTO> ControladoraServicoGerente::pesquisarPorEmail(const string email) {
        if (!persistencia) persistencia = new ControladoraPersistenciaGerente();
        return persistencia->pesquisarPorEmail(email);
    }
}