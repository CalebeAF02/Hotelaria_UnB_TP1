//
// Created by caleb on 14/11/2025.
//

/**
 * @file ControladoraApresentacaoAcessoGerente.hpp
 * @brief Declaração da classe ControladoraApresentacaoAcessoGerente.
 *
 * Esta classe funciona como a camada de apresentação responsável pelo fluxo
 * de autenticação e navegação do gerente dentro do sistema de hotelaria.
 * Interage diretamente com menus, tabelas e utilitários visuais.
 *
 * A classe implementa a interface InterfaceApresentacaoAcessoGerente,
 * garantindo que os métodos essenciais de exibição e controle sejam
 * disponibilizados para a camada superior da aplicação.
 */
#ifndef Hotelaria_UnB_TP1_CAI_HPP
#define Hotelaria_UnB_TP1_CAI_HPP


#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

#include "ControladoraPersistenciaGerente.hpp"
#include "InterfaceApresentacaoAcessoGerente.hpp"
#include "InterfaceApresentacaoGerente.hpp"


using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    /**
     * @class ControladoraApresentacaoAcessoGerente
     * @brief Controla o fluxo de acesso do gerente na camada de apresentação.
     *
     * A classe gerencia o processo de autenticação, exibição de menus e
     * encaminhamento das opções escolhidas pelo gerente. Atua como ponte
     * entre a interface visual e as regras de negócio subjacentes.
     *
     * Responsabilidades principais:
     * - Exibir o menu inicial de acesso do gerente.
     * - Validar credenciais e manter estado de autenticação.
     * - Exibir o menu completo do gerente após autenticação.
     * - Encaminhar ações solicitadas pelo usuário.
     *
     * @note Esta classe **não** realiza validação de credenciais diretamente.
     *       Especificamente, a autenticação real é intermediada pela
     *       ControladoraPersistenciaGerente.
     */
    class ControladoraApresentacaoAcessoGerente : public InterfaceApresentacaoAcessoGerente {
    private:
        /**
         * @brief Indica se o gerente está atualmente autenticado.
         *
         * @details
         * Inicialmente definido como false. Torna-se true apenas após
         * autenticação bem-sucedida, permitindo acesso ao menu exclusivo
         * do gerente.
         */
        bool estaAutenticado = false;

    public:
        /**
         * @brief Exibe o menu inicial de acesso ao gerente.
         *
         * Este menu é responsável por iniciar o processo de autenticação,
         * apresentando opções como: "Login", "Ajuda" ou "Sair".
         *
         * @override Implementação da interface InterfaceApresentacaoAcessoGerente.
         */
        void exibirMenu() override;

        /**
         * @brief Exibe o menu principal do gerente após autenticação.
         *
         * Aqui o gerente tem acesso às funcionalidades de gestão,
         * como cadastro de hotéis, gerentes, quartos e outras operações
         * administrativas.
         *
         * @warning Caso o gerente não esteja autenticado, este método
         *          não deve ser acessado. É responsabilidade da camada
         *          superior garantir a ordem correta de chamadas.
         *
         * @override Implementação da interface InterfaceApresentacaoAcessoGerente.
         */
        void exibirMenuGerenciador() override;

        /**
         * @brief Simula o processo de autenticação (modo especial de acesso).
         *
         * O método existe como recurso alternativo, podendo ser usado
         * para acesso rápido, testes ou ferramentas administrativas.
         *
         * @note Este método pode alterar diretamente o estado interno
         *       @ref estaAutenticado para permitir o acesso ao menu
         *       completo do gerente.
         *
         * @override Implementação da interface InterfaceApresentacaoAcessoGerente.
         */
        void autenticarHacker() override;
    };
}


#endif //Hotelaria_UnB_TP1_CAI_HPP