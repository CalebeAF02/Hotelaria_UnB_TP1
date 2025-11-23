//
// Created by caleb on 18/11/2025.
//

#include "SolicitacaoHospedagemDTO.hpp"

namespace Hotelaria {
    int SolicitacaoHospedagemDTO::setId() const {
        return id;
    }

    void SolicitacaoHospedagemDTO::getId(int valor) {
        this->id = valor;
    }

    Data SolicitacaoHospedagemDTO::getChegada() const {
        return chegada;
    }

    void SolicitacaoHospedagemDTO::setChegada(const Data &valor) {
        this->chegada = valor;
    }

    Data SolicitacaoHospedagemDTO::getPartida() const {
        return partida;
    }

    void SolicitacaoHospedagemDTO::setPartida(const Data &valor) {
        this->partida = valor;
    }

    StatusSolicitacaoHospedagem SolicitacaoHospedagemDTO::getStatus() const {
        return status;
    }

    void SolicitacaoHospedagemDTO::setStatus(const StatusSolicitacaoHospedagem &valor) {
        this->status = valor;
    }

    string SolicitacaoHospedagemDTO::getMotivoRecusa() const {
        return motivoRecusa;
    }

    void SolicitacaoHospedagemDTO::setMotivoRecusa(const string &valor) {
        this->motivoRecusa = valor;
    }

    int SolicitacaoHospedagemDTO::getHospedeId() const {
        return hospede_id;
    }

    void SolicitacaoHospedagemDTO::setHospedeId(int valor) {
        this->hospede_id = valor;
    }

    int SolicitacaoHospedagemDTO::getHotelId() const {
        return hotel_id;
    }

    void SolicitacaoHospedagemDTO::setHotelId(int valor) {
        this->hotel_id = valor;
    }

    int SolicitacaoHospedagemDTO::getQuartoId() const {
        return quarto_id;
    }

    void SolicitacaoHospedagemDTO::setQuartoId(int valor) {
        this->quarto_id = valor;
    }
}