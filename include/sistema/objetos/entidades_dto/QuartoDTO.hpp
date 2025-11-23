//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class QuartoDTO {
    private:
        int id;
        string numero;
        int capacidade;
        int dinheiro;
        string ramal;
        int hotel_id;

    public:
        QuartoDTO() = default;

        QuartoDTO(int id, string numero, int capacidade, int dinheiro, string ramal, int hotel_id) : id(id),
            numero(numero), capacidade(capacidade), dinheiro(dinheiro), ramal(ramal), hotel_id(hotel_id) {
        };

        int getId() const;

        void setId(int valor);

        string getNumero() const;

        void setNumero(const string &valor);

        int getCapacidade() const;

        void setCapacidade(const int &valor);

        int getDinheiro() const;

        void setDinheiro(const int &valor);

        string getRamal() const;

        void setRamal(const string &valor);

        int getHotelId() const;

        void setHotelId(int valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP