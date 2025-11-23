//
// Created by caleb on 19/11/2025.
//
/**
 * @file InterfacePersistenciaHospede.hpp
 * @brief Declara a interface responsável pela camada de persistência de dados
 *        referentes aos hóspedes do sistema de hotelaria.
 *
 * Esta interface define o contrato mínimo que qualquer classe de persistência
 * deve cumprir, seja utilizando:
 * - SQLite
 * - MySQL
 * - Arquivos
 * - Memória volátil (mock)
 *
 * A camada de persistência é responsável por armazenar, atualizar, consultar
 * e remover dados da entidade Hospede.
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP

#include "HospedeDTO.hpp"
#include "Hospede.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    /**
     * @class InterfacePersistenciaHospede
     * @brief Interface abstrata que define as operações de CRUD e consulta
     *        relacionadas à entidade Hospede.
     *
     * Esta interface segue o padrão DAO (Data Access Object), permitindo
     * que múltiplas implementações possam ser utilizadas sem alterar
     * a lógica das camadas superiores (Serviço e Apresentação).
     */
    class InterfacePersistenciaHospede {
    public:
        /**
         * @brief Insere um novo hóspede no banco de dados.
         *
         * @param hospede Objeto Hospede contendo os dados completos do hóspede.
         * @return true se a inserção foi realizada com sucesso,
         *         false caso contrário.
         */
        virtual bool inserir(const Hospede &hospede) = 0;

        /**
         * @brief Atualiza os dados de um hóspede identificado por e-mail.
         *
         * @param email E-mail que identifica unicamente o hóspede no banco.
         * @param hospede Objeto Hospede com os dados atualizados.
         * @return true se a atualização ocorreu corretamente,
         *         false caso o hóspede não seja encontrado ou a operação falhe.
         */
        virtual bool atualizar(const Email &email, const Hospede &hospede) = 0;

        /**
         * @brief Exclui um hóspede com base em seu ID.
         *
         * @param id Identificador numérico único do hóspede.
         * @return true se o registro foi removido com sucesso,
         *         false caso não exista ou ocorra erro.
         */
        virtual bool excluir(const int &id) = 0;

        /**
         * @brief Lista todos os hóspedes cadastrados no sistema.
         *
         * @return Vetor contendo objetos HospedeDTO com dados simplificados
         *         de todos os hóspedes.
         */
        virtual vector<HospedeDTO> listar() = 0;

        /**
         * @brief Pesquisa um hóspede através do seu ID.
         *
         * @param id Identificador único do hóspede.
         * @return std::optional contendo HospedeDTO se encontrado,
         *         ou std::nullopt caso não exista.
         */
        virtual optional<HospedeDTO> pesquisar(const int &id) = 0;

        /**
         * @brief Pesquisa um hóspede através de seu e-mail.
         *
         * @param email E-mail do hóspede a ser buscado.
         * @return std::optional contendo HospedeDTO caso o e-mail exista,
         *         ou std::nullopt se não for encontrado.
         */
        virtual optional<HospedeDTO> pesquisarPorEmail(const string email) = 0;

        /**
         * @brief Verifica se um e-mail já está cadastrado no sistema.
         *
         * @param email E-mail a ser verificado.
         * @return true caso já exista um hóspede com esse e-mail,
         *         false caso contrário.
         */
        virtual bool existeEmail(const string &email) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~InterfacePersistenciaHospede() = default;
    };
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP