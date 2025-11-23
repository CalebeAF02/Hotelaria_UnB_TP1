//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoHospede.hpp"

#include "SistemaSessao.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoHospede::setControladoraServicoHospede(
        InterfaceServicoHospede *servico) {
        this->servico = servico;
    }

    void ControladoraApresentacaoHospede::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Hospede");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Hospedes");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Hospede (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Hospede (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Hospedes (CRUD)");

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
    };

    bool ControladoraApresentacaoHospede::criar() {
        bool criado = false;
        bool tudoOK = true;

        while (!criado) {
            Hospede hospede;

            Formato::TituloEmCaixa("Criando Novo Hospede");

            IO::Print("Informe o Nome: ");
            string nomeStr = IO::LerLinha();
            try {
                hospede.setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                IO::Println(erro.what());
                tudoOK = false;
                break;
            }
            if (tudoOK) {
                IO::Print("Informe o Email: ");
                string emailStr = IO::LerLinha();
                try {
                    hospede.setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Endereco: ");
                string enderecoStr = IO::LerLinha();
                try {
                    hospede.setEndereco(Endereco(enderecoStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Cartao: ");
                string cartaoStr = IO::LerLinha();
                try {
                    hospede.setCartao(Cartao(cartaoStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                bool sucesso = servico->criar(hospede);

                if (sucesso) IO::Println("Hospede Cadastrado com Sucesso!");
                else IO::Println("Falha ao cadastrar (Erro de Servico/Banco).");

                criado = sucesso;
            }
        }
        return criado;
    }

    void ControladoraApresentacaoHospede::listar() {
        vector<HospedeDTO> lista = servico->listarTodos();

        if (lista.empty()) {
            IO::Println("Nenhum hospede cadastrado.");
            return;
        }
        Tabela tab;

        for (const HospedeDTO &item: lista) {
            Linha *objLinha = tab.criarObj();

            objLinha->atributo("id", item.getId());
            objLinha->atributo("Nome", item.getNome());
            objLinha->atributo("Email", item.getEmail());
            objLinha->atributo("Endereco", item.getEndereco());
        }
        tab.exibirTabela("Lista De Hoespedes");
    };

    void ControladoraApresentacaoHospede::atualizar() {
        IO::Print("Informe o Id do Gerente: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id inválido");
            return;
        }

        int id = stoi(idStr);
        optional<HospedeDTO> dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Hospede não encontrado.");
            return;
        }

        Tabela tab;
        Linha *obj = tab.criarObj();
        obj->atributo("Id", dto->getId());
        obj->atributo("Nome", dto->getNome());
        obj->atributo("Email", dto->getEmail());
        obj->atributo("Endereco", dto->getEndereco());
        tab.exibirTabela("Hospede Atual");

        Hospede hospede(*dto);
        bool alterado = false;

        Menu menu;
        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar");
        const int OPCAO_ALTERAR_NOME = menu.adcionarItens("Alterar Nome");
        const int OPCAO_ALTERAR_EMAIL = menu.adcionarItens("Alterar Email");
        const int OPCAO_ALTERAR_ENDERECO = menu.adcionarItens("Alterar Endereco");
        const int OPCAO_ALTERAR_CARTAO = menu.adcionarItens("Alterar Cartao");

        int opcao = menu.executa("Atualizacao de Cadastro");

        if (opcao == OPCAO_ALTERAR_NOME) {
            IO::Print("Novo Nome: ");
            string v = IO::LerLinha();
            try {
                hospede.setNome(Nome(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_EMAIL) {
            IO::Print("Novo Email: ");
            string v = IO::LerLinha();
            try {
                hospede.setEmail(Email(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_ENDERECO) {
            IO::Print("Novo Endereco: ");
            string v = IO::LerLinha();
            try {
                hospede.setEndereco(Endereco(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_ALTERAR_CARTAO) {
            IO::Print("Nova Cartao: ");
            string v = IO::LerLinha();
            try {
                hospede.setCartao(Cartao(v));
                alterado = true;
            } catch (invalid_argument &e) { IO::Println(e.what()); }
        } else if (opcao == OPCAO_VOLTAR) {
            IO::Println("Atualizacao cancelada.");
            return;
        } else {
            IO::Println("Opcao invalida.");
        }

        bool ok = servico->editar(Email(dto->getEmail()), hospede);
        IO::Println(ok ? "Cadastro atualizado com sucesso!" : "Erro ao atualizar cadastro.");
    };

    void ControladoraApresentacaoHospede::remover() {
        IO::Print("Informe o Id do Hospede: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id inválido");
            return;
        }

        int id = stoi(idStr);

        auto dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Hospede não encontrado.");
            return;
        }

        Tabela tab;
        Linha *obj = tab.criarObj();
        obj->atributo("Id", dto->getId());
        obj->atributo("Nome", dto->getNome());
        obj->atributo("Email", dto->getEmail());
        obj->atributo("Endereco", dto->getEndereco());
        tab.exibirTabela("Hospede a Remover");

        bool ok = servico->remover(id);
        IO::Println(ok ? "Hospede excluído com sucesso!" : "Erro ao excluir hospede.");
    };
}