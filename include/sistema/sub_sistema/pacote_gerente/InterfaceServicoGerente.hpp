//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceServicoGerente.hpp
 * @brief Declara a interface da camada de serviço responsável pela lógica de negócios relacionada ao Gerente.
 *
 * Esta interface define o contrato para as operações de alto nível envolvendo
 * o gerenciamento de objetos do tipo `Gerente`, servindo como intermediária entre
 * a camada de apresentação e a camada de persistência.
 *
 * Funções incluem criação, edição, remoção e consultas — sempre aplicando
 * regras de negócio antes de repassar para a persistência.
 *
 * A camada de serviço evita que a camada de apresentação tenha contato direto
 * com o banco de dados, garantindo:
 *  - encapsulamento da lógica de domínio
 *  - aplicação de validações
 *  - desacoplamento entre interface e armazenamento
 */
#ifndef Hotelaria_UnB_TP1_ISP_HPP
#define Hotelaria_UnB_TP1_ISP_HPP

#include "InterfacePersistenciaGerente.hpp"
#include "Gerente.hpp"
#include "Email.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    /**
     * @class InterfaceServicoGerente
     * @brief Interface responsável pela camada de regras de negócio do módulo de Gerentes.
     *
     * Qualquer implementação desta interface deve realizar:
     *  - validações de domínio
     *  - verificações de integridade
     *  - chamadas apropriadas à persistência
     *
     * Exemplos de validações típicas:
     *  - impedir cadastros com email duplicado
     *  - validar campos obrigatórios
     *  - aplicar regras de atualização
     *
     * Essa camada é essencial para manter o sistema coeso,
     * garantindo que ações proibidas ou inconsistentes não alcancem o banco de dados.
     */
    class InterfaceServicoGerente {
    public:
        /**
         * @brief Configura a controladora de persistência utilizada pelo serviço.
         *
         * @param persistencia Ponteiro para a controladora responsável pela persistência.
         */
        virtual void setControladoraPersistencia(InterfacePersistenciaGerente *persistencia) = 0;

        /**
         * @brief Cria um novo gerente no sistema, aplicando regras de negócio.
         *
         * @param gerente Objeto contendo os dados do gerente a ser criado.
         * @return `true` se o gerente for criado com sucesso.
         *
         * Regras comuns implementadas nesta camada:
         *  - verificar se o email já existe
         *  - validar campos obrigatórios
         */
        virtual bool criar(const Gerente &gerente) = 0;

        /**
         * @brief Edita os dados de um gerente existente.
         *
         * @param email Email que identifica o gerente que será alterado.
         * @param gerenteAtualizado Objeto contendo os novos valores.
         * @return `true` se a atualização ocorrer com sucesso.
         */
        virtual bool editar(const Email &email, const Gerente &gerenteAtualizado) = 0;

        /**
         * @brief Remove um gerente do sistema.
         *
         * @param id Identificador numérico do gerente.
         * @return `true` se a remoção for bem-sucedida.
         */
        virtual bool remover(const int &id) = 0;

        /**
         * @brief Lista todos os gerentes cadastrados no sistema.
         *
         * @return Vetor contendo objetos GerenteDTO.
         *
         * Essa operação deve retornar apenas dados relevantes de exibição,
         * protegendo informações sensíveis.
         */
        virtual vector<GerenteDTO> listarTodos() = 0;

        /**
         * @brief Pesquisa um gerente pelo ID.
         *
         * @param id Identificador único.
         * @return Um optional contendo o GerenteDTO caso o gerente seja encontrado.
         */
        virtual optional<GerenteDTO> pesquisar(const int &id) = 0;

        /**
         * @brief Pesquisa um gerente pelo email.
         *
         * @param email Endereço de email a ser pesquisado.
         * @return Um optional contendo o GerenteDTO caso seja localizado.
         */
        virtual optional<GerenteDTO> pesquisarPorEmail(const string email) = 0;

        /// Destrutor virtual padrão.
        virtual ~InterfaceServicoGerente() = default;
    };
}


#endif //Hotelaria_UnB_TP1_ISP_HPP