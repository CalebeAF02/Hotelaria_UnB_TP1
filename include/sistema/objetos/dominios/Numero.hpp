//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NUMERO_H
#define GERENCIADOR_HOTEL_UNB_NUMERO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Numero
     * @brief Classe responsável por armazenar e validar números representados como string.
     *
     * A classe Numero é utilizada em diferentes contextos do sistema sempre que um
     * valor numérico simples precisa ser armazenado, validado e tratado como texto,
     * preservando zeros à esquerda ou formatos específicos.
     */
    class Numero {
    private:
        /**
         * @brief Armazena o número validado.
         */
        string numeroStr;

        /**
         * @brief Valida o número fornecido.
         *
         * A validação pode envolver regras como:
         * - Verificar se contém apenas dígitos (0–9);
         * - Conferir se não está vazio;
         * - Garantir tamanho mínimo/máximo (se aplicável);
         *
         * @param valor Número em formato string.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Numero sem valor inicial.
         */
        Numero() = default;

        /**
         * @brief Construtor que inicializa com um número.
         *
         * @param valor Número a ser atribuído.
         * @throw invalid_argument Caso o número seja inválido.
         */
        explicit Numero(const string &valor);

        /**
         * @brief Define o valor do número após validação.
         *
         * @param valor String contendo o número.
         * @throw invalid_argument Caso o número seja inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o número armazenado como string.
         *
         * @return Número em formato string.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_NUMERO_H