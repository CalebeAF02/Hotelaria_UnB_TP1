//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOTEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOTEL_HPP

#include "HotelDTO.hpp"
#include "Hotel.hpp"

#include <optional>
#include <vector>

namespace Hotelaria {
    class InterfacePersistenciaHotel {
    public:
        virtual bool inserir(const Hotel &hotel) = 0;

        virtual bool atualizar(const int &id, const Hotel &hotel) = 0;

        virtual bool excluir(const int &id) = 0;

        virtual vector<HotelDTO> listar() = 0;

        virtual optional<HotelDTO> pesquisar(const int &id) = 0;

        virtual bool existeCodigo(const string &codigo) = 0;

        virtual int getQuantidadeDeHoteisDoGerente(int gerente_id) = 0;

        virtual ~InterfacePersistenciaHotel() = default;
    };
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOTEL_HPP