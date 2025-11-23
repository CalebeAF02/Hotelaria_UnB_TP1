//
// Created by caleb on 16/10/2025.
//
/**
 * @file InterfaceFabricaGerenciavel.hpp
 * @brief Declara a interface base para fábricas responsáveis por produzir menus CRUD
 *        associados a entidades gerenciáveis do sistema.
 *
 * Esta interface estabelece o contrato que todas as fábricas de operações CRUD devem seguir
 * no sistema de gerenciamento hoteleiro. Ela é utilizada como parte de um padrão
 * arquitetural que separa:
 *  - A lógica de apresentação (menus interativos)
 *  - A lógica de domínio (entidades)
 *  - A lógica de persistência (camada de dados)
 *
 * O objetivo é permitir que cada entidade (Gerente, Hotel, Quarto, Hóspede, etc.)
 * possua sua própria fábrica de menus CRUD, totalmente encapsulada.
 */
#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H

#include <memory>
#include "../../../../libs/menu/MenuCRUD.hpp"

using namespace std;

namespace Hotelaria {
    /**
     * @class InterfaceFabricaGerenciavel
     * @brief Interface abstrata responsável por definir a criação de menus CRUD
     *        para entidades gerenciáveis do sistema.
     *
     * Esta interface aplica o padrão **Abstract Factory** permitindo que cada entidade
     * implemente sua própria fábrica de menus, mantendo a arquitetura modular,
     * extensível e de baixo acoplamento.
     *
     * Qualquer classe concreta que herde desta interface deve implementar o método
     * criar(), que retorna um objeto MenuCRUD totalmente configurado.
     *
     * Exemplo de implementação:
     * @code
     * class FabricaGerente : public InterfaceFabricaGerenciavel {
     * public:
     *     unique_ptr<MenuCRUD> criar() override {
     *         return make_unique<MenuCRUD>("Gerenciar Gerentes");
     *     }
     * };
     * @endcode
     */
    class InterfaceFabricaGerenciavel {
    public:
        /**
         * @brief Cria e retorna um menu CRUD associado a uma entidade específica.
         *
         * O método deve retornar um objeto único (unique_ptr) do tipo MenuCRUD,
         * já configurado com as opções que a entidade em questão oferece.
         *
         * @return unique_ptr<MenuCRUD> Ponteiro único para o menu CRUD criado.
         */
        virtual unique_ptr<MenuCRUD> criar() = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Permite que a destruição correta ocorra em heranças polimórficas.
         */
        virtual ~InterfaceFabricaGerenciavel() = default;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEFABRICAGERENCIAVEL_H