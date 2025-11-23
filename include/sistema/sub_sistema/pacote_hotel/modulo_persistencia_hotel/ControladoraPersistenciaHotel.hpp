//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H
#define Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H

#include "InterfacePersistenciaHotel.hpp"
#include "Hotel.hpp"
#include "HotelDTO.hpp"

#include "../../../banco/BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;


namespace Hotelaria {
    class ControladoraPersistenciaHotel : public InterfacePersistenciaHotel {
    public:
        bool inserir(const Hotel &hotel) override;

        bool atualizar(const int &id, const Hotel &hotel) override;

        bool excluir(const int &id) override;

        vector<HotelDTO> listar() override;

        optional<HotelDTO> pesquisar(const int &id) override;

        bool existeCodigo(const string &codigo) override;

        int getQuantidadeDeHoteisDoGerente(int gerente_id) override;
    };
}


#endif //Hotelaria_UnB_TP1_PERSISTENCIAHOTEL_H