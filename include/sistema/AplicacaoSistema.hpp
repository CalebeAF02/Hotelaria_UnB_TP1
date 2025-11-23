//
// Created by caleb on 22/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_APLICACAOSISTEMA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_APLICACAOSISTEMA_HPP
#include "Modos.hpp"

#include "Sistema.hpp"
#include "SistemaHacker.hpp"

#include <string>
#include "sqlite3.h"

#include "Formato.hpp"

#include "banco/BancoDeDados.hpp"
#include "InterfaceDeTestes.hpp"
#include "SmokeTeste.hpp"
#include "TestandoSmoke.hpp"

// Testes de domínios
#include "TesteCapacidade.hpp"
#include "TesteCartao.hpp"
#include "TesteCodigo.hpp"
#include "TesteDinheiro.hpp"
#include "TesteEmail.hpp"
#include "TesteEndereco.hpp"
#include "TesteNome.hpp"
#include "TesteNumero.hpp"
#include "TesteRamal.hpp"
#include "TesteSenha.hpp"
#include "TesteTelefone.hpp"

// Testes de entidades
#include "TesteGerente.hpp"
#include "TesteHospede.hpp"
#include "TesteHotel.hpp"
#include "TesteQuarto.hpp"
#include "TesteReserva.hpp"


#include "banco/BancoDeDados.hpp"
#include "Sistema.hpp"
#include "SistemaHacker.hpp"
#include "TestandoSmoke.hpp"

#include "SistemaSessao.hpp"

// Controladoras de apresentação
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoAcessoHospede.hpp"
#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladoraApresentacaoGerente.hpp"
#include "ControladoraApresentacaoHospede.hpp"
#include "ControladoraApresentacaoHotel.hpp"
#include "ControladoraApresentacaoQuarto.hpp"
#include "ControladoraApresentacaoReserva.hpp"

// Controladoras de servico
#include "ControladoraServicoAutenticavel.hpp"
#include "ControladoraServicoGerente.hpp"
#include "ControladoraServicoHospede.hpp"
#include "ControladoraServicoHotel.hpp"
#include "ControladoraServicoQuarto.hpp"
#include "ControladoraServicoReserva.hpp"

#include "ControladoraPersistenciaAutenticavel.hpp"
#include "ControladoraPersistenciaGerente.hpp"
#include "ControladoraPersistenciaHospede.hpp"
#include "ControladoraPersistenciaHotel.hpp"
#include "ControladoraPersistenciaQuarto.hpp"
#include "ControladoraPersistenciaReserva.hpp"
#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"

namespace Hotelaria {
    class AplicacaoSistema {
    public:
        void iniciar(MODOS MODO_ATUAL);

    private:
        void desenhar_logo();

        void iniciando_controladores();
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_APLICACAOSISTEMA_HPP