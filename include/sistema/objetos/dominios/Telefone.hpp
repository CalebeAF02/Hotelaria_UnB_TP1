//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_TELEFONE_H
#define GERENCIADOR_HOTEL_UNB_TELEFONE_H

#include "iostream"
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Telefone
     * @brief Classe responsável por armazenar e validar números de telefone.
     *
     * A classe Telefone encapsula um número telefônico no formato string e delega
     * ao método validar() a responsabilidade de verificar seu formato. Exemplos
     * de verificações possíveis:
     *
     * - Apenas dígitos, com ou sem máscara;
     * - Tamanho específico (ex.: 10 ou 11 dígitos);
     * - Verificação de DDD válido;
     * - Proibição de espaços ou caracteres inválidos.
     *
     * Essa classe garante integridade dos dados fornecidos ao sistema e evita
     * armazenamento de telefones inconsistentes.
     */
    class Telefone {
    private:
        /**
         * @brief Armazena o telefone já validado.
         */
        string telefoneStr;

        /**
         * @brief Valida o número de telefone.
         *
         * Este método deve implementar as regras de validação necessárias para
         * garantir consistência do telefone no sistema. Exemplos:
         * - Verificar se o valor não está vazio;
         * - Conferir se contém somente dígitos (quando aplicável);
         * - Garantir tamanho compatível com o padrão brasileiro;
         * - Rejeitar caracteres especiais inesperados.
         *
         * @param valor Telefone em formato string.
         * @throw invalid_argument Caso o número seja inválido.
         */

        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um telefone vazio, sem valor inicial.
         */
        Telefone() = default;

        /**
         * @brief Construtor que inicializa o objeto com um telefone.
         *
         * @param valor Telefone a ser atribuído.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        explicit Telefone(const string &valor);

        /**
         * @brief Define o valor do telefone após validação.
         *
         * @param valor Telefone em formato string.
         * @throw invalid_argument Caso o valor seja inválido.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o telefone armazenado.
         * @return Telefone em formato string.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_TELEFONE_H