//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoHospede.hpp"

namespace Hotelaria {
    void ControladoraServicoHospede::setControladoraPersistencia(InterfacePersistenciaHospede *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoHospede::criar(const Hospede &hospede) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHospede();
        return persistencia->inserir(hospede);
    }

    bool ControladoraServicoHospede::editar(const Email &email, const Hospede &hospede) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHospede();
        return persistencia->atualizar(email, hospede);
    }

    bool ControladoraServicoHospede::remover(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHospede();
        return persistencia->excluir(id);
    }

    vector<HospedeDTO> ControladoraServicoHospede::listarTodos() {
        if (!persistencia) persistencia = new ControladoraPersistenciaHospede();
        return persistencia->listar();
    }

    optional<HospedeDTO> ControladoraServicoHospede::pesquisar(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHospede();
        return persistencia->pesquisar(id);
    }
}