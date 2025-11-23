//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAQUARTO_HPP
#define Hotelaria_UnB_TP1_IAQUARTO_HPP
#include "InterfaceServicoQuarto.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class InterfaceApresentacaoQuarto {
    public:
        virtual void setControladoraServicoQuarto(InterfaceServicoQuarto *) = 0;

        virtual void exibirMenuCRUD() = 0;

        virtual bool criar(int gerente_id, int hotel_id) = 0;

        virtual void listar() = 0;

        virtual void atualizar() = 0;

        virtual void remover() = 0;

        virtual ~InterfaceApresentacaoQuarto() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAQUARTO_HPP