//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CARTAO_H
#define GERENCIADOR_HOTEL_UNB_CARTAO_H

#include "iostream"
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Cartao
     * @brief Representa um cartão utilizado no sistema de hotelaria.
     *
     * A classe **Cartao** funciona como um *Domínio* responsável por armazenar e
     * validar um número de cartão (de crédito, débito, ou cartão de registro interno).
     *
     * Este domínio encapsula:
     * - Armazenamento seguro do valor
     * - Validação do formato fornecido
     * - Controle centralizado dos padrões aceitos pelo sistema
     *
     * A validação é feita pelo método privado @ref validar, garantindo que qualquer cartão
     * criado esteja em um estado consistente.
     *
     * ### Exemplo de uso:
     * @code
     * Cartao c("1234567890123456");
     * cout << c.getValor();   // imprime o valor validado
     * @endcode
     */
    class Cartao {
    private:
        /**
         * @brief Valor armazenado do cartão.
         *
         * Pode representar números de cartão de crédito, débito ou identificadores internos,
         * dependendo da camada de aplicação.
         * Mantido como string para preservar zeros à esquerda e permitir máscaras.
         */
        string cartaoStr;

        /**
         * @brief Valida um valor de cartão antes de ser armazenado.
         *
         * Este método é responsável por garantir que o cartão informado cumpre
         * os requisitos do sistema (como tamanho mínimo, formato, caracteres válidos).
         *
         * @param valor Valor a ser validado.
         *
         * @throw invalid_argument Caso o valor não seja considerado válido.
         *
         * ### Possíveis validações esperadas:
         * - Apenas dígitos numéricos
         * - Tamanho entre 8 e 19 caracteres
         * - Eventual validação Luhn, caso desejado
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Cartao sem valor definido.
         * O valor só poderá ser atribuído posteriormente via @ref setValor.
         */
        Cartao() = default;

        /**
         * @brief Construtor que inicializa um cartão já validado.
         *
         * Internamente chama @ref setValor, que executa a validação.
         *
         * @param valor String contendo o valor do cartão.
         */
        explicit Cartao(const string &valor);

        /**
         * @brief Define o valor do cartão após validar o conteúdo.
         *
         * @param valor Novo valor do cartão.
         *
         * @throw invalid_argument Caso o valor informado seja inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Recupera o valor bruto do cartão.
         *
         * @return Uma string contendo o valor armazenado do cartão.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CARTAO_H