//
// Created by caleb on 22/11/2025.
//

#include "../../include/sistema/AplicacaoSistema.hpp"


namespace Hotelaria {
    void AplicacaoSistema::iniciar(MODOS MODO_ATUAL) {
        BancoDeDados banco;
        banco.iniciar();

        desenhar_logo();

        iniciando_controladores();

        // Escolhendo modo de execução
        switch (MODO_ATUAL) {
            case MODOS::MODO_SMOKE: {
                TestandoSmoke teste;
                teste.executarSmokeTest();
                Teste::InterfaceDeTeste::mostrarRelatorioDeTestes();
                break;
            }
            case MODOS::MODO_PRODUCAO: {
                Sistema sistema;
                sistema.iniciar();
                break;
            }
            case MODOS::MODO_HACKER: {
                SistemaHacker sistema_hacker;
                sistema_hacker.iniciar();
                break;
            }
        }
    }


    void AplicacaoSistema::finalizar() {
        SistemaSessao &sessao = SistemaSessao::getInstance();

        sessao.finalizar();
    }


    void AplicacaoSistema::desenhar_logo() {
        const char *logo = R"(   .+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.
  )                                                                (
   (                                                                )
  )     _   _  ___ _____ _____ _        _    ____  ___    _        (
   (   | | | |/ _ \_   _| ____| |      / \  |  _ \|_ _|  / \        )
  )    | |_| | | | || | |  _| | |     / _ \ | |_) || |  / _ \      (
   (   |  _  | |_| || | | |___| |___ / ___ \|  _ < | | / ___ \      )
  )    |_| |_|\___/ |_| |_____|_____/_/   \_\_| \_\___/_/   \_\    (
   (                                                                )
  )                                                                (  )";


        const char *rodape = R"(   "+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+"+.+" )";


        IO::Println("");
        IO::Println(logo);
        IO::Print(
            "   )           Versao " + Versao::getVersaoCompleta() + " Compilado em " + Versao::getData() +
            "          ( \n");
        IO::Print("  )                     CALEBE ALVES FREITAS                        ( \n");
        IO::Println("   )                                                               (");

        IO::Println(rodape);
        IO::Println("");
    }

    void AplicacaoSistema::iniciando_controladores() {
        SistemaSessao &sessao = SistemaSessao::getInstance();


        ControladoraApresentacaoAcessoGerente *acessoGerente = new ControladoraApresentacaoAcessoGerente();
        sessao.setControladoraApresentacaoAcessoGerente(acessoGerente);

        ControladoraApresentacaoAcessoHospede *acessoHospede = new ControladoraApresentacaoAcessoHospede();
        sessao.setControladoraApresentacaoAcessoHospede(acessoHospede);


        ControladoraApresentacaoGerente *apresentacaoGerente = new ControladoraApresentacaoGerente();
        sessao.setControladoraApresentacao(apresentacaoGerente);

        ControladoraServicoGerente *servGerente = new ControladoraServicoGerente();
        apresentacaoGerente->setControladoraServicoGerente(servGerente);

        ControladoraPersistenciaGerente *perGerente = new ControladoraPersistenciaGerente();
        servGerente->setControladoraPersistencia(perGerente);


        ControladoraApresentacaoHospede *apresentacaoHospede = new ControladoraApresentacaoHospede();
        sessao.setControladoraApresentacao(apresentacaoHospede);

        ControladoraServicoHospede *servHospede = new ControladoraServicoHospede();
        apresentacaoHospede->setControladoraServicoHospede(servHospede);

        ControladoraPersistenciaHospede *perHospede = new ControladoraPersistenciaHospede();
        servHospede->setControladoraPersistencia(perHospede);


        ControladoraApresentacaoAutenticavel *autenticador = new ControladoraApresentacaoAutenticavel();
        sessao.setControladoraApresentacao(autenticador);

        ControladoraServicoAutenticavel *servAutenticavel = new ControladoraServicoAutenticavel();
        autenticador->setControladoraServicoAutenticavel(servAutenticavel);

        ControladoraPersistenciaAutenticavel *perAutenticavel = new ControladoraPersistenciaAutenticavel();
        servAutenticavel->setControladoraPersistencia(perAutenticavel);


        ControladoraApresentacaoHotel *apresentacaoHotel = new ControladoraApresentacaoHotel();
        sessao.setControladoraApresentacao(apresentacaoHotel);

        ControladoraServicoHotel *servHotel = new ControladoraServicoHotel();
        apresentacaoHotel->setControladoraServicoHotel(servHotel);

        ControladoraPersistenciaHotel *perHotel = new ControladoraPersistenciaHotel();
        servHotel->setControladoraPersistencia(perHotel);


        ControladoraApresentacaoQuarto *apresentacaoQuarto = new ControladoraApresentacaoQuarto();
        sessao.setControladoraApresentacao(apresentacaoQuarto);

        ControladoraServicoQuarto *servQuarto = new ControladoraServicoQuarto();
        apresentacaoQuarto->setControladoraServicoQuarto(servQuarto);

        ControladoraPersistenciaQuarto *perQuarto = new ControladoraPersistenciaQuarto();
        servQuarto->setControladoraPersistencia(perQuarto);


        ControladoraApresentacaoReserva *apresentacaoReserva = new ControladoraApresentacaoReserva();
        sessao.setControladoraApresentacao(apresentacaoReserva);

        ControladoraServicoReserva *servReserva = new ControladoraServicoReserva();
        apresentacaoReserva->setControladoraServicoReserva(servReserva);

        ControladoraPersistenciaReserva *perReserva = new ControladoraPersistenciaReserva();
        servReserva->setControladoraPersistencia(perReserva);
    }
}