//
// Created by caleb on 18/11/2025.
//

#include "HospedeDTO.hpp"

namespace Hotelaria {
    int HospedeDTO::getId() const {
        return id;
    }

    void HospedeDTO::setId(int valor) {
        this->id = valor;
    }

    string HospedeDTO::getNome() const {
        return nome;
    }

    void HospedeDTO::setNome(const string &valor) {
        this->nome = valor;
    }

    string HospedeDTO::getEmail() const {
        return email;
    }

    void HospedeDTO::setEmail(const string &valor) {
        this->email = valor;
    }

    string HospedeDTO::getEndereco() const {
        return endereco;
    }

    void HospedeDTO::setEndereco(const string &valor) {
        this->endereco = valor;
    }

    string HospedeDTO::getCartao() const {
        return cartao;
    }

    void HospedeDTO::setCartao(const string &valor) {
        this->cartao = valor;
    }
}