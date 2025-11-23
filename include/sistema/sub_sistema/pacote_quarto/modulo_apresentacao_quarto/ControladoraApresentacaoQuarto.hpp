//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAQUARTO_HPP
#define Hotelaria_UnB_TP1_CAQUARTO_HPP

#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceServicoQuarto.hpp"

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
    class ControladoraApresentacaoQuarto : public InterfaceApresentacaoQuarto {
    private:
        InterfaceServicoQuarto *servico;
        bool executando = false;

    public:
        void setControladoraServicoQuarto(InterfaceServicoQuarto *servico) override;

        void exibirMenuCRUD() override;

        bool criar(int gerente_id, int hotel_id) override;

        void listar() override;

        void atualizar() override;

        void remover() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAQUARTO_HPP