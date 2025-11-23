//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceApresentacaoAutenticavel.hpp
 * @brief Declara a interface da camada de apresentação responsável pelo fluxo de autenticação.
 *
 * A camada de apresentação é responsável por interagir diretamente com o usuário,
 * exibindo menus, capturando entradas e coordenando o fluxo de autenticação.
 *
 * Esta interface estabelece os métodos essenciais para que qualquer classe concreta
 * que represente uma "apresentação autenticável" (ex.: menu do gerente) seja capaz de:
 *
 *  - Integrar-se com a camada de serviço de autenticação.
 *  - Controlar o estado de autenticação do gerente.
 *  - Armazenar temporariamente o email do gerente que deseja autenticar-se.
 *  - Executar o fluxo de autenticação utilizando o serviço.
 *
 * Arquitetura:
 *  - Apresentação → Serviço → Persistência
 *
 * O objetivo central é garantir independência entre camadas,
 * flexibilizando manutenção e futuras expansões do sistema.
 */

#ifndef Hotelaria_UnB_TP1_IAA_HPP
#define Hotelaria_UnB_TP1_IAA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "IO.hpp"
#include <iostream>

using namespace std;

namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoAutenticavel
     * @brief Interface da camada de apresentação destinada ao processo de autenticação.
     *
     * Classes concretas que implementarem esta interface serão responsáveis por:
     *  - Interagir com o usuário (entrada e saída).
     *  - Coordenar o fluxo de autenticação do gerente.
     *  - Solicitar ao serviço de autenticação a validação das credenciais.
     *
     * Esta interface não conhece regras de negócio nem lógica de persistência,
     * apenas organiza o fluxo e a experiência do usuário.
     */
    class InterfaceApresentacaoAutenticavel {
    public:
        /**
         * @brief Injeta a dependência da camada de serviço de autenticação.
         *
         * Permite que a camada de apresentação utilize as regras de negócio
         * de autenticação sem depender diretamente de implementações concretas.
         *
         * @param servico Ponteiro para um objeto que implementa InterfaceServicoAutenticavel.
         */
        virtual void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *servico) = 0;


        /**
         * @brief Armazena temporariamente o email do gerente que será autenticado.
         *
         * Esse dado é normalmente solicitado ao usuário antes da autenticação
         * e utilizado internamente pelo fluxo da apresentação.
         *
         * @param email Email informado pelo gerente.
         */
        virtual void setEmailDoGerente(const string &email) = 0;

        /**
         * @brief Recupera o email armazenado do gerente.
         *
         * @return string contendo o email previamente definido.
         */
        virtual string getEmailDOGerente() = 0;


        /**
         * @brief Define se o gerente está autenticado.
         *
         * Esse estado é útil para controlar permissões, exibir menus específicos
         * ou permitir ações restritas.
         *
         * @param estaAutenticado true se o gerente estiver autenticado, false caso contrário.
         */
        virtual void setEstaAutenticado(bool estaAutenticado) = 0;

        /**
         * @brief Obtém o estado atual de autenticação do gerente.
         *
         * @return true se estiver autenticado.
         * @return false caso contrário.
         */
        virtual bool getEstaAutenticado() = 0;


        /**
         * @brief Executa o fluxo de autenticação completo.
         *
         * Este método normalmente:
         *  - Exibe prompts ao usuário.
         *  - Solicita email e senha.
         *  - Encaminha os dados ao serviço de autenticação.
         *  - Atualiza o estado de autenticação.
         *
         * @return true se autenticado com sucesso.
         * @return false caso não autenticado.
         */
        virtual bool autenticar() = 0;


        /**
         * @brief Retorna a controladora de serviço associada.
         *
         * Possui finalidade de debugging ou inspeção interna.
         * O nome "getHacke" sugere uso temporário ou técnico.
         *
         * @return Ponteiro para InterfaceServicoAutenticavel.
         */
        virtual InterfaceServicoAutenticavel *getHacke() = 0;


        /// @brief Destrutor virtual padrão.
        virtual ~InterfaceApresentacaoAutenticavel() = default;
    };
}


#endif //Hotelaria_UnB_TP1_IAA_HPP