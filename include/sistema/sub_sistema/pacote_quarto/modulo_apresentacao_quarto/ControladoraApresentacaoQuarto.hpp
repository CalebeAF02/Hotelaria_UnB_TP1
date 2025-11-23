//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraApresentacaoQuarto.hpp
 * @brief Declaração da classe ControladoraApresentacaoQuarto, responsável pela camada de apresentação
 *        da funcionalidade de Quartos no sistema de Hotelaria.
 *
 * Esta classe implementa a interface InterfaceApresentacaoQuarto e atua como a controladora da
 * camada de apresentação (UI/CLI). Ela coordena as interações do usuário com os serviços de
 * manipulação de Quartos (criação, listagem, atualização e remoção).
 *
 * ## Responsabilidades
 * - Exibir menus relacionados aos Quartos.
 * - Interagir com o usuário via terminal.
 * - Validar entradas básicas.
 * - Acionar a camada de serviço para operações CRUD.
 *
 * ## Colabora com
 * - InterfaceServicoQuarto (Regra de Negócio)
 * - VisualizadorDeMenu (Exibição de menus na tela)
 * - VisualizadorDeTabela (Listagem organizada em tabela)
 * - Utils (Funções auxiliares)
 * - IO (Entrada e saída robusta)
 */
#ifndef Hotelaria_UnB_TP1_CAQUARTO_HPP
#define Hotelaria_UnB_TP1_CAQUARTO_HPP

#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceServicoQuarto.hpp"

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
 * @class ControladoraApresentacaoQuarto
 * @brief Camada de apresentação para gerenciamento de Quartos.
 *
 * Esta classe é responsável pela interação com o usuário e por conduzir o fluxo de operações
 * referentes aos Quartos. Ela recebe comandos do usuário, coleta dados, exibe informações e
 * invoca a camada de serviço.
 *
 * ### Fluxos operados:
 * - Criar novo Quarto
 * - Listar Quartos de um Hotel
 * - Atualizar dados de um Quarto existente
 * - Remover um Quarto
 *
 * A classe não contém lógica de negócios, delegando essa responsabilidade à InterfaceServicoQuarto.
 */
    class ControladoraApresentacaoQuarto : public InterfaceApresentacaoQuarto {
    private:
        /**
     * @brief Ponteiro para a controladora da camada de serviço responsável pelos Quartos.
     *
     * A ControladoraApresentacaoQuarto delega todas as regras de negócio à InterfaceServicoQuarto.
     */
        InterfaceServicoQuarto *servico;

        /**
     * @brief Indica se o menu está em execução.
     */
        bool executando = false;

    public:
        /**
     * @brief Define a controladora responsável pelos serviços de Quarto.
     *
     * @param servico Ponteiro para implementação concreta de InterfaceServicoQuarto.
     */
        void setControladoraServicoQuarto(InterfaceServicoQuarto *servico) override;

        /**
     * @brief Exibe o menu de operações CRUD relacionadas aos Quartos.
     *
     * Este método controla o loop principal de interação com o usuário.
     */
        void exibirMenuCRUD() override;

        /**
     * @brief Cria um novo Quarto associado a um gerente e hotel.
     *
     * @param gerente_id Identificador do gerente responsável.
     * @param hotel_id Identificador do hotel ao qual o quarto pertence.
     * @return true se a criação foi bem-sucedida; false caso contrário.
     */
        bool criar(int gerente_id, int hotel_id) override;

        /**
     * @brief Lista todos os quartos cadastrados no sistema.
     *
     * A listagem é apresentada em formato de tabela formatada.
     */
        void listar() override;

        /**
     * @brief Atualiza os dados de um Quarto existente.
     *
     * Solicita o ID do quarto, coleta novos dados e envia à camada de serviço.
     */
        void atualizar() override;

        /**
     * @brief Remove um Quarto existente do sistema.
     *
     * Solicita o ID do quarto e aciona a camada de serviço para exclusão.
     */
        void remover() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAQUARTO_HPP