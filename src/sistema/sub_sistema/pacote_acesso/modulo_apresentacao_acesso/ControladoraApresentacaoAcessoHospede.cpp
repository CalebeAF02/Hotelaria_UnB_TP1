//
// Created by caleb on 15/11/2025.
//

#include "ControladoraApresentacaoAcessoHospede.hpp"

#include "InterfaceApresentacaoHospede.hpp"

namespace Hotelaria {

    void ControladoraApresentacaoAcessoHospede::exibirMenu() {
        bool executando = true;

        Menu menu;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_HOSPEDAGENS = menu.adcionarItens("Opcoes de Hospedagem");
        const int OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Criar Solicitacao de Hospedagem");
        const int OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Status da Solicitacao de Hospedagem");

        while (executando) {
            int opcao = menu.executa("Faca o acesso para liberar os servicos");

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                executando = false;
                IO::Println("Voltando a selecao de usuario!");
            } else if (opcao == OPCAO_HOSPEDAGENS) {
                opcoesDeHospedagem();
            } else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM) {
                solicitandoHospedagem();
            } else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM) {
                statusDaSolicitandoHospedagem();
            } else {
                IO::Println("Opcao Invalida!");
            }
        }
    };

    void ControladoraApresentacaoAcessoHospede::opcoesDeHospedagem() {
        bool executando = true;

        Formato::TituloEmCaixa("Opcoes de Hospedagem");
        IO::Println("Esta opcao ainda nao foi construida! Retornando...");
    }

    void ControladoraApresentacaoAcessoHospede::solicitandoHospedagem() {
        bool executando = true;

        while (executando) {
            Formato::TituloEmCaixa("Criar Solicitacao de Hospedagem");

            IO::Print("Informe o Email: ");
            string email = IO::LerLinha();

            IO::Print("Codigo do hotel desejado: ");
            string idHotel = IO::LerLinha();

            IO::Print("Codigo do quarto desejado: ");
            string idQuarto = IO::LerLinha();

            IO::Print("Data de chegada (dd/mm/aaaa): ");
            string chegadaStr = IO::LerLinha();

            IO::Print("Data de partida (dd/mm/aaaa): ");
            string partidaStr = IO::LerLinha();

            IO::Println(idHotel.length() + " e " + idQuarto.length());
            try {
                Data chegada(chegadaStr);
                Data partida(partidaStr);

                SolicitacaoHospedagem solicitacao(
                    stoi(email),
                    stoi(idHotel),
                    stoi(idQuarto),
                    chegada,
                    partida,
                    StatusSolicitacaoHospedagem::PENDENTE,
                    ""
                );

                ControladoraPersistenciaSolicitacaoHospedagem::salvar(solicitacao);
                IO::Println("Solicitacao registrada com sucesso!");
            } catch (exception &e) {
                IO::Println("Erro ao criar solicitacao: " + string(e.what()));
            }
            if (IO::tentarNovamente()) {
                break;
            }
        }
    }

    void ControladoraApresentacaoAcessoHospede::statusDaSolicitandoHospedagem() const {
        Formato::TituloEmCaixa("Status da Solicitacao de Hospedagem");

        IO::Print("Informe o Email: ");
        string email = IO::LerLinha();

        const vector<SolicitacaoHospedagem> lista =
                ControladoraPersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

        if (lista.empty()) {
            IO::Println("Nenhuma solicitacao encontrada.");
            return;
        }

        for (const SolicitacaoHospedagem &s: lista) {
            string statusStr = (s.getStatus() == StatusSolicitacaoHospedagem::PENDENTE)
                                   ? "Pendente"
                                   : (s.getStatus() == StatusSolicitacaoHospedagem::APROVADO)
                                         ? "Aprovada"
                                         : "Recusada";

            IO::Println("Hotel: " + s.getHotelId());
            IO::Println("Quarto: " + s.getQuartoId());
            IO::Println("Chegada: " + s.getChegada().toString());
            IO::Println("Partida: " + s.getPartida().toString());
            IO::Println("Status: " + statusStr);

            if (s.getStatus() == StatusSolicitacaoHospedagem::RECUSADO)
                cout << "\n | Motivo: " << s.getMotivoRecusa();
        }
    }
}