#ifndef QUARTO_INCLUDE
#define QUARTO_INCLUDE

#include "QuartoDTO.hpp"
#include "Numero.hpp"
#include "Capacidade.hpp"
#include "Dinheiro.hpp"
#include "Ramal.hpp"

#include <string>
#include <stdexcept>

using namespace std;

namespace Hotelaria {
    /**
     * @class Quarto
     * @brief Representa um quarto disponível no hotel.
     *
     * A classe Quarto contém informações essenciais sobre um quarto,
     * incluindo número, capacidade, valor da diária, ramal interno e o ID
     * do hotel ao qual o quarto pertence. Pode ser criada diretamente ou
     * através de um QuartoDTO.
     */
    class Quarto {
    private:
        /**
          * @brief Número identificador do quarto.
          */
        Numero numero;
        /**
         * @brief Capacidade máxima de hóspedes que o quarto comporta.
         */
        Capacidade capacidade;
        /**
         * @brief Valor da diária do quarto.
         */
        Dinheiro diaria;
        /**
         * @brief Ramal interno do quarto.
         */
        Ramal ramal;
        /**
         * @brief ID do hotel ao qual este quarto pertence.
         */
        int hotel_id;

    public:
        /// @name Construtores
        /// @{
        /**
         * @brief Construtor padrão.
         *
         * Cria um objeto Quarto não inicializado.
         */
        Quarto() = default;

        /**
         * @brief Construtor completo do quarto.
         *
         * @param numero Número identificador do quarto.
         * @param capacidade Capacidade máxima de hóspedes.
         * @param diaria Valor da diária.
         * @param ramal Ramal interno do quarto.
         * @param hotel_id ID do hotel responsável.
         */
        Quarto(Numero numero, Capacidade capacidade, Dinheiro diaria, Ramal ramal, int hotel_id);

        /**
         * @brief Constrói um quarto a partir de um QuartoDTO.
         *
         * Geralmente utilizado quando os dados são carregados do banco.
         *
         * @param quarto_dto DTO contendo dados do quarto.
         */
        Quarto(QuartoDTO &quarto_dto);

        /// @}
        /// @name Métodos Setters
        /// @{
        /**
         * @brief Define o número do quarto.
         *
         * @param newNumero Novo número.
         */
        void setNumero(const Numero &newNumero);

        /**
         * @brief Define a capacidade máxima do quarto.
         *
         * @param newCapacidade Nova capacidade.
         */
        void setCapacidade(const Capacidade &newCapacidade);

        /**
         * @brief Define o valor da diária.
         *
         * @param newDiaria Novo valor.
         */
        void setDiaria(const Dinheiro &newDiaria);

        /**
         * @brief Define o ramal interno do quarto.
         *
         * @param newRamal Novo ramal.
         */
        void setRamal(const Ramal &newRamal);

        /**
         * @brief Define o ID do hotel ao qual o quarto pertence.
         *
         * @param hotel_id Novo ID do hotel.
         */
        void setHotelID(const int hotel_id);

        /// @}
        /// @name Métodos Getters
        /// @{
        /**
         * @brief Retorna o número do quarto como string.
         *
         * @return Número do quarto.
         */
        string getNumero() const;

        /**
         * @brief Retorna a capacidade máxima do quarto.
         *
         * @return Capacidade do quarto.
         */
        int getCapacidade() const;

        /**
         * @brief Retorna o valor da diária do quarto.
         *
         * @return Valor da diária.
         */
        int getDiaria() const;

        /**
         * @brief Retorna o ramal interno do quarto como string.
         *
         * @return Ramal do quarto.
         */
        string getRamal() const;

        /**
         * @brief Retorna o ID do hotel responsável pelo quarto.
         *
         * @return ID do hotel.
         */
        int getHotelID() const;

        /// @}
    };
}

#endif