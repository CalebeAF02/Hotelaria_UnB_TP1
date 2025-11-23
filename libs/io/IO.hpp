//
// Created by caleb on 02/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CONSOLEIO_HPP
#define Hotelaria_UnB_TP1_CONSOLEIO_HPP

#include <iostream>
#include <string>
#include <limits> // Para clear/ignore do buffer se necessário
#include "../formato/Formato.hpp"

using namespace std;

// Classe responsável pela manipulação de entrada e saída de dados simples.
namespace IO {
    // Métodos de Input
    string LerLinha();

    // Métodos de Input com texto "Opção: "
    string LerOpcao();

    // Opção para tentar novamente ou sair
    bool tentarNovamente();

    // Métodos de Output Simples
    // Usaremos para imprimir uma mensagens e pular uma linha
    void Println(const string &mensagem);

    // Usaremos para imprimir mensagens na mesma linha
    void Print(const string &mensagem);

    void Println(string mensagem, string valor);

    void Println(string mensagem, int valor);
};

#endif //Hotelaria_UnB_TP1_CONSOLEIO_HPP