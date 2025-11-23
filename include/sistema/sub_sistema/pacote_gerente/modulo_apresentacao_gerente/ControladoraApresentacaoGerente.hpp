//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraApresentacaoGerente.hpp
 * @brief Declaração da classe ControladoraApresentacaoGerente, responsável pela
 *        camada de apresentação do Gerente no sistema de Hotelaria.
 *
 * @details
 * A classe ControladoraApresentacaoGerente implementa a interface
 * InterfaceApresentacaoGerente e atua como o controlador responsável por mediar
 * a interação entre o usuário (Gerente) e a lógica de negócios fornecida pela
 * InterfaceServicoGerente.
 *
 * Esta classe segue rigorosamente o padrão arquitetural MVC, separando
 * responsabilidades e promovendo baixo acoplamento via injeção de dependências.
 */
#ifndef Hotelaria_UnB_TP1_CAP_HPP
#define Hotelaria_UnB_TP1_CAP_HPP

#include "InterfaceApresentacaoGerente.hpp"
#include "InterfaceServicoGerente.hpp"
#include "Sistema.hpp"

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
     * @class ControladoraApresentacaoGerente
     * @brief Controla a apresentação e fluxo de interação do Gerente no sistema.
     *
     * @details
     * Esta classe é responsável por:
     *  - Exibir menus de interação do Gerente (CRUD + funcionalidades administrativas).
     *  - Mediar requisições e respostas entre a interface textual e o serviço.
     *  - Garantir fluxo seguro (autenticação mínima, estados, tratamento de erros).
     *  - Executar operações CRUD sobre entidades gerenciáveis criando menus, tabelas
     *    e capturando entradas do usuário.
     *
     * A classe respeita princípios SOLID, especialmente:
     *  - **S (Single Responsibility):** Responsável apenas pela apresentação para o Gerente.
     *  - **D (Dependency Inversion):** Depende de serviços por meio de interfaces.
     *
     * Além disso, utiliza:
     *  - Injeção de dependência (setControladoraServicoGerente)
     *  - Encapsulamento de fluxo (estado executando/autenticado)
     *  - Polimorfismo por interface
     */
    class ControladoraApresentacaoGerente : public InterfaceApresentacaoGerente {
    private:
        /**
         * @brief Ponte para o serviço responsável pela lógica de negócios do Gerente.
         *
         * @details
         * Através desta interface, a controladora solicita operações
         * de criação, consulta, atualização, remoção e avaliação.
         *
         * Implementações concretas podem incluir:
         *  - ServicoGerente
         *  - MockServicoGerente (para testes unitários)
         */
        InterfaceServicoGerente *servico = nullptr;

        /**
         * @brief Indica se o menu principal deve continuar sendo exibido.
         *
         * @note Usado para loops de execução.
         */
        bool executando = true;

        /**
         * @brief Define se o gerente está autenticado.
         *
         * @note
         * Algumas operações são restritas e só podem ser executadas mediante autenticação.
         */
        bool estaAutenticado = false;

    public:
        /**
         * @brief Vincula a controladora ao serviço que implementa a lógica do Gerente.
         *
         * @param servico Ponte para InterfaceServicoGerente.
         *
         * @throws std::invalid_argument Caso o serviço passado seja nulo.
         *
         * @note
         * Este método implementa a Injeção de Dependência, permitindo
         * troca de implementações sem alterar a controladora.
         */
        void setControladoraServicoGerente(InterfaceServicoGerente *servico) override;

        /**
         * @brief Exibe o menu CRUD principal e controla o fluxo das operações do Gerente.
         *
         * @details
         * Apresenta opções de:
         *  - Criar
         *  - Listar
         *  - Atualizar
         *  - Remover
         *  - Avaliar solicitações
         *
         * O método permanece em loop até que `executando = false`.
         */
        void exibirMenuCRUD() override;

        /**
         * @brief Executa o fluxo de criação de um novo item gerenciável.
         *
         * @return true Caso a criação seja concluída com sucesso.
         * @return false Em caso de falhas de entrada ou erros no serviço.
         *
         * @details
         * Utiliza Menu e IO para solicitar dados ao usuário e repassa
         * o resultado para o serviço.
         */
        bool criar() override;

        /**
         * @brief Lista todos os itens gerenciáveis, exibindo-os em uma tabela organizada.
         *
         * @details
         * Utiliza o módulo Tabela.hpp para criar uma visualização tabular limpa e alinhada.
         */
        void listar() override;

        /**
         * @brief Atualiza um item existente após solicitar identificação e novos dados ao usuário.
         *
         * @details
         * O fluxo padrão inclui:
         *  - Exibir lista
         *  - Solicitar ID
         *  - Coletar novos valores
         *  - Enviar para o serviço
         */
        void atualizar() override;

        /**
         * @brief Remove um item existente mediante confirmação explícita do usuário.
         *
         * @details
         * Segue o fluxo:
         *  - Listar → escolher ID → confirmar remoção → delegar ao serviço
         */
        void remover() override;

        /**
         * @brief Exibe, analisa e julga solicitações pendentes submetidas ao Gerente.
         *
         * @details
         * Exemplos de solicitações:
         *  - Aprovação de reservas
         *  - Solicitações administrativas internas
         *  - Pedidos de alteração de cadastro
         *
         * Após avaliação, o resultado é registrado pelo serviço.
         */
        void avaliarSolicitacoes() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAP_HPP