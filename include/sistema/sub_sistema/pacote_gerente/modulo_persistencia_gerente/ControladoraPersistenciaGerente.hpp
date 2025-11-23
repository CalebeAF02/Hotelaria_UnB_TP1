//
// Created by caleb on 16/10/2025.
//
/**
 * @file ControladoraPersistenciaGerente.hpp
 * @brief Declaração da classe ControladoraPersistenciaGerente, responsável pela
 *        persistência de dados de Gerentes utilizando SQLite.
 *
 * @details
 * Esta classe implementa a interface InterfacePersistenciaGerente e fornece
 * métodos para manipulação persistente de registros de Gerentes, incluindo:
 *  - Inserção
 *  - Autenticação
 *  - Atualização
 *  - Remoção
 *  - Pesquisa
 *  - Listagem
 *
 * A classe segue o padrão arquitetural **DAO/Repository**, sendo responsável
 * exclusivamente pelo acesso ao banco de dados e mapeamento entre objetos da
 * aplicação e registros persistidos.
 *
 * Utiliza a biblioteca SQLite3 e a infraestrutura do BancoDeDados do sistema.
 */

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include "InterfacePersistenciaGerente.hpp"
#include "GerenteDTO.hpp"
#include "Gerente.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    /**
     * @class ControladoraPersistenciaGerente
     * @brief Implementação concreta da persistência de Gerentes via SQLite.
     *
     * @details
     * Essa classe atua como o repositório/DAO do módulo "Gerente".
     * É responsável por traduzir objetos de domínio (Gerente) para registros
     * persistidos no banco de dados e vice-versa (GerenteDTO).
     *
     * Cada método executa comandos SQL diretamente, utilizando a conexão
     * fornecida pelo BancoDeDados.
     *
     * A classe respeita princípios SOLID:
     *  - **S – Single Responsibility:** Apenas manipula persistência.
     *  - **D – Dependency Inversion:** Depende da interface InterfacePersistenciaGerente,
     *    permitindo fácil substituição por mocks ou outras tecnologias de banco.
     */
    class ControladoraPersistenciaGerente : public InterfacePersistenciaGerente {
    public:
        /**
         * @brief Insere um novo Gerente no banco de dados.
         *
         * @param gerente Objeto contendo os dados estruturados do Gerente.
         * @return true Se a inserção foi realizada com sucesso.
         * @return false Se ocorreu um erro de banco ou restrição (ex.: email duplicado).
         *
         * @details
         * Este método usa SQL INSERT INTO.
         * Aplica verificação de unicidade de email antes da inserção.
         */
        bool inserir(const Gerente &gerente) override;

        /**
         * @brief Verifica se existe um Gerente com o email e senha fornecidos.
         *
         * @param email Email informado no login.
         * @param senha Senha em texto puro (normalmente comparada após hash).
         * @return true Caso as credenciais coincidam com um registro persistido.
         * @return false Caso não exista ou senha não corresponda.
         *
         * @details
         * Executa SQL SELECT filtrando por email e senha.
         * Implementações reais recomendariam hashing seguro.
         */
        bool autenticar(const string &email, const string &senha) override;

        /**
         * @brief Atualiza os dados de um Gerente já existente.
         *
         * @param email Email utilizado como chave para localizar o registro.
         * @param gerente Objeto contendo os novos valores a serem aplicados.
         * @return true Se a atualização foi bem-sucedida.
         * @return false Se nenhum registro foi encontrado ou houve erro de banco.
         *
         * @details
         * Executa SQL UPDATE filtrando pelo email.
         */
        bool atualizar(const Email &email, const Gerente &gerente) override;

        /**
         * @brief Exclui um Gerente baseado no seu ID único.
         *
         * @param id Identificador numérico do registro.
         * @return true Em caso de remoção bem-sucedida.
         * @return false Se o ID não existir ou ocorrer erro.
         *
         * @details
         * Executa SQL DELETE FROM com cláusula WHERE id = ?.
         */
        bool excluir(const int &id) override;

        /**
         * @brief Retorna todos os gerentes cadastrados na base.
         *
         * @return Vetor contendo todos os GerenteDTO persistidos.
         *
         * @details
         * Executa SQL SELECT * FROM Gerentes.
         * Os resultados brutos são convertidos para objetos GerenteDTO.
         */
        vector<GerenteDTO> listar() override;

        /**
         * @brief Pesquisa um Gerente pelo seu ID.
         *
         * @param id Identificador único do registro.
         * @return optional<GerenteDTO> contendo o registro, se existir.
         *
         * @details
         * Retorna std::nullopt caso nenhum registro correspondente seja encontrado.
         */
        optional<GerenteDTO> pesquisarPorID(const int &id) override;

        /**
         * @brief Pesquisa um Gerente pelo email cadastrado.
         *
         * @param email Email associado ao Gerente.
         * @return optional<GerenteDTO> contendo o registro, se existir.
         */
        optional<GerenteDTO> pesquisarPorEmail(const string email) override;

        /**
         * @brief Verifica se já existe um gerente cadastrado com o email informado.
         *
         * @param email Email a ser verificado.
         * @return true Se já existe um gerente com esse email.
         * @return false Caso contrário.
         *
         * @details
         * Usado principalmente para garantir unicidade antes de inserções.
         */
        bool existeEmail(const string &email) override;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H