//
// Created by caleb on 19/11/2025.
//
/**
 * @file InterfacePersistenciaAutenticavel.hpp
 * @brief Declara a interface de persistência usada para autenticação no sistema de Hotelaria.
 *
 * Esta interface representa o contrato mínimo que a camada de persistência deve cumprir
 * para fornecer suporte à autenticação de usuários (como gerentes ou administradores).
 *
 * A implementação concreta desta interface deve acessar a fonte de dados adequada,
 * podendo ser:
 *  - Arquivos locais
 *  - Banco de dados relacional
 *  - Banco não relacional
 *  - Sistemas externos
 *
 * O objetivo desta interface é garantir baixo acoplamento entre a camada de serviço
 * (responsável pelas regras de autenticação) e a camada de persistência.
 *
 * Arquitetura utilizada:
 *  - Interface de Persistência  → acesso a dados
 *  - Interface de Serviço       → regras de negócio
 *  - Interface de Apresentação  → interação com o usuário
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP

#include <iostream>

using namespace std;

namespace Hotelaria {
    /**
     * @class InterfacePersistenciaAutenticavel
     * @brief Interface base para persistência de autenticação.
     *
     * Define o método necessário para que qualquer implementação possa validar
     * as credenciais de um usuário, verificando email e senha em uma fonte de dados.
     */
    class InterfacePersistenciaAutenticavel {
    public:
        /**
         * @brief Verifica se as credenciais fornecidas correspondem a um registro válido.
         *
         * Este método é utilizado pela camada de serviço para confirmar se o usuário
         * pode ser autenticado no sistema.
         *
         * @param email E-mail informado pelo usuário.
         * @param senha Senha correspondente ao e-mail informado.
         *
         * @return true Se a autenticação for bem-sucedida.
         * @return false Caso o e-mail ou a senha não correspondam aos registros.
         */
        virtual bool autenticar(const string &email, const string &senha) = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAAUTENTICAVEL_HPP