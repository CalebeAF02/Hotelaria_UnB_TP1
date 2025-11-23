//
// Created by caleb on 22/11/2025.
//

#include "../../include/sistema/SistemaSessao.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    static SistemaSessao *instancia;
    static bool iniciado = false;

    SistemaSessao &SistemaSessao::getInstance() {
        if (!iniciado) {
            //IO::Println("Criando sessao");
            instancia = new SistemaSessao();
            iniciado = true;
        } else {
            //IO::Println("Reutilizando sessao");
        }
        return *instancia;
    }

    void SistemaSessao::setGerenteId(int id) {
        gerente_id = id;
    }

    int SistemaSessao::getGerenteId() const {
        return gerente_id;
    }

    void SistemaSessao::setHotelId(int id) {
        hotel_id = id;
    }

    int SistemaSessao::getHoteleId() const {
        return hotel_id;
    }

    void SistemaSessao::setControladoraApresentacaoAcessoGerente(
        InterfaceApresentacaoAcessoGerente *apresentacao_acesso) {
        this->apresentacao_acesso_gerente = apresentacao_acesso;
    }

    void SistemaSessao::setControladoraApresentacaoAcessoHospede(
        InterfaceApresentacaoAcessoHospede *apresentacao_acesso) {
        this->apresentacao_acesso_hospede = apresentacao_acesso;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoAutenticavel *apresentacao_autenticavel) {
        this->apresentacao_autenticavel = apresentacao_autenticavel;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoGerente *apresentacao_gerente) {
        this->apresentacao_gerente = apresentacao_gerente;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoHospede *apresentacao_hospede) {
        this->apresentacao_hospede = apresentacao_hospede;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoHotel *apresentacao_hotel) {
        this->apresentacao_hotel = apresentacao_hotel;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoQuarto *apresentacao_quarto) {
        this->apresentacao_quarto = apresentacao_quarto;
    }

    void SistemaSessao::setControladoraApresentacao(
        InterfaceApresentacaoReserva *apresentacao_reserva) {
        this->apresentacao_reserva = apresentacao_reserva;
    }


    InterfaceApresentacaoAcessoGerente *SistemaSessao::getControladoraApresentacaoAcessoGerente() {
        return apresentacao_acesso_gerente;
    }

    InterfaceApresentacaoAcessoHospede *SistemaSessao::getControladoraApresentacaoAcessoHospede() {
        return apresentacao_acesso_hospede;
    }

    InterfaceApresentacaoAutenticavel *SistemaSessao::getControladoraApresentacaoAutenticavel() {
        return apresentacao_autenticavel;
    }

    InterfaceApresentacaoGerente *SistemaSessao::getControladoraApresentacaoGerente() {
        return apresentacao_gerente;
    }

    InterfaceApresentacaoHospede *SistemaSessao::getControladoraApresentacaoHospede() {
        return apresentacao_hospede;
    }

    InterfaceApresentacaoHotel *SistemaSessao::getControladoraApresentacaoHotel() {
        return apresentacao_hotel;
    }

    InterfaceApresentacaoQuarto *SistemaSessao::getControladoraApresentacaoQuarto() {
        return apresentacao_quarto;
    }

    InterfaceApresentacaoReserva *SistemaSessao::getControladoraApresentacaoReserva() {
        return apresentacao_reserva;
    }
}