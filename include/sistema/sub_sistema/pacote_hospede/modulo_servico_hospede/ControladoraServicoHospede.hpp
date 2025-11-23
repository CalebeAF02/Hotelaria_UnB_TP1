//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraServicoHospede.cpp
 * @brief Implementação da camada de serviço responsável pelas regras de negócio do módulo de Hóspedes.
 *
 * A ControladoraServicoHospede atua como intermediária entre a camada de apresentação
 * (UI / menus) e a camada de persistência (banco de dados).
 *
 * Sua função é:
 *   - Validar e encaminhar solicitações provenientes da camada de apresentação.
 *   - Delegar operações CRUD para a persistência.
 *   - Garantir que a instância de persistência esteja disponível.
 *
 * Arquitetura do sistema:
 *    InterfaceApresentacaoHospede → ControladoraServicoHospede → Persistência → Banco SQLite
 *
 * A classe não interage com o usuário, não imprime nada e não contém SQL.
 * Tudo relacionado a banco é responsabilidade da ControladoraPersistenciaHospede.
 */

#ifndef Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP

#include "InterfaceServicoHospede.hpp"
#include "InterfacePersistenciaHospede.hpp"
#include "ControladoraPersistenciaHospede.hpp"

#include "FabricaGerenciavel.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    /**
 * @brief Controladora de serviços relacionados a hóspedes.
 *
 * Esta classe é responsável por gerenciar operações de serviço para hóspedes
 * em um sistema de hotelaria, implementando a interface InterfaceServicoHospede.
 * Inclui funcionalidades de criação, edição, remoção, listagem e pesquisa de hóspedes.
 *
 * @note Utiliza um ponteiro para InterfacePersistenciaHospede para delegar operações
 * de persistência, mantendo a separação entre lógica de negócio e armazenamento de dados.
 */
    class ControladoraServicoHospede : public InterfaceServicoHospede {
    private:
        /**
     * @brief Ponteiro para a camada de persistência de hóspedes.
     *
     * Usado para delegar operações de armazenamento e recuperação de dados.
     */
        InterfacePersistenciaHospede *persistencia = nullptr;

    public:
        /**
     * @brief Define a controladora de persistência de hóspedes.
     *
     * Permite injetar a implementação concreta de persistência para o serviço.
     *
     * @param persistencia Ponteiro para a instância de InterfacePersistenciaHospede.
     */
        void setControladoraPersistencia(InterfacePersistenciaHospede *persistencia) override;

        /**
     * @brief Cria um novo hóspede no sistema.
     *
     * @param hospede Referência para o objeto Hospede a ser criado.
     * @return true se a criação foi bem-sucedida, false caso contrário.
     */
        bool criar(const Hospede &hospede) override;

        /**
     * @brief Edita os dados de um hóspede existente.
     *
     * Busca o hóspede pelo email fornecido e atualiza suas informações.
     *
     * @param email Email do hóspede a ser atualizado.
     * @param hospedeAtualizado Objeto Hospede com os novos dados.
     * @return true se a atualização foi bem-sucedida, false caso contrário.
     */
        bool editar(const Email &email, const Hospede &hospedeAtualizado) override;

        /**
     * @brief Remove um hóspede do sistema.
     *
     * @param id Identificador único do hóspede a ser removido.
     * @return true se a remoção foi bem-sucedida, false caso contrário.
     */
        bool remover(const int &id) override;

        /**
     * @brief Lista todos os hóspedes cadastrados.
     *
     * @return Um vetor contendo DTOs (Data Transfer Objects) de todos os hóspedes.
     */
        vector<HospedeDTO> listarTodos() override;

        /**
     * @brief Pesquisa um hóspede pelo seu ID.
     *
     * @param id Identificador único do hóspede.
     * @return Um optional contendo o DTO do hóspede, ou vazio se não encontrado.
     */
        optional<HospedeDTO> pesquisar(const int &id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP