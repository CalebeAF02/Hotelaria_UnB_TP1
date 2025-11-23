//
// Created by caleb on 18/11/2025.
//
#include "ReservaDTO.hpp"

namespace Hotelaria {
    int ReservaDTO::getId() const {
        return reservaId;
    }

    void ReservaDTO::setId(int valor) {
        this->reservaId = valor;
    }

    string ReservaDTO::getChegada() const {
        return chegada;
    }

    void ReservaDTO::setChegada(const string &valor) {
        this->chegada = valor;
    }

    string ReservaDTO::getPartida() const {
        return partida;
    }

    void ReservaDTO::setPartida(const string &valor) {
        this->partida = valor;
    }

    int ReservaDTO::getDinheiro() const {
        return dinheiro;
    }

    void ReservaDTO::setDinheiro(const int &valor) {
        this->dinheiro = valor;
    }

    string ReservaDTO::getCodigo() const {
        return codigo;
    }

    void ReservaDTO::setCodigo(const string &valor) {
        this->codigo = valor;
    }

    int ReservaDTO::getQuartoId() const {
        return quarto_id;
    }

    void ReservaDTO::setQuartoId(int valor) {
        this->quarto_id = valor;
    }
}