//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoQuarto.hpp"

#include "ControladoraServicoHotel.hpp"
#include "SistemaSessao.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoQuarto::setControladoraServicoQuarto(
        InterfaceServicoQuarto *servico) {
        this->servico = servico;
    }

    void ControladoraApresentacaoQuarto::exibirMenuCRUD() {
        SistemaSessao &sessao = SistemaSessao::getInstance();

        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Quarto");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Quartos");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Quarto (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Quarto (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Quartos (CRUD)");

            if (opcao == OPCAO_VOLTAR) {
                executando = false;
                IO::Println("Voltando ao menu de acesso.");
            } else if (opcao == OPCAO_CRIAR) {
                criar(sessao.getGerenteId(), sessao.getHoteleId());
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

    bool ControladoraApresentacaoQuarto::criar(int gerente_id, int hotel_id) {
        bool criado = false;

        /*
        if (servico->getQuantidadeDeQuartosDoHotel( hotel_id) >= Sistema::MAXIMO_QUARTOS_POR_HOTEL) {
            IO::Println("Erro: O Hotel so pode ter no maximo {1} quartos cadastrados !",Sistema::MAXIMO_QUARTOS_POR_HOTEL);
            return false;
        }*/

        while (!criado) {
            Quarto *criando = new Quarto();
            criando->setHotelID(hotel_id);

            bool tudoOK = true;

            Formato::TituloEmCaixa("Criando Novo Quarto");

            IO::Print("Informe o Numero: ");
            string numeroStr = IO::LerLinha();
            try {
                criando->setNumero(Numero(numeroStr));
            } catch (invalid_argument &erro) {
                IO::Println(erro.what());
                tudoOK = false;
                break;
            }
            if (tudoOK) {
                IO::Print("Informe o Capacidade: ");
                string capacidadeStr = IO::LerLinha();

                if (Utils::verificaSeENumero(capacidadeStr)) {
                    try {
                        criando->setCapacidade(Capacidade(stoi(capacidadeStr)));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                } else {
                    IO::Println("A Capacidade deve ser um numero inteiro");
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Dinheiro: ");
                string dinheiroStr = IO::LerLinha();
                if (Utils::verificaSeENumero(dinheiroStr)) {
                    try {
                        criando->setDiaria(Dinheiro(stoi(dinheiroStr)));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                } else {
                    IO::Println("O Dinheiro deve ser um numero inteiro");
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Ramal: ");
                string ramalStr = IO::LerLinha();
                try {
                    criando->setRamal(Ramal(ramalStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
            }
            if (tudoOK) {
                bool sucesso = servico->criar(*criando);

                if (sucesso) IO::Println("Quarto Cadastrado com Sucesso!");
                else IO::Println("Falha ao cadastrar (Erro de Servico/Banco).");

                criado = sucesso;
            }
        }
        return criado;
    };

    void ControladoraApresentacaoQuarto::listar() {
        vector<QuartoDTO> lista = servico->listarTodos();

        if (lista.empty()) {
            IO::Println("Nenhum quarto cadastrado.");
        }
        Tabela tab;

        for (QuartoDTO item: lista) {
            Linha *objLinha = tab.criarObj();

            objLinha->atributo("id", item.getId());
            objLinha->atributo("Numero", item.getNumero());
            objLinha->atributo("Capacidade", item.getCapacidade());
            objLinha->atributo("Dinheiro", item.getDinheiro());
            objLinha->atributo("Ramal", item.getRamal());
            objLinha->atributo("HotelID", item.getHotelId());
        }

        tab.exibirTabela("Lista De Quartos");
    };

    void ControladoraApresentacaoQuarto::atualizar() {
        IO::Print("Informe o Id do quarto: ");
        string quarto_id = IO::LerLinha();

        if (verificaSeENumero(quarto_id)) {
            bool alterado = false;

            int id_numero = stoi(quarto_id);
            optional<QuartoDTO> existe_quarto = servico->pesquisar(id_numero);

            if (existe_quarto.has_value()) {
                Tabela tab;

                Linha *objLinha = tab.criarObj();

                objLinha->atributo("Id", existe_quarto->getId());
                objLinha->atributo("Numero", existe_quarto->getNumero());
                objLinha->atributo("Capacidade", existe_quarto->getCapacidade());
                objLinha->atributo("Dinheiro", existe_quarto->getDinheiro());
                objLinha->atributo("Ramal", existe_quarto->getRamal());
                objLinha->atributo("HotelID", existe_quarto->getHotelId());


                tab.exibirTabela("Lista De Quartos");

                Quarto quarto(*existe_quarto);

                Menu menu;

                const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
                const int OPCAO_ALTERAR_NUMERO = menu.adcionarItens("Alterar Numero");
                const int OPCAO_ALTERAR_CAPACIDADE = menu.adcionarItens("Alterar Capacidade");
                const int OPCAO_ALTERAR_DINHEIRO = menu.adcionarItens("Alterar Dinheiro");
                const int OPCAO_ALTERAR_RAMAL = menu.adcionarItens("Alterar Ramal");

                int opcao = menu.executa("Atualizacao de Cadastro");

                if (opcao == OPCAO_ALTERAR_NUMERO) {
                    IO::Print("Novo Numero: ");
                    string valor = IO::LerLinha();
                    try {
                        quarto.setNumero(Numero(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_CAPACIDADE) {
                    IO::Print("Novo Capacidade: ");
                    string valor = IO::LerLinha();
                    try {
                        quarto.setCapacidade(Capacidade(stoi(valor)));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_DINHEIRO) {
                    IO::Print("Novo Dinheiro: ");
                    string valor = IO::LerLinha();
                    try {
                        quarto.setDiaria(Dinheiro(stoi(valor)));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_RAMAL) {
                    IO::Print("Novo Ramal: ");
                    string valor = IO::LerLinha();
                    try {
                        quarto.setRamal(Ramal(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                    IO::Println("Atualizacao cancelada.");
                    return;
                } else {
                    IO::Println("Opcao invalida.");
                }


                if (alterado) {
                    bool sucesso = servico->editar(id_numero, quarto);
                    if (sucesso) {
                        IO::Println("Quarto Atualizado!");
                    } else {
                        IO::Println("Erro ao atualizar quarto no banco!");
                    }
                }
            } else {
                IO::Println("Erro: Quarto nao encontrado");
            }
        } else {
            IO::Println("Erro: Id Invalido");
        }
    };

    void ControladoraApresentacaoQuarto::remover() {
        IO::Print("Informe o Id do Quarto: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id invalido");
            return;
        }

        int id = stoi(idStr);

        // Buscar gerente para mostrar antes de excluir
        auto dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Quarto nao encontrado.");
            return;
        }

        // Exibir dados do gerente encontrado
        Tabela tab;
        Linha *objLinha = tab.criarObj();
        objLinha->atributo("Id", dto->getId());
        objLinha->atributo("Numero", dto->getNumero());
        objLinha->atributo("Capacidade", dto->getCapacidade());
        objLinha->atributo("Dinheiro", dto->getDinheiro());
        objLinha->atributo("Ramal", dto->getRamal());
        objLinha->atributo("HotelID", dto->getHotelId());

        tab.exibirTabela("Quarto a Remover");

        // Chamar serviço para remover
        bool ok = servico->remover(id);
        IO::Println(ok ? "Quarto excluido com sucesso!" : "Erro ao excluir Quarto.");
    };
}