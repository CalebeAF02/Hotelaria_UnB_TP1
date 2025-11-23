#ifndef PESSOA_INCLUDE
#define PESSOA_INCLUDE

#include "Nome.hpp"
#include "Email.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Pessoa
     * @brief Classe base que representa uma pessoa no sistema de hotelaria.
     *
     * A classe Pessoa é abstrata no sentido conceitual, servindo como base para
     * classes mais específicas como Gerente e Hospede. Ela contém atributos
     * comuns como nome e email, além de métodos de acesso e modificação.
     */
    class Pessoa {
    protected:
        /**
         * @brief Nome da pessoa.
         */
        Nome nome;
        /**
         * @brief Email da pessoa.
         */
        Email email;

    public:
        /// @name Construtores
        /// @{
        /**
         * @brief Construtor que inicializa a pessoa com nome e email.
         *
         * @param nomeObj Nome da pessoa.
         * @param emailObj Email da pessoa.
         */
        Pessoa(Nome nomeObj, Email emailObj) : nome(nomeObj), email(emailObj) {
        };

        /// @}
        /// @name Métodos Setters
        /// @{
        /**
         * @brief Define o nome da pessoa.
         *
         * @param valor Novo nome.
         */
        void setPessoaNome(const Nome &valor);

        /**
         * @brief Define o email da pessoa.
         *
         * @param valor Novo email.
         */
        void setPessoaEmail(const Email &valor);

        /// @}
        /// @name Métodos Getters
        /// @{
        /**
         * @brief Retorna o nome da pessoa como string.
         *
         * @return Nome da pessoa.
         */
        string getNome() const;

        /**
         * @brief Retorna o email da pessoa como string.
         *
         * @return Email da pessoa.
         */
        string getEmail() const;

        /// @}
    };
}

#endif