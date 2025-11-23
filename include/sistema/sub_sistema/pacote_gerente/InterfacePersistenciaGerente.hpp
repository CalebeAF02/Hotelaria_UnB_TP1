//
// Created by caleb on 19/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP

#include "GerenteDTO.hpp"
#include "Gerente.hpp"

#include <vector>
#include <optional>

namespace Hotelaria {
    class InterfacePersistenciaGerente {
    public:
        virtual bool inserir(const Gerente &gerente) = 0;

        virtual bool autenticar(const string &email, const string &senha) = 0;

        virtual bool atualizar(const Email &email, const Gerente &gerente) = 0;

        virtual bool excluir(const int &id) = 0;

        virtual vector<GerenteDTO> listar() = 0;

        virtual optional<GerenteDTO> pesquisarPorID(const int &id) = 0;

        virtual optional<GerenteDTO> pesquisarPorEmail(const string email) = 0;

        virtual bool existeEmail(const string &email) = 0;

        virtual ~InterfacePersistenciaGerente() = default;
    };
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_INTERFACEPERSISTENCIAGERENTE_HPP