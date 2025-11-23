//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISQUARTO_HPP
#define Hotelaria_UnB_TP1_ISQUARTO_HPP

#include "InterfacePersistenciaQuarto.hpp"
#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class InterfaceServicoQuarto {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaQuarto *persistencia) = 0;

        virtual bool criar(const Quarto &quarto) = 0;

        virtual bool editar(const int &id, const Quarto &quarto) = 0;

        virtual bool remover(const int &id) = 0;

        virtual vector<QuartoDTO> listarTodos() = 0;

        virtual optional<QuartoDTO> pesquisar(const int &id) = 0;

        virtual int getQuantidadeDeQuartosDoHotel(int hotel_id) =0;

        virtual ~InterfaceServicoQuarto() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISQUARTO_HPP