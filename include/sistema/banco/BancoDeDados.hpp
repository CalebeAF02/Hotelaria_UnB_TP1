//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_BANCODEDADOS_H
#define Hotelaria_UnB_TP1_BANCODEDADOS_H

#include "sqlite3.h"
#include <iostream>
#include "../../../libs/io/IO.hpp"
#include "../../../libs/formato/Formato.hpp"

using namespace std;

namespace Hotelaria {
    /**
 * @class BancoDeDados
 * @brief Classe responsável pelo gerenciamento do banco de dados SQLite da aplicação de hotelaria.
 *
 * A classe BancoDeDados fornece métodos para:
 * - Abrir e fechar a conexão com o banco de dados;
 * - Criar as tabelas necessárias para o sistema de hotelaria;
 * - Executar consultas auxiliares para verificação de existência de dados e contagens.
 *
 * Todas as operações de persistência de dados no sistema de hotelaria passam por esta classe.
 */
    class BancoDeDados {
    private:
        /**
     * @brief Ponteiro para a conexão SQLite.
     */
        sqlite3 *db = nullptr;

        /**
     * @brief Cria a tabela de gerentes no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaGerente(sqlite3 *db);

        /**
     * @brief Cria a tabela de hóspedes no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaHospede(sqlite3 *db);

        /**
     * @brief Cria a tabela de hotéis no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaHotel(sqlite3 *db);

        /**
     * @brief Cria a tabela de quartos no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaQuarto(sqlite3 *db);

        /**
     * @brief Cria a tabela de reservas no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaReserva(sqlite3 *db);

        /**
     * @brief Cria a tabela de solicitações de hospedagem no banco de dados, se não existir.
     * @param db Ponteiro para a conexão SQLite.
     */
        void tabelaSolicitacoesDeHospedagem(sqlite3 *db);

    public:
        /**
     * @brief Retorna o ponteiro da conexão atual com o banco de dados.
     * @return sqlite3* Ponteiro para a conexão SQLite.
     */
        sqlite3 *getConexao() const;

        /**
     * @brief Abre a conexão com o banco de dados SQLite.
     * @return true se a conexão foi aberta com sucesso, false caso contrário.
     */
        bool abrindoConexao();

        /**
     * @brief Fecha a conexão com o banco de dados SQLite.
     * @return true se a conexão foi fechada com sucesso, false caso contrário.
     */
        bool fechandoConexao();

        /**
     * @brief Inicializa o banco de dados criando todas as tabelas necessárias.
     */
        void iniciar();

        /**
     * @brief Verifica se existe um valor específico em uma coluna de uma tabela.
     * @param tabela Nome da tabela.
     * @param coluna Nome da coluna.
     * @param valor Valor a ser verificado.
     * @return true se o valor existir na coluna, false caso contrário.
     */
        static bool EXISTE_TABELA_VALOR(string tabela, string coluna, string valor);

        /**
     * @brief Conta quantas vezes um valor string aparece em uma coluna de uma tabela.
     * @param tabela Nome da tabela.
     * @param coluna Nome da coluna.
     * @param valor Valor string a ser contado.
     * @return int Número de ocorrências do valor na coluna.
     */
        static int CONTAGEM_STRING(string tabela, string coluna, string valor);

        /**
     * @brief Conta quantas vezes um valor inteiro aparece em uma coluna de uma tabela.
     * @param tabela Nome da tabela.
     * @param coluna Nome da coluna.
     * @param valor Valor inteiro a ser contado.
     * @return int Número de ocorrências do valor na coluna.
     */
        static int CONTAGEM_INTEIRO(string tabela, string coluna, int valor);

        /**
     * @brief Conta quantas vezes uma combinação de dois valores inteiros aparece em duas colunas de uma tabela.
     * @param tabela Nome da tabela.
     * @param coluna1 Nome da primeira coluna.
     * @param valor1 Valor inteiro da primeira coluna.
     * @param coluna2 Nome da segunda coluna.
     * @param valor2 Valor inteiro da segunda coluna.
     * @return int Número de ocorrências da combinação de valores na tabela.
     */
        static int CONTAGEM_INTEIRO_DUPLO(string tabela, string coluna1, int valor1, string coluna2, int valor2);
    };
}

#endif //Hotelaria_UnB_TP1_BANCODEDADOS_H