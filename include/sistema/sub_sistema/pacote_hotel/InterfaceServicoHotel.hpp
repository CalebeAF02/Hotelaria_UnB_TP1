//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISHOTEL_HPP
#define Hotelaria_UnB_TP1_ISHOTEL_HPP

#include "InterfacePersistenciaHotel.hpp"
#include "Hotel.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class InterfaceServicoHotel {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaHotel *persistencia) = 0;

        virtual bool criar(const Hotel &hotel) = 0;

        virtual bool existeCodigo(const string &codigo) = 0;

        virtual bool editar(const int &id, const Hotel &hotel) = 0;

        virtual bool remover(const int &id) = 0;

        virtual vector<HotelDTO> listarTodos() = 0;

        virtual optional<HotelDTO> pesquisar(const int &id) = 0;

        virtual int getQuantidadeDeHoteisDoGerente(int gerente_id) =0;

        virtual ~InterfaceServicoHotel() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISHOTEL_HPP