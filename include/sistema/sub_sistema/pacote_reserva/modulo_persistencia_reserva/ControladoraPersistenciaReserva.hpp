//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIARESERVA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIARESERVA_HPP

#include "InterfacePersistenciaReserva.hpp"
#include "Reserva.hpp"
#include "ReservaDTO.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>

#include "InterfacePersistenciaReserva.hpp"
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    class ControladoraPersistenciaReserva : public InterfacePersistenciaReserva {
    public:
        bool inserir(const Reserva &reserva) override;

        bool atualizar(const int &id, const Reserva &reserva) override;

        bool excluir(const int &id) override;

        vector<ReservaDTO> listar() override;

        optional<ReservaDTO> pesquisar(const int &id) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIARESERVA_HPP