#ifndef GERENTE_INCLUDE
#define GERENTE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"
#include "GerenteDTO.hpp"
#include "IO.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Gerente
     * @brief Classe que representa um gerente no sistema de hotelaria.
     *
     * A classe Gerente herda de Pessoa e adiciona atributos específicos como
     * ramal e senha para controle de acesso e comunicação interna.
     */
    class Gerente : public Pessoa {
    private:
        /**
         * @brief Número de contato interno do gerente (telefone interno).
         */
        Ramal ramal;

        /**
         * @brief Senha utilizada pelo gerente para acessar o sistema.
         */
        Senha senha;

    public:
        /// @name Construtores
        /// @{

        /**
         * @brief Construtor padrão.
         *
         * Inicializa um gerente com nome e email vazios.
         */
        Gerente() : Pessoa(Nome(), Email()) {
        };

        /**
         * @brief Construtor completo.
         * @param nomePessoaObj Nome do gerente.
         * @param emailPessoaObj Email do gerente.
         * @param ramal Ramal de contato interno.
         * @param senha Senha de acesso ao sistema.
         */
        Gerente(Nome nomePessoaObj, Email emailPessoaObj, Ramal ramal, Senha senha) : Pessoa(nomePessoaObj,
                emailPessoaObj), ramal(ramal), senha(senha) {
        };

        /**
         * @brief Construtor que cria um objeto Gerente a partir de um GerenteDTO.
         *
         * Esse construtor é normalmente utilizado quando os dados do gerente vêm do banco de dados.
         * @param gerente_dto Objeto DTO contendo os dados do gerente.
         */
        Gerente(GerenteDTO &gerente_dto) : Pessoa(Nome(gerente_dto.getNome()), Email(gerente_dto.getEmail())) {
            setRamal(Ramal(gerente_dto.getRamal()));
        };
        /// @}

        /// @name Métodos Setters
        /// @{

        /**
         * @brief Define o nome do gerente.
         *
         * @param newNome Novo nome.
         */
        void setNome(const Nome &newNome);

        /**
         * @brief Define o email do gerente.
         *
         * @param newEmail Novo email.
         */
        void setEmail(const Email &newEmail);

        /**
         * @brief Define o ramal do gerente.
         *
         * @param newRamal Novo ramal.
         */
        void setRamal(const Ramal &newRamal);

        /**
         * @brief Define a senha do gerente.
         *
         * @param newSenha Nova senha.
         */
        void setSenha(const Senha &newSenha);

        /// @}

        /// @name Métodos Getters
        /// @{

        /**
        * @brief Retorna o número do ramal como string.
        *
        * @return String contendo o ramal.
        */
        string getRamal() const;

        /**
         * @brief Retorna a senha do gerente como string.
         *
         * @return Senha em formato string.
         */
        string getSenha() const;

        /// @}
    };
}

#endif