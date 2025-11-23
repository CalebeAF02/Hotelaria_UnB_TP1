//
// Created by caleb on 28/09/2025.
//

#include "Sistema.hpp"

#include "SistemaSessao.hpp"
#include "sqlite3.h"
#include "Versao.hpp"

namespace Hotelaria {
    Sistema::Sistema() {
    }


    void Sistema::iniciar() {
        while (executando) {
            exibirMenu();
        }
    }

    void Sistema::exibirMenu() {
        SistemaSessao &sessao = SistemaSessao::getInstance();
        Menu menu;

        int OPCAO_SAIR_DO_SISTEMA = menu.adcionarItens("Sair");
        int OPCAO_ENTRAR_COMO_GERENTE = menu.adcionarItens("Entrar como Gerente");
        int OPCAO_ENTRAR_COMO_HOSPEDE = menu.adcionarItens("Entrar como Hospede");

        while (executando) {
            int opcao = menu.executa("Seja bem vindo ao Gerenciador de Hoteis");

            if (opcao == OPCAO_SAIR_DO_SISTEMA) {
                this->executando = false;
                IO::Println("Encerrando o sistema...");
            } else if (opcao == OPCAO_ENTRAR_COMO_GERENTE) {
                sessao.getControladoraApresentacaoAcessoGerente()->exibirMenu();
            } else if (opcao == OPCAO_ENTRAR_COMO_HOSPEDE) {
                sessao.getControladoraApresentacaoAcessoHospede()->exibirMenu();
            }
        }
    }

    void Sistema::setGerenteID(int valor) {
        this->gerente_id = valor;
    }

    void Sistema::setGerenteAutenticado(bool valor) {
        this->gerente_autenticado = valor;
    }

    bool Sistema::getGerenteID() {
        return gerente_id;
    }

    bool Sistema::getGerenteAutenticado() {
        return gerente_autenticado;
    }
}