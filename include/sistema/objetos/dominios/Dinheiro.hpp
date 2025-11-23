//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_DINHEIRO_H
#define GERENCIADOR_HOTEL_UNB_DINHEIRO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Dinheiro
     * @brief Classe responsável por armazenar, validar e gerenciar valores monetários inteiros.
     *
     * A classe Dinheiro representa valores monetários em forma de número inteiro,
     * evitando possíveis inconsistências causadas pelo uso de ponto flutuante.
     * Inclui mecanismos de validação para garantir que o valor informado é válido.
     */
    class Dinheiro {
    private:
        /**
         * @brief Valor monetário armazenado (em unidades inteiras).
         *
         * Por exemplo, um valor de **1500** pode representar **R$ 1500,00** dependendo do contexto do sistema.
         */
        int dinheiro;

        /**
         * @brief Método privado de validação do valor monetário.
         *
         * Garante que o valor fornecido é considerado válido pelas regras do domínio.
         *
         * @param dinheiroInt Valor inteiro a ser validado.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        void validar(int valor);

    public:
        /**
         * @brief Construtor padrão da classe Dinheiro.
         *
         * Inicializa o objeto sem definir valor específico.
         */
        Dinheiro() = default;

        /**
         * @brief Construtor que inicializa o valor monetário.
         *
         * Chama internamente o método setValor(), que aplica a validação.
         *
         * @param dinheiroInt Valor monetário inicial.
         */
        explicit Dinheiro(const int &valor);

        /**
         * @brief Define o valor monetário.
         *
         * Antes de atribuir, o valor passa pelo método validar().
         *
         * @param dinheiroInt Novo valor a ser atribuído.
         */
        void setValor(int valor);

        /**
         * @brief Retorna o valor monetário armazenado.
         *
         * @return Valor inteiro do dinheiro.
         */
        int getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_DINHEIRO_H