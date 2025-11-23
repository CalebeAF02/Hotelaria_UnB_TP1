#ifndef Hotelaria_UnB_TP1_VERSAO_HPP
#define Hotelaria_UnB_TP1_VERSAO_HPP

#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

namespace Hotelaria {
    class Versao {
    private:
        static constexpr uint64_t valor = 236;
        static inline const string data = "2025-11-23 20:46";

    public:
        static uint8_t patch() { return valor % 10; }
        static uint8_t minor() { return (valor / 10) % 10; }
        static uint64_t major() { return valor / 100; }
        static uint64_t getValor() { return valor; }
        static string getData() { return data; }

        static string getVersaoCompleta() {
            return to_string(major()) + "." +
                   to_string(minor()) + "." +
                   to_string(patch());
        }
    };
}

#endif