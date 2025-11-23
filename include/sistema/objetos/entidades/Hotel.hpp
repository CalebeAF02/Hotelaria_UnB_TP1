#ifndef HOTEL_INCLUDE
#define HOTEL_INCLUDE

#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"
#include "HotelDTO.hpp"

#include <string>

using namespace std;

namespace Hotelaria {
    class Hotel {
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;
        int gerente_id;

    public:
        Hotel() = default;

        Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo, int gerente_id);

        Hotel(HotelDTO &hotel_dto);

        void setNome(const Nome &newNome);

        void setEndereco(const Endereco &newEndereco);

        void setTelefone(const Telefone &newTelefone);

        void setCodigo(const Codigo &newCodigo);

        string getNome() const;

        string getEndereco() const;

        string getTelefone() const;

        string getCodigo() const;

        void setGerenteId(const int &newGerenteId);

        int getGerenteId() const;
    };
}

#endif