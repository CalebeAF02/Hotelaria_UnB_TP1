//
// Created by caleb on 22/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP

namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoAcessoGerente
     * @brief Interface responsável pela apresentação e controle de acesso do gerente.
     *
     * Define operações fundamentais para:
     * - exibição do menu principal do gerente;
     * - exibição do menu do módulo gerenciador;
     * - autenticação em modo privilegiado ("autenticarHacker").
     *
     * Esta classe é abstrata, sendo utilizada como contrato para camadas de UI,
     * garantindo independência entre a lógica de apresentação e a lógica de negócio.
     */
    class InterfaceApresentacaoAcessoGerente {
    public:
        /**
         * @brief Exibe o menu inicial destinado ao gerente.
         *
         * Este menu geralmente contém opções como acesso ao painel administrativo,
         * autenticação, gerenciamento de reservas, funcionários, relatórios etc.
         *
         * Implementações devem garantir navegação fluida e validação de entrada.
         */
        virtual void exibirMenu() = 0;

        /**
         * @brief Exibe o menu de gerenciamento avançado.
         *
         * Este menu deve disponibilizar ferramentas específicas para o gerente,
         * como gestão de acomodações, auditoria, controle financeiro e demais
         * operações administrativas.
         */
        virtual void exibirMenuGerenciador() = 0;

        /**
         * @brief Executa o processo de autenticação privilegiada.
         *
         * "autenticarHacker" funciona como método de acesso especial, destinado
         * a ambientes de teste, depuração ou validação administrativa.
         * A implementação concreta deve definir o comportamento exato.
         */
        virtual void autenticarHacker() = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Necessário para garantir destruição correta de objetos derivados quando
         * manipulados através de ponteiros para a interface.
         */
        virtual ~InterfaceApresentacaoAcessoGerente() = default;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOGERENTE_HPP