//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_RAMAL_H
#define GERENCIADOR_HOTEL_UNB_RAMAL_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Ramal
     * @brief Representa um ramal telefônico interno dentro do sistema.
     *
     * A classe Ramal é utilizada para armazenar e validar números de ramais
     * internos (ex.: "101", "2004", "55"), garantindo que o formato esteja correto
     * antes de ser aceito pelo sistema.
     *
     * Exemplos comuns de validação incluem:
     * - Permitir apenas dígitos;
     * - Tamanho mínimo ou máximo (dependendo das regras de negócio);
     * - Proibir strings vazias.
     */
    class Ramal {
    private:
        /**
         * @brief Armazena o ramal validado.
         */
        string ramalStr;

        /**
        * @brief Realiza a validação do ramal fornecido.
        *
        * Deve verificar se o valor atende aos critérios definidos
        * para ramais internos. Normalmente inclui:
        * - Verificar caracteres permitidos;
        * - Garantir que não esteja vazio;
        * - Conferir se o tamanho está dentro das regras.
        *
        * @param valor Ramal em formato string.
        * @throw invalid_argument Se o ramal informado for inválido.
         */
        void validar(const string &valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Ramal sem valor inicial.
         */
        Ramal() = default;

        /**
         * @brief Construtor que inicializa o objeto já com um ramal.
         *
         * @param valor Ramal a ser atribuído.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        explicit Ramal(const string &valor);

        /**
         * @brief Define o valor do ramal após validar.
         *
         * @param valor String contendo o ramal.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o ramal armazenado como string.
         *
         * @return Ramal em formato textual.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_RAMAL_H