//
// Created by caleb on 18/11/2025.
//
/**
 * @file ControladoraPersistenciaQuarto.hpp
 * @brief Declaração da classe responsável pela camada de persistência de dados referente aos quartos.
 *
 * Esta classe implementa a interface @ref InterfacePersistenciaQuarto, fornecendo operações CRUD
 * completas para manipulação de instâncias de @ref Quarto no banco de dados da aplicação.
 *
 * A classe atua como intermediária entre o domínio (entidades e DTOs) e a camada de acesso
 * ao banco (SQLite), garantindo encapsulamento e segurança nas interações com a base de dados.
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP

#include "InterfacePersistenciaQuarto.hpp"
#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    /**
     * @class ControladoraPersistenciaQuarto
     * @brief Implementação concreta da interface de persistência para objetos do tipo @ref Quarto.
     *
     * Esta classe é responsável por manipular os registros de quartos na base de dados SQLite,
     * fornecendo métodos para inserção, atualização, exclusão, listagem e pesquisa individual.
     *
     * ### Responsabilidades principais
     * - Realizar operações *CRUD* na tabela de quartos.
     * - Executar consultas SQL de forma segura.
     * - Converter entidades do domínio para DTOs e vice-versa.
     * - Garantir que os dados armazenados estejam consistentes.
     *
     * ### Exemplo de uso
     * @code
     * Hotelaria::ControladoraPersistenciaQuarto persistencia;
     * Quarto quarto(...);
     * persistencia.inserir(quarto);
     * @endcode
     */
    class ControladoraPersistenciaQuarto : public InterfacePersistenciaQuarto {
    public:
        /**
         * @brief Insere um novo quarto no banco de dados.
         *
         * Executa um comando SQL de inserção contendo todos os atributos do objeto @ref Quarto.
         *
         * @param quarto Objeto de domínio contendo os dados a serem persistidos.
         * @return `true` se o quarto for inserido com sucesso, `false` caso contrário.
         *
         * @throws std::runtime_error Caso ocorra falha na execução do SQL.
         */
        bool inserir(const Quarto &quarto) override;

        /**
         * @brief Atualiza os dados de um quarto já existente.
         *
         * Localiza o registro pelo ID e aplica a atualização baseada no objeto @ref Quarto recebido.
         *
         * @param id Identificador único do quarto a ser atualizado.
         * @param quarto Objeto contendo os novos valores para o quarto.
         * @return `true` se a atualização for bem-sucedida, `false` se o ID não existir.
         *
         * @throws std::runtime_error Caso ocorra erro na operação SQL.
         */
        bool atualizar(const int &id, const Quarto &quarto) override;

        /**
         * @brief Exclui um quarto do sistema com base em seu ID.
         *
         * @param id Identificador do quarto a ser removido.
         * @return `true` se o registro for excluído, `false` se não existir.
         *
         * @throws std::runtime_error Caso ocorra erro ao executar o comando de exclusão.
         */
        bool excluir(const int &id) override;

        /**
         * @brief Lista todos os quartos cadastrados no sistema.
         *
         * Realiza uma consulta SQL que retorna todos os registros da tabela de quartos,
         * convertendo cada um deles em um objeto @ref QuartoDTO para transporte eficiente
         * entre camadas.
         *
         * @return Um vetor contendo todos os quartos cadastrados.
         *
         * @throws std::runtime_error Em caso de falha na consulta SQL.
         */
        vector<QuartoDTO> listar() override;

        /**
         * @brief Pesquisa um quarto específico pelo ID.
         *
         * Caso o ID seja encontrado, retorna um @ref QuartoDTO encapsulado em `std::optional`.
         * Caso contrário, retorna `std::nullopt`.
         *
         * @param id Identificador do quarto desejado.
         * @return `optional<QuartoDTO>` contendo o resultado da consulta.
         *
         * @throws std::runtime_error Em caso de erro ao executar a consulta.
         */
        optional<QuartoDTO> pesquisar(const int &id) override;

        /**
         * @brief Retorna a quantidade total de quartos cadastrados para um determinado hotel.
         *
         * Realiza um `SELECT COUNT(*)` filtrado pelo ID do hotel.
         *
         * @param hotel_id ID do hotel alvo.
         * @return Número total de quartos vinculados ao hotel.
         *
         * @throws std::runtime_error Em falhas de leitura no banco.
         */
        int getQuantidadeDeQuartosDoHotel(int hotel_id) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP