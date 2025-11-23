//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_ENDERECO_H
#define GERENCIADOR_HOTEL_UNB_ENDERECO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Endereco
     * @brief Classe responsável por armazenar e validar endereços.
     *
     * A classe assegura que o endereço recebido segue regras básicas de formato,
     * evitando valores vazios ou inválidos. Pode ser utilizada por diversas
     * entidades do sistema (como Hospede, Hotel, etc.).
     */
    class Endereco {
    private:
        /**
         * @brief String que armazena o endereço tratado e validado.
         */
        string enderecoStr;

        /**
         * @brief Método responsável por validar o endereço fornecido.
         *
         * A validação pode incluir regras como:
         * - Não permitir string vazia
         * - Não permitir endereços muito curtos
         * - Verificar se há caracteres proibidos
         *
         * @param valor Endereço que será validado.
         * @throw invalid_argument Caso o endereço esteja em formato inválido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Endereco sem valor inicial.
         */
        Endereco() = default;

        /**
         * @brief Construtor que recebe um endereço inicial.
         *
         * Realiza validação antes de armazenar o valor.
         *
         * @param valor Endereço inicial a ser atribuído ao objeto.
         */
        explicit Endereco(const string &valor);

        /**
         * @brief Define um novo endereço.
         *
         * Aplica validação antes de atribuir.
         *
         * @param valor Novo valor do endereço.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o endereço armazenado.
         *
         * @return String contendo o endereço atual.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_ENDERECO_H