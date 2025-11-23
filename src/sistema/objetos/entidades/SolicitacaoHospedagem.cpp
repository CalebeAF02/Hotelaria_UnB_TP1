//
// Created by caleb on 26/10/2025.
//

#include "SolicitacaoHospedagem.hpp"

namespace Hotelaria {
    SolicitacaoHospedagem::SolicitacaoHospedagem(
        const Data &chegada,
        const Data &partida,
        const StatusSolicitacaoHospedagem status,
        const string &motivoRecusa,
        const int &hospedeId,
        const int &hotelId,
        const int &quartoId
    ) {
        setChegada(chegada);
        setPartida(partida);
        setStatus(status);
        setMotivoRecusa(motivoRecusa);
        setHospedeId(hospedeId);
        setHotelId(hotelId);
        setQuartoId(quartoId);
    }

    SolicitacaoHospedagem::SolicitacaoHospedagem(SolicitacaoHospedagemDTO &solicitacao_hospedagem_dto) {
        setChegada(Data(solicitacao_hospedagem_dto.getChegada()));
        setPartida(Data(solicitacao_hospedagem_dto.getPartida()));
        setStatus(StatusSolicitacaoHospedagem(solicitacao_hospedagem_dto.getStatus()));

        setMotivoRecusa(solicitacao_hospedagem_dto.getMotivoRecusa());

        setHospedeId(solicitacao_hospedagem_dto.getHospedeId());
        setHotelId(solicitacao_hospedagem_dto.getHotelId());
        setQuartoId(solicitacao_hospedagem_dto.getQuartoId());
    };

    void SolicitacaoHospedagem::setHospedeId(const int &valor) {
        hospedeId = valor;
    }

    void SolicitacaoHospedagem::setHotelId(const int &valor) {
        hotelId = valor;
    }

    void SolicitacaoHospedagem::setQuartoId(const int &valor) {
        quartoId = valor;
    }

    void SolicitacaoHospedagem::setChegada(const Data &valor) {
        chegada = valor;
    }

    void SolicitacaoHospedagem::setPartida(const Data &valor) {
        partida = valor;
    }

    void SolicitacaoHospedagem::setStatus(StatusSolicitacaoHospedagem valor) {
        this->status = valor;
    }

    void SolicitacaoHospedagem::setMotivoRecusa(const string &motivo) {
        motivoRecusa = motivo;
    }

    int SolicitacaoHospedagem::getHospedeId() const {
        return hospedeId;
    }

    int SolicitacaoHospedagem::getHotelId() const {
        return hotelId;
    }

    int SolicitacaoHospedagem::getQuartoId() const {
        return quartoId;
    }

    Data SolicitacaoHospedagem::getChegada() const {
        return chegada;
    }

    Data SolicitacaoHospedagem::getPartida() const {
        return partida;
    }

    StatusSolicitacaoHospedagem SolicitacaoHospedagem::getStatus() const {
        return status;
    }

    string SolicitacaoHospedagem::getMotivoRecusa() const {
        return motivoRecusa;
    }
}