#ifndef DATA_INCLUDE
#define DATA_INCLUDE

#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

namespace Hotelaria {
    /**
     * @class Data
     * @brief Representa uma data válida no formato dia/mês/ano.
     *
     * A classe **Data** funciona como um domínio responsável pela validação,
     * armazenamento e manipulação de datas dentro do sistema de hotelaria.
     *
     * Este domínio garante que:
     * - A data informada é válida (ex.: 31/02 não é aceito)
     * - O formato pode ser convertido para string
     * - O sistema trabalha apenas com datas coerentes
     *
     * A classe também define constantes para todos os meses do ano,
     * facilitando o uso em outras partes do sistema.
     *
     * Embora derive de `std::exception`, isso serve apenas para compatibilidade
     * com mecanismos de tratamento de erro presentes em implementações anteriores.
     */
    class Data : public exception {
    private:
        /**
         * @brief Valida se os campos dia, mês e ano armazenados representam uma data real.
         *
         * O método verifica:
         * - Se o mês está no intervalo 1–12
         * - Se o dia é válido para o mês correspondente
         * - Se o ano é positivo
         * - Se fevereiro respeita anos bissextos
         *
         * @throw invalid_argument Caso a data seja inválida.
         */
        void validar();

    public:
        /** @brief Representa o dia do mês (1 a 31, dependendo do mês). */
        int dia;

        /** @brief Representa o mês do ano (1 a 12). */
        int mes;

        /** @brief Representa o ano (valor positivo). */
        int ano;

        static int const JAN = 1;
        static int const FEV = 2;
        static int const MAR = 3;
        static int const ABR = 4;
        static int const MAI = 5;
        static int const JUN = 6;
        static int const JUL = 7;
        static int const AGO = 8;
        static int const SET = 9;
        static int const OUT = 10;
        static int const NOV = 11;
        static int const DEZ = 12;

        /**
         * @brief Construtor padrão.
         *
         * Cria uma data sem valores definidos.
         * Os valores deverão ser definidos posteriormente via @ref setData.
         */
        Data() = default;

        /**
         * @brief Construtor que aceita uma string no formato "DD/MM/AAAA".
         *
         * O valor é analisado, convertido para inteiros e validado.
         *
         * @param dataStr Representação textual da data.
         *
         * @throw invalid_argument Caso a string não esteja no formato correto ou a data seja inválida.
         *
         * ### Exemplo:
         * @code
         * Data d("25/12/2025");
         * @endcode
         */
        explicit Data(const string &valor);

        /**
         * @brief Converte a data atual para o formato "DD/MM/AAAA".
         *
         * @return Uma string representando a data.
         *
         * ### Exemplo:
         * @code
         * Data d("01/01/2026");
         * cout << d.toString();   // "1/1/2026"
         * @endcode
         */
        string toString();

        /**
         * @brief Define os campos dia, mês e ano simultaneamente.
         *
         * Após definir os valores, o método @ref validar é chamado para garantir
         * que a data seja real.
         *
         * @param d Dia.
         * @param m Mês.
         * @param a Ano.
         *
         * @throw invalid_argument Caso a data seja inválida.
         */
        void setData(int d, int m, int a);

        /**
         * @brief Retorna o dia armazenado.
         *
         * @return Inteiro representando o dia do mês.
         */
        int getDia();

        /**
         * @brief Retorna o mês armazenado.
         *
         * @return Inteiro representando o mês do ano.
         */
        int getMes();

        /**
         * @brief Retorna o ano armazenado.
         *
         * @return Inteiro representando o ano.
         */
        int getAno();
    };
}

#endif