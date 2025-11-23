//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraServicoAutenticavel.hpp
 * @brief Declara a classe responsável pela lógica de autenticação na camada de serviços.
 *
 * Esta classe implementa a interface de serviço de autenticação, conectando a camada
 * de apresentação à camada de persistência. É responsável por orquestrar o processo
 * de autenticação, realizando validações e delegando as verificações finais de
 * credenciais à camada de persistência.
 *
 * Seu papel é essencial na arquitetura do sistema, pois centraliza a lógica de
 * autenticação e impede que a camada de apresentação acesse diretamente os dados
 * persistidos.
 *
 * Arquitetura relacionada:
 * - Camada de Apresentação (View)
 * - Camada de Serviço (Application)
 * - Camada de Persistência (Repository)
 */
#ifndef Hotelaria_UnB_TP1_CSA_HPP
#define Hotelaria_UnB_TP1_CSA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"
#include "ControladoraPersistenciaGerente.hpp"
#include "Email.hpp"
#include "Senha.hpp"

#include "IO.hpp"
#include <iostream>

using namespace std;

namespace Hotelaria {
    /**
     * @class ControladoraServicoAutenticavel
     * @brief Implementação concreta do serviço de autenticação do sistema.
     *
     * Esta classe funciona como o módulo intermediário entre a interface de
     * apresentação e a camada de persistência. Sua principal função é receber
     * credenciais encapsuladas nos objetos @c Email e @c Senha, realizar
     * validações preliminares (se necessário) e solicitar ao mecanismo de
     * persistência que confirme se as credenciais são válidas.
     *
     * Responsabilidades principais:
     * - Receber email e senha da camada de apresentação.
     * - Delegar ao componente de persistência a verificação das credenciais.
     * - Aplicar regras de autenticação, caso existam.
     * - Garantir isolamento entre apresentação e dados.
     *
     * A classe segue o princípio de inversão de dependência (DIP),
     * permitindo que diferentes implementações de persistência sejam
     * utilizadas sem alterar o código da lógica de autenticação.
     */
    class ControladoraServicoAutenticavel : public InterfaceServicoAutenticavel {
    private:
        /**
         * @brief Ponteiro para o componente responsável pela persistência.
         *
         * Esse componente será utilizado para autenticar o usuário com base
         * nos dados armazenados. O uso de uma interface permite facilmente
         * trocar a implementação de persistência sem alterar o serviço.
         */
        InterfacePersistenciaAutenticavel *persistencia;

    public:
        /**
         * @brief Injeta a controladora de persistência utilizada no processo de autenticação.
         *
         * Esta operação implementa o padrão de injeção de dependência,
         * permitindo que a camada de serviço seja independente da implementação
         * específica da persistência.
         *
         * @param persistencia Ponteiro para um objeto que implementa
         *                     @c InterfacePersistenciaAutenticavel.
         */
        void setControladoraPersistencia(InterfacePersistenciaAutenticavel *persistencia) override;

        /**
         * @brief Executa o processo de autenticação.
         *
         * Recebe objetos @c Email e @c Senha, e delega a validação para a
         * camada de persistência. O método pode incluir, em versões futuras,
         * verificações adicionais, como regras de segurança ou auditoria.
         *
         * @param email Objeto representando o email informado pelo usuário.
         * @param senha Objeto representando a senha informada.
         * @return true se as credenciais forem válidas; false caso contrário.
         */
        bool autenticar(const Email &email, const Senha &senha) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSA_HPP