//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class ReservaDTO {
    private:
        int reservaId;
        string chegada;
        string partida;
        int dinheiro;
        string codigo;
        int quarto_id;

    public:
        ReservaDTO() = default;

        ReservaDTO(int reservaId, string chegada, string partida, int dinheiro, string codigo,
                   int quarto_id) : reservaId(reservaId),
                                    chegada(chegada), partida(partida), dinheiro(dinheiro), codigo(codigo),
                                    quarto_id(quarto_id) {
        };

        int getId() const;

        void setId(int valor);

        string getChegada() const;

        void setChegada(const string &valor);

        string getPartida() const;

        void setPartida(const string &valor);

        int getDinheiro() const;

        void setDinheiro(const int &valor);

        string getCodigo() const;

        void setCodigo(const string &valor);

        int getQuartoId() const;

        void setQuartoId(int valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP