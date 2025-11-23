//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoHotel.hpp"

#include "InterfaceApresentacaoQuarto.hpp"
#include "SistemaSessao.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoHotel::setControladoraServicoHotel(InterfaceServicoHotel *controladora_servico_hotel) {
        this->servico = controladora_servico_hotel;
    }

    void ControladoraApresentacaoHotel::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_ACESSAR = menu.adcionarItens("Acessar Hotel");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Hotel");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Hoteis");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Hotel (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Hotel (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Hoteis (CRUD)");

            if (opcao == OPCAO_VOLTAR) {
                executando = false;
                IO::Println("Voltando ao menu de acesso.");
            } else if (opcao == OPCAO_ACESSAR) {
                acessar();
            } else if (opcao == OPCAO_CRIAR) {
                SistemaSessao &sessao = SistemaSessao::getInstance();
                int gerente_id = sessao.getGerenteId();
                criar(gerente_id);
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

    void ControladoraApresentacaoHotel::acessar() {
        IO::Print("Informe o Id do Hotel: ");
        string hotel_id = IO::LerLinha();
        try {
        } catch (invalid_argument &erro) {
            IO::Println(erro.what());
        }

        if (Utils::verificaSeENumero(hotel_id)) {
            int hotel_id_inteiro = stoi(hotel_id);
            optional<HotelDTO> op_hotel = servico->pesquisar(hotel_id_inteiro);
            if (op_hotel.has_value()) {
                IO::Println(op_hotel->getNome());
                SistemaSessao &sessao = SistemaSessao::getInstance();
                sessao.setHotelId(hotel_id_inteiro);
                InterfaceApresentacaoQuarto *apresentacao_quarto = sessao.getControladoraApresentacaoQuarto();
                apresentacao_quarto->exibirMenuCRUD();
            } else {
                IO::Println("Erro: Hotel nao encontrado!");
            }
        } else {
            IO::Println("Erro: Id invalido!");
        }
    }

    void ControladoraApresentacaoHotel::criar(int gerente_id) {
        IO::Println("Quantidade :: " + to_string(servico->getQuantidadeDeHoteisDoGerente(gerente_id)));

        /*
        if (servico->getQuantidadeDeHoteisDoGerente(gerente_id) >= Sistema::MAXIMO_HOTEL_POR_GERENTE) {
            IO::Println("Erro: O gerente so pode ter no maximo " + to_string(Sistema::MAXIMO_HOTEL_POR_GERENTE) + " hoteis cadastrados !");
            return;
        }*/

        bool criado = false;
        bool tudoOK = true;

        while (!criado) {
            Hotel *hotel = new Hotel();
            hotel->setGerenteId(gerente_id);

            Formato::TituloEmCaixa("Criando Novo Hotel");
            if (tudoOK) {
                IO::Print("Informe o Nome: ");
                string valor = IO::LerLinha();
                try {
                    hotel->setNome(Nome(valor));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
                if (tudoOK) {
                    IO::Print("Informe o Endereco: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel->setEndereco(Endereco(valor));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    IO::Print("Informe o Telefone: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel->setTelefone(Telefone(valor));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    IO::Print("Informe o Codigo: ");
                    string valor = IO::LerLinha();
                    try {
                        if (!servico->existeCodigo(valor)) {
                            hotel->setCodigo(Codigo(valor));
                        } else {
                            IO::Println("Erro: Ja existe um Hotel Cadastrado com este Codigo!");
                            tudoOK = false;
                            break;
                        }
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    bool sucesso = servico->criar(*hotel);

                    if (sucesso) IO::Println("Hotel Cadastrado com Sucesso!");
                    else IO::Println("Falha ao cadastrar (Erro de Servico/Banco).");

                    criado = sucesso;
                }
                delete hotel;
            }
        }
    }


    void ControladoraApresentacaoHotel::listar() {
        vector<HotelDTO> lista = servico->listarTodos();

        if (lista.empty()) {
            IO::Println("Nenhum hotel cadastrado.");
        }
        Tabela tab;

        for (HotelDTO item: lista) {
            Linha *objLinha = tab.criarObj();

            objLinha->atributo("id", item.getId());
            objLinha->atributo("Nome", item.getNome());
            objLinha->atributo("Endereco", item.getEndereco());
            objLinha->atributo("Telefone", item.getTelefone());
            objLinha->atributo("Codigo", item.getCodigo());
            objLinha->atributo("GerenteID", item.getGerenteID());
        }

        tab.exibirTabela("Lista De Hoteis");
    }

    void ControladoraApresentacaoHotel::atualizar() {
        IO::Print("Informe o Id do hotel: ");
        string id_hotel = IO::LerLinha();

        if (verificaSeENumero(id_hotel)) {
            bool alterado = false;

            int id_numero = stoi(id_hotel);
            optional<HotelDTO> existe_hotel = servico->pesquisar(id_numero);

            if (existe_hotel.has_value()) {
                Tabela tab;

                Linha *objLinha = tab.criarObj();

                objLinha->atributo("Id", existe_hotel->getId());
                objLinha->atributo("Nome", existe_hotel->getNome());
                objLinha->atributo("Endereco", existe_hotel->getEndereco());
                objLinha->atributo("Telefone", existe_hotel->getTelefone());
                objLinha->atributo("Codigo", existe_hotel->getCodigo());
                objLinha->atributo("GerenteID", existe_hotel->getGerenteID());


                tab.exibirTabela("Lista De Hoteis");

                // Perguntas para o usuario
                Hotel hotel(*existe_hotel); // Construtor em Hotel, para HotelDTO

                Menu menu;

                const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
                const int OPCAO_ALTERAR_NOME = menu.adcionarItens("Alterar Nome");
                const int OPCAO_ALTERAR_ENDERECO = menu.adcionarItens("Alterar Endereco");
                const int OPCAO_ALTERAR_TELEFONE = menu.adcionarItens("Alterar Telefone");
                const int OPCAO_ALTERAR_CODIGO = menu.adcionarItens("Alterar Codigo");

                int opcao = menu.executa("Atualizacao de Cadastro");

                if (opcao == OPCAO_ALTERAR_NOME) {
                    IO::Print("Novo nome: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setNome(Nome(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_ENDERECO) {
                    IO::Print("Novo Endereco: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setEndereco(Endereco(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_TELEFONE) {
                    IO::Print("Novo Telefone: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setTelefone(Telefone(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_CODIGO) {
                    IO::Print("Novo Codigo: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setCodigo(Codigo(valor));
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
                    bool sucesso = servico->editar(id_numero, hotel);
                    if (sucesso) {
                        IO::Println("Hotel Atualizado!");
                    } else {
                        IO::Println("Erro ao atualizar hotel no banco!");
                    }
                }
            } else {
                IO::Println("Erro: Hotel nao encontrado");
            }
        } else {
            IO::Println("Erro: Id Invalido");
        }
    };

    void ControladoraApresentacaoHotel::remover() {
        IO::Print("Informe o Id do Hotel: ");
        string idStr = IO::LerLinha();

        if (!Utils::verificaSeENumero(idStr)) {
            IO::Println("Erro: Id invalido");
            return;
        }

        int id = stoi(idStr);

        // Buscar gerente para mostrar antes de excluir
        auto dto = servico->pesquisar(id);
        if (!dto.has_value()) {
            IO::Println("Erro: Hotel nao encontrado.");
            return;
        }

        // Exibir dados do gerente encontrado
        Tabela tab;
        Linha *objLinha = tab.criarObj();
        objLinha->atributo("Id", dto->getId());
        objLinha->atributo("Nome", dto->getNome());
        objLinha->atributo("Endereco", dto->getEndereco());
        objLinha->atributo("Telefone", dto->getTelefone());
        objLinha->atributo("Codigo", dto->getCodigo());
        objLinha->atributo("GerenteID", dto->getGerenteID());

        tab.exibirTabela("Hotel a Remover");

        // Chamar serviço para remover
        bool ok = servico->remover(id);
        IO::Println(ok ? "Hotel excluido com sucesso!" : "Erro ao excluir Hotel.");
    }
}