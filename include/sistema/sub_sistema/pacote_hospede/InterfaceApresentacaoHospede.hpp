//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#include "InterfaceServicoHospede.hpp"

namespace Hotelaria {
    class InterfaceApresentacaoHospede {
    public:
        virtual void setControladoraServicoHospede(InterfaceServicoHospede *) = 0;

        virtual void exibirMenuCRUD() = 0;

        virtual bool criar() = 0;

        virtual void listar() = 0;

        virtual void atualizar() = 0;

        virtual void remover() = 0;

        virtual ~InterfaceApresentacaoHospede() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP