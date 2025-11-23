//
// Created by caleb on 19/11/2025.
//
/**
 * @file InterfacePersistenciaGerente.hpp
 * @brief Define a interface responsável pela persistência de dados de Gerentes no sistema de Hotelaria.
 *
 * Esta interface estabelece o contrato mínimo necessário para qualquer classe
 * que implemente a persistência de objetos do tipo `Gerente`.
 *
 * Ela permite que diferentes tecnologias de armazenamento (SQLite, MySQL,
 * arquivos, APIs externas etc.) possam ser utilizadas sem alterar as camadas
 * superiores do sistema.
 *
 * O padrão arquitetural aplicado segue a divisão em camadas: Apresentação →
 * Serviço → Persistência.
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP

#include "GerenteDTO.hpp"
#include "Gerente.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    /**
     * @class InterfacePersistenciaGerente
     * @brief Interface abstrata para operações de persistência relacionadas ao Gerente.
     *
     * Esta interface define os métodos essenciais para armazenamento,
     * consulta, modificação e exclusão de registros de gerentes.
     *
     * Implementações concretas podem incluir:
     * - Persistência em banco SQLite
     * - Persistência em MySQL
     * - Persistência em arquivos JSON/CSV
     * - Mock para testes automatizados
     */
    class InterfacePersistenciaGerente {
    public:
        /**
         * @brief Insere um novo gerente no repositório.
         *
         * @param gerente Objeto contendo os dados completos do gerente.
         * @return `true` se a inserção ocorrer com sucesso, `false` caso contrário.
         */
        virtual bool inserir(const Gerente &gerente) = 0;

        /**
         * @brief Autentica um gerente com base em email e senha.
         *
         * @param email Email cadastrado do gerente.
         * @param senha Senha correspondente ao email.
         * @return `true` se as credenciais forem válidas, `false` caso contrário.
         */
        virtual bool autenticar(const string &email, const string &senha) = 0;

        /**
         * @brief Atualiza os dados de um gerente já existente.
         *
         * @param email Identificador do gerente a ser atualizado.
         * @param gerente Objeto contendo os novos dados do gerente.
         * @return `true` se os dados forem atualizados com sucesso.
         */
        virtual bool atualizar(const Email &email, const Gerente &gerente) = 0;

        /**
         * @brief Exclui um gerente do repositório.
         *
         * @param id Identificador único do gerente.
         * @return `true` se a exclusão for bem-sucedida.
         */
        virtual bool excluir(const int &id) = 0;

        /**
         * @brief Lista todos os gerentes cadastrados.
         *
         * @return Um vetor contendo objetos GerenteDTO.
         */
        virtual vector<GerenteDTO> listar() = 0;

        /**
         * @brief Pesquisa um gerente pelo seu ID.
         *
         * @param id Identificador único do gerente.
         * @return Um `optional` contendo o GerenteDTO, caso encontrado.
         */
        virtual optional<GerenteDTO> pesquisarPorID(const int &id) = 0;

        /**
         * @brief Pesquisa um gerente com base no email cadastrado.
         *
         * @param email Email a ser buscado.
         * @return Um `optional` contendo o GerenteDTO, caso encontrado.
         */
        virtual optional<GerenteDTO> pesquisarPorEmail(const string email) = 0;

        /**
         * @brief Verifica se já existe um gerente com determinado email.
         *
         * @param email Email a ser verificado.
         * @return `true` se o email já estiver cadastrado.
         */
        virtual bool existeEmail(const string &email) = 0;

        /// Destrutor virtual padrão.
        virtual ~InterfacePersistenciaGerente() = default;
    };
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP