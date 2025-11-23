//
// Created by caleb on 08/11/2025.
//

#ifndef Hotelaria_UnB_TP1_HOTELDTO_HPP
#define Hotelaria_UnB_TP1_HOTELDTO_HPP

#include <iostream>

using namespace std;

namespace Hotelaria {
    class HotelDTO {
    private:
        int id;
        string nome;
        string endereco;
        string telefone;
        string codigo;
        int gerente_id;

    public:
        HotelDTO() = default;

        HotelDTO(int id, string nome, string endereco, string telefone, string codigo,
                 int gerenteid) : id(id),
                                  nome(nome), endereco(endereco), telefone(telefone), codigo(codigo),
                                  gerente_id(gerenteid) {
        };

        int getId() const;

        void setId(int valor);

        string getNome() const;

        void setNome(const string &valor);

        string getEndereco() const;

        void setEndereco(const string &valor);

        string getTelefone() const;

        void setTelefone(const string &valor);

        string getCodigo() const;

        void setCodigo(const string &valor);

        int getGerenteID() const;

        void setGerenteID(int valor);
    };
}

#endif //Hotelaria_UnB_TP1_HOTELDTO_HPP