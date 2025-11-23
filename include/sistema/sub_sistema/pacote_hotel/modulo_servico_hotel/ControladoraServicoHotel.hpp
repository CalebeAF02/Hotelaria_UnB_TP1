//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSHOTEL_HPP
#define Hotelaria_UnB_TP1_CSHOTEL_HPP

#include "InterfacePersistenciaHotel.hpp"
#include "InterfaceServicoHotel.hpp"
#include "ControladoraPersistenciaHotel.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraServicoHotel : public InterfaceServicoHotel {
    private:
        InterfacePersistenciaHotel *persistencia;
        bool executando = false;

    public:
        void setControladoraPersistencia(InterfacePersistenciaHotel *persistencia) override;

        bool criar(const Hotel &hotel) override;

        bool existeCodigo(const string &codigo) override;

        bool editar(const int &id, const Hotel &hotel) override;

        bool remover(const int &id) override;

        vector<HotelDTO> listarTodos() override;

        int getQuantidadeDeHoteisDoGerente(int gerente_id) override;


        optional<HotelDTO> pesquisar(const int &id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSHOTEL_HPP