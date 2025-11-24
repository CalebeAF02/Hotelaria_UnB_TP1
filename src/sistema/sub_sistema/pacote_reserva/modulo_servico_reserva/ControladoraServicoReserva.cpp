//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoReserva.hpp"

namespace Hotelaria {
    void ControladoraServicoReserva::setControladoraPersistencia(InterfacePersistenciaReserva *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoReserva::criar(const Reserva &reserva) {
        if (!persistencia) persistencia = new ControladoraPersistenciaReserva();
        return persistencia->inserir(reserva);
    };

    bool ControladoraServicoReserva::editar(const int &id, const Reserva &reserva) {
        if (!persistencia) persistencia = new ControladoraPersistenciaReserva();
        return persistencia->atualizar(id, reserva);
    };

    bool ControladoraServicoReserva::remover(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaReserva();
        return persistencia->excluir(id);
    };

    vector<ReservaDTO> ControladoraServicoReserva::listarTodos() {
        if (!persistencia) persistencia = new ControladoraPersistenciaReserva();
        return persistencia->listar();
    }

    optional<ReservaDTO> ControladoraServicoReserva::pesquisar(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaReserva();
        return persistencia->pesquisar(id);
    };
}