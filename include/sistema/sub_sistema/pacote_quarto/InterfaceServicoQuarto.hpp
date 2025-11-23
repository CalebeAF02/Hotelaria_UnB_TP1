//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceServicoQuarto.hpp
 * @brief Define o contrato da camada de serviços voltada à lógica de negócios dos quartos.
 *
 * Esta interface representa a *Service Layer* responsável por manipular a entidade
 * @ref Quarto e seus respectivos DTOs, aplicando regras de negócio, validação e comunicação
 * com a camada de persistência (@ref InterfacePersistenciaQuarto).
 *
 * Ela funciona como intermediária entre a camada de apresentação e a persistência,
 * garantindo que nenhuma regra de negócio seja violada.
 */
#ifndef Hotelaria_UnB_TP1_ISQUARTO_HPP
#define Hotelaria_UnB_TP1_ISQUARTO_HPP

#include "InterfacePersistenciaQuarto.hpp"
#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    /**
     * @class InterfaceServicoQuarto
     * @brief Interface abstrata para a camada de serviço que gerencia operações de quartos.
     *
     * Esta interface define todas as operações essenciais que a camada de serviço deve
     * oferecer ao restante do sistema. Ela representa o ponto central onde regras de negócio
     * e validações referentes à entidade @ref Quarto são aplicadas antes de qualquer interação
     * com o banco de dados.
     *
     * ### Responsabilidades principais da camada de serviço:
     * - Validar dados antes de enviá-los para a persistência.
     * - Garantir integridade lógica das operações.
     * - Intermediar comunicação entre apresentação e persistência.
     * - Converter entidades para DTOs e vice-versa, quando necessário.
     *
     * ### Padrões utilizados:
     * - *Service Layer*
     * - *Dependency Injection*
     * - *Repository Pattern*
     * - *Single Responsibility Principle (SRP)*
     * - *Dependency Inversion Principle (DIP)*
     */
    class InterfaceServicoQuarto {
    public:
        /**
         * @brief Define qual controladora de persistência será utilizada.
         *
         * O sistema utiliza Injeção de Dependência para permitir diferentes formas de
         * persistência (SQLite, MySQL, arquivos, memória, mocks para testes).
         *
         * @param persistencia Ponte para uma implementação concreta de @ref InterfacePersistenciaQuarto.
         */
        virtual void setControladoraPersistencia(InterfacePersistenciaQuarto *persistencia) = 0;

        /**
         * @brief Cria um novo quarto após aplicar regras de negócio e validações.
         *
         * Este método deve verificar consistência do objeto @ref Quarto e apenas então
         * repassar a solicitação à camada de persistência.
         *
         * @param quarto Objeto contendo os dados do quarto.
         * @return `true` se a criação for bem-sucedida, `false` caso contrário.
         */
        virtual bool criar(const Quarto &quarto) = 0;

        /**
         * @brief Atualiza os dados de um quarto existente.
         *
         * Antes de atualizar, a camada de serviço pode realizar validações importantes,
         * como a verificação se o quarto realmente existe ou se os novos valores são válidos.
         *
         * @param id Identificador único do quarto.
         * @param quarto Dados atualizados.
         * @return `true` se a operação for concluída com sucesso, `false` caso o ID seja inválido.
         */
        virtual bool editar(const int &id, const Quarto &quarto) = 0;

        /**
         * @brief Remove um quarto do sistema.
         *
         * Este método deve garantir que a operação seja válida e repassar a solicitação
         * à camada de persistência.
         *
         * @param id Identificador do quarto a ser removido.
         * @return `true` se a remoção ocorrer, `false` caso o ID seja inválido ou inexistente.
         */
        virtual bool remover(const int &id) = 0;

        /**
         * @brief Lista todos os quartos existentes.
         *
         * Retorna um vetor de @ref QuartoDTO contendo todos os dados necessários
         * para apresentação ao usuário ou para outras operações.
         *
         * @return Vetor completo de @ref QuartoDTO.
         */
        virtual vector<QuartoDTO> listarTodos() = 0;

        /**
         * @brief Pesquisa um quarto pelo ID.
         *
         * @param id Identificador do quarto desejado.
         * @return Um `optional<QuartoDTO>` contendo os dados encontrados,
         *         ou `nullopt` se não houver registro correspondente.
         */
        virtual optional<QuartoDTO> pesquisar(const int &id) = 0;

        /**
         * @brief Retorna a quantidade de quartos pertencentes a um hotel.
         *
         * Muito útil para validações de negócio, como impedir criação de novos quartos
         * acima do limite permitido.
         *
         * @param hotel_id Identificador do hotel.
         * @return Número total de quartos associados ao hotel.
         */
        virtual int getQuantidadeDeQuartosDoHotel(int hotel_id) = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Permite que a interface seja manipulada por ponteiros
         * e destruída corretamente ao utilizar implementações concretas.
         */
        virtual ~InterfaceServicoQuarto() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISQUARTO_HPP