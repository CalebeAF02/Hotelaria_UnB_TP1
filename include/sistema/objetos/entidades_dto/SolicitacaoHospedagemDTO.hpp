//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP

#include "Data.hpp"
#include "StatusSolicitacaoHospedagem.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    class SolicitacaoHospedagemDTO {
    private:
        int id;
        Data chegada;
        Data partida;
        StatusSolicitacaoHospedagem status;
        string motivoRecusa;
        int hospede_id;
        int hotel_id;
        int quarto_id;

    public:
        SolicitacaoHospedagemDTO() = default;

        SolicitacaoHospedagemDTO(int id, Data chegada, Data partida,
                                 StatusSolicitacaoHospedagem (status), string motivoRecusa, int hospede_id,
                                 int hotel_id, int quarto_id) : id(id),
                                                                chegada(chegada), partida(partida), status(status),
                                                                motivoRecusa(motivoRecusa), hospede_id(hospede_id),
                                                                hotel_id(hotel_id), quarto_id(quarto_id) {
        };

        int setId() const;

        void getId(int valor);

        Data getChegada() const;

        void setChegada(const Data &valor);

        Data getPartida() const;

        void setPartida(const Data &valor);

        StatusSolicitacaoHospedagem getStatus() const;

        void setStatus(const StatusSolicitacaoHospedagem &valor);

        string getMotivoRecusa() const;

        void setMotivoRecusa(const string &valor);

        int getHospedeId() const;

        void setHospedeId(int valor);

        int getHotelId() const;

        void setHotelId(int valor);

        int getQuartoId() const;

        void setQuartoId(int valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP