//
// Created by caleb on 15/11/2025.
//
/**
 * @file ControladoraApresentacaoAcessoHospede.hpp
 * @brief Declaração da classe ControladoraApresentacaoAcessoHospede.
 *
 * Esta classe representa a camada de apresentação responsável por controlar
 * o fluxo de interação do hóspede dentro do sistema de hotelaria.
 * Ela trabalha diretamente com menus, tabelas e utilitários da interface,
 * além de coordenar ações relacionadas a solicitações de hospedagem.
 *
 * A classe implementa a interface InterfaceApresentacaoAcessoHospede, o que
 * garante que os métodos necessários à navegação e às funcionalidades do hóspede
 * estejam sempre disponíveis para a camada superior.
 */
#ifndef Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP
#define Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP


#include "Sistema.hpp"

#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"
#include "Data.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

#include "InterfaceApresentacaoAcessoHospede.hpp"
#include "InterfaceApresentacaoHospede.hpp"

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    /**
     * @class ControladoraApresentacaoAcessoHospede
     * @brief Classe responsável por gerenciar as interações do hóspede na camada de apresentação.
     *
     * Esta controladora centraliza o fluxo de navegação voltado ao hóspede, permitindo:
     * - Exibir menus específicos para hóspedes;
     * - Encaminhar ações como solicitar hospedagem;
     * - Consultar o status de solicitações já feitas;
     * - Acessar funcionalidades adicionais da interface de hóspede.
     *
     * A classe também faz uso da interface InterfaceApresentacaoHospede,
     * que contém rotinas complementares, evitando que esta controladora
     * assuma responsabilidades além do escopo da camada de apresentação.
     */
    class ControladoraApresentacaoAcessoHospede : public InterfaceApresentacaoAcessoHospede {
    private:
        /**
         * @brief Ponte para a interface detalhada de apresentação do hóspede.
         *
         * Esta ponte permite que a controladora delegue ações mais específicas,
         * tais como visualizar solicitações, listar reservas e outras operações.
         *
         * @note O ciclo de vida do objeto apontado não é gerenciado por esta classe.
         */
        InterfaceApresentacaoHospede *apresentacao_hospede;

    public:
        /**
         * @brief Exibe o menu principal do hóspede.
         *
         * Este menu fornece acesso a opções como solicitar hospedagem,
         * verificar status e consultar funcionalidades adicionais.
         *
         * @override Implementação da interface InterfaceApresentacaoAcessoHospede.
         */
        void exibirMenu() override;

        /**
         * @brief Exibe ao hóspede as opções relacionadas à hospedagem.
         *
         * Este método apresenta opções como:
         * - Solicitar hospedagem
         * - Consultar solicitações existentes
         * - Retornar ao menu anterior
         *
         * @override Método definido na interface InterfaceApresentacaoAcessoHospede.
         */
        void opcoesDeHospedagem() override;

        /**
         * @brief Inicia o processo de solicitação de hospedagem pelo hóspede.
         *
         * O método conduz o usuário pelas etapas necessárias para registrar
         * uma nova solicitação no sistema, realizando seleção de hotel,
         * datas, quartos e demais informações.
         *
         * @warning Nenhuma verificação de conflito é feita aqui; esta etapa
         *          deve ser realizada pela camada de persistência.
         *
         * @override Método herdado da interface InterfaceApresentacaoAcessoHospede.
         */
        void solicitandoHospedagem() override;

        /**
         * @brief Exibe o status atual das solicitações de hospedagem do hóspede.
         *
         * Este método apresenta ao usuário:
         * - Solicitações pendentes;
         * - Solicitações aprovadas;
         * - Solicitações recusadas, com motivo detalhado.
         *
         * @note Esse método é apenas de consulta e não altera dados internos.
         */
        void statusDaSolicitandoHospedagem() const;
    };
}

#endif //Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP