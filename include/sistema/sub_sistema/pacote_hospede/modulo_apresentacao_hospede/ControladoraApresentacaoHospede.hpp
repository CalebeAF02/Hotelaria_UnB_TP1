//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP

#include "InterfaceApresentacaoHospede.hpp"
#include "InterfaceServicoHospede.hpp"

#include "FabricaGerenciavel.hpp"
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
    class ControladoraApresentacaoHospede : public InterfaceApresentacaoHospede {
    private:
        InterfaceServicoHospede *servico;

        bool executando = true;

    public:
        void setControladoraServicoHospede(InterfaceServicoHospede *servico) override;

        void exibirMenuCRUD() override;

        bool criar() override;

        void listar() override;

        void atualizar() override;

        void remover() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP