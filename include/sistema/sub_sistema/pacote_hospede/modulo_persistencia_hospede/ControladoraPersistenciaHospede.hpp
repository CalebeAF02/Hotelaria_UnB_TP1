//
// Created by caleb on 16/10/2025.
//

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
    class ControladoraPersistenciaHospede : public InterfacePersistenciaHospede {
    public:
        bool inserir(const Hospede &hospede) override;

        bool atualizar(const Email &email, const Hospede &hospede) override;

        bool excluir(const int &id) override;

        vector<HospedeDTO> listar() override;

        optional<HospedeDTO> pesquisar(const int &id) override;

        optional<HospedeDTO> pesquisarPorEmail(const string email) override;

        bool existeEmail(const string &email) override;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H