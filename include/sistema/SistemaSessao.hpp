//
// Created by caleb on 22/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_SISTEMASESSAO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_SISTEMASESSAO_HPP

#include "InterfaceApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoGerente.hpp"
#include "InterfaceApresentacaoAcessoHospede.hpp"
#include "InterfaceApresentacaoHospede.hpp"
#include "InterfaceApresentacaoHotel.hpp"
#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceApresentacaoReserva.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"

namespace Hotelaria {
    class SistemaSessao {
    private:
        InterfaceApresentacaoAcessoGerente *apresentacao_acesso_gerente;
        InterfaceApresentacaoAcessoHospede *apresentacao_acesso_hospede;

        InterfaceApresentacaoAutenticavel *apresentacao_autenticavel;

        InterfaceApresentacaoGerente *apresentacao_gerente;
        InterfaceApresentacaoHospede *apresentacao_hospede;
        InterfaceApresentacaoHotel *apresentacao_hotel;
        InterfaceApresentacaoQuarto *apresentacao_quarto;
        InterfaceApresentacaoReserva *apresentacao_reserva;
        //InterfaceapresentacaoSolicitacaoHospedagem *apresentacao_solicitacao_hospedagem;

        int gerente_id;
        int hotel_id;

        SistemaSessao() : gerente_id(-1) {
        }

        SistemaSessao(const SistemaSessao &) = delete;

        SistemaSessao &operator=(const SistemaSessao &) = delete;

    public:
        static SistemaSessao &getInstance();

        void setGerenteId(int id);

        int getGerenteId() const;

        void setHotelId(int id);

        int getHoteleId() const;

        void setControladoraApresentacaoAcessoGerente(InterfaceApresentacaoAcessoGerente *apresentacao_acesso_gerente);

        void setControladoraApresentacaoAcessoHospede(InterfaceApresentacaoAcessoHospede *apresentacao_acesso_hospede);

        void setControladoraApresentacao(InterfaceApresentacaoAutenticavel *apresentacao_autenticavel);

        void setControladoraApresentacao(InterfaceApresentacaoGerente *apresentacao_gerente);

        void setControladoraApresentacao(InterfaceApresentacaoHospede *apresentacao_hospede);

        void setControladoraApresentacao(InterfaceApresentacaoHotel *apresentacao_hotel);

        void setControladoraApresentacao(InterfaceApresentacaoQuarto *apresentacao_quarto);

        void setControladoraApresentacao(InterfaceApresentacaoReserva *apresentacao_reserva);

        InterfaceApresentacaoAcessoGerente *getControladoraApresentacaoAcessoGerente();

        InterfaceApresentacaoAcessoHospede *getControladoraApresentacaoAcessoHospede();

        InterfaceApresentacaoAutenticavel *getControladoraApresentacaoAutenticavel();

        InterfaceApresentacaoGerente *getControladoraApresentacaoGerente();

        InterfaceApresentacaoHospede *getControladoraApresentacaoHospede();

        InterfaceApresentacaoHotel *getControladoraApresentacaoHotel();

        InterfaceApresentacaoQuarto *getControladoraApresentacaoQuarto();

        InterfaceApresentacaoReserva *getControladoraApresentacaoReserva();
    };
}

#endif