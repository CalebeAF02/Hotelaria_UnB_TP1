//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAHOTEL_HPP
#define Hotelaria_UnB_TP1_CAHOTEL_HPP

#include "InterfaceApresentacaoHotel.hpp"
#include "InterfaceServicoHotel.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>


using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoHotel : public InterfaceApresentacaoHotel {
    private:
        InterfaceServicoHotel *servico;
        bool executando = false;
        bool estaAutenticado = false;

    public:
        void setControladoraServicoHotel(InterfaceServicoHotel *) override;

        void exibirMenuCRUD() override;

        void acessar() override;

        void criar(int gerente_id) override;

        void listar() override;

        void atualizar() override;

        void remover() override;
    };
}


#endif //Hotelaria_UnB_TP1_CAHOTEL_HPP