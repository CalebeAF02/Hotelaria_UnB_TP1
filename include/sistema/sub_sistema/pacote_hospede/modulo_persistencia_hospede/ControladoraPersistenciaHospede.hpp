//
// Created by caleb on 16/10/2025.
//
/**
 * @file ControladoraPersistenciaHospede.hpp
 * @brief Implementação da camada de persistência para o módulo de Hóspedes.
 *
 * Esta classe é responsável por realizar todas as operações relacionadas ao
 * armazenamento e recuperação de dados de hóspedes no banco de dados SQLite.
 *
 * A camada de persistência:
 *  - Conecta-se ao banco
 *  - Executa comandos SQL
 *  - Converte resultados para DTOs
 *  - Não contém regras de negócio
 *  - Não interage com o usuário
 *
 * Arquitetura:
 *    Apresentação → Serviço → **Persistência** → Banco SQLite
 *
 * Cada método representa uma operação CRUD:
 *  - inserir()
 *  - atualizar()
 *  - excluir()
 *  - listar()
 *  - pesquisar()
 *  - pesquisarPorEmail()
 *  - existeEmail()
 */
#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H

#include "InterfacePersistenciaHospede.hpp"
#include "Hospede.hpp"
#include "HospedeDTO.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    /**
     * @class ControladoraPersistenciaHospede
     * @brief Classe responsável por interagir diretamente com o banco de dados para manipulação de hóspedes.
     *
     * Esta implementação utiliza o banco de dados SQLite (via sqlite3.h) e
     * a classe BancoDeDados para executar consultas SQL.
     *
     * Cada método contém a responsabilidade de montar consultas SQL corretas,
     * realizar o tratamento de erros e converter os resultados para objetos
     * de transferência de dados (DTOs).
     */
    class ControladoraPersistenciaHospede : public InterfacePersistenciaHospede {
    public:
        /**
         * @brief Insere um novo hóspede no banco de dados.
         *
         * @param hospede Objeto contendo todos os dados validados do hóspede.
         * @return `true` se a operação for concluída com sucesso.
         */
        bool inserir(const Hospede &hospede) override;

        /**
         * @brief Atualiza os dados de um hóspede já existente.
         *
         * A busca é feita pelo e-mail original, não pelo objeto atualizado.
         *
         * @param email E-mail atual que identifica o hóspede.
         * @param hospede Objeto com os dados atualizados.
         * @return `true` em caso de sucesso.
         */
        bool atualizar(const Email &email, const Hospede &hospede) override;

        /**
         * @brief Exclui um hóspede com base no seu ID.
         *
         * @param id Identificador único do hóspede.
         * @return `true` se o registro foi removido.
         */
        bool excluir(const int &id) override;

        /**
         * @brief Retorna todos os hóspedes cadastrados.
         *
         * @return Vetor contendo objetos `HospedeDTO`.
         */
        vector<HospedeDTO> listar() override;

        /**
         * @brief Pesquisa um hóspede pelo ID.
         *
         * @param id Identificador único do hóspede.
         * @return `optional<HospedeDTO>` contendo o resultado, caso exista.
         */
        optional<HospedeDTO> pesquisar(const int &id) override;

        /**
         * @brief Pesquisa um hóspede pelo seu e-mail.
         *
         * @param email E-mail do hóspede.
         * @return `optional<HospedeDTO>` contendo o hóspede encontrado.
         */
        optional<HospedeDTO> pesquisarPorEmail(const string email) override;

        /**
         * @brief Verifica se um e-mail já está cadastrado no banco.
         *
         * @param email E-mail a ser verificado.
         * @return `true` se o e-mail já existir.
         */
        bool existeEmail(const string &email) override;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H