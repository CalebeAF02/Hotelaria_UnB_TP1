//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NOME_H
#define GERENCIADOR_HOTEL_UNB_NOME_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Nome
     * @brief Classe responsável por armazenar e validar nomes.
     *
     * A classe Nome garante que o valor fornecido esteja em um formato válido,
     * evitando strings vazias, caracteres inválidos ou tamanhos inadequados.
     * É utilizada em diversas entidades do sistema, como Pessoa, Gerente e Hospede.
     */
    class Nome {
    private:
        /**
         * @brief Armazena o nome validado.
         */
        string nomeStr;

        /**
         * @brief Valida o nome recebido.
         *
         * A validação pode incluir regras como:
         * - Verificar se o nome não está vazio
         * - Verificar se o tamanho é suficiente (ex: mínimo 3 caracteres)
         * - Garantir que não contenha números ou caracteres especiais inadequados
         *
         * @param valor Nome a ser validado.
         * @throw invalid_argument Caso o nome seja inválido.
         */
        void validar(const string &valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Nome sem valor inicial.
         */
        Nome() = default;

        /**
         * @brief Construtor que define um nome inicial.
         *
         * @param valor Nome a ser atribuído.
         * @throw invalid_argument Caso o nome seja inválido.
         */
        explicit Nome(const string &valor);

        /**
         * @brief Define um novo valor para o nome.
         *
         * Antes de atribuir, o valor é validado pelo método validar().
         *
         * @param valor Novo nome.
         * @throw invalid_argument Caso o nome seja inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o nome armazenado.
         *
         * @return Nome em formato string.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_NOME_H