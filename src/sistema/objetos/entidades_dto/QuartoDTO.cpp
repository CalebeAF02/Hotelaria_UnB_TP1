//
// Created by caleb on 18/11/2025.
//

#include "QuartoDTO.hpp"

namespace Hotelaria {
    int QuartoDTO::getId() const {
        return id;
    }

    void QuartoDTO::setId(int valor) {
        this->id = valor;
    }

    string QuartoDTO::getNumero() const {
        return numero;
    }

    void QuartoDTO::setNumero(const string &valor) {
        this->numero = valor;
    }

    int QuartoDTO::getCapacidade() const {
        return capacidade;
    }

    void QuartoDTO::setCapacidade(const int &valor) {
        this->capacidade = valor;
    }

    int QuartoDTO::getDinheiro() const {
        return dinheiro;
    }

    void QuartoDTO::setDinheiro(const int &valor) {
        this->dinheiro = valor;
    }

    string QuartoDTO::getRamal() const {
        return ramal;
    }

    void QuartoDTO::setRamal(const string &valor) {
        this->ramal = valor;
    }

    int QuartoDTO::getHotelId() const {
        return hotel_id;
    }

    void QuartoDTO::setHotelId(int valor) {
        this->hotel_id = valor;
    }
}