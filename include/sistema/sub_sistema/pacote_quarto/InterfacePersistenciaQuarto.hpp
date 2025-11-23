//
// Created by caleb on 19/11/2025.
//
/**
 * @file InterfacePersistenciaQuarto.hpp
 * @brief Declaração da interface que define o contrato da camada de persistência para quartos.
 *
 * Esta interface estabelece todas as operações necessárias para que qualquer implementação
 * de persistência de dados (SQLite, PostgreSQL, MySQL, arquivos, etc.) possa ser utilizada pelo
 * sistema sem alterar a lógica de negócio.
 *
 * Ela representa o repositório da entidade @ref Quarto, permitindo que a aplicação siga os
 * princípios de baixo acoplamento, inversão de dependência e separação de responsabilidades.
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP

#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    /**
     * @class InterfacePersistenciaQuarto
     * @brief Interface base para operações de persistência da entidade Quarto.
     *
     * Qualquer classe concreta responsável por acessar o banco de dados deve implementar esta
     * interface, garantindo que o sistema possa executar:
     * - Inserção de novos quartos.
     * - Atualização de dados existentes.
     * - Exclusão de registros.
     * - Listagem de todos os quartos.
     * - Pesquisa por ID.
     * - Contagem de quartos por hotel.
     *
     * ### Propósitos principais
     * - Estabelecer um contrato claro entre a camada de serviço e a camada de persistência.
     * - Permitir substituição da tecnologia de banco de dados sem alterar o código da aplicação.
     * - Facilitar testes unitários através de *mocks* ou *stubs* de persistência.
     *
     * ### Padrões aplicados
     * - *Repository Pattern*
     * - *Dependency Inversion Principle (DIP)*
     * - *Interface Segregation Principle (ISP)*
     */
    class InterfacePersistenciaQuarto {
    public:
        /**
         * @brief Insere um novo quarto no armazenamento persistente.
         *
         * @param quarto Objeto contendo os dados que serão armazenados.
         * @return `true` se o quarto for inserido com sucesso, `false` em caso de falha.
         */
        virtual bool inserir(const Quarto &quarto) = 0;

        /**
         * @brief Atualiza os dados de um quarto já existente.
         *
         * @param id Identificador único do quarto a ser atualizado.
         * @param quarto Objeto contendo os novos valores a serem aplicados.
         * @return `true` se o registro for encontrado e atualizado, `false` caso contrário.
         */
        virtual bool atualizar(const int &id, const Quarto &quarto) = 0;

        /**
         * @brief Remove definitivamente um quarto do armazenamento.
         *
         * @param id Identificador do quarto a ser removido.
         * @return `true` se a remoção ocorrer com sucesso, `false` se o ID não existir.
         */
        virtual bool excluir(const int &id) = 0;

        /**
         * @brief Retorna a lista completa de quartos cadastrados.
         *
         * Utiliza objetos do tipo @ref QuartoDTO para transportar dados de forma eficiente
         * sem expor regras internas da entidade.
         *
         * @return Vetor contendo todos os quartos cadastrados.
         */
        virtual vector<QuartoDTO> listar() = 0;

        /**
         * @brief Pesquisa um quarto específico pelo seu ID.
         *
         * @param id Identificador do quarto desejado.
         * @return `optional<QuartoDTO>` contendo os dados, caso encontrado,
         *         ou `nullopt` se não existir.
         */
        virtual optional<QuartoDTO> pesquisar(const int &id) = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Garante a destruição correta das instâncias concretas via ponteiros para interface.
         */
        virtual ~InterfacePersistenciaQuarto() = default;

        /**
         * @brief Obtém a quantidade de quartos pertencentes a um hotel específico.
         *
         * @param hotel_id ID do hotel alvo.
         * @return Número total de quartos vinculados ao hotel.
         */
        virtual int getQuantidadeDeQuartosDoHotel(int hotel_id) = 0;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAQUARTO_HPP