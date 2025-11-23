//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_EMAIL_H
#define GERENCIADOR_HOTEL_UNB_EMAIL_H

#include "iostream"
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Email
     * @brief Classe responsável pelo armazenamento e validação de endereços de e-mail.
     *
     * A classe garante que o e-mail armazenado esteja dentro de um formato válido,
     * seguindo regras básicas de composição, como presença de '@' e domínio.
     */
    class Email {
    private:
        /**
         * @brief Armazena o e-mail validado em formato de string.
         */
        string emailStr;

        /**
         * @brief Método privado que valida o formato do e-mail.
         *
         * Verifica se o e-mail contém ao menos um '@', um domínio e
         * não possui caracteres proibidos.
         *
         * @param valor String contendo o e-mail a ser validado.
         * @throw invalid_argument Caso o e-mail esteja em formato inválido.
         */
        void validar(const string &valor);

    public:
        /**
         * @brief Construtor padrão da classe Email.
         *
         * Cria o objeto sem atribuir um valor inicial.
         */
        Email() = default;

        /**
         * @brief Construtor que inicializa o objeto com um e-mail.
         *
         * Chama o método setValor(), que aplica a validação.
         *
         * @param valor Endereço de e-mail inicial.
         */
        explicit Email(const string &valor);

        /**
         * @brief Atribui um novo valor ao e-mail.
         *
         * Antes de atribuir, o método validar() é chamado para garantir
         * que o e-mail segue o formato correto.
         *
         * @param valor Novo e-mail a ser armazenado.
         */
        void setValor(const string &valor);

        /**
         * @brief Retorna o e-mail armazenado.
         *
         * @return String contendo o e-mail validado.
         */
        string getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_EMAIL_H