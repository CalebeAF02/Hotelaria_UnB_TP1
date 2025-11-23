//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SENHA_H
#define GERENCIADOR_HOTEL_UNB_SENHA_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Senha
     * @brief Classe responsável por armazenar e validar senhas de acesso ao sistema.
     *
     * A classe Senha garante que apenas senhas válidas possam ser atribuídas ao objeto.
     * A lógica de validação pode envolver:
     * - Tamanho mínimo e máximo;
     * - Presença de caracteres específicos (ex.: letras, números, símbolos);
     * - Proibição de espaços;
     * - Outros critérios de segurança definidos pelo sistema.
     *
     * Esta classe é usada especialmente pela entidade Gerente, mas pode ser aplicada
     * a qualquer objeto que precise de autenticação.
     */
    class Senha {
    private:
        /**
         * @brief Armazena a senha já validada.
         */
        string senhaStr;

        /**
         * @brief Realiza a validação da senha informada.
         *
         * Deve verificar se a senha cumpre os critérios de segurança definidos
         * pelo sistema. Exemplos de validações possíveis:
         * - Verificar se não está vazia;
         * - Conferir o tamanho mínimo (ex.: 6 ou 8 caracteres);
         * - Forçar presença de caracteres variados;
         * - Impedir senhas muito fracas.
         *
         * @param valor Senha fornecida pelo usuário.
         * @throw invalid_argument Caso a senha seja considerada inválida.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Senha sem valor inicial.
         */
        Senha() = default;

        /**
         * @brief Construtor que inicializa o objeto com uma senha.
         *
         * @param valor Senha inicial.
         * @throw invalid_argument Caso a senha não seja válida.
         */
        explicit Senha(const string &valor);

        /**
         * @brief Modifica o valor da senha após validação.
         *
         * @param valor Senha em formato string.
         * @throw invalid_argument Caso a senha seja inválida.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna a senha em formato string.
         *
         * @attention Em um sistema real, expor senhas em texto puro não seria seguro.
         *            Aqui é permitido apenas por simplificação acadêmica do projeto.
         *
         * @return A senha armazenada.
         */
        string getValor() const;
    };
}


#endif //GERENCIADOR_HOTEL_UNB_SENHA_H