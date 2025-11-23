//
// Created by caleb on 09/11/2025.
//

#ifndef Hotelaria_UnB_TP1_GERENTEDTO_HPP
#define Hotelaria_UnB_TP1_GERENTEDTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class GerenteDTO {
    private:
        int id;
        string nome;
        string email;
        string ramal;
        string senha;

    public:
        GerenteDTO() = default;

        GerenteDTO(int id, string nome, string email, string ramal) : id(id), nome(nome),
                                                                      email(email), ramal(ramal) {
        };

        int getId() const;

        void setId(int valor);

        string getNome() const;

        void setNome(const string &valor);

        string getEmail() const;

        void setEmail(const string &valor);

        string getRamal() const;

        void setRamal(const string &valor);

        string getSenha() const;

        void setSenha(const string &valor);
    };
}

#endif //Hotelaria_UnB_TP1_GERENTEDTO_HPP