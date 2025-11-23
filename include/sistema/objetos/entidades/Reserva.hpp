#ifndef RESERVA_INCLUDE
#define RESERVA_INCLUDE

#include "ReservaDTO.hpp"
#include "Data.hpp"
#include "Dinheiro.hpp"
#include "Codigo.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @class Reserva
     * @brief Representa uma reserva realizada no hotel.
     *
     * A classe Reserva guarda informações relacionadas a uma reserva,
     * incluindo datas de chegada e partida, o valor total da reserva e
     * um código identificador. Pode ser construída manualmente ou a partir
     * de um objeto ReservaDTO proveniente de uma fonte externa (como BD).
     */
    class Reserva {
    private:
        /**
         * @brief Data de chegada do hóspede.
         */
        Data chegada;

        /**
         * @brief Data de partida do hóspede.
         */
        Data partida;

        /**
         * @brief Valor total da reserva.
         */
        Dinheiro dinheiro;

        /**
         * @brief Código identificador da reserva.
         */
        Codigo codigo;

    public:
        /// @name Construtores
        /// @{
        /**
         * @brief Construtor padrão da reserva.
         *
         * Cria uma reserva sem inicializar seus atributos.
         */
        Reserva() = default;

        /**
         * @brief Construtor completo da reserva.
         *
         * @param chegada Data de chegada.
         * @param partida Data de partida.
         * @param dinheiro Valor total da reserva.
         * @param codigo Código identificador da reserva.
         */
        Reserva(Data chegada, Data partida, Dinheiro dinheiro, Codigo codigo);

        /**
         * @brief Constrói uma reserva a partir de um ReservaDTO.
         *
         * @param reserva_dto DTO contendo os dados da reserva.
         */
        Reserva(ReservaDTO &reserva_dto);

        /// @}
        /// @name Métodos Setters
        /// @{
        /**
         * @brief Define a data de chegada.
         *
         * @param newChegada Nova data de chegada.
         */
        void setChegada(const Data &newChegada);

        /**
         * @brief Define a data de partida.
         *
         * @param newPartida Nova data de partida.
         */
        void setPartida(const Data &newPartida);

        /**
         * @brief Define o valor da reserva.
         *
         * @param newDinheiro Novo valor.
         */
        void setDinheiro(const Dinheiro &newDinheiro);

        /**
         * @brief Define o código identificador da reserva.
         *
         * @param newCodigo Novo código.
         */
        void setCodigo(const Codigo &newCodigo);

        /**
         * @brief Retorna a data de chegada.
         *
         * @return Objeto Data representando a chegada.
         */
        Data getChegada() const;

        /**
         * @brief Retorna a data de partida.
         *
         * @return Objeto Data representando a partida.
         */
        Data getPartida() const;

        /**
         * @brief Retorna o valor da reserva.
         *
         * @return Valor total da reserva.
         */
        int getDinheiro() const;

        /**
         * @brief Retorna o código identificador da reserva.
         *
         * @return Código da reserva.
         */
        string getCodigo() const;

        /// @}
    };
}

#endif