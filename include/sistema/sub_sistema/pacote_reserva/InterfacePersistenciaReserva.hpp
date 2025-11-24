//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIARESERVA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIARESERVA_HPP

#include "ReservaDTO.hpp"
#include "Reserva.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    class InterfacePersistenciaReserva {
    public:
        virtual bool inserir(const Reserva &reserva) = 0;

        virtual bool atualizar(const int &id, const Reserva &reserva) = 0;

        virtual bool excluir(const int &id) = 0;

        virtual vector<ReservaDTO> listar() = 0;

        virtual optional<ReservaDTO> pesquisar(const int &id) = 0;

        virtual ~InterfacePersistenciaReserva() = default;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIARESERVA_HPP