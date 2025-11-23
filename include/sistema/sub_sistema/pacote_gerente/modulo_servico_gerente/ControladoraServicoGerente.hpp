//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraServicoGerente.hpp
 * @brief Declaração da classe ControladoraServicoGerente, responsável pela
 *        lógica de negócios do módulo de Gerentes.
 *
 * @details
 * Esta classe implementa a interface InterfaceServicoGerente e atua como a
 * camada intermediária entre:
 *    - A camada de apresentação (UI)
 *    - A camada de persistência (DAO/Repository)
 *
 * Suas responsabilidades incluem:
 *  - Aplicar regras de negócio antes da persistência
 *  - Coordenar operações CRUD
 *  - Validar dados de entrada
 *  - Interagir com InterfacePersistenciaGerente
 *
 * Segue princípios SOLID:
 *  - **S — Single Responsibility:** Apenas gerencia regras e fluxo entre camadas.
 *  - **D — Dependency Inversion:** Depende de InterfacePersistenciaGerente.
 */
#ifndef Hotelaria_UnB_TP1_CSP_HPP
#define Hotelaria_UnB_TP1_CSP_HPP

#include "InterfaceServicoGerente.hpp"
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
     * @class ControladoraServicoGerente
     * @brief Implementação da camada de serviço para operações de Gerente.
     *
     * @details
     * Esta classe recebe os pedidos da camada de apresentação,
     * valida os dados recebidos, e chama a camada de persistência
     * para realizar operações de armazenamento.
     *
     * Atua como um orquestrador entre UI ↔ Serviço ↔ Persistência.
     */
    class ControladoraServicoGerente : public InterfaceServicoGerente {
    private:
        /**
         * @brief Ponteiro para a camada de persistência responsável por salvar,
         * atualizar, excluir e consultar Gerentes.
         */
        InterfacePersistenciaGerente *persistencia = nullptr;

        /**
         * @brief Indica se a controladora está ativa para execução interna.
         * Usado em menus ou loops internos.
         */
        bool executando = false;

    public:
        /**
         * @brief Define a controladora de persistência utilizada pelo serviço.
         *
         * @param persistencia Ponteiro para a interface de persistência.
         *
         * @details
         * Esta injeção de dependência permite substituir facilmente a implementação
         * do banco por mock, fake, SQLite, etc.
         */
        void setControladoraPersistencia(InterfacePersistenciaGerente *persistencia) override;

        /**
         * @brief Cria um novo gerente após realizar validações de regra de negócio.
         *
         * @param gerente Dados completos do Gerente a ser cadastrado.
         * @return true Caso o cadastro tenha sido realizado com sucesso.
         * @return false Caso o email já exista ou haja falha na persistência.
         *
         * @details
         * Regras aplicadas:
         *  - Verifica existência prévia de email.
         *  - Encaminha o objeto à camada de persistência.
         */
        bool criar(const Gerente &gerente) override;

        /**
         * @brief Edita um gerente já cadastrado, localizando-o pelo email.
         *
         * @param email Email utilizado como chave única.
         * @param gerenteAtualizado Novo conjunto de atributos do gerente.
         * @return true Se a atualização foi concluída com sucesso.
         * @return false Caso o email não exista ou haja erro no banco.
         */
        bool editar(const Email &email, const Gerente &gerenteAtualizado) override;

        /**
         * @brief Remove um gerente da base de dados.
         *
         * @param id Identificador único do Gerente.
         * @return true Se a remoção foi feita com sucesso.
         * @return false Caso o ID não exista ou ocorra erro.
         */
        bool remover(const int &id) override;

        /**
         * @brief Retorna todos os gerentes cadastrados no banco.
         *
         * @return Vetor de GerenteDTO contendo todos os registros persistidos.
         *
         * @details
         * Ideal para exibir tabelas de listagem no sistema.
         */
        vector<GerenteDTO> listarTodos() override;

        /**
         * @brief Pesquisa um gerente pelo seu ID único.
         *
         * @param id Identificador do gerente.
         * @return optional<GerenteDTO> contendo o registro se encontrado,
         *         ou std::nullopt caso contrário.
         */
        optional<GerenteDTO> pesquisar(const int &id) override;

        /**
         * @brief Pesquisa um gerente pelo seu endereço de email.
         *
         * @param email Email a ser consultado.
         * @return optional<GerenteDTO> contendo os dados encontrados,
         *         ou std::nullopt se nenhum gerente possuir esse email.
         */
        optional<GerenteDTO> pesquisarPorEmail(const string email) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSP_HPP