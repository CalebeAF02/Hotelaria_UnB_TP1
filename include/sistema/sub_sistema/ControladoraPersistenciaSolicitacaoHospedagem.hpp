//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H

#include "SolicitacaoHospedagem.hpp"
#include "EnumConversor.hpp"
#include "SolicitacaoHospedagem.hpp"

#include "../banco/BancoDeDados.hpp"
#include <vector>
#include <string>
#include <sqlite3.h>
#include <iostream>

namespace Hotelaria {
    class ControladoraPersistenciaSolicitacaoHospedagem {
    public:
        static void salvar(const SolicitacaoHospedagem &status);

        static void atualizar(const SolicitacaoHospedagem &status);

        static vector<SolicitacaoHospedagem> buscarPorEmail(const string &email);

        static vector<SolicitacaoHospedagem> buscarPorStatus(int status);
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H