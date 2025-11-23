//
// Created by caleb on 15/11/2025.
//
#include "ControladoraApresentacaoAcessoGerente.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoAcessoGerente::exibirMenu() {
        bool executando = true;

        Menu menu;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
        const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

        SistemaSessao &sessao = SistemaSessao::getInstance();

        while (executando) {
            int opcao = menu.executa("Faca o acesso para liberar os servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                executando = false;
                IO::Println("Voltando a selecao de usuario!");
            } else if (opcao == OPCAO_CRIAR_UM_GERENTE) {
                sessao.getControladoraApresentacaoGerente()->criar();
            } else if (opcao == OPCAO_FAZER_LOGIN) {
                if (sessao.getControladoraApresentacaoAutenticavel()->autenticar()) {
                    this->estaAutenticado = true;
                }
                if (this->estaAutenticado) {
                    SistemaSessao &sessao = SistemaSessao::getInstance();

                    int gerente = sessao.getGerenteId();

                    if (gerente) {
                        sessao.setGerenteId(gerente);
                    }
                    IO::Println("Agora Voce Possui Super-Poderes");
                    exibirMenuGerenciador();
                }
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    }

    void ControladoraApresentacaoAcessoGerente::exibirMenuGerenciador() {
        Menu menu;
        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
        const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
        const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
        //const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
        const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
        const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

        SistemaSessao &sessao = SistemaSessao::getInstance();

        while (estaAutenticado) {
            int opcao = menu.executa("Seja bem vindo a central de servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                this->estaAutenticado = false;
                IO::Println("Voce Saiu da Central de servicos e foi deslogado!");
            } else if (opcao == OPCAO_GERENCIE_GERENTES) {
                sessao.getControladoraApresentacaoGerente()->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
                sessao.getControladoraApresentacaoHospede()->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
                sessao.getControladoraApresentacaoHotel()->exibirMenuCRUD();
                //} else if (opcao == OPCAO_GERENCIE_QUARTOS) {
                //apresentacao_hotel->listar();
                //apresentacao_quarto->exibirMenuCRUD();
            } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
                sessao.getControladoraApresentacaoReserva()->exibirMenuCRUD();
            } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
                //interface_apresentacao_solicitacao_hospedagem->exibirMenuCRUD();
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    }


    void ControladoraApresentacaoAcessoGerente::autenticarHacker() {
        this->estaAutenticado = true;
    }
}