//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoHotel.hpp"
#include "Utils.hpp"
#include "Tabela.hpp"
#include "ControladoraPersistenciaHotel.hpp"
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    void ControladoraServicoHotel::setControladoraPersistencia(InterfacePersistenciaHotel *persistencia) {
        this->persistencia = persistencia;
    }

    bool ControladoraServicoHotel::criar(const Hotel &hotel) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->inserir(hotel);
    }

    bool ControladoraServicoHotel::existeCodigo(const string &codigo) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->existeCodigo(codigo);
    }

    bool ControladoraServicoHotel::editar(const int &id, const Hotel &hotelAtualizado) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->atualizar(id, hotelAtualizado);
    }

    bool ControladoraServicoHotel::remover(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->excluir(id);
    }

    vector<HotelDTO> ControladoraServicoHotel::listarTodos() {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->listar();
    }

    optional<HotelDTO> ControladoraServicoHotel::pesquisar(const int &id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->pesquisar(id);
    }

    int ControladoraServicoHotel::getQuantidadeDeHoteisDoGerente(int gerente_id) {
        if (!persistencia) persistencia = new ControladoraPersistenciaHotel();
        return persistencia->getQuantidadeDeHoteisDoGerente(gerente_id);
    }
}