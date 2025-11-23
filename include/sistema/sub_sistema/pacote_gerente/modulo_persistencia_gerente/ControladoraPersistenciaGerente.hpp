//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include "InterfacePersistenciaGerente.hpp"
#include "GerenteDTO.hpp"
#include "Gerente.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    class ControladoraPersistenciaGerente : public InterfacePersistenciaGerente {
    public:
        bool inserir(const Gerente &gerente) override;

        bool autenticar(const string &email, const string &senha) override;

        bool atualizar(const Email &email, const Gerente &gerente) override;

        bool excluir(const int &id) override;

        vector<GerenteDTO> listar() override;

        optional<GerenteDTO> pesquisarPorID(const int &id) override;

        optional<GerenteDTO> pesquisarPorEmail(const string email) override;

        bool existeEmail(const string &email) override;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H