//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP

#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    class InterfacePersistenciaQuarto {
    public:
        virtual bool inserir(const Quarto &quarto) = 0;

        virtual bool atualizar(const int &id, const Quarto &quarto) = 0;

        virtual bool excluir(const int &id) = 0;

        virtual vector<QuartoDTO> listar() = 0;

        virtual optional<QuartoDTO> pesquisar(const int &id) = 0;

        virtual ~InterfacePersistenciaQuarto() = default;

        virtual int getQuantidadeDeQuartosDoHotel(int hotel_id) = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP