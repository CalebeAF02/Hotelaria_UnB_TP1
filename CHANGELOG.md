# Histórico de Alterações (Changelog) - Gerenciador de Hotéis

Todas as mudanças notáveis neste projeto serão documentadas aqui.

Este projeto segue o formato [Keep a Changelog](https://keepachangelog.com/pt-BR/1.0.0/)
e [Semantic Versioning](https://semver.org/lang/pt-BR/).

# Histórico de Alterações (Changelog) - Hotelaria_UnB_TP1

Todas as mudanças notáveis neste projeto serão documentadas aqui.  
Este projeto segue o formato [Keep a Changelog](https://keepachangelog.com/pt-BR/1.0.0/)
e [Semantic Versioning](https://semver.org/lang/pt-BR/).

---

## [Unreleased]

- Implementar CRUD completo de reservas.
- Integração com sessão para restringir operações.
- Exportação de dados para `.csv` ou `.tsv`.
- Interface gráfica futura (Qt ou Web).

---

## [1.1.4] - 2025-11-23

### Adicionado

- **Feature:** Modelo de documentação definido.
- **Feature:** Impede o cadastro de Gerente com email duplicado.
- **Feature:** Verifica se email existe na tabela Gerentes do banco de dados.
- **Feature:** Implementando DTOs.
- **Feature:** Método `TentarNovamente` para fluxo de interação.
- **Feature:** Remoção de gerente (CRUD completo).

### Refatorado

- Refatoração da `SolicitacaoHospedagem` (corrigindo uso de `stoi(email)` e ordem dos parâmetros).
- Refatoração do `Main` para organização do fluxo principal.
- Refatoração completa dos objetos e do `sub_sistema`.
- Mudança conceitual na organização das interfaces e serviços.
- Refatoração do modo Hacker (autenticação e fluxo).
- Refatoração de namespaces: `Hotelaria`, `Utils`, `Menu`, `VisualizadorDeTabela`, `Formato`, `IO`, `Teste`.
- Refatoração de entidades, domínios e DTOs movidos para pasta `objetos`.
- Refatoração de autenticação (novo modelo).
- Refatoração de documentação e organização de módulos.
- Refatoração de nomes de métodos e classes do Console.
- Refatoração para uso de `PrintMensagem`, `Pergunta`, `SubPergunta`.

### Corrigido

- Correção do laço de execução do sistema.
- Correção na organização do banco de dados.

### Documentação

- Produção de diagramas de testes e sub_sistemas.
- Produção de diagramas de classes completos.
- Documentação com Doxygen.
- Atualização do README.
- Diagramas de domínios e entidades (incluindo versão em Mermaid).
- Remoção de testes de diagramas obsoletos.

### Estilo

- Organização geral do projeto (`.hpp` declarações, `.cpp` implementações).
- Reformatando código e organização visual.
- Padronização de estilo em múltiplos módulos.

### Build

- Atualização do Doxyfile.
- Organização de versão.
- Integração do Doxygen no fluxo de build.

### Removido

- Remoção da pasta `.idea` do versionamento.
- Exclusão da pasta de validação principal.
- Remoção de docs antigos e arquivos de build desnecessários.

---

### Versao 1.1.3 - 2025-11-09

#### Adicionado

* **Feature:** Adicionando Versionamento (`#6`, `#7`).
* **Feature:** Apresenta atualização de um Hotel por ID.
* **Feature:** Verifica se a string é um número inteiro.
* **Feature:** Criação de `GerenteDTO`.
* **Recurso:** Implementação da classe `Tabela`.

#### Refatorado

* Refatoração de DTOs para operações de Atualização e Leitura.
* Refatoração para utilização da classe `Tabela` para melhor exibição.
* Refatoração dos *logs* de comentários do banco de dados.
* Refatoração do código de atualização do Hotel.

#### Estilo

* Formatando código (`close #6`, `close #7`).
* Projeto completamente reformatado.

### Versao 1.1.2 - 2025-11-08

#### Refatorado

* Refatoração de `Hacker`, `HotelDTO` e `ControladorInterfaceHotel`.
* Refatoração das bibliotecas SQLite.
* Refatoração do código principal e do sistema.
* Refatoração e renomeação de `MostrarTabelaGenerica` para `ConsoleFormater`.
* Refatoração do método de leitura (`ler->Gerentes`).

### Versao 1.1.1 - 2025-11-07

#### Refatorado

* Código completamente formatado.
* Finalização dos `TestesEntidades` e `TestesDominios`.
* *Bugs* resolvidos após a finalização dos testes.

### Versao 1.1.0 - 2025-11-03 (Grande Refatoração de Testes e Visuais)

#### Refatorado

* Finalização e refatoração dos `TestesEntidades`, `Teste de Fumaça`, `TestandoSmoke`, e `InterfaceDeTest`.
* Refatoração de `ConsoleIO` e `ConsoleFormatter`, com novos visuais e novo Resumo de Testes.

#### Tarefa

* Adicionado `.gitattributes` para corrigir a contagem de linguagens (C++).

### Versao 1.0.1 - 2025-11-02

#### Refatorado

* Criação da classe `TestandoSmoke` para encapsular a chamada dos testes (deixando `Smoke_Tests` apenas com os métodos).
* Arquivos de cabeçalho (`.h`) foram transformados para o padrão `.hpp`.
* Atualizações no `CMakeLists.txt`.

### Versao 1.0.0 - 2025-11-01 (Lançamento Estável - Features de Gerente/Hotel)

#### Adicionado

* **Recurso:** Implementação da funcionalidade `Criar Hotel`.
* **Recurso:** Implementação da `InterfaceApresentaçãoExibirMenu`.
* **Recurso:** Implementação da `InterfaceApresentaçãoAutênticavel`.

#### Corrigido

* Correção no fluxo de Solicitação de Hospedagem.
* Correção de *bug* no módulo Gerente que ocorria quando o *login* falhava.
* Correção de `Interface Autenticação (Apresentação)` duplicada.
* Correção no fluxo: Não existe mais *login* para Hóspede (apenas Solicitação de Hospedagem).

#### Refatorado

* Organização completa do Módulo Gerente (`InterfaceApresentação`, `InterfaceServiço`, `Controlador`).
* Refatoração dos Menus de Serviços.
* Métodos `ExibirMenu` e `ExibirCentralDeServico` movidos para a Classe `Sistema`.
* Implementação do *status* em `enum` para Solicitação de Hospedagem (`close #4`).
* Atualização e refatoração dos Testes.

#### Tarefa

* Remoção das classes `HospedeGerenciavel` e `GerenteGerenciavel`.

### Versao 0.5.0 - 2025-10-31 (Estabilização do Banco de Dados/SQLite)

#### Corrigido

* Correção do *bug* de autenticação do hóspede.
* Correção para compilar SQLite como C, evitando conflitos com C++.

#### Refatorado

* Reorganização de `sqlite3.h` e `libsqlite3.a`.
* Ajuste na estrutura SQLite e atualização de testes e entidades.
* Renomeação de `sqlite3.c` para `.cpp` e ajuste no `CMakeLists.txt`.

#### Documentação

* Atualização do `README` com estrutura, autores e instruções de contribuição.
* Adição do `Changelog` com histórico completo do projeto.

#### Tarefa

* Adicionado `libsqlite3.a` e cabeçalho `sqlite3.h`.
* Integração do SQLite como biblioteca estática e ajustes no `main`.

### Versao 0.4.0 - 2025-10-29 (Reorganização Arquitetural)

#### Refatorado

* Reorganização completa do projeto, atualizando pastas antigas com código atualizado.

#### Tarefa

* *Merge* do projeto finalizado com o conteúdo do antigo.

### Versao 0.3.5 - 2025-10-28

#### Refatorado

* Organização das massas de dados.

### Versao 0.3.4 - 2025-10-26 (Nova Modelagem)

#### Refatorado

* Refatoração do `SmokeTestes` em `TetsUnicos`.
* Implementação de sistema de Modelagem com Interfaces e Módulos (nova forma de autenticar o usuário).

### Versao 0.3.3 - 2025-10-23

#### Adicionado

* Criação de todas as tabelas inovadoras no banco de dados.

#### Corrigido

* Correção no retorno de `adicionarAoBD` para controle de persistência.

#### Refatorado

* Refatoração da `PersistenciaGerente`: Renomeação de métodos e simplificação da conexão com o banco.

### Versao 0.3.2 - 2025-10-20

#### Documentação

* Atualiza `README.md` com imagens da interface.

#### Refatorado

* Organização da estrutura visual do projeto.

#### Corrigido

* Correção do fluxo de login e serviços.

### Versao 0.3.1 - 2025-10-19 (Integração Inicial do BD/SQLite)

#### Adicionado

* Criação de tabela para gerentes no banco de dados SQLite.
* Adicionado fluxo de hospedagem com criação e *status* de solicitação.
* Inclusão da biblioteca SQLite ao projeto.

#### Refatorado

* Refatoração e reorganização do sistema de fábricas, *gerenciáveis* e interfaces.
* Organização do projeto: criação de pastas `libs` e mudança dos testes de lugar.
* Refatoração do sistema de `ServiçosHospede`, utilizando interfaces, persistências, *gerenciáveis* e fábricas.

### Versao 0.2.2 - 2025-10-17

#### Adicionado

* Adicionado fluxo de autenticação de gerente com criação, *login* e menu CRUD protegido.

#### Documentação

* Documentação das fábricas, *gerenciáveis*, interfaces e persistências criadas.

### Versao 0.2.1 - 2025-10-16

#### Adicionado

* Implementação de Fábricas (`Pessoa`, `Gerente` e `Hospede`).

### Versao 0.2.0 - 2025-10-12 (Ajustes em Serviços)

#### Alterado

* Refatoração de entradas e saídas de operações nos serviços.

### Versao 0.1.7 - 2025-10-11

#### Adicionado

* Criação e organização do sistema de serviços para Gerentes e Hóspedes.

### Versao 0.1.6 - 2025-10-08

#### Alterado

* Classe `Reserva` atualizada (lógica de anos bissextos pendente).
* Adicionada visualização de *logging* programado no módulo `TESTANDO`.

### Versao 0.1.5 - 2025-10-07

#### Alterado

* Aulas atualizadas com mudanças na criação de objetos.

### Versao 0.1.4 - 2025-10-02

#### Refatorado

* Classes de domínios e entidades finalizadas (`OK`). Refatoração completa para iniciar as funcionalidades do sistema.
* Refatoração dos domínios de classe e correção das entidades para receber os domínios.
* Refatoração dos validadores de objetos.

#### Removido

* Diretório `cmake-build-debug` excluído.

### Versao 0.1.3 - 2025-10-01

#### Refatorado

* Refatoração completa das Entidades (`Pessoa`, `Gerente`, `Hospede`) e Domínios (`Nome`, `Email`).
* Projeto reformulado para aderir à documentação (classes Domínios e Entidades).
* Validação incorporada nas classes de domínio (validadores antigos removidos).

### Versao 0.1.2 - 2025-09-30

#### Tarefa

* Confirmação inicial da estrutura do projeto.

### Versao 0.1.0 - 2025-09-28 (Estrutura Básica de Sistema/Login)

#### Adicionado

* Criação dos métodos `menuSistema`, `fazerLogin`, `exibirCentralDeServicos` e `loginGerente`.
* Implementação da classe abstrata `linhaTSV` em Gerente.

#### Alterado

* Métodos `set` e `get` (`Tsv`) implementados em Gerente.

#### Refatorado

* Organização de arquivos: classes `Data` e `Serviços` movidas para a pasta `Sistema`.
* Refatoração do método `setTSV`.

### Versao 0.0.9 - 2025-09-27

#### Adicionado

* Criação do objeto `Gerente` e suas entradas.

#### Refatorado

* Refatoração de *includes*, *defines* e renomeação de `testesValidadores` para `Smoke_Testes`.

### Versao 0.0.8 - 2025-09-26

#### Refatorado

* Organização dos arquivos em um estilo padrão de projetos.

### Versao 0.0.7 - 2025-09-25

#### Corrigido

* Tentativa de retirar um *bug* relacionado à conta antiga.

#### Tarefa

* Organização das pastas.

### Versao 0.0.6 - 2025-09-24

#### Refatorado

* Atualização e refatoração de todos os validadores e seus testes.
* Troca de tipos de atributos.
* Mudança de métodos `virtual` para `static` em validações.

#### Documentação

* `README` atualizado.

### Versao 0.0.5 - 2025-09-23

#### Refatorado

* Atualizações em validações: `Senha`, `Ramal`, `Cartão`, `Telefone`, `Endereço` e seus testes.

#### Corrigido

* Tentativas de resolver erros de *commit*.

### Versao 0.0.4 - 2025-09-22

#### Alterado

* Atributos da classe `Reserva` (`partida` e `chegada`) consertados, sendo declarados como objetos de dados.
* Atualização em testes de validadores.

#### Documentação

* Criação do arquivo `README.md`.

### Versao 0.0.3 - 2025-09-21 (Implementação da Reserva)

#### Adicionado

* Criação da Classe `Reserva` e implementação de todos os validadores.
* Início da implementação de todos os testes de validadores.

#### Alterado

* Classe `Reserva` atualizada (correção de erro em Dinheiro).
* Atualização em testes de validadores.

### Versao 0.0.1 - 2025-09-20 (Início do Projeto)

#### Adicionado

* Início do projeto.
* Implementação da classe `Testes` com contador de sucessos e problemas.
* Implementação inicial de Validação e Testes de Validação.
* **Estrutura:** Entrando na vida de desenvolvimento com a estrutura inicial.