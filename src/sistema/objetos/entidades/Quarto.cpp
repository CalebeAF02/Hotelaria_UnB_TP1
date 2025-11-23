#include "Quarto.hpp"

namespace Hotelaria {
    Quarto::Quarto(Numero numero, Capacidade capacidade, Dinheiro diaria, Ramal ramal, int hotel_id) {
        setNumero(numero);
        setCapacidade(capacidade);
        setDiaria(diaria);
        setRamal(ramal);
        setHotelID(hotel_id);
    }

    Quarto::Quarto(QuartoDTO &quarto_dto) {
        setNumero(Numero(quarto_dto.getNumero()));
        setCapacidade(Capacidade(quarto_dto.getCapacidade()));
        setDiaria(Dinheiro(quarto_dto.getDinheiro()));
        setRamal(Ramal(quarto_dto.getRamal()));
    };

    void Quarto::setNumero(const Numero &newNumero) {
        this->numero = newNumero;
    }

    void Quarto::setCapacidade(const Capacidade &newCapacidade) {
        this->capacidade = newCapacidade;
    }

    void Quarto::setDiaria(const Dinheiro &newDiaria) {
        this->diaria = newDiaria;
    }

    void Quarto::setRamal(const Ramal &newRamal) {
        this->ramal = newRamal;
    }

    void Quarto::setHotelID(const int valor) {
        this->hotel_id = valor;
    }

    string Quarto::getNumero() const {
        return numero.getValor();
    }

    int Quarto::getCapacidade() const {
        return capacidade.getValor();
    }

    int Quarto::getDiaria() const {
        return diaria.getValor();
    }

    string Quarto::getRamal() const {
        return ramal.getValor();
    }

    int Quarto::getHotelID() const {
        return hotel_id;
    }
}