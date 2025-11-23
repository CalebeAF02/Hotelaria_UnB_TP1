//
// Created by caleb on 09/11/2025.
//

#include "GerenteDTO.hpp"

namespace Hotelaria {
    int GerenteDTO::getId() const {
        return id;
    }

    void GerenteDTO::setId(int valor) {
        this->id = valor;
    }

    string GerenteDTO::getNome() const {
        return nome;
    }

    void GerenteDTO::setNome(const string &valor) {
        this->nome = valor;
    }

    string GerenteDTO::getEmail() const {
        return email;
    }

    void GerenteDTO::setEmail(const string &valor) {
        this->email = valor;
    }

    string GerenteDTO::getRamal() const {
        return ramal;
    }

    void GerenteDTO::setRamal(const string &valor) {
        this->ramal = valor;
    }

    string GerenteDTO::getSenha() const {
        return senha;
    }

    void GerenteDTO::setSenha(const string &valor) {
        this->senha = valor;
    }
}