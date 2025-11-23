//
// Created by caleb on 14/11/2025.
//
/**
 * @file InterfaceApresentacaoQuarto.hpp
 * @brief Declaração da interface responsável pela camada de apresentação (UI) dos quartos.
 *
 * Esta interface define o contrato que qualquer classe de apresentação (menus, telas,
 * interface textual ou gráfica) deve implementar para permitir a interação do usuário
 * com as funcionalidades relacionadas à entidade @ref Quarto.
 *
 * Ela atua como o ponto de entrada da aplicação para as operações de CRUD,
 * conectando-se com a camada de serviços por meio de @ref InterfaceServicoQuarto.
 */
#ifndef Hotelaria_UnB_TP1_IAQUARTO_HPP
#define Hotelaria_UnB_TP1_IAQUARTO_HPP
#include "InterfaceServicoQuarto.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    /**
     * @class InterfaceApresentacaoQuarto
     * @brief Interface para a camada de apresentação e interação com o usuário sobre quartos.
     *
     * A classe define os métodos essenciais que qualquer implementação da interface gráfica
     * ou textual deve fornecer para manipular operações sobre quartos.
     *
     * Seguindo o padrão *Model–View–Controller (MVC)*, esta interface representa a "View",
     * responsável por:
     * - Exibir menus e opções de interação.
     * - Coletar entradas do usuário.
     * - Acionar ações na camada de serviços.
     * - Apresentar resultados e mensagens.
     *
     * ### Responsabilidades principais
     * - Apresentar o menu CRUD de quartos.
     * - Repassar requisições à camada de serviço.
     * - Receber entradas do usuário para criação, atualização e remoção.
     * - Renderizar listas e mensagens no terminal ou interface gráfica.
     *
     * ### Acoplamento e Inversão de Dependência
     * A dependência com a camada de serviço é injetada externamente via
     * @ref setControladoraServicoQuarto, garantindo baixo acoplamento.
     */
    class InterfaceApresentacaoQuarto {
    public:
        /**
         * @brief Define qual controladora de serviço será utilizada pela interface de apresentação.
         *
         * Implementa injeção de dependência para conectar a "View" (interface com o usuário)
         * com a "Service Layer" (@ref InterfaceServicoQuarto), permitindo testes independentes
         * e substituição de implementações.
         *
         * @param controladora Ponte para uma instância de @ref InterfaceServicoQuarto.
         */
        virtual void setControladoraServicoQuarto(InterfaceServicoQuarto *controladora) = 0;

        /**
         * @brief Exibe o menu principal de operações CRUD de quartos.
         *
         * Este método deve:
         * - Renderizar opções como "Criar", "Listar", "Atualizar" e "Remover".
         * - Ler entradas do usuário.
         * - Redirecionar para os métodos adequados conforme a escolha.
         *
         * Implementações concretas podem usar interface textual (CLI) ou interface gráfica.
         */
        virtual void exibirMenuCRUD() = 0;

        /**
         * @brief Realiza o fluxo completo de criação de um quarto.
         *
         * O método deve:
         * - Solicitar e capturar os dados necessários ao usuário.
         * - Validar as entradas.
         * - Encaminhar para @ref InterfaceServicoQuarto::criar.
         *
         * @param gerente_id ID do gerente responsável pela operação.
         * @param hotel_id ID do hotel ao qual o quarto será vinculado.
         * @return `true` se o quarto for criado com sucesso, `false` caso haja erro.
         */
        virtual bool criar(int gerente_id, int hotel_id) = 0;

        /**
         * @brief Lista todos os quartos cadastrados, exibindo-os ao usuário.
         *
         * A implementação concreta deve renderizar as informações
         * em formato de tabela, lista ou outra representação visual.
         */
        virtual void listar() = 0;

        /**
         * @brief Atualiza os dados de um quarto selecionado.
         *
         * Este método deve:
         * - Perguntar ao usuário qual quarto deseja alterar.
         * - Coletar os novos dados.
         * - Repassar a solicitação à camada de serviços.
         *
         * A exibição de mensagens e validações é responsabilidade da implementação concreta.
         */
        virtual void atualizar() = 0;

        /**
         * @brief Remove um quarto do sistema.
         *
         * O método deve solicitar ao usuário o ID do quarto e então chamar
         * @ref InterfaceServicoQuarto::remover.
         */
        virtual void remover() = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Garante que os objetos derivados sejam deletados corretamente,
         * evitando *memory leaks* e respeitando o polimorfismo.
         */
        virtual ~InterfaceApresentacaoQuarto() = default;
    };
}

#endif //Hotelaria_UnB_TP1_IAQUARTO_HPP