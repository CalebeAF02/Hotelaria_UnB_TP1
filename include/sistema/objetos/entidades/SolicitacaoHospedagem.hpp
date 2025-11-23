//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H

#include "SolicitacaoHospedagemDTO.hpp"
#include "StatusSolicitacaoHospedagem.hpp"
#include "Data.hpp"
#include "Codigo.hpp"

#include <string>
#include <stdexcept>

namespace Hotelaria {
    /**
     * @file SolicitacaoHospedagem.hpp
     * @brief Declaração da classe SolicitacaoHospedagem, responsável por representar
     *        uma solicitação de hospedagem feita por um hóspede a um hotel.
     *
     * A classe registra informações essenciais para gerenciamento do fluxo de reservas,
     * incluindo datas, status da solicitação, IDs envolvidos e possível motivo de recusa.
     */
    /**
     * @class SolicitacaoHospedagem
     * @brief Representa uma solicitação formal de hospedagem realizada por um hóspede.
     *
     * Esta classe armazena dados como datas de chegada/partida, status atual
     * (pendente, aprovada, recusada), IDs do hóspede/hotel/quarto e, se houver,
     * o motivo da recusa.
     *
     * Também pode ser criada diretamente a partir de um objeto DTO.
     */
    class SolicitacaoHospedagem {
    private:
        Data chegada;

        Data partida;

        StatusSolicitacaoHospedagem status;

        string motivoRecusa;

        int hospedeId;

        int hotelId;

        int quartoId;

    public:
        /// @name Construtores
        /// @{

        /**
         * @brief Construtor padrão.
         */
        SolicitacaoHospedagem() = default;

        /**
         * @brief Constrói uma solicitação de hospedagem com todos os parâmetros necessários.
         *
         * @param chegada Data de chegada.
         * @param partida Data de partida.
         * @param status Status atual da solicitação.
         * @param motivoRecusa Motivo da recusa (se aplicável).
         * @param hospedeId ID do hóspede.
         * @param hotelId ID do hotel.
         * @param quartoId ID do quarto.
         *
         * @throws runtime_error caso alguma validação interna falhe.
         */
        SolicitacaoHospedagem(
            const Data &chegada,
            const Data &partida,
            const StatusSolicitacaoHospedagem status,
            const string &motivoRecusa,
            const int &hospedeId,
            const int &hotelId,
            const int &quartoId
        );

        /**
         * @brief Construtor que cria uma solicitação a partir de um DTO.
         *
         * @param solicitacao_hospedagem_dto Objeto DTO contendo os dados da solicitação.
         */
        SolicitacaoHospedagem(SolicitacaoHospedagemDTO &solicitacao_hospedagem_dto);

        /// @}
        /// @name Métodos Setters
        /// @{
        /** @brief Define o ID do hóspede. */
        void setHospedeId(const int &valor);

        /** @brief Define o ID do hotel. */
        void setHotelId(const int &valor);

        /** @brief Define o ID do quarto. */
        void setQuartoId(const int &valor);

        /** @brief Define a data de chegada. */
        void setChegada(const Data &valor);

        /** @brief Define a data de partida. */
        void setPartida(const Data &valor);

        /** @brief Define o status da solicitação. */
        void setStatus(StatusSolicitacaoHospedagem valor);

        /** @brief Define o motivo da recusa da solicitação. */
        void setMotivoRecusa(const string &valor);

        /// @}
        /// @name Métodos Getters
        /// @{
        /** @return ID do hóspede. */
        int getHospedeId() const;

        /** @return ID do hotel. */
        int getHotelId() const;

        /** @return ID do quarto. */
        int getQuartoId() const;

        /** @return Data de chegada. */
        Data getChegada() const;

        /** @return Data de partida. */
        Data getPartida() const;

        /** @return Status atual da solicitação. */
        StatusSolicitacaoHospedagem getStatus() const;

        /** @return Motivo da recusa, se houver. */
        string getMotivoRecusa() const;

        /// @}
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H