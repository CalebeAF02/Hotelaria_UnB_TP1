cmake_minimum_required(VERSION 3.10)
project(Gerenciador-De-Hoteis---UNB)

set(CMAKE_CXX_STANDARD 17)

# Caminhos
set(VERSAO_TXT "${CMAKE_CURRENT_SOURCE_DIR}/meta/versao.txt")
set(VERSAO_HPP "${CMAKE_CURRENT_SOURCE_DIR}/include/sistema/Versao.hpp")

# Geração automática do cabeçalho
add_custom_command(
        OUTPUT ${VERSAO_HPP}
        COMMAND ${CMAKE_COMMAND} -DINPUT_FILE=${VERSAO_TXT} -DOUTPUT_FILE=${VERSAO_HPP} -P ${CMAKE_SOURCE_DIR}/meta/atualizar_versao.cmake
        DEPENDS ${VERSAO_TXT}
        COMMENT "Atualizando versão automaticamente..."
)

add_custom_target(gerar_versao DEPENDS ${VERSAO_HPP})

# Fontes principais
add_executable(Gerenciador-De-Hoteis---UNB
        src/main.cpp

        # Libs - Formato
        libs/formato/Formato.cpp

        # Libs - IO
        libs/io/IO.cpp

        # Libs - Menu
        libs/menu/Menu.cpp
        libs/menu/MenuItem.cpp
        libs/menu/ExibirMenu.cpp
        libs/menu/MenuCRUD.cpp

        # Libs - Sqlite
        libs/sqlite/sqlite3.c

        # Libs - Tabela
        libs/tabela/Tabela.cpp
        libs/tabela/Linha.cpp
        libs/tabela/Atributo.cpp
        libs/tabela/TamanhoAtributo.cpp

        # Libs - teste
        libs/teste/InterfaceDeTestes.cpp
        libs/teste/SmokeTeste.cpp

        # HACKER
        src/HACKER/SistemaHacker.cpp

        # Sistema
        src/sistema/Sistema.cpp

        # Sistema - Banco
        src/sistema/banco/BancoDeDados.cpp

        ## Sub Sistema - Apresentacao
        src/sistema/sub_sistema/pacote_acesso/modulo_apresentacao_acesso/ControladoraApresentacaoAcessoGerente.cpp
        src/sistema/sub_sistema/pacote_acesso/modulo_apresentacao_acesso/ControladoraApresentacaoAcessoHospede.cpp
        src/sistema/sub_sistema/pacote_autenticavel/modulo_apresentacao_autenticavel/ControladoraApresentacaoAutenticavel.cpp
        src/sistema/sub_sistema/pacote_gerente/modulo_apresentacao_gerente/ControladoraApresentacaoGerente.cpp
        src/sistema/sub_sistema/pacote_hospede/modulo_apresentacao_hospede/ControladoraApresentacaoHospede.cpp
        src/sistema/sub_sistema/pacote_hotel/modulo_apresentacao_hotel/ControladoraApresentacaoHotel.cpp
        src/sistema/sub_sistema/pacote_quarto/modulo_apresentacao_quarto/ControladoraApresentacaoQuarto.cpp
        src/sistema/sub_sistema/pacote_reserva/modulo_apresentacao_reserva/ControladoraApresentacaoReserva.cpp

        ## Sub Sistema - Servico
        src/sistema/sub_sistema/pacote_autenticavel/modulo_servico_autenticavel/ControladoraServicoAutenticavel.cpp
        src/sistema/sub_sistema/pacote_gerente/modulo_servico_gerente/ControladoraServicoGerente.cpp
        src/sistema/sub_sistema/pacote_hospede/modulo_servico_hospede/ControladoraServicoHospede.cpp
        src/sistema/sub_sistema/pacote_hotel/modulo_servico_hotel/ControladoraServicoHotel.cpp
        src/sistema/sub_sistema/pacote_quarto/modulo_servico_quarto/ControladoraServicoQuarto.cpp
        src/sistema/sub_sistema/pacote_reserva/modulo_servico_reserva/ControladoraServicoReserva.cpp

        # Sub Sistema - Persistências
        src/sistema/sub_sistema/pacote_autenticavel/modulo_persistencia_autenticavel/ControladoraPersistenciaAutenticavel.cpp
        src/sistema/sub_sistema/pacote_gerente/modulo_persistencia_gerente/ControladoraPersistenciaGerente.cpp
        src/sistema/sub_sistema/pacote_hospede/modulo_persistencia_hospede/ControladoraPersistenciaHospede.cpp
        src/sistema/sub_sistema/pacote_hotel/modulo_persistencia_hotel/ControladoraPersistenciaHotel.cpp
        src/sistema/sub_sistema/pacote_quarto/modulo_persistencia_quarto/ControladoraPersistenciaQuarto.cpp
        src/sistema/sub_sistema/pacote_reserva/modulo_persistencia_reserva/ControladoraPersistenciaReserva.cpp
        src/sistema/sub_sistema/ControladoraPersistenciaSolicitacaoHospedagem.cpp


        # Objetos - Domínios
        src/sistema/objetos/dominios/Nome.cpp
        src/sistema/objetos/dominios/Email.cpp
        src/sistema/objetos/dominios/Ramal.cpp
        src/sistema/objetos/dominios/Senha.cpp
        src/sistema/objetos/dominios/Endereco.cpp
        src/sistema/objetos/dominios/Cartao.cpp
        src/sistema/objetos/dominios/Telefone.cpp
        src/sistema/objetos/dominios/Codigo.cpp
        src/sistema/objetos/dominios/Numero.cpp
        src/sistema/objetos/dominios/Capacidade.cpp
        src/sistema/objetos/dominios/Dinheiro.cpp
        src/sistema/objetos/dominios/Data.cpp

        # Objetos - Entidades_DTO
        src/sistema/objetos/entidades_dto/PessoaDTO.cpp
        src/sistema/objetos/entidades_dto/GerenteDTO.cpp
        src/sistema/objetos/entidades_dto/HospedeDTO.cpp
        src/sistema/objetos/entidades_dto/HotelDTO.cpp
        src/sistema/objetos/entidades_dto/QuartoDTO.cpp
        src/sistema/objetos/entidades_dto/ReservaDTO.cpp
        src/sistema/objetos/entidades_dto/SolicitacaoHospedagemDTO.cpp

        # Objetos - Entidades
        src/sistema/objetos/entidades/Gerente.cpp
        src/sistema/objetos/entidades/Hospede.cpp
        src/sistema/objetos/entidades/Hotel.cpp
        src/sistema/objetos/entidades/Pessoa.cpp
        src/sistema/objetos/entidades/Quarto.cpp
        src/sistema/objetos/entidades/Reserva.cpp
        src/sistema/objetos/entidades/SolicitacaoHospedagem.cpp

        # Fábricas
        src/sistema/sub_sistema/pacote_fabrica/modulo_apresentacao_fabrica/FabricaGerenciavel.cpp

        # Utilitários
        src/sistema/utilitarios/Utils.cpp
        src/sistema/utilitarios/Modos.cpp

        # Utilitários - Enum
        src/sistema/utilitarios/enum/StatusSolicitacaoHospedagem.cpp
        src/sistema/utilitarios/enum/EnumConversor.cpp

        # Versao
        src/sistema/Versao.cpp

        # Testes
        testes/TestandoSmoke.cpp

        # Testes - Domínios
        testes/testes_dominios/TesteCapacidade.cpp
        testes/testes_dominios/TesteCartao.cpp
        testes/testes_dominios/TesteCodigo.cpp
        testes/testes_dominios/TesteDinheiro.cpp
        testes/testes_dominios/TesteEmail.cpp
        testes/testes_dominios/TesteEndereco.cpp
        testes/testes_dominios/TesteNome.cpp
        testes/testes_dominios/TesteNumero.cpp
        testes/testes_dominios/TesteRamal.cpp
        testes/testes_dominios/TesteSenha.cpp
        testes/testes_dominios/TesteTelefone.cpp
        testes/testes_dominios/TestesData.cpp

        # Testes - Entidades
        testes/testes_entidades/TesteGerente.cpp
        testes/testes_entidades/TesteHospede.cpp
        testes/testes_entidades/TesteHotel.cpp
        testes/testes_entidades/TesteQuarto.cpp
        testes/testes_entidades/TesteReserva.cpp

        src/sistema/SistemaSessao.cpp

        src/sistema/AplicacaoSistema.cpp


)

add_dependencies(Gerenciador-De-Hoteis---UNB gerar_versao)

# Diretórios de headers
target_include_directories(Gerenciador-De-Hoteis---UNB PRIVATE
        ${CMAKE_SOURCE_DIR}/libs/formato
        ${CMAKE_SOURCE_DIR}/libs/io
        ${CMAKE_SOURCE_DIR}/libs/sqlite
        ${CMAKE_SOURCE_DIR}/libs/tabela
        ${CMAKE_SOURCE_DIR}/libs/teste
        ${CMAKE_SOURCE_DIR}/libs/menu

        ${CMAKE_SOURCE_DIR}/include

        ${CMAKE_SOURCE_DIR}/include/HACKER

        ${CMAKE_SOURCE_DIR}/include/sistema

        ${CMAKE_SOURCE_DIR}/include/sistema/banco

        ${CMAKE_SOURCE_DIR}/include/sistema/objetos

        ${CMAKE_SOURCE_DIR}/include/sistema/objetos/dominios
        ${CMAKE_SOURCE_DIR}/include/sistema/objetos/entidades_dto
        ${CMAKE_SOURCE_DIR}/include/sistema/objetos/entidades

        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema

        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_acesso
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_autenticavel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_fabrica
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_gerente
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hospede
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hotel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_quarto
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_reserva


        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_acesso/modulo_apresentacao_acesso
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_autenticavel/modulo_apresentacao_autenticavel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_fabrica/modulo_apresentacao_fabrica
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_gerente/modulo_apresentacao_gerente
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hospede/modulo_apresentacao_hospede
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hotel/modulo_apresentacao_hotel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_quarto/modulo_apresentacao_quarto
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_reserva/modulo_apresentacao_reserva


        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_autenticavel/modulo_servico_autenticavel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_fabrica/modulo_servico_fabrica
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_gerente/modulo_servico_gerente
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hospede/modulo_servico_hospede
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hotel/modulo_servico_hotel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_quarto/modulo_servico_quarto
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_reserva/modulo_servico_reserva

        ${CMAKE_SOURCE_DIR}/ include/sistema/sub_sistema/pacote_autenticavel/modulo_persistencia_autenticavel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_gerente/modulo_persistencia_gerente
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hospede/modulo_persistencia_hospede
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_hotel/modulo_persistencia_hotel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_quarto/modulo_persistencia_quarto
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/pacote_reserva/modulo_persistencia_reserva

        ${CMAKE_SOURCE_DIR}/include/sistema/utilitarios

        ${CMAKE_SOURCE_DIR}/include/sistema/utilitarios/enum

        ${CMAKE_SOURCE_DIR}/testes

        ${CMAKE_SOURCE_DIR}/testes/testes_dominios
        ${CMAKE_SOURCE_DIR}/testes/testes_entidades


)