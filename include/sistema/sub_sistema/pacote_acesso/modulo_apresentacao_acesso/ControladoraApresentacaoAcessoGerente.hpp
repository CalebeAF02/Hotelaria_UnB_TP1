//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAI_HPP
#define Hotelaria_UnB_TP1_CAI_HPP


#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

#include "ControladoraPersistenciaGerente.hpp"
#include "InterfaceApresentacaoAcessoGerente.hpp"
#include "InterfaceApresentacaoGerente.hpp"


using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoAcessoGerente : public InterfaceApresentacaoAcessoGerente {
    private:
        bool estaAutenticado = false;

    public:
        void exibirMenu() override;

        void exibirMenuGerenciador() override;

        void autenticarHacker() override;
    };
}


#endif //Hotelaria_UnB_TP1_CAI_HPP