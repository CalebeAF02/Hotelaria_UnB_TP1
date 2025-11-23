//
// Created by caleb on 15/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP
#define Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP


#include "Sistema.hpp"

#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"
#include "Data.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

#include "InterfaceApresentacaoAcessoHospede.hpp"
#include "InterfaceApresentacaoHospede.hpp"

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoAcessoHospede : public InterfaceApresentacaoAcessoHospede {
    private:
        InterfaceApresentacaoHospede *apresentacao_hospede;

    public:
        void exibirMenu() override;

        void opcoesDeHospedagem() override;

        void solicitandoHospedagem() override;

        void statusDaSolicitandoHospedagem() const;
    };
}

#endif //Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP