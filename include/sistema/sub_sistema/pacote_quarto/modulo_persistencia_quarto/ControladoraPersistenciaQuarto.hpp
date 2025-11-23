//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP

#include "InterfacePersistenciaQuarto.hpp"
#include "QuartoDTO.hpp"
#include "Quarto.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    class ControladoraPersistenciaQuarto : public InterfacePersistenciaQuarto {
    public:
        bool inserir(const Quarto &quarto) override;

        bool atualizar(const int &id, const Quarto &quarto) override;

        bool excluir(const int &id) override;

        vector<QuartoDTO> listar() override;

        optional<QuartoDTO> pesquisar(const int &id) override;

        int getQuantidadeDeQuartosDoHotel(int hotel_id) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAQUARTO_HPP