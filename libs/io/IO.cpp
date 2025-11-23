//
// Created by caleb on 02/11/2025.
//

#include "IO.hpp"

#include <regex>

//
// Created by caleb on 02/11/2025.
//
namespace IO {
    string LerLinha() {
        string valor = "";
        // Limpa o buffer antes de ler, para evitar lixo (importante em C++ com cin/getline misturado)
        if (cin.rdbuf()->in_avail() > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        getline(cin, valor);
        return valor;
    }

    string LerOpcao() {
        cout << "Opcao: ";
        return LerLinha();
    }

    void Println(const string &mensagem) {
        cout << mensagem << endl;
    }

    void Println(string mensagem, string valor) {
        string mudar = "{1}";
        size_t start_pos = 0;
        while ((start_pos = mensagem.find(mudar, start_pos)) != std::string::npos) {
            mensagem.replace(start_pos, mudar.length(), valor);
            start_pos += valor.length();
        }
        cout << mensagem << endl;
    }

    void Println(string mensagem, int valor) {
        string s_valor = to_string(valor);
        string mudar = "{1}";
        size_t start_pos = 0;
        while ((start_pos = mensagem.find(mudar, start_pos)) != std::string::npos) {
            mensagem.replace(start_pos, mudar.length(), s_valor);
            start_pos += s_valor.length();
        }

        cout << mensagem << endl;
    }

    void Print(const string &pergunta) {
        cout << pergunta;
    }

    bool tentarNovamente() {
        while (true) {
            Println("Deseja :");
            Formato::OpcaoSimples("Voltar", 0);
            Formato::OpcaoSimples("Tentar novamente", 1);
            string opcaoSTR = LerLinha();
            try {
                int opcaoINT = stoi(opcaoSTR);
                if (opcaoINT == 0) {
                    return false;
                } else if (opcaoINT == 1) {
                    return true;
                } else {
                    Println("Erro: Opcao Invalida (somente 0 ou 1).");
                }
            } catch (const invalid_argument &erro) {
                Println("Erro: Numero fora do limite. Por favor, digite 0 ou 1.");
            }
        }
    }
}