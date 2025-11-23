//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraServicoQuarto.hpp
 * @brief Declaração da classe responsável pela camada de serviços aplicada aos quartos.
 *
 * A classe @ref ControladoraServicoQuarto representa a camada de lógica de aplicação (Service Layer)
 * responsável por orquestrar regras de negócio relacionadas à entidade @ref Quarto.
 *
 * Ela funciona como intermediária entre a camada de apresentação (UI) e a camada de persistência,
 * delegando operações ao repositório apropriado (@ref InterfacePersistenciaQuarto) e realizando
 * validações, formatações, verificações de estado e tratamento de erros.
 *
 * Esta classe é utilizada pelo sistema de hotelaria para manipular quartos de forma controlada,
 * garantindo que todas as operações sigam as regras da aplicação.
 */
#ifndef Hotelaria_UnB_TP1_CSQUARTO_HPP
#define Hotelaria_UnB_TP1_CSQUARTO_HPP

#include "InterfaceServicoQuarto.hpp"
#include "InterfacePersistenciaGerente.hpp"
#include "ControladoraPersistenciaGerente.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    /**
     * @class ControladoraServicoQuarto
     * @brief Camada de serviço responsável pela lógica de negócios relacionada a quartos.
     *
     * Esta classe implementa a interface @ref InterfaceServicoQuarto e fornece métodos para:
     * - Criar um novo quarto.
     * - Editar dados de um quarto existente.
     * - Remover um quarto.
     * - Listar todos os quartos.
     * - Pesquisar um quarto por ID.
     * - Verificar a quantidade de quartos associados a um determinado hotel.
     *
     * Atua como uma "fachada" entre a interface do usuário e a camada de persistência,
     * garantindo que a lógica do negócio seja aplicada corretamente antes de persistir,
     * exibir ou modificar dados.
     *
     * ### Padrões aplicados
     * - *Service Layer*: organiza a lógica de negócio.
     * - *Dependency Injection*: a persistência é injetada via @ref setControladoraPersistencia.
     * - *DTO Pattern*: as operações retornam @ref QuartoDTO em vez da entidade completa.
     */
    class ControladoraServicoQuarto : public InterfaceServicoQuarto {
    private:
        /**
         * @brief Ponte para o componente responsável pela persistência de quartos.
         *
         * Esta dependência é configurada externamente utilizando o método
         * @ref setControladoraPersistencia, permitindo maior flexibilidade, inversão de controle
         * e testabilidade da aplicação.
         */
        InterfacePersistenciaQuarto *persistencia;

    public:
        /**
         * @brief Define qual controladora de persistência será utilizada pelo serviço.
         *
         * Este método implementa injeção de dependência, permitindo que diferentes
         * implementações de persistência sejam utilizadas sem alterar a lógica da classe.
         *
         * @param persistencia Ponte para uma instância que implementa @ref InterfacePersistenciaQuarto.
         */
        void setControladoraPersistencia(InterfacePersistenciaQuarto *persistencia) override;

        /**
         * @brief Cria um novo quarto no sistema após validar os dados fornecidos.
         *
         * Realiza verificações de consistência, regras de negócio e, se válido,
         * encaminha o objeto @ref Quarto para ser persistido.
         *
         * @param quarto Objeto contendo os dados do quarto a ser criado.
         * @return `true` caso o quarto seja criado com sucesso, `false` em caso de erro ou dados inválidos.
         *
         * @throws std::runtime_error Caso ocorra alguma falha crítica durante a operação.
         */
        bool criar(const Quarto &quarto) override;

        /**
         * @brief Edita as informações de um quarto já existente.
         *
         * Antes da atualização, a classe pode realizar validação de campos e verificar
         * se o quarto realmente existe. Caso positivo, a atualização é repassada para a camada
         * de persistência.
         *
         * @param id Identificador único do quarto.
         * @param quarto Objeto contendo os novos dados.
         * @return `true` se a operação for concluída, `false` caso o ID seja inválido ou inexistente.
         *
         * @throws std::runtime_error Em falhas inesperadas de persistência.
         */
        bool editar(const int &id, const Quarto &quarto) override;

        /**
         * @brief Remove um quarto do sistema com base em seu ID.
         *
         * @param id Identificador do quarto a ser removido.
         * @return `true` se a remoção for realizada, `false` caso o quarto não exista.
         *
         * @throws std::runtime_error Caso a operação SQL falhe.
         */
        bool remover(const int &id) override;

        /**
         * @brief Lista todos os quartos cadastrados no sistema.
         *
         * @return Vetor contendo todos os objetos @ref QuartoDTO existentes.
         *
         * @throws std::runtime_error Caso haja falha na leitura do banco de dados.
         */
        vector<QuartoDTO> listarTodos() override;

        /**
         * @brief Pesquisa um quarto específico com base no ID.
         *
         * @param id Identificador do quarto desejado.
         * @return `optional<QuartoDTO>` contendo o resultado da busca.
         *         Se o quarto não existir, retorna `nullopt`.
         *
         * @throws std::runtime_error Em caso de falhas de comunicação com a camada de persistência.
         */
        optional<QuartoDTO> pesquisar(const int &id) override;

        /**
         * @brief Obtém a quantidade de quartos cadastrados para um hotel específico.
         *
         * @param hotel_id ID do hotel alvo.
         * @return Número de quartos vinculados ao hotel.
         *
         * @throws std::runtime_error Caso ocorra falha na execução da consulta.
         */
        int getQuantidadeDeQuartosDoHotel(int hotel_id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSQUARTO_HPP