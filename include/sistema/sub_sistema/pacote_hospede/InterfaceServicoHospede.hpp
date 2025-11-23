//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceServicoHospede.hpp
 * @brief Define a interface responsável pela camada de serviço aplicada à entidade Hospede.
 *
 * A camada de serviço funciona como intermediária entre:
 *  - a camada de apresentação (InterfaceApresentacaoHospede)
 *  - a camada de persistência (InterfacePersistenciaHospede)
 *
 * Sua função principal é:
 *  - validar dados
 *  - aplicar regras de negócio
 *  - coordenar operações de persistência
 *  - garantir integridade das informações antes de serem enviadas ao banco
 *
 * Segue o padrão arquitetural em camadas (Presentation → Service → Persistence).
 */
#ifndef Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP

#include "InterfacePersistenciaHospede.hpp"
#include "HospedeDTO.hpp"
#include "Hospede.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    /**
     * @class InterfaceServicoHospede
     * @brief Interface abstrata que define as operações de serviço aplicadas ao gerenciamento de hóspedes.
     *
     * Esta interface estabelece o contrato que qualquer classe de serviço relacionada aos hóspedes deve cumprir.
     * A implementação concreta (ControladoraServicoHospede) aplica regras de negócio e garante que a persistência
     * seja acionada de forma consistente e segura.
     *
     * Responsabilidades típicas da camada de serviço incluem:
     * - verificação de duplicidade de e-mail
     * - validação de dados do domínio
     * - envio de erros amigáveis à camada de apresentação
     * - coordenação com a camada de persistência
     */
    class InterfaceServicoHospede {
    public:
        /**
         * @brief Define uma implementação de persistência que será utilizada pelo serviço.
         *
         * Permite inversão de dependência, possibilitando testar a camada de serviço com
         * implementações de persistência reais ou mockadas.
         *
         * @param persistencia Ponteiro para uma classe concreta que implementa InterfacePersistenciaHospede.
         */
        virtual void setControladoraPersistencia(InterfacePersistenciaHospede *persistencia) = 0;

        /**
         * @brief Cria um novo hóspede aplicando regras de negócio e enviando-o à persistência.
         *
         * Exemplos de validações que podem ser realizadas pela camada de serviço:
         * - verificar se o e-mail já está cadastrado
         * - validar formato do e-mail
         * - validar CPF
         * - validar nome e telefone
         *
         * @param hospede Objeto Hospede contendo todos os dados a serem validados e registrados.
         * @return true se o hóspede for criado com sucesso,
         *         false caso ocorra erro de validação ou na persistência.
         */
        virtual bool criar(const Hospede &hospede) = 0;

        /**
         * @brief Edita os dados de um hóspede já existente.
         *
         * A camada de serviço deve garantir:
         * - busca prévia pelo hóspede original
         * - validação dos novos dados
         * - impedir conflitos de e-mail com outros cadastros
         *
         * @param email E-mail atual que identifica o hóspede que será modificado.
         * @param hospedeAtualizado Objeto com os novos dados do hóspede.
         * @return true se a alteração for bem-sucedida,
         *         false se o hóspede não existir ou se ocorrer falha.
         */
        virtual bool editar(const Email &email, const Hospede &hospedeAtualizado) = 0;

        /**
         * @brief Remove um hóspede com base em seu identificador único.
         *
         * Regras de negócio aplicáveis incluem:
         * - verificar se o hóspede possui reservas ativas
         * - impedir exclusão caso existam dependências vinculadas
         *
         * @param id Identificador numérico do hóspede.
         * @return true se a remoção ocorrer sem falhas,
         *         false caso não exista o hóspede ou ocorra erro.
         */
        virtual bool remover(const int &id) = 0;

        /**
         * @brief Retorna uma lista completa de hóspedes cadastrados no sistema.
         *
         * @return Vetor contendo objetos HospedeDTO, com dados estruturados para exibição.
         */
        virtual vector<HospedeDTO> listarTodos() = 0;

        /**
         * @brief Pesquisa um hóspede pelo ID.
         *
         * @param id Identificador único do hóspede.
         * @return std::optional contendo HospedeDTO se encontrado,
         *         std::nullopt caso não exista.
         */
        virtual optional<HospedeDTO> pesquisar(const int &id) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~InterfaceServicoHospede() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP