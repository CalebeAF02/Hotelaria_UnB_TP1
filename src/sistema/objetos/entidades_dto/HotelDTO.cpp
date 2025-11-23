//
// Created by caleb on 08/11/2025.
//

#include "HotelDTO.hpp"

namespace Hotelaria {
    int HotelDTO::getId() const {
        return id;
    }

    void HotelDTO::setId(int valor) {
        this->id = valor;
    }

    string HotelDTO::getNome() const {
        return nome;
    }

    void HotelDTO::setNome(const string &valor) {
        this->nome = valor;
    }

    string HotelDTO::getEndereco() const {
        return endereco;
    }

    void HotelDTO::setEndereco(const string &valor) {
        this->endereco = valor;
    }

    string HotelDTO::getTelefone() const {
        return telefone;
    }

    void HotelDTO::setTelefone(const string &valor) {
        this->telefone = valor;
    }

    string HotelDTO::getCodigo() const {
        return codigo;
    }

    void HotelDTO::setCodigo(const string &valor) {
        this->codigo = valor;
    }

    int HotelDTO::getGerenteID() const {
        return gerente_id;
    }

    void HotelDTO::setGerenteID(int valor) {
        this->gerente_id = valor;
    }
}