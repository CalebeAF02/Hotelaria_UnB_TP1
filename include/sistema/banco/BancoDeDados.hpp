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
    class BancoDeDados {
    private:
        sqlite3 *db = nullptr;

        void tabelaGerente(sqlite3 *db);

        void tabelaHospede(sqlite3 *db);

        void tabelaHotel(sqlite3 *db);

        void tabelaQuarto(sqlite3 *db);

        void tabelaReserva(sqlite3 *db);

        void tabelaSolicitacoesDeHospedagem(sqlite3 *db);

    public:
        sqlite3 *getConexao() const;

        bool abrindoConexao();

        bool fechandoConexao();

        void iniciar();

        static bool EXISTE_TABELA_VALOR(string tabela, string coluna, string valor);

        static int CONTAGEM_STRING(string tabela, string coluna, string valor);

        static int CONTAGEM_INTEIRO(string tabela, string coluna, int valor);

        static int CONTAGEM_INTEIRO_DUPLO(string tabela, string coluna1, int valor1, string coluna2, int valor2);
    };
}

#endif //Hotelaria_UnB_TP1_BANCODEDADOS_H