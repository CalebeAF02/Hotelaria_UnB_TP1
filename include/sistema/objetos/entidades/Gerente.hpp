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
     * @brief Representa um gerente do sistema de hotelaria.
     *
     * Herda de Pessoa e adiciona atributos específicos como ramal e senha.
     */
    class Gerente : public Pessoa {
    private:
        /// Atributos específicos do gerente
        /// O ramal é o número de contato interno do gerente (ex.: telefone interno)
        Ramal ramal;

        /// Senha usada pelo gerente para acessar o sistema
        Senha senha;

    public:
        /// @name Construtores
        /// @{

        /**
         * @brief Construtor padrão do gerente.
         *
         * Cria um gerente com nome e email vazios.
         */
        Gerente() : Pessoa(Nome(), Email()) {
        };

        /**
         * @brief Construtor completo do gerente.
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

        /// @name Métodos de acesso
        /// @{
        /// SETTERS - usados para alterar os valores dos atributos depois que o objeto já foi criado
        void setNome(const Nome &newNome);

        void setEmail(const Email &newEmail);

        void setRamal(const Ramal &newRamal);

        void setSenha(const Senha &newSenha);

        /// @}

        /// @name Métodos de acesso
        /// @{

        /**
         * @brief Retorna o número do ramal como string.
         * @return Ramal do gerente.
         */
        string getRamal() const;

        /**
         * @brief Retorna a senha do gerente como string.
         * @return Senha do gerente.
         */
        string getSenha() const;

        /// @}
    };
}

#endif