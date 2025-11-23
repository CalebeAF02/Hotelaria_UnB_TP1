#ifndef HOTEL_INCLUDE
#define HOTEL_INCLUDE

#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"
#include "HotelDTO.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Hotel
     * @brief Representa um hotel no sistema de hotelaria.
     *
     * A classe Hotel contém informações básicas sobre o estabelecimento,
     * incluindo nome, endereço, telefone, código identificador e o gerente
     * responsável. Pode ser construída diretamente ou a partir de um DTO.
     */
    class Hotel {
    private:
        /**
         * @brief Nome do hotel.
         */
        Nome nome;
        /**
         * @brief Endereço físico do hotel.
         */
        Endereco endereco;
        /**
         * @brief Telefone de contato do hotel.
         */
        Telefone telefone;
        /**
         * @brief Código identificador do hotel.
         */
        Codigo codigo;
        /**
         * @brief Identificador do gerente responsável pelo hotel.
         */
        int gerente_id;

    public:
        /// @name Construtores
        /// @{
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Hotel sem inicializar seus atributos.
         */
        Hotel() = default;

        /**
         * @brief Construtor completo do hotel.
         *
         * @param nome Nome do hotel.
         * @param endereco Endereço do hotel.
         * @param telefone Telefone de contato.
         * @param codigo Código identificador do hotel.
         * @param gerente_id ID do gerente responsável.
         */
        Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo, int gerente_id);

        /**
         * @brief Constrói um hotel a partir de um HotelDTO.
         *
         * Geralmente utilizado quando os dados vêm do banco de dados.
         *
         * @param hotel_dto DTO contendo os dados do hotel.
         */
        Hotel(HotelDTO &hotel_dto);

        /// @}
        /// @name Métodos Setters
        /// @{
        /**
         * @brief Define o nome do hotel.
         *
         * @param newNome Novo nome.
         */
        void setNome(const Nome &newNome);

        /**
         * @brief Define o endereço do hotel.
         *
         * @param newEndereco Novo endereço.
         */
        void setEndereco(const Endereco &newEndereco);

        /**
         * @brief Retorna o telefone do hotel como string.
         *
         * @return Telefone do hotel.
         */
        void setTelefone(const Telefone &newTelefone);

        /**
         * @brief Define o código identificador do hotel.
         *
         * @param newCodigo Novo código.
         */
        void setCodigo(const Codigo &newCodigo);

        /**
         * @brief Define o ID do gerente responsável.
         *
         * @param newGerenteId Novo ID do gerente.
         */
        void setGerenteId(const int &newGerenteId);


        /// @}
        /// @name Métodos Getters
        /// @{
        /**
         * @brief Retorna o nome do hotel como string.
         *
         * @return Nome do hotel.
         */
        string getNome() const;

        /**
         * @brief Retorna o endereço do hotel como string.
         *
         * @return Endereço do hotel.
         */
        string getEndereco() const;

        /**
         * @brief Retorna o telefone do hotel como string.
         *
         * @return Telefone do hotel.
         */
        string getTelefone() const;

        /**
         * @brief Retorna o código identificador do hotel como string.
         *
         * @return Código do hotel.
         */
        string getCodigo() const;


        /**
         * @brief Retorna o ID do gerente responsável pelo hotel.
         *
         * @return ID do gerente.
         */
        int getGerenteId() const;

        /// @}
    };
}

#endif