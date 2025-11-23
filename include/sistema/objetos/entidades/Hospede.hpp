#ifndef HOSPEDE_INCLUDE
#define HOSPEDE_INCLUDE

#include "Pessoa.hpp"

#include "Nome.hpp"
#include "Email.hpp"
#include "Cartao.hpp"
#include "Endereco.hpp"

#include "HospedeDTO.hpp"
#include <string>
#include "IO.hpp"

using namespace std;

namespace Hotelaria {
    /**
     * @class Hospede
     * @brief Representa um hóspede no sistema de hotelaria.
     *
     * A classe Hospede herda de Pessoa e adiciona atributos específicos como
     * endereço e cartão, utilizados para cadastro e operações de hospedagem
     * e pagamentos.
     */
    class Hospede : public Pessoa {
    private:
        /**
         * @brief Endereço residencial do hóspede.
         */
        Endereco endereco;
        /**
         * @brief Cartão cadastrado para pagamentos.
         */
        Cartao cartao;

    public:
        /// @name Construtores
        /// @{
        /**
          * @brief Construtor padrão.
          *
          * Inicializa um hóspede com nome e email vazios.
          */
        Hospede() : Pessoa(Nome(), Email()) {
        };
        /**
         * @brief Construtor completo do hóspede.
         *
         * @param nomePessoaObj Nome do hóspede.
         * @param emailPessoaObj Email do hóspede.
         * @param endereco Endereço do hóspede.
         * @param cartao Cartão utilizado pelo hóspede.
         */
        Hospede(Nome nomePessoaObj, Email emailPessoaObj, Endereco endereco, Cartao cartao) : Pessoa(nomePessoaObj,
                emailPessoaObj), endereco(endereco), cartao(cartao) {
        };
        /**
         * @brief Constrói um hóspede a partir de um objeto HospedeDTO.
         *
         * Geralmente utilizado quando os dados vêm do banco de dados.
         *
         * @param hospede_dto DTO contendo as informações do hóspede.
         */
        Hospede(HospedeDTO &hospede_dto) : Pessoa(Nome(hospede_dto.getNome()), Email(hospede_dto.getEmail())) {
            setEndereco(Endereco(hospede_dto.getEndereco()));
        };
        /// @}
        /// @name Métodos Setters
        /// @{
        /**
         * @brief Define o nome do hóspede.
         *
         * @param newNome Novo nome.
         */
        void setNome(const Nome &newNome);

        /**
         * @brief Define o email do hóspede.
         *
         * @param newEmail Novo email.
         */
        void setEmail(const Email &newEmail);

        /**
         * @brief Define o endereço do hóspede.
         *
         * @param newEndereco Novo endereço.
         */
        void setEndereco(const Endereco &newEndereco);

        /**
         * @brief Define o cartão do hóspede.
         *
         * @param newCartao Novo cartão.
         */
        void setCartao(const Cartao &newCartao);

        /// @}
        /// @name Métodos Getters
        /// @{
        /**
         * @brief Retorna o endereço do hóspede como string.
         *
         * @return String contendo o endereço.
         */
        string getEndereco() const;

        /**
         * @brief Retorna o cartão do hóspede como string.
         *
         * @return String contendo os dados do cartão.
         */
        string getCartao() const;

        /// @}
    };
}

#endif