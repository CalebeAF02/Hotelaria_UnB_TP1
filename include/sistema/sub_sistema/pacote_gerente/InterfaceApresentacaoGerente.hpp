//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceApresentacaoGerente.hpp
 * @brief Define a interface da camada de apresentação destinada ao módulo de Gerente.
 *
 * @details
 * Esta interface estabelece o contrato que qualquer classe de apresentação
 * (UI, CLI ou outro frontend) deve seguir para interagir com o módulo
 * de gerenciamento de Gerentes.
 *
 * Ela atua como o elo entre:
 *  - O usuário final (interação direta)
 *  - A camada de serviço (InterfaceServicoGerente)
 *
 * Não contém lógica de negócio: apenas orquestra fluxos de entrada e saída.
 *
 * Métodos definidos:
 *  - Configuração da controladora de serviços
 *  - Operações CRUD (criar, listar, atualizar, remover)
 *  - Avaliação de solicitações de hospedagem
 *
 * Segue o princípio **DIP** (Dependency Inversion Principle).
 */
#ifndef Hotelaria_UnB_TP1_IAP_HPP
#define Hotelaria_UnB_TP1_IAP_HPP

#include "InterfaceServicoGerente.hpp"

namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoGerente
     * @brief Interface para a camada de apresentação do módulo Gerente.
     *
     * @details
     * Esta interface define todos os métodos que uma classe de apresentação
     * deve implementar para permitir que um Gerente execute tarefas administrativas.
     *
     * Exemplo de responsabilidades:
     *  - Controlar menus
     *  - Exibir mensagens ao usuário
     *  - Coletar dados para operações CRUD
     *  - Solicitar ações ao serviço (InterfaceServicoGerente)
     */
    class InterfaceApresentacaoGerente {
    public:
        /**
         * @brief Define o serviço (camada de negócios) que será utilizado pela apresentação.
         *
         * @param servico Ponteiro para uma implementação de InterfaceServicoGerente.
         *
         * @details
         * Implementa o padrão *Dependency Injection*.
         */
        virtual void setControladoraServicoGerente(InterfaceServicoGerente *servico) = 0;

        /**
         * @brief Exibe o menu CRUD de gerentes.
         *
         * @details
         * Deve apresentar opções como:
         *  - Criar Gerente
         *  - Listar Gerentes
         *  - Atualizar Gerente
         *  - Remover Gerente
         *
         * É o principal ponto de entrada da interface visual do módulo.
         */
        virtual void exibirMenuCRUD() = 0;

        /**
         * @brief Realiza o cadastro de um novo gerente.
         *
         * @return true Caso a criação seja bem-sucedida.
         * @return false Caso ocorra erro de validação ou persistência.
         *
         * @details
         * A implementação deve coletar informações do usuário,
         * validar formatos básicos e enviar os dados ao serviço.
         */
        virtual bool criar() = 0;

        /**
         * @brief Lista todos os gerentes cadastrados no sistema.
         *
         * @details
         * A implementação deve solicitar ao serviço a lista e exibi-la
         * de forma organizada (tabela, lista, etc.).
         */
        virtual void listar() = 0;

        /**
         * @brief Atualiza os dados de um gerente existente.
         *
         * @details
         * A classe de apresentação deve:
         *  - Solicitar identificação (email, ID…)
         *  - Perguntar novos dados
         *  - Encaminhar ao serviço para validação e persistência
         */
        virtual void atualizar() = 0;

        /**
         * @brief Remove um gerente do sistema.
         *
         * @details
         * A apresentação deve confirmar a operação com o usuário antes
         * de encaminhar ao serviço.
         */
        virtual void remover() = 0;

        /**
         * @brief Permite ao gerente avaliar solicitações de hospedagem pendentes.
         *
         * @details
         * Este método integra o módulo de Gerente com o módulo de Solicitação
         * de Hospedagem, permitindo operações como:
         *  - Aprovar
         *  - Rejeitar
         *  - Revisar detalhes da solicitação
         */
        virtual void avaliarSolicitacoes() = 0;

        /// @brief Destrutor virtual para uso seguro com ponteiros polimórficos.
        virtual ~InterfaceApresentacaoGerente() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAP_HPP