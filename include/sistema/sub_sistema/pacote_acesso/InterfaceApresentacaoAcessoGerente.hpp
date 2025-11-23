//
// Created by caleb on 22/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP

namespace Hotelaria {
    class InterfaceApresentacaoAcessoGerente {
    public:
        virtual void exibirMenu() = 0;

        virtual void exibirMenuGerenciador() = 0;

        virtual void autenticarHacker() = 0;

        virtual ~InterfaceApresentacaoAcessoGerente() = default;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP