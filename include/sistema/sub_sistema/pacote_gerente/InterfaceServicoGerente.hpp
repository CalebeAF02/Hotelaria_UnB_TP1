//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISP_HPP
#define Hotelaria_UnB_TP1_ISP_HPP

#include "InterfacePersistenciaGerente.hpp"
#include "Gerente.hpp"
#include "Email.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class InterfaceServicoGerente {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaGerente *persistencia) = 0;

        virtual bool criar(const Gerente &gerente) = 0;

        virtual bool editar(const Email &email, const Gerente &gerenteAtualizado) = 0;

        virtual bool remover(const int &id) = 0;

        virtual vector<GerenteDTO> listarTodos() = 0;

        virtual optional<GerenteDTO> pesquisar(const int &id) = 0;

        virtual optional<GerenteDTO> pesquisarPorEmail(const string email) =0;

        virtual ~InterfaceServicoGerente() = default;
    };
}


#endif //Hotelaria_UnB_TP1_ISP_HPP