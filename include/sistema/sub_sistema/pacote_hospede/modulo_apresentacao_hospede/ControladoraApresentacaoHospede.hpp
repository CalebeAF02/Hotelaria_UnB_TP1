//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraApresentacaoHospede.hpp
 * @brief Declara a classe responsável pela camada de apresentação dos Hóspedes.
 *
 * A classe ControladoraApresentacaoHospede implementa a interface de apresentação
 * destinada ao módulo de Hóspedes. Ela funciona como a camada diretamente conectada
 * ao usuário, exibindo menus, coletando dados e enviando solicitações para a
 * camada de serviço.
 *
 * Esta classe:
 *   - Não contém regras de negócio
 *   - Não acessa banco de dados diretamente
 *   - Apenas interage com o usuário e chama o serviço correspondente
 *
 * Arquitetura:
 *   Interface (UI) → Serviço (Regras de Negócio) → Persistência (Banco de Dados)
 */
#ifndef Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP

#include "InterfaceApresentacaoHospede.hpp"
#include "InterfaceServicoHospede.hpp"

#include "FabricaGerenciavel.hpp"
#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    /**
     * @class ControladoraApresentacaoHospede
     * @brief Implementação da camada de apresentação para operações relacionadas a Hóspedes.
     *
     * Responsabilidades principais:
     *  - Exibir o menu CRUD ao usuário
     *  - Ler entradas e validar formatos básicos
     *  - Encaminhar solicitações para a camada de serviço
     *  - Exibir resultados e mensagens de retorno
     *
     * Esta camada nunca deve:
     *  - Acessar banco de dados diretamente
     *  - Implementar regras de negócio
     *  - Realizar verificações de lógica de domínio
     */
    class ControladoraApresentacaoHospede : public InterfaceApresentacaoHospede {
    private:
        /**
         * @brief Ponteiro para a camada de serviço responsável pela lógica de negócio do Hóspede.
         *
         * A apresentação deve sempre delegar ao serviço qualquer operação.
         */
        InterfaceServicoHospede *servico = nullptr;

        /**
         * @brief Controla o loop de execução do menu.
         */
        bool executando = true;

    public:
        /**
         * @brief Define a controladora de serviço utilizada por esta camada.
         *
         * @param servico Ponteiro para a implementação de InterfaceServicoHospede.
         */
        void setControladoraServicoHospede(InterfaceServicoHospede *servico) override;

        /**
         * @brief Exibe o menu CRUD de hóspedes e coordena as opções escolhidas.
         *
         * Este método é o ponto central da interação entre o usuário e o módulo.
         */
        void exibirMenuCRUD() override;

        /**
         * @brief Solicita dados ao usuário e envia uma requisição de criação de hóspede.
         *
         * @return `true` se o hóspede for criado com sucesso.
         */
        bool criar() override;

        /**
         * @brief Obtém todos os hóspedes cadastrados e os exibe em formato tabular.
         */
        void listar() override;

        /**
         * @brief Solicita a seleção de um hóspede e envia dados atualizados ao serviço.
         */
        void atualizar() override;

        /**
         * @brief Solicita a identificação de um hóspede e envia requisição de exclusão.
         */
        void remover() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAHOSPEDAGEM_HPP