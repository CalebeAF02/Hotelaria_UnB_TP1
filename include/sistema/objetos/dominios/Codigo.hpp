//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CODIGO_H
#define GERENCIADOR_HOTEL_UNB_CODIGO_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Codigo
     * @brief Representa um código identificador genérico dentro do sistema de hotelaria.
     *
     * A classe **Codigo** é um domínio responsável pelo armazenamento seguro
     * e validação de códigos textuais usados no sistema, como:
     *
     * - Códigos de hotéis
     * - Códigos de quartos
     * - Códigos de reservas
     * - Identificadores internos padronizados
     *
     * A lógica de validação (implementada em @ref validar) garante que o valor
     * fornecido esteja de acordo com regras de formato, tamanho e caracteres permitidos.
     *
     * Essa classe centraliza a consistência dos identificadores utilizados ao
     * longo de toda a aplicação.
     *
     * ### Exemplo de uso:
     * @code
     * Codigo c("HTL001");
     * cout << c.getValor(); // retorna "HTL001"
     * @endcode
     */
    class Codigo {
    private:
        /**
         * @brief Armazena o valor textual do código.
         *
         * Mantido como string para permitir:
         * - Identificadores alfanuméricos
         * - Prefixos (ex.: "HTL", "RES", "QRT")
         * - Zeros à esquerda
         */
        string codigoStr;

        /**
         * @brief Valida o valor fornecido antes de armazenar.
         *
         * Este método garante que o código atende às regras do sistema —
         * como tamanho mínimo, máximo, caracteres válidos ou padrões específicos
         * (por exemplo, "ABC123").
         *
         * @param valor String contendo o código a ser validado.
         *
         * @throw invalid_argument Caso o valor seja considerado inválido.
         *
         * ### Exemplos de validações esperadas:
         * - Tamanho entre 3 e 15 caracteres
         * - Somente letras e números
         * - Padrão alfanumérico sem espaços
         * - Possível verificação de prefixos obrigatórios
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Codigo não inicializado.
         * O valor poderá ser definido posteriormente via @ref setValor.
         */
        Codigo() = default;

        /**
         * @brief Construtor que inicializa o código imediatamente.
         *
         * Internamente chama @ref setValor, que executa a validação.
         *
         * @param valor Código inicial a ser validado e armazenado.
         *
         * @throw invalid_argument Caso o código seja inválido.
         */
        explicit Codigo(const string &valor);

        /**
         * @brief Define (com validação) o valor do código.
         *
         * @param valor String contendo o novo código.
         *
         * @throw invalid_argument Caso o código seja considerado inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o código armazenado.
         *
         * @return Uma string contendo o valor atual do código validado.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CODIGO_H