//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSP_HPP
#define Hotelaria_UnB_TP1_CSP_HPP

#include "InterfaceServicoGerente.hpp"
#include "InterfacePersistenciaGerente.hpp"
#include "ControladoraPersistenciaGerente.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraServicoGerente : public InterfaceServicoGerente {
    private:
        InterfacePersistenciaGerente *persistencia = nullptr;
        bool executando = false;

    public:
        void setControladoraPersistencia(InterfacePersistenciaGerente *persistencia) override;

        bool criar(const Gerente &gerente) override;

        bool editar(const Email &email, const Gerente &gerenteAtualizado) override;

        bool remover(const int &id) override;

        vector<GerenteDTO> listarTodos() override;

        optional<GerenteDTO> pesquisar(const int &id) override;

        optional<GerenteDTO> pesquisarPorEmail(const string email) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSP_HPP