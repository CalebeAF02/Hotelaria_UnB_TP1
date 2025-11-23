//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include <iostream>
#include <string>
#include "sqlite3.h"
#include "Menu.hpp"
#include "Formato.hpp"

using namespace std;

namespace Hotelaria {
    class Sistema {
    private:
        bool executando = true;
        bool gerente_autenticado = false;
        int gerente_id;

    public:
        Sistema();

        void exibirMenu();

        void iniciar();

        void setGerenteID(int valor);

        void setGerenteAutenticado(bool valor);

        bool getGerenteID();

        bool getGerenteAutenticado();

        static constexpr int MAXIMO_HOTEL_POR_GERENTE = 2;
        static constexpr int MAXIMO_QUARTOS_POR_HOTEL = 4;
    };
}
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H