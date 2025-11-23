//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceApresentacaoHospede.hpp
 * @brief Declaração da interface de apresentação responsável pela camada de UI
 *        e interação com o usuário para operações envolvendo hóspedes.
 *
 * Esta interface define as operações básicas que toda tela/menu de hóspedes
 * deve implementar, seguindo o padrão Arquitetural MVC/Camadas:
 *
 * - Interface → Apresentação ao usuário
 * - Serviço   → Regras de negócio
 * - Persistência → Banco de Dados
 *
 * A InterfaceApresentacaoHospede lida apenas com a entrada e saída de dados,
 * encaminhando solicitações para a camada de serviço.
 */
#ifndef Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP
#include "InterfaceServicoHospede.hpp"

namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoHospede
     * @brief Interface responsável pela apresentação e interação com o usuário,
     *        referente às operações CRUD de hóspedes.
     *
     * Qualquer implementação (menus, interface gráfica, terminal, etc.)
     * deve seguir esta estrutura.
     */
    class InterfaceApresentacaoHospede {
    public:
        /**
         * @brief Injeta a dependência da Controladora de Serviço de Hóspede.
         *
         * A controladora de serviço contém as regras de negócio e se comunica
         * com a camada de persistência.
         *
         * @param servico Ponteiro para uma implementação de InterfaceServicoHospede.
         */
        virtual void setControladoraServicoHospede(InterfaceServicoHospede *servico) = 0;

        /**
         * @brief Exibe o menu principal de operações CRUD para hóspedes.
         *
         * Deve permitir, por exemplo:
         * - Criar hóspede
         * - Listar hóspedes
         * - Atualizar hóspede
         * - Remover hóspede
         * - Voltar ao menu principal
         */
        virtual void exibirMenuCRUD() = 0;

        /**
         * @brief Solicita ao usuário os dados necessários e cria um novo hóspede.
         *
         * A implementação deve validar dados e encaminhar para a camada de serviço.
         *
         * @return true se o hóspede foi criado com sucesso, false caso contrário.
         */
        virtual bool criar() = 0;

        /**
         * @brief Lista todos os hóspedes cadastrados no sistema.
         *
         * Deve exibir de forma tabulada ou organizada as informações básicas.
         */
        virtual void listar() = 0;

        /**
         * @brief Atualiza os dados de um hóspede existente.
         *
         * Normalmente solicita um e-mail ou ID para localizar o hóspede,
         * e em seguida os novos dados a serem aplicados.
         */
        virtual void atualizar() = 0;

        /**
         * @brief Remove um hóspede do sistema.
         *
         * A implementação pode solicitar um ID ou e-mail para realizar a operação.
         */
        virtual void remover() = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~InterfaceApresentacaoHospede() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAHOSPEDAGEM_HPP