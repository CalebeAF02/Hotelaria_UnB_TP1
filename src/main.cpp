#include <iostream>


#include "Modos.hpp"


// Controladoras de Persistencia
#include "AplicacaoSistema.hpp"


using namespace Hotelaria;


int main() {
    AplicacaoSistema app;

    app.iniciar(MODOS::MODO_HACKER);

    return 0;
}