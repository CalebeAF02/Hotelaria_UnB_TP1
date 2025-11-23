//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAHOTEL_HPP
#define Hotelaria_UnB_TP1_IAHOTEL_HPP
#include "InterfaceServicoHotel.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoHotel {
    public:
        virtual void setControladoraServicoHotel(InterfaceServicoHotel *) = 0;

        virtual void exibirMenuCRUD() = 0;

        virtual void acessar() = 0;

        virtual void criar(int gerente_id) = 0;

        virtual void listar() = 0;

        virtual void atualizar() = 0;

        virtual void remover() = 0;

        virtual ~InterfaceApresentacaoHotel() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAHOTEL_HPP