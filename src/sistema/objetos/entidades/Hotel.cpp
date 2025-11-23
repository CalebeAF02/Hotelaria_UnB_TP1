#include "Hotel.hpp"

namespace Hotelaria {
    Hotel::Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo, int gerente_id) {
        setNome(nome);
        setEndereco(endereco);
        setTelefone(telefone);
        setCodigo(codigo);
        setGerenteId(gerente_id);
    };

    Hotel::Hotel(HotelDTO &hotel_dto) {
        setNome(Nome(hotel_dto.getNome()));
        setEndereco(Endereco(hotel_dto.getEndereco()));
        setTelefone(Telefone(hotel_dto.getTelefone()));
        setCodigo(Codigo(hotel_dto.getCodigo()));
        setGerenteId(hotel_dto.getGerenteID());
    };

    void Hotel::setNome(const Nome &newNome) {
        this->nome = newNome;
    };

    void Hotel::setEndereco(const Endereco &newEndereco) {
        this->endereco = newEndereco;
    };

    void Hotel::setTelefone(const Telefone &newTelefone) {
        this->telefone = newTelefone;
    };

    void Hotel::setCodigo(const Codigo &newCodigo) {
        this->codigo = newCodigo;
    };

    string Hotel::getNome() const {
        return nome.getValor();
    };

    string Hotel::getEndereco() const {
        return endereco.getValor();
    };

    string Hotel::getTelefone() const {
        return telefone.getValor();
    };

    string Hotel::getCodigo() const {
        return codigo.getValor();
    };

    void Hotel::setGerenteId(const int &valor) {
        this->gerente_id = valor;
    }

    int Hotel::getGerenteId() const {
        return gerente_id;
    }
}