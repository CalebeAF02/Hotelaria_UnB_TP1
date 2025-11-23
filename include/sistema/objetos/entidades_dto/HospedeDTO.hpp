//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class HospedeDTO {
    private:
        int id;
        string nome;
        string email;
        string endereco;
        string cartao;

    public:
        HospedeDTO() = default;

        HospedeDTO(int id, string nome, string email, string endereco, string cartao) : id(id),
            nome(nome), email(email), endereco(endereco), cartao(cartao) {
        };

        int getId() const;

        void setId(int valor);

        string getNome() const;

        void setNome(const string &valor);

        string getEmail() const;

        void setEmail(const string &valor);

        string getEndereco() const;

        void setEndereco(const string &valor);

        string getCartao() const;

        void setCartao(const string &valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_HOSPEDEDTO_HPP