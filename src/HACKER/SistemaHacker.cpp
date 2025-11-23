//
// Created by caleb on 08/11/2025.
//

#include "SistemaHacker.hpp"

#include "ControladoraPersistenciaGerente.hpp"
#include "SistemaSessao.hpp"

namespace Hotelaria {
    SistemaHacker::SistemaHacker() {
    }

    void SistemaHacker::iniciar() {
        SistemaSessao &sessao = SistemaSessao::getInstance();

        Email emailHK;
        emailHK.setValor("calebe.2324@gmail.com");
        Email *emailObj = &emailHK;

        Senha senhaHK;
        senhaHK.setValor("A1!b2");


        ControladoraPersistenciaGerente persistencia_gerente;
        if (!persistencia_gerente.existeEmail(emailObj->getValor())) {
            Gerente gerenteHakeado(Nome("Calebe"), Email("calebe.2324@gmail.com"), Ramal("01"), Senha("A1!b2"));
            persistencia_gerente.inserir(gerenteHakeado);
        }


        bool estaAutenticado = sessao.getControladoraApresentacaoAutenticavel()->getHacke()->autenticar(
            *emailObj, senhaHK);


        sessao.getControladoraApresentacaoAcessoGerente()->autenticarHacker();
        sessao.getControladoraApresentacaoAutenticavel()->setEstaAutenticado(true);

        if (estaAutenticado) {
            IO::Println("Agora Voce Possui Super-Poderes");
            ControladoraPersistenciaGerente controladora_persistencia_gerente;
            optional<GerenteDTO> gerente = controladora_persistencia_gerente.pesquisarPorEmail(emailObj->getValor());

            if (gerente.has_value()) {
                sessao.setGerenteId(gerente->getId());
            }
            sessao.getControladoraApresentacaoAcessoGerente()->exibirMenuGerenciador();
        }
    }
}