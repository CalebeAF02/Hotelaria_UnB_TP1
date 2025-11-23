//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_CAPACIDADE_H
#define GERENCIADOR_HOTEL_UNB_CAPACIDADE_H

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    /**
     * @file Capacidade.hpp
     * @brief Declaração da classe Capacidade, responsável por representar e validar valores inteiros de capacidade
     *        dentro do domínio da aplicação hoteleira.
     *
     * @details
     * A classe Capacidade faz parte do módulo de domínio do sistema de Gerenciamento de Hotel.
     * Ela encapsula um valor inteiro que representa alguma forma de capacidade — por exemplo,
     * número máximo de hóspedes permitidos em um quarto, quantidade de unidades disponíveis,
     * capacidade operacional, entre outras métricas específicas do negócio.
     *
     * Esta classe garante que o valor atribuído sempre esteja em um estado válido, evitando
     * inconsistências durante a execução do sistema. Para isso, utiliza o mtodo privado
     * @ref validar, que aplica regras semânticas rígidas sobre o valor recebido.
     *
     * A classe foi projetada segundo princípios de:
     * - **Encapsulamento**: impedindo acesso direto aos atributos internos.
     * - **Segurança semântica**: impedindo valores inválidos ou incoerentes com o domínio.
     * - **Baixo acoplamento**: dependência mínima de outros módulos.
     * - **Alta coesão**: responsabilidade única e bem definida.
     *
     * Este arquivo integra o namespace @ref Hotelaria.
     *
     * @version 1.0
     * @date 01/10/2025
     * @author Caleb
     */
    /**
     * @class Capacidade
     * @brief Representa um valor inteiro que simboliza uma capacidade no contexto hoteleiro.
     *
     * @details
     * A classe Capacidade abstrai um valor numérico cuja função é indicar limites operacionais ou
     * físicos dentro do sistema de hotelaria. Seu objetivo principal é evitar que valores inválidos
     * sejam utilizados, garantindo consistência no fluxo do software.
     *
     * Exemplos de uso:
     * - Capacidade máxima de hóspedes em um quarto.
     * - Número máximo de reservas simultâneas.
     * - Quantidade de unidades disponíveis para um serviço.
     *
     * A classe inclui:
     * - Construtor padrão.
     * - Construtor explícito com validação imediata.
     * - Métodos de acesso (getters/setters) com proteções semânticas.
     *
     * Regras de validação geralmente incluem:
     * - Não aceitar valores negativos.
     * - Impedir valores incompatíveis com os limites físicos da operação.
     *
     * O método @ref validar é responsável por aplicar tais regras.
     */
    class Capacidade {
    private:
        /**
         * @brief Armazena o valor inteiro da capacidade.
         *
         * @details
         * Este atributo representa numericamente o limite definido pelo domínio.
         * A classe assegura que esse valor é sempre válido por meio da validação no setter
         * e no construtor parametrizado.
         */
        int capacidadeInt;

        /**
         * @brief Verifica se o valor fornecido atende às regras de validade do domínio.
         *
         * @param valor Valor inteiro a ser validado.
         *
         * @throw std::invalid_argument Se o valor for negativo ou não atender às regras de negócio.
         *
         * @details
         * Este método é fundamental para garantir integridade lógica no sistema.
         * A validação deve incluir regras como:
         * - O valor não pode ser menor que zero.
         * - O valor deve estar dentro dos limites definidos pelo contexto de uso.
         *
         * Caso a validação falhe, uma exceção é lançada para impedir que o objeto entre
         * em um estado inválido.
         */
        void validar(int valor);

    public:
        /**
         * @brief Construtor padrão da classe Capacidade.
         *
         * @details
         * Cria um objeto sem valor inicial definido. O valor deverá ser estabelecido posteriormente
         * com @ref setValor, que realizará nova validação.
         */
        Capacidade() = default;

        /**
         * @brief Construtor explícito que recebe um valor de capacidade.
         *
         * @param valor Referência constante para o valor inteiro a ser definido.
         *
         * @details
         * Imediatamente após a criação do objeto, o valor passado é validado.
         * Caso seja inválido, uma exceção é lançada, impedindo que o objeto seja criado em estado incorreto.
         */
        explicit Capacidade(const int &valor);

        /**
         * @brief Define um novo valor para a capacidade.
         *
         * @param valor Valor inteiro a ser atribuído.
         *
         * @throw std::invalid_argument Se o valor fornecido for inválido.
         *
         * @details
         * Antes de armazenar o valor, o método chama @ref validar para assegurar conformidade
         * com as regras do domínio. Caso a validação seja bem-sucedida, o valor é atribuído
         * ao atributo interno.
         */
        void setValor(const int &valor);

        /**
         * @brief Obtém o valor atual da capacidade.
         *
         * @return int Valor inteiro armazenado.
         *
         * @details
         * Este método fornece acesso seguro ao valor encapsulado. Não altera o estado do objeto
         * e pode ser utilizado em contextos de somente leitura.
         */
        int getValor() const;
    };
}

#endif //GERENCIADOR_HOTEL_UNB_CAPACIDADE_H