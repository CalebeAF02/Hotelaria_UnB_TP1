//
// Created by caleb on 21/11/2025.
//
/**
 * @file ControladoraPersistenciaAutenticavel.hpp
 * @brief Declara a classe responsável pela autenticação na camada de persistência.
 *
 * Esta classe implementa a interface de persistência voltada para autenticação,
 * realizando a verificação de credenciais diretamente no mecanismo de armazenamento
 * (ex.: arquivos, banco de dados, estruturas internas, etc.).
 *
 * Funciona como a ponte entre a lógica de domínio e o repositório de dados,
 * garantindo encapsulamento e desacoplamento da camada de serviço.
 */
#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP

#include "InterfacePersistenciaAutenticavel.hpp"

namespace Hotelaria {
    /**
     * @class ControladoraPersistenciaAutenticavel
     * @brief Implementa os métodos de autenticação da camada de persistência.
     *
     * Esta classe fornece a implementação concreta para a verificação de login,
     * conforme definido na InterfacePersistenciaAutenticavel.
     *
     * É responsável por:
     * - Acessar os dados persistidos (arquivos, BD, etc.);
     * - Comparar email e senha informados com os registros existentes;
     * - Indicar se a autenticação foi bem-sucedida.
     *
     * Faz parte da arquitetura de camadas do sistema:
     *
     * **Apresentação → Serviço → Persistência**
     *
     * Seu uso é indireto, chamado pela camada de serviço responsável pela autenticação.
     */
    class ControladoraPersistenciaAutenticavel : public InterfacePersistenciaAutenticavel {
    public:
        /**
         * @brief Verifica se email e senha correspondem a um registro válido no sistema.
         *
         * A implementação concreta deste método deve consultar a base de dados persistida
         * e retornar verdadeiro caso o par (email, senha) exista e seja válido.
         *
         * @param email Email informado pelo usuário.
         * @param senha Senha correspondente ao email.
         * @return true se as credenciais forem válidas; false caso contrário.
         */
        bool autenticar(const string &email, const string &senha) override;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAPERSISTENCIAAUTENTICAVEL_HPP