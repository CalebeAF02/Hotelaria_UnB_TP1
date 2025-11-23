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
    class Quarto {
    private:
        Numero numero;
        Capacidade capacidade;
        Dinheiro diaria;
        Ramal ramal;
        int hotel_id;

    public:
        Quarto() = default;

        Quarto(Numero numero, Capacidade capacidade, Dinheiro diaria, Ramal ramal, int hotel_id);

        Quarto(QuartoDTO &quarto_dto);

        void setNumero(const Numero &newNumero);

        void setCapacidade(const Capacidade &newCapacidade);

        void setDiaria(const Dinheiro &newDiaria);

        void setRamal(const Ramal &newRamal);

        void setHotelID(const int hotel_id);

        string getNumero() const;

        int getCapacidade() const;

        int getDiaria() const;

        string getRamal() const;

        int getHotelID() const;
    };
}

#endif