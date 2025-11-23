//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoQuarto.hpp"

#include "ControladoraPersistenciaQuarto.hpp"

namespace Hotelaria {
    void ControladoraServicoQuarto::setControladoraPersistencia(InterfacePersistenciaQuarto *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoQuarto::criar(const Quarto &quarto) {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->inserir(quarto);
    }

    bool ControladoraServicoQuarto::editar(const int &id, const Quarto &quarto) {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->atualizar(id, quarto);
    }

    bool ControladoraServicoQuarto::remover(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->excluir(id);
    }

    vector<QuartoDTO> ControladoraServicoQuarto::listarTodos() {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->listar();
    }

    optional<QuartoDTO> ControladoraServicoQuarto::pesquisar(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->pesquisar(id);
    }

    int ControladoraServicoQuarto::getQuantidadeDeQuartosDoHotel(int hotel_id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaQuarto();
        return persistencia->getQuantidadeDeQuartosDoHotel(hotel_id);
    }
}