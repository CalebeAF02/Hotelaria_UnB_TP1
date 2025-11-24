//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoReserva.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoReserva::setControladoraServicoReserva(InterfaceServicoReserva *servico) {
        this->servico = servico;
    }

    void ControladoraApresentacaoReserva::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Nova Reserva");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todas as Reservas");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Reserva (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Reserva (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Reservas (CRUD)");

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

    void ControladoraApresentacaoReserva::criar() {
        Formato::TituloEmCaixa("Criando Reserva");

        IO::Print("Email do Hospede: ");
        string emailHospede = IO::LerLinha();

        IO::Print("Quarto ID: ");
        string quartoIdStr = IO::LerLinha();

        IO::Print("Chegada (dd/mm/aaaa): ");
        string chegadaStr = IO::LerLinha();

        IO::Print("Partida (dd/mm/aaaa): ");
        string partidaStr = IO::LerLinha();

        IO::Print("Valor (inteiro): ");
        string dinheiroStr = IO::LerLinha();

        try {
            if (!Utils::verificaSeENumero(quartoIdStr) || !Utils::verificaSeENumero(dinheiroStr)) {
                IO::Println("Erro: QuartoID e Dinheiro devem ser numeros inteiros.");
                return;
            }

            Data chegada(chegadaStr);
            Data partida(partidaStr);
            Dinheiro money(stoi(dinheiroStr));

            // Gera um timestamp e corta para 7 dígitos
            string base = to_string(time(nullptr)).substr(0, 7);

            // Prefixa com "RES" → total = 10 caracteres
            string codigoGerado = "RES" + base; // "RES1234567"
            Codigo codigo(codigoGerado);
            Reserva reserva(chegada, partida, money, codigo);

            // Persistir: como a tabela não armazena o email nem o codigo na entidade,
            // o email deve ser repassado na persistencia. Alternativa: adicionar coluna 'codigo' na tabela.
            // Aqui, mantemos o design atual: inserir a reserva (sem quarto_id) e orientar a criar via banco.
            bool ok = servico->criar(reserva);
            IO::Println(ok ? "Reserva registrada." : "Erro: Falha ao registrar reserva.");
        } catch (invalid_argument &e) {
            IO::Println(string("Erro: ") + e.what());
        }
    }

    void ControladoraApresentacaoReserva::listar() {
        vector<ReservaDTO> lista = servico->listarTodos();
        if (lista.empty()) {
            IO::Println("Nenhuma reserva encontrada para o hotel atual.");
            return;
        }
        Tabela tab;
        for (const ReservaDTO &r: lista) {
            Linha *ln = tab.criarObj();
            ln->atributo("Id", r.getId());
            ln->atributo("Chegada", r.getChegada());
            ln->atributo("Partida", r.getPartida());
            ln->atributo("Dinheiro", r.getDinheiro());
            ln->atributo("QuartoID", r.getQuartoId());
        }
        tab.exibirTabela("Reservas");
    }

    void ControladoraApresentacaoReserva::atualizar() {
        IO::Print("Id da Reserva: ");
        string idStr = IO::LerLinha();
        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id invalido.");
            return;
        }

        int id = stoi(idStr);
        auto dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Reserva não encontrada.");
            return;
        }

        Tabela t;
        Linha *ln = t.criarObj();
        ln->atributo("Id", dto->getId());
        ln->atributo("Chegada", dto->getChegada());
        ln->atributo("Partida", dto->getPartida());
        ln->atributo("Dinheiro", dto->getDinheiro());
        ln->atributo("QuartoID", dto->getQuartoId());
        t.exibirTabela("Reserva Atual");

        IO::Print("Nova Chegada (dd/mm/aaaa): ");
        string chegadaStr = IO::LerLinha();
        IO::Print("Nova Partida (dd/mm/aaaa): ");
        string partidaStr = IO::LerLinha();
        IO::Print("Novo Valor (inteiro): ");
        string dinheiroStr = IO::LerLinha();

        try {
            Data chegada(chegadaStr);
            Data partida(partidaStr);
            Dinheiro money(stoi(dinheiroStr));
            // Mantemos o código existente (não persistido)
            string codigoGerado = "EDIT" + to_string(time(nullptr)).substr(0, 6);
            // "EDIT123456" → 10 caracteres
            Codigo codigo(codigoGerado);

            Reserva reserva(chegada, partida, money, codigo);
            bool ok = servico->editar(id, reserva);
            IO::Println(ok ? "Reserva atualizada." : "Falha ao atualizar reserva.");
        } catch (invalid_argument &e) {
            IO::Println(string("Erro: ") + e.what());
        }
    };

    void ControladoraApresentacaoReserva::remover() {
        IO::Print("Id da Reserva: ");
        string idStr = IO::LerLinha();
        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id invalido.");
            return;
        }
        int id = stoi(idStr);
        bool ok = servico->remover(id);
        IO::Println(ok ? "Reserva removida." : "Falha ao remover reserva.");
    }
}