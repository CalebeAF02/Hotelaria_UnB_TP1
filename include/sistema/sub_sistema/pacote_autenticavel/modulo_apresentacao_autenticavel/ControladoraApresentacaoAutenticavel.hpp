//
// Created by caleb on 14/11/2025.
//
/**
 * @file ControladoraApresentacaoAutenticavel.hpp
 * @brief Declara a classe responsável pelo fluxo de autenticação na camada de apresentação.
 *
 * Esta classe atua como intermediária entre o usuário (via interface de apresentação)
 * e a camada de serviços, responsável por validar credenciais de acesso.
 * Permite que gerentes ou usuários autenticáveis realizem login e tenham
 * seus dados verificados adequadamente pela lógica de domínio.
 */
#ifndef Hotelaria_UnB_TP1_CAA_HPP
#define Hotelaria_UnB_TP1_CAA_HPP

#include "InterfaceApresentacaoAutenticavel.hpp"
#include "InterfaceServicoAutenticavel.hpp"
#include "Email.hpp"
#include "Senha.hpp"

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
     * @class ControladoraApresentacaoAutenticavel
     * @brief Implementação concreta da interface de apresentação de autenticação.
     *
     * A classe é responsável por:
     * - Exibir menus relacionados ao login;
     * - Receber credenciais do usuário;
     * - Delegar a autenticação ao serviço apropriado;
     * - Armazenar o estado de autenticação;
     * - Manter o email do gerente para autenticação.
     *
     * Integra-se diretamente com a camada de serviços por meio de
     * InterfaceServicoAutenticavel, permitindo inversão de dependência.
     */
    class ControladoraApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
    private:
        /**
         * @brief Serviço de autenticação injetado na controladora.
         *
         * É responsável por validar email e senha e determinar se o usuário está autorizado.
         */
        InterfaceServicoAutenticavel *servico;

        /**
         * @brief Indica se o usuário atual está autenticado.
         *
         * É atualizado pelo método autenticar().
         */
        bool estaAutenticado = false;

        /**
         * @brief Armazena o email informado pelo gerente no processo de login.
         *
         * Útil para reaproveitar a informação sem solicitar novamente.
         */
        string gerente_email;

    public:
        /**
         * @brief Injeta a controladora de serviço responsável pela autenticação.
         *
         * Permite desacoplar a apresentação da lógica de domínio.
         *
         * @param servico Ponteiro para a implementação de InterfaceServicoAutenticavel.
         */
        void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *servico) override;

        /**
         * @brief Define o email do gerente que será autenticado.
         *
         * @param email Email no formato string.
         */
        void setEmailDoGerente(const string &email) override;

        /**
         * @brief Retorna o email armazenado do gerente.
         *
         * @return string contendo o email previamente definido.
         */
        string getEmailDOGerente() override;

        /**
         * @brief Define o estado de autenticação do gerente.
         *
         * @param estaAutenticado true se autenticado, false caso contrário.
         */
        void setEstaAutenticado(bool estaAutenticado) override;

        /**
         * @brief Informa se o gerente está autenticado.
         *
         * @return true se autenticado, false se não.
         */
        bool getEstaAutenticado() override;

        /**
         * @brief Realiza o processo completo de autenticação.
         *
         * O método deve:
         * - Exibir campos de entrada de email e senha;
         * - Validar os dados via serviço de autenticação;
         * - Atualizar o atributo estaAutenticado;
         * - Retornar o resultado da operação.
         *
         * @return true se a autenticação for bem-sucedida, false caso contrário.
         */
        bool autenticar() override;

        /**
         * @brief Retorna o serviço de autenticação.
         *
         * OBS: O nome do método (`getHacke()`) foi preservado exatamente como no código original,
         * embora não reflita claramente sua intenção. Serve como getter para o serviço injetado.
         *
         * @return Ponteiro para InterfaceServicoAutenticavel.
         */
        InterfaceServicoAutenticavel *getHacke() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAA_HPP