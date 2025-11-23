//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSRESERVA_HPP
#define Hotelaria_UnB_TP1_CSRESERVA_HPP

#include "ControladoraPersistenciaReserva.hpp"
#include "InterfaceServicoReserva.hpp"
#include "InterfacePersistenciaReserva.hpp"
#include "ControladoraServicoReserva.hpp"
#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraServicoReserva : public InterfaceServicoReserva {
    private:
        InterfacePersistenciaReserva *persistencia;

    public:
        void setControladoraPersistencia(InterfacePersistenciaReserva *persistencia) override;

        bool criar(const Reserva &reserva) override;

        bool editar(const int &id, const Reserva &reserva) override;

        bool remover(const int &id) override;

        vector<ReservaDTO> listarTodos() override;

        optional<ReservaDTO> pesquisar(const int &id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSRESERVA_HPP