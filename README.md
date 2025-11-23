# 🏨 Hotelaria_UnB_TP1

Projeto acadêmico em **C++**, desenvolvido na Universidade de Brasília (UnB), com foco em **Programação Orientada a
Objetos (POO)**, **arquitetura modular**, **persistência com SQLite** e **documentação automatizada com Doxygen**.

O sistema simula um **gerenciador de hotel**, permitindo:

- Cadastro e login de **hóspedes** e **gerentes**
- Gerenciamento de **quartos**, **reservas**, **solicitações** e **hotéis**
- Validação de dados diretamente nas classes de domínio
- Navegação por menus interativos via **interface de terminal (CLI)**
- Separação por pacotes funcionais: apresentação, serviço, persistência e fábrica

---

## 🚀 Funcionalidades Atuais

- Interface de terminal com menus dinâmicos
- CRUD completo de gerentes
- Fluxo de hóspedes com registro de hospedagem e consulta de status
- Validação embutida nos domínios com tratamento de exceções
- Persistência local com banco SQLite (`hotel.db`)
- Documentação gerada automaticamente em `docs/html` e `docs/latex`
- Script `gerar_documentacao.bat` para automatizar a geração da documentação
- Modo de desenvolvimento com acesso rápido via `SistemaHacker`

---

## 🧭 Linha do Tempo de Funcionalidades

| Etapa | Funcionalidade      | Descrição                                            |
|-------|---------------------|------------------------------------------------------|
| 1️⃣   | Tela Inicial        | Escolha entre gerente ou hóspede                     |
| 2️⃣   | Acesso como Gerente | Menu com opções de criar, logar e gerenciar          |
| 3️⃣   | Criar Gerente       | Cadastro com validação de nome, email, ramal e senha |
| 4️⃣   | Login de Gerente    | Verificação no banco com feedback de sucesso ou erro |
| 5️⃣   | Central de Serviços | Acesso às operações CRUD de gerentes                 |
| 6️⃣   | Ler Gerentes        | Listagem formatada dos gerentes cadastrados          |
| 7️⃣   | Remover Gerente     | Exclusão por email com confirmação                   |
| 8️⃣   | Acesso como Hóspede | Menu com opções de hospedagem e status               |
| 9️⃣   | Criar Solicitação   | Interface para registrar interesse em hospedagem     |
| 🔟    | Ver Status          | Consulta ao status da solicitação feita              |
| 🔜    | Atualizar Gerente   | (Em desenvolvimento) Edição de dados do gerente      |

---

## 🧭 Fluxo de Navegação

- Gerente:
    - Login via autenticação persistente
    - Acesso à central de serviços
    - CRUD de gerentes, hotéis, quartos, reservas
    - Avaliação de solicitações de hospedagem
- Hóspede:
    - Registro de solicitação de hospedagem
    - Consulta de status por email
- Hacker:
    - Criação automática de gerente para testes
    - Acesso direto à central de serviços

---

## 📸 Exemplos Visuais da Interface

### 🏁 Tela Inicial do Sistema

![Tela de boas-vindas com opções de acesso](docs/imagens/tela_inicial.png)

### 🛏️ Menu para Hospedagem

![Menu para hospedagem com opções de solicitação e status](docs/imagens/menu_hospedagem.png)

### 🧑‍💼 Menu Inicial do Gerente

![Opções de criar gerente ou fazer login](docs/imagens/menu_inicial_gerente.png)

### Tentativa de Login com Erro

![Erro de login: usuário não encontrado ou senha incorreta](docs/imagens/login_erro.png)

### 👤 Cadastro de Novo Gerente

![Cadastro de gerente com nome, email, ramal e senha](docs/imagens/cadastro_gerente.png)

### 🔐 Login de Gerente com Sucesso

![Login realizado com sucesso e acesso à central de serviços](docs/imagens/login_sucesso_menu_servicos.png)

### 🧠 Central de Serviços

![Menu principal após login, com acesso aos módulos do sistema](docs/imagens/central_servicos.png)

### 🧭 Menu CRUD de Gerentes

![Central de serviços com opções de criar, ler, atualizar e remover](docs/imagens/menu_crud_gerente.png)

### 📋 Lista de Gerentes

![Exibição dos gerentes cadastrados](docs/imagens/lista_gerentes.png)

---

## 📂 Estrutura do Projeto

Hotelaria_UnB_TP1/
├── docs/ # Documentação gerada (HTML/LaTeX/Imagens)
├── include/ # Headers (.hpp) da aplicação
│ ├── HACKER/
│ │ └── SistemaHacker.hpp
│ └── sistema/
│ ├── banco/
│ │ └── BancoDeDados.hpp
│ ├── objetos/
│ │ ├── dominios/ # Tipos de valor com validação (Nome, Email, Senha, etc.)
│ │ ├── entidades/ # Pessoa, Gerente, Hospede, Hotel, Quarto, Reserva, SolicitacaoHospedagem
│ │ ├── entidades_dto/ # DTOs correspondentes
│ │ └── sub_sistema/
│ │ ├── ControladoraPersistenciaSolicitacaoHospedagem.hpp
│ │ ├── pacote_acesso/
│ │ │ ├── InterfaceApresentacaoAcessoGerente.hpp
│ │ │ ├── InterfaceApresentacaoAcessoHospede.hpp
│ │ │ └── modulo_apresentacao_acesso/
│ │ │ ├── ControladoraApresentacaoAcessoGerente.hpp
│ │ │ └── ControladoraApresentacaoAcessoHospede.hpp
│ │ ├── pacote_autenticavel/
│ │ │ ├── InterfaceApresentacaoAutenticavel.hpp
│ │ │ ├── InterfacePersistenciaAutenticavel.hpp
│ │ │ ├── InterfaceServicoAutenticavel.hpp
│ │ │ ├── modulo_apresentacao_autenticavel/
│ │ │ │ └── ControladoraApresentacaoAutenticavel.hpp
│ │ │ ├── modulo_persistencia_autenticavel/
│ │ │ │ └── ControladoraPersistenciaAutenticavel.hpp
│ │ │ └── modulo_servico_autenticavel/
│ │ │ └── ControladoraServicoAutenticavel.hpp
│ │ ├── pacote_fabrica/
│ │ │ ├── InterfaceFabricaGerenciavel.hpp
│ │ │ └── modulo_apresentacao_fabrica/
│ │ │ └── FabricaGerenciavel.hpp
│ │ ├── pacote_gerente/
│ │ │ ├── InterfaceApresentacaoGerente.hpp
│ │ │ ├── InterfacePersistenciaGerente.hpp
│ │ │ ├── InterfaceServicoGerente.hpp
│ │ │ ├── modulo_apresentacao_gerente/
│ │ │ │ └── ControladoraApresentacaoGerente.hpp
│ │ │ ├── modulo_persistencia_gerente/
│ │ │ │ └── ControladoraPersistenciaGerente.hpp
│ │ │ └── modulo_servico_gerente/
│ │ │ └── ControladoraServicoGerente.hpp
│ │ ├── pacote_hospede/
│ │ │ ├── InterfaceApresentacaoHospede.hpp
│ │ │ ├── InterfacePersistenciaHospede.hpp
│ │ │ ├── InterfaceServicoHospede.hpp
│ │ │ ├── modulo_apresentacao_hospede/
│ │ │ │ └── ControladoraApresentacaoHospede.hpp
│ │ │ ├── modulo_persistencia_hospede/
│ │ │ │ └── ControladoraPersistenciaHospede.hpp
│ │ │ └── modulo_servico_hospede/
│ │ │ └── ControladoraServicoHospede.hpp
│ │ ├── pacote_hotel/
│ │ │ ├── InterfaceApresentacaoHotel.hpp
│ │ │ ├── InterfacePersistenciaHotel.hpp
│ │ │ ├── InterfaceServicoHotel.hpp
│ │ │ ├── modulo_apresentacao_hotel/
│ │ │ │ └── ControladoraApresentacaoHotel.hpp
│ │ │ ├── modulo_persistencia_hotel/
│ │ │ │ └── ControladoraPersistenciaHotel.hpp
│ │ │ └── modulo_servico_hotel/
│ │ │ └── ControladoraServicoHotel.hpp
│ │ ├── pacote_quarto/
│ │ │ ├── InterfaceApresentacaoQuarto.hpp
│ │ │ ├── InterfacePersistenciaQuarto.hpp
│ │ │ ├── InterfaceServicoQuarto.hpp
│ │ │ ├── modulo_apresentacao_quarto/
│ │ │ │ └── ControladoraApresentacaoQuarto.hpp
│ │ │ ├── modulo_persistencia_quarto/
│ │ │ │ └── ControladoraPersistenciaQuarto.hpp
│ │ │ └── modulo_servico_quarto/
│ │ │ └── ControladoraServicoQuarto.hpp
│ │ └── pacote_reserva/
│ │ ├── InterfaceApresentacaoReserva.hpp
│ │ ├── InterfacePersistenciaReserva.hpp
│ │ ├── InterfaceServicoReserva.hpp
│ │ ├── modulo_apresentacao_reserva/
│ │ │ └── ControladoraApresentacaoReserva.hpp
│ │ ├── modulo_persistencia_reserva/
│ │ │ └── ControladoraPersistenciaReserva.hpp
│ │ └── modulo_servico_reserva/
│ │ └── ControladoraServicoReserva.hpp
│ └── utilitarios/
│ ├── enum/ # Modos.hpp
│ ├── Utils.hpp
│ ├── AplicacaoSistema.hpp
│ ├── Sistema.hpp
│ ├── SistemaSessao.hpp
│ └── Versao.hpp
├── libs/ # Bibliotecas e componentes reutilizáveis
│ ├── formato/ # Formato.cpp/.hpp
│ ├── io/ # IO.cpp/.hpp
│ ├── menu/ # Menu, MenuCRUD, MenuItem, ExibirMenu
│ ├── sqlite/ # sqlite3.c/.h (embutido)
│ ├── tabela/ # Atributo, Linha, Tabela, TamanhoAtributo
│ └── teste/ # SmokeTeste, InterfaceDeTestes
├── src/ # Implementações (.cpp) — espelha include/ quando aplicável
│ ├── HACKER/SistemaHacker.cpp
│ └── sistema/sub_sistema/
│ ├── ControladoraPersistenciaSolicitacaoHospedagem.cpp
│ ├── pacote_acesso/
│ │ └── modulo_apresentacao_acesso/
│ │ ├── ControladoraApresentacaoAcessoGerente.cpp
│ │ └── ControladoraApresentacaoAcessoHospede.cpp
│ ├── pacote_autenticavel/
│ │ ├── modulo_apresentacao_autenticavel/
│ │ │ └── ControladoraApresentacaoAutenticavel.cpp
│ │ ├── modulo_persistencia_autenticavel/
│ │ │ └── ControladoraPersistenciaAutenticavel.cpp
│ │ └── modulo_servico_autenticavel/
│ │ └── ControladoraServicoAutenticavel.cpp
│ ├── pacote_fabrica/
│ │ └── modulo_apresentacao_fabrica/
│ │ └── FabricaGerenciavel.cpp
│ ├── pacote_gerente/
│ │ ├── modulo_apresentacao_gerente/
│ │ │ └── ControladoraApresentacaoGerente.cpp
│ │ ├── modulo_persistencia_gerente/
│ │ │ └── ControladoraPersistenciaGerente.cpp
│ │ └── modulo_servico_gerente/
│ │ └── ControladoraServicoGerente.cpp
│ ├── pacote_hospede/
│ │ ├── modulo_apresentacao_hospede/
│ │ │ └── ControladoraApresentacaoHospede.cpp
│ │ ├── modulo_persistencia_hospede/
│ │ │ └── ControladoraPersistenciaHospede.cpp
│ │ └── modulo_servico_hospede/
│ │ └── ControladoraServicoHospede.cpp
│ ├── pacote_hotel/
│ │ ├── modulo_apresentacao_hotel/
│ │ │ └── ControladoraApresentacaoHotel.cpp
│ │ ├── modulo_persistencia_hotel/
│ │ │ └── ControladoraPersistenciaHotel.cpp
│ │ └── modulo_servico_hotel/
│ │ └── ControladoraServicoHotel.cpp
│ ├── pacote_quarto/
│ │ ├── modulo_apresentacao_quarto/
│ │ │ └── ControladoraApresentacaoQuarto.cpp
│ │ ├── modulo_persistencia_quarto/
│ │ │ └── ControladoraPersistenciaQuarto.cpp
│ │ └── modulo_servico_quarto/
│ │ └── ControladoraServicoQuarto.cpp
│ └── pacote_reserva/
│ ├── modulo_apresentacao_reserva/
│ │ └── ControladoraApresentacaoReserva.cpp
│ ├── modulo_persistencia_reserva/
│ │ └── ControladoraPersistenciaReserva.cpp
│ └── modulo_servico_reserva/
│ └── ControladoraServicoReserva.cpp
├── meta/ # Tema Doxygen Awesome e customizações (CSS/JS/header)
├── testes/
│ ├── testes_dominios/ # Testes por domínio
│ └── testes_entidades/ # Testes por entidade
├── Doxyfile
├── gerar_documentacao.bat
└── README.md



---

## 🔹 Validação Embutida nos Domínios

A validação de dados agora é feita diretamente dentro das classes de domínio. Cada classe é responsável por garantir sua
própria integridade, lançando exceções (`invalid_argument`) quando os dados são invalidos.

Exemplos:

Nome nome("Calebe"); // valido  
Email email("email@invalido"); // lança exceção  
Senha senha("123"); // lança exceção se nao atender aos critérios

### 🔹 Utilitários Genéricos

Algumas validações genéricas ainda são mantidas para entradas livres:

- ValidarString → valida strings genéricas (menus, comandos)
- ValidarInt → valida inteiros fora dos domínios

---

## 🧪 Testes

- TesteValidadores: conjunto de testes unitários para verificar os domínios
- Contadores estáticos para monitorar execução:
- contTotalTestes
- contTotalTestesOk
- contTotalTestesProblema

---

## 🛠️ Como Compilar

mkdir build && cd build  
cmake ..  
make  
./gerenciador_hotel_unb

Este projeto já inclui o SQLite como biblioteca estática:

- libs/sqlite/sqlite3.h → cabeçalho da API
- libs/extern/libsqlite3.a → biblioteca compilada
  Nenhuma instalação externa é necessária. Basta clonar e compilar.

---

## 🤝 Como Contribuir

Se você deseja colaborar com o projeto, siga estas etapas:

1. Clone o repositório :
   git clone https://github.com/CalebeAF02/Gerenciador-De-Hoteis---UNB.git
   cd Gerenciador-De-Hoteis---UNB

2. Crie uma branch :

   git checkout -b nome-da-sua-branch

3. Compile e teste localmente :

   mkdir build && cd build
   cmake ..
   make

4. Commit e push :

   git add .
   git commit -m "feat: descrição clara da funcionalidade"
   git push origin nome-da-sua-branch

5. Abra um Pull Request no GitHub

---

## 📚 Próximos Passos

- Finalizar função de atualização de gerente
- Implementar persistência para hóspedes e solicitações
- Criar exportação de dados para .tsv ou .csv
- Ampliar cobertura dos testes
- Migrar para interface gráfica (Qt ou Web)

---

##🎯 Objetivo Educacional

Este projeto visa aplicar conceitos de POO em C++ moderno, com foco em:

- Herança e Polimorfismo
- Encapsulamento
- Tratamento de exceções
- Arquitetura limpa e boas práticas
- Persistência com banco de dados

---

##👤 Autores

Projeto desenvolvido por:

- [Calebe Alves](https://github.com/CalebeAF02) — Universidade de Brasília (UnB)
- [Artur Silva](https://github.com/TUTUBOY-PRO) — Universidade de Brasília (UnB)

📎 Repositorio: https://github.com/CalebeAF02/gerenciador_hotel_unb

---
