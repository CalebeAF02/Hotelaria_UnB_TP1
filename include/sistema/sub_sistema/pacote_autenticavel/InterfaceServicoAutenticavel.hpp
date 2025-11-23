//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceServicoAutenticavel.hpp
 * @brief Declara a interface da camada de serviço responsável pela autenticação no sistema.
 *
 * A camada de serviço representa o nível intermediário entre a camada de apresentação
 * (interface com o usuário) e a camada de persistência (acesso aos dados),
 * sendo responsável por aplicar regras de negócio relacionadas à autenticação.
 *
 * Esta interface define as operações essenciais para que qualquer implementação
 * de serviço de autenticação possa:
 *  - Receber a controladora de persistência responsável por consultar os dados.
 *  - Realizar a autenticação validando estruturas de domínio mais ricas,
 *    como Email e Senha.
 *
 * O objetivo é garantir baixo acoplamento, alta coesão e maior capacidade de manutenção
 * dentro da arquitetura do sistema de hotelaria.
 *
 * Arquitetura:
 *  - Apresentação → Serviço → Persistência
 */
#ifndef Hotelaria_UnB_TP1_ISA_HPP
#define Hotelaria_UnB_TP1_ISA_HPP

#include "InterfacePersistenciaAutenticavel.hpp"
#include "Email.hpp"
#include "Senha.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    /**
     * @class InterfaceServicoAutenticavel
     * @brief Interface responsável pela lógica de autenticação do sistema.
     *
     * Abstrai a camada de regras de negócio referente ao processo de autenticação,
     * permitindo múltiplas implementações (mock, arquivo, banco, etc.) sem alterar
     * as camadas superiores.
     */
    class InterfaceServicoAutenticavel {
    public:
        /**
         * @brief Injeta a dependência da controladora de persistência.
         *
         * Este método conecta a camada de serviço à camada de persistência,
         * permitindo que o serviço consulte a base de dados ou outros mecanismos
         * de armazenamento.
         *
         * @param persistencia Ponteiro para um objeto que implementa InterfacePersistenciaAutenticavel.
         */
        virtual void setControladoraPersistencia(InterfacePersistenciaAutenticavel *persistencia) = 0;

        /**
         * @brief Realiza a autenticação de acordo com as regras de negócio.
         *
         * Diferente da camada de persistência, esta camada trabalha com objetos
         * de domínio mais ricos, garantindo que os dados recebidos já foram validados
         * semanticamente (e.g., formato de email, força da senha).
         *
         * @param email Objeto da classe Email contendo o endereço do gerente/usuário.
         * @param senha Objeto da classe Senha contendo a senha já validada.
         *
         * @return true Se as credenciais forem válidas.
         * @return false Caso contrário.
         */
        virtual bool autenticar(const Email &email, const Senha &senha) = 0;

        /// @brief Destrutor virtual padrão.
        virtual ~InterfaceServicoAutenticavel() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISA_HPP