//
// Created by caleb on 22/11/2025.
//
/**
 * @file InterfaceApresentacaoAcessoHospede.hpp
 * @brief Declaração da interface de apresentação para acesso e operações do hóspede
 *        no sistema de Gerenciamento de Hotéis.
 *
 * Esta interface define as funcionalidades essenciais disponíveis para o hóspede,
 * incluindo visualização de menus, opções de hospedagem e solicitações de reserva.
 * Qualquer classe concreta que implemente esta interface deve fornecer uma
 * implementação consistente dessas operações.
 *
 * @date 22/11/2025
 * @author Caleb
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP


namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoAcessoHospede
     * @brief Interface responsável pela apresentação das funcionalidades acessíveis ao hóspede.
     *
     * Esta interface define o contrato mínimo que classes de interface gráfica ou textual
     * devem seguir para disponibilizar operações específicas ao usuário hóspede do sistema.
     * Entre essas operações estão:
     *
     * - Exibição do menu principal;
     * - Acesso às opções de hospedagem disponíveis;
     * - Procedimentos de solicitação de hospedagem (reserva).
     *
     * Garante isolamento entre a lógica de apresentação e a lógica de negócios.
     */
    class InterfaceApresentacaoAcessoHospede {
    public:
        /**
         * @brief Exibe o menu principal destinado ao hóspede.
         *
         * Deve apresentar opções como:
         * - visualizar acomodações disponíveis;
         * - solicitar reserva;
         * - acessar informações do cadastro;
         * - consultar status de hospedagem.
         *
         * A implementação deve assegurar validação adequada da entrada do usuário.
         */
        virtual void exibirMenu() = 0;

        /**
         * @brief Exibe as opções de hospedagem disponíveis.
         *
         * Pode incluir:
         * - tipos de quartos;
         * - tarifas;
         * - comodidades;
         * - disponibilidade no período desejado.
         *
         * Implementações podem se conectar a um módulo de catálogo ou repositório.
         */
        virtual void opcoesDeHospedagem() = 0;

        /**
         * @brief Realiza o procedimento de solicitação de hospedagem.
         *
         * Geralmente envolve:
         * - coleta de dados do hóspede;
         * - datas de check-in e check-out;
         * - validação de disponibilidade;
         * - confirmação da reserva.
         *
         * Classes concretas devem definir como essas etapas são apresentadas ao usuário.
         */
        virtual void solicitandoHospedagem() = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Necessário para garantir destruição correta das classes derivadas
         * manipuladas via ponteiros para a interface.
         */
        virtual ~InterfaceApresentacaoAcessoHospede() = default;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEAPRESENTACAOACESSOHOSPEDE_HPP