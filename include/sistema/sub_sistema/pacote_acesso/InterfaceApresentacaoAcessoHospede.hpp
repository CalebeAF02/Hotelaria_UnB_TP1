//
// Created by caleb on 22/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP


namespace Hotelaria {
    class InterfaceApresentacaoAcessoHospede {
    public:
        virtual void exibirMenu() = 0;

        virtual void opcoesDeHospedagem() = 0;

        virtual void solicitandoHospedagem() = 0;

        virtual ~InterfaceApresentacaoAcessoHospede() = default;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP