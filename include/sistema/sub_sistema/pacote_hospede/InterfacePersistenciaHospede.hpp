//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP

#include "HospedeDTO.hpp"
#include "Hospede.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    class InterfacePersistenciaHospede {
    public:
        virtual bool inserir(const Hospede &hospede) = 0;

        virtual bool atualizar(const Email &email, const Hospede &hospede) = 0;

        virtual bool excluir(const int &id) = 0;

        virtual vector<HospedeDTO> listar() = 0;

        virtual optional<HospedeDTO> pesquisar(const int &id) = 0;

        virtual optional<HospedeDTO> pesquisarPorEmail(const string email) = 0;

        virtual bool existeEmail(const string &email) = 0;

        virtual ~InterfacePersistenciaHospede() = default;
    };
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAHOSPEDE_HPP