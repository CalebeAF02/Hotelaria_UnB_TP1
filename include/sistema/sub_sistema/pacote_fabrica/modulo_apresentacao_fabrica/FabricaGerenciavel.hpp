//
// Created by caleb on 19/10/2025.
//
/**
 * @file FabricaGerenciavel.hpp
 * @brief Declara a classe template FabricaGerenciavel, responsável por abstrair a criação e manipulação
 *        de entidades gerenciáveis (CRUD) de forma padronizada dentro do sistema.
 *
 * Esta classe tem como objetivo central aplicar o padrão de projeto **Factory Method**
 * para encapsular:
 *  - A criação de objetos gerenciáveis por ponteiros inteligentes.
 *  - A execução das operações CRUD sobre qualquer tipo T.
 *  - A integração com o sistema de menus para interação com o usuário.
 *
 * A classe funciona como uma fábrica genérica para qualquer entidade que implemente
 * os métodos públicos obrigatórios:
 *  - criar()
 *  - ler()
 *  - atualizar()
 *  - remover()
 *
 * Arquitetura utilizada:
 *  - Template para reaproveitamento estrutural entre entidades distintas.
 *  - Uso de shared_ptr para garantir gerenciamento automático de memória.
 *  - Menu dinâmico para interação com o usuário.
 */
#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#include <memory>

#include "../../../../../libs/menu/Menu.hpp"
#include "../../../../../libs/formato/Formato.hpp"

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    /**
     * @class FabricaGerenciavel
     * @brief Classe template que encapsula a criação e manipulação de objetos gerenciáveis.
     *
     * Essa classe é responsável por fornecer uma interface padronizada para operações CRUD,
     * permitindo que qualquer tipo T, desde que implemente os métodos esperados, possa ser
     * manipulado de forma uniforme.
     *
     * Exemplo de uso:
     * @code
     * FabricaGerenciavel<GerenteGerenciavel> fabrica;
     * fabrica.criar();     // Cria um gerente
     * fabrica.ler();       // Lê dados do gerente
     * fabrica.atualizar(); // Atualiza dados
     * fabrica.remover();   // Remove entidade
     * @endcode
     *
     * Requisitos para o tipo T:
     *  - Deve possuir métodos públicos: criar(), ler(), atualizar(), remover().
     */
    template<typename T>
    class FabricaGerenciavel {
    public:
        /**
         * @brief Cria um novo objeto do tipo T, encapsulado em um shared_ptr.
         *
         * O método instancia um objeto via make_shared e invoca internamente o método criar()
         * da entidade gerenciável, delegando ao próprio tipo T a responsabilidade pela lógica
         * da criação.
         *
         * @return shared_ptr<T> Objeto criado e inicializado.
         */
        shared_ptr<T> criar() {
            shared_ptr<T> objeto = make_shared<T>();
            objeto->criar();
            return objeto;
        }

        /**
         * @brief Lê informações de um objeto do tipo T.
         *
         * É criada uma instância temporária da entidade que executa sua própria lógica de leitura.
         */
        void ler() {
            shared_ptr<T> objeto = make_shared<T>();
            objeto->ler();
        }

        /**
         * @brief Atualiza dados de um objeto do tipo T.
         *
         * Instancia um objeto e faz com que ele execute sua rotina de atualização.
         */
        void atualizar() {
            shared_ptr<T> objeto = make_shared<T>();
            objeto->atualizar();
        }

        /**
         * @brief Remove uma entidade do tipo T.
         *
         * Invoca dinamicamente o comportamento de remoção definido pelo próprio tipo T.
         */
        void remover() {
            //shared_ptr == Classe de compartilhamento de ponteiros por referencia
            //make_shared == criar um objeto de ponteiro compartilhado
            shared_ptr<T> objeto = make_shared<T>();
            // objeto == FabricaGerenciavel do tipo T.
            // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
            objeto->remover();
        }

        void executarMenu(string tituloStr, bool &executando) {
            Menu menu;

            const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
            const int OPCAO_CRIAR = menu.adcionarItens("criar");
            const int OPCAO_LER = menu.adcionarItens("Ler");
            const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar");
            const int OPCAO_REMOVER = menu.adcionarItens("Remover");

            int opcao = menu.executa(tituloStr);

            if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                executando = false;
                IO::Println("Voce Saiu do Menu CRUD!");
                return;
            } else if (opcao == OPCAO_CRIAR) criar();
            else if (opcao == OPCAO_LER) ler();
            else if (opcao == OPCAO_ATUALIZAR) atualizar();
            else if (opcao == OPCAO_REMOVER) remover();
        }
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H