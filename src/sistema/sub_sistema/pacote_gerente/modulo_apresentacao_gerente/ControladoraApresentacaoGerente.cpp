//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoGerente.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoGerente::setControladoraServicoGerente(InterfaceServicoGerente *servico) {
        this->servico = servico;
    }

    // --- EXECUÇÃO PRINCIPAL (MENU CRUD) ---
    void ControladoraApresentacaoGerente::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Gerente");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Gerentes");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Gerente (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Gerente (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Gerentes (CRUD)");

            if (opcao == OPCAO_VOLTAR) {
                executando = false;
                IO::Println("Voltando ao menu de acesso.");
            } else if (opcao == OPCAO_CRIAR) {
                criar();
            } else if (opcao == OPCAO_LISTAR) {
                listar();
            } else if (opcao == OPCAO_ATUALIZAR) {
                atualizar();
            } else if (opcao == OPCAO_REMOVER) {
                remover();
            } else {
                IO::Println("Opcao Invalida! Tente novamente.");
            }
        }
    }

    bool ControladoraApresentacaoGerente::criar() {
        bool criado = false;

        while (!criado) {
            bool tudoOK = true;
            Gerente gerente;

            Formato::TituloEmCaixa("Criando Novo Gerente");

            IO::Print("Informe o Nome: ");
            string nomeStr = IO::LerLinha();
            try {
                gerente.setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                IO::Println(erro.what());
                tudoOK = false;
                break;
            }
            if (tudoOK) {
                IO::Print("Informe o Email: ");
                string emailStr = IO::LerLinha();
                try {
                    gerente.setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Ramal: ");
                string ramalStr = IO::LerLinha();
                try {
                    gerente.setRamal(Ramal(ramalStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Senha: ");
                string senhaStr = IO::LerLinha();
                try {
                    gerente.setSenha(Senha(senhaStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                bool sucesso = servico->criar(gerente);

                if (sucesso) IO::Println("Gerente Cadastrado com Sucesso!");
                else IO::Println("Falha ao cadastrar (Erro de Servico/Banco).");

                criado = sucesso;
            }
        }
        return criado;
    }

    void ControladoraApresentacaoGerente::listar() {
        vector<GerenteDTO> lista = servico->listarTodos();

        if (lista.empty()) {
            IO::Println("Nenhum gerente cadastrado.");
            return;
        }
        Tabela tab;

        for (const GerenteDTO &item: lista) {
            Linha *objLinha = tab.criarObj();

            objLinha->atributo("id", item.getId());
            objLinha->atributo("Nome", item.getNome());
            objLinha->atributo("Email", item.getEmail());
            objLinha->atributo("Ramal", item.getRamal());
        }
        tab.exibirTabela("Lista De Gerentes");
    }

    void ControladoraApresentacaoGerente::atualizar() {
        IO::Print("Informe o Id do Gerente: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id inválido");
            return;
        }

        int id = stoi(idStr);
        optional<GerenteDTO> dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Gerente não encontrado.");
            return;
        }

        Tabela tab;
        Linha *obj = tab.criarObj();
        obj->atributo("Id", dto->getId());
        obj->atributo("Nome", dto->getNome());
        obj->atributo("Email", dto->getEmail());
        obj->atributo("Ramal", dto->getRamal());
        tab.exibirTabela("Gerente Atual");

        Gerente gerente(*dto);
        bool alterado = false;

        Menu menu;
        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar");
        const int OPCAO_ALTERAR_NOME = menu.adcionarItens("Alterar Nome");
        const int OPCAO_ALTERAR_EMAIL = menu.adcionarItens("Alterar Email");
        const int OPCAO_ALTERAR_RAMAL = menu.adcionarItens("Alterar Ramal");
        const int OPCAO_ALTERAR_SENHA = menu.adcionarItens("Alterar Senha");

        int opcao = menu.executa("Atualizacao de Cadastro");

        if (opcao == OPCAO_ALTERAR_NOME) {
            IO::Print("Novo Nome: ");
            string v = IO::LerLinha();
            try {
                gerente.setNome(Nome(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_EMAIL) {
            IO::Print("Novo Email: ");
            string v = IO::LerLinha();
            try {
                gerente.setEmail(Email(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_RAMAL) {
            IO::Print("Novo Ramal: ");
            string v = IO::LerLinha();
            try {
                gerente.setRamal(Ramal(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_SENHA) {
            IO::Print("Nova Senha: ");
            string v = IO::LerLinha();
            try {
                gerente.setSenha(Senha(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_VOLTAR) {
            IO::Println("Atualizacao cancelada.");
            return;
        } else {
            IO::Println("Opcao invalida.");
        }

        bool ok = servico->editar(Email(dto->getEmail()), gerente);
        IO::Println(ok ? "Cadastro atualizado com sucesso!" : "Erro ao atualizar cadastro.");
    }

    void ControladoraApresentacaoGerente::remover() {
        IO::Print("Informe o Id do Gerente: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id inválido");
            return;
        }

        int id = stoi(idStr);

        auto dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Gerente não encontrado.");
            return;
        }

        Tabela tab;
        Linha *obj = tab.criarObj();
        obj->atributo("Id", dto->getId());
        obj->atributo("Nome", dto->getNome());
        obj->atributo("Email", dto->getEmail());
        obj->atributo("Ramal", dto->getRamal());
        tab.exibirTabela("Gerente a Remover");

        bool ok = servico->remover(id);
        IO::Println(ok ? "Gerente excluído com sucesso!" : "Erro ao excluir gerente.");
    }

    void ControladoraApresentacaoGerente::avaliarSolicitacoes() {
        /*
        Formato::TituloEmCaixa("Avaliar Solicitacoes de Hospedagem");

        auto pendentes = ControladoraPersistenciaSolicitacaoHospedagem::buscarPorStatus(0); // status = pendente

        if (pendentes.empty()) {
            IO::Println("Nenhuma solicitacao pendente.");
            return;
        }

        for (auto &solicitacao: pendentes) {
            IO::Println("Hospede: " + solicitacao.getHospedeId());
            IO::Println("Hotel: " + solicitacao.getHotelId());
            IO::Println("Quarto: " + solicitacao.getId());
            IO::Println("Chegada: " + solicitacao.getChegada().toString());
            IO::Println("Partida: " + solicitacao.getPartida().toString());
            IO::Println("Status atual: Pendente");

            IO::Println("Deseja aprovar (A) ou recusar (R) esta solicitacao?");
            string escolha = IO::LerOpcao();

            if (escolha == "A" || escolha == "a") {
                solicitacao.setStatus(StatusSolicitacaoHospedagem::APROVADO); // aprovada
                solicitacao.setMotivoRecusa(""); // limpa motivo
                ControladoraPersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
                IO::Println("Solicitacao aprovada com sucesso.");
            } else if (escolha == "R" || escolha == "r") {
                IO::Println("Informe o motivo da recusa:");
                string motivo = IO::LerLinha();
                solicitacao.setStatus(StatusSolicitacaoHospedagem::RECUSADO); // recusada
                solicitacao.setMotivoRecusa(motivo);
                ControladoraPersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
                IO::Println("Solicitacao recusada.");
            } else {
                IO::Println("Opcao invalida. Solicitacao nao foi alterada.");
            }
        }
        */
    }
}