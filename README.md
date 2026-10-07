<div align="center">

# 📚 BiblioLink

**Gerenciamento de livros utilizando estruturas de dados auto-organizáveis.**

Uma aplicação desenvolvida para explorar estruturas de dados na prática, utilizando listas duplamente encadeadas para reorganizar seus elementos dinamicamente de acordo com a frequência de acesso aos livros.

[![C](https://img.shields.io/badge/C-Language-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.c-language.org/)
[![Make](https://img.shields.io/badge/Make-Build-6D00CC?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![Git](https://img.shields.io/badge/Git-Versionamento-F05032?style=for-the-badge&logo=git&logoColor=white)](https://git-scm.com/)

[Código-fonte](https://github.com/gothlul/BiblioLink) · [Reportar bug](../../issues)

</div>

<br>

> O **BiblioLink** é um projeto autoral desenvolvido por [Lucas Rasoppi](https://github.com/gothlul). O projeto nasceu como uma aplicação prática dos conceitos estudados em Estruturas de Dados e evoluiu durante o desenvolvimento com experimentações relacionadas à organização e ao comportamento dos dados.

<br>

## 📖 Sobre o projeto

O **BiblioLink** nasceu como um projeto pessoal voltado à aplicação prática de conceitos de **Estruturas de Dados utilizando C**.

A proposta inicial era utilizar o gerenciamento de livros como domínio para implementar manualmente uma **lista duplamente encadeada**, trabalhando diretamente com ponteiros, alocação dinâmica de memória, operações sobre nós e modularização.

Durante o desenvolvimento, o projeto acabou evoluindo além dessa proposta inicial. A implementação das operações de busca levou à criação de um mecanismo de **reorganização dos elementos com base em sua frequência de acesso**, fazendo com que a própria estrutura se adapte ao modo como seus elementos são utilizados.

Atualmente, a estrutura permite:

- 📚 **Cadastrar livros** e armazená-los dinamicamente em uma lista duplamente encadeada;
- 🔍 **Pesquisar livros pelo identificador**, percorrendo os elementos da estrutura;
- 📈 **Contabilizar a frequência de acesso** individual de cada livro;
- 🔄 **Reorganizar automaticamente a lista**, priorizando livros mais acessados;
- 🗑️ **Remover elementos** preservando as conexões entre os nós;
- ↔️ **Navegar pela estrutura nos dois sentidos**, utilizando referências para os elementos anterior e posterior;
- 🧠 **Gerenciar dinamicamente a memória**, incluindo criação e liberação das estruturas utilizadas.

<br>

## 🔄 Organização por frequência de acesso

Uma das principais características do BiblioLink surgiu durante a implementação do algoritmo de busca.

Cada nó da lista mantém um contador responsável por registrar a quantidade de vezes que determinado livro foi encontrado. Sempre que uma busca é realizada com sucesso, esse contador é incrementado e a posição do elemento é reavaliada.

Caso o livro possua uma frequência de acesso superior — ou equivalente, conforme a regra atual de ordenação — à dos elementos anteriores, o nó avança pela lista.

Por exemplo:

```text
Estado inicial:

Livro A (4) ⇄ Livro B (3) ⇄ Livro C (2) ⇄ Livro D (1)
```

Caso o `Livro D` receba 3 novos acessos, a lista se reorganizará para o seguinte estado:

```text
Livro A (4) ⇄ Livro D (4) ⇄ Livro B (3) ⇄ Livro C (2)
```

Dessa forma, os elementos mais utilizados tendem a permanecer próximos ao início da estrutura.

A reorganização acontece diretamente sobre os **ponteiros dos nós**, sem copiar os livros para novas posições. Durante cada movimentação, as referências `last` e `next` são atualizadas para preservar a integridade da lista duplamente encadeada.

O comportamento aproxima a implementação do conceito de uma **Self-Organizing List**, utilizando a frequência de acesso como critério para reorganização.

<br>

## 🏗️ Estrutura

O núcleo do BiblioLink é formado por uma lista duplamente encadeada implementada manualmente.

Cada livro é associado a um nó que armazena, além do próprio elemento, sua quantidade de acessos e as referências necessárias para conectar a estrutura:

<img width="1485" height="847" alt="Image" src="https://github.com/user-attachments/assets/24da756f-3d6f-4ab3-9f45-21d3a5a4af79" />
<br><br>

A estrutura mantém referências para seu início (`begin`) e fim (`end`), permitindo o controle dos limites da lista sem necessidade de percorrê-la completamente para localizar suas extremidades.

A implementação é dividida entre a definição da estrutura, suas operações e a camada responsável pela interação com o usuário.

```text
BiblioLink/
│
├── include/
│   └── bookList.h
│
├── src/
│   └── bookList.c
│
├── obj/
├── bin/
│
├── main.c
├── Makefile
└── README.md
```

- **`bookList.h`** — define as estruturas e a interface das operações disponíveis sobre a lista;
- **`bookList.c`** — implementa as operações de criação, inserção, busca, reorganização, remoção e manipulação dos elementos;
- **`main.c`** — ponto de entrada da aplicação e interface de interação com a estrutura;
- **`Makefile`** — automatiza a compilação dos arquivos e a geração do executável.

<br>

## 🧠 Conceitos aplicados

O desenvolvimento do BiblioLink explora principalmente conceitos fundamentais de **Algoritmos e Estruturas de Dados**, implementando as estruturas sem depender de coleções prontas fornecidas por bibliotecas externas.

Entre os principais conceitos trabalhados estão:

- **Listas duplamente encadeadas**;
- **Ponteiros e referências entre estruturas**;
- **Alocação e liberação dinâmica de memória**;
- **Inserção, remoção e busca em estruturas encadeadas**;
- **Manipulação de `structs`**;
- **Tipos abstratos de dados (TADs)**;
- **Modularização em C**;
- **Reorganização dinâmica de estruturas**;
- **Ordenação baseada em frequência de acesso**;
- **Preservação das invariantes de uma lista encadeada**.

<br>

## 📂 Estrutura de dados

Os livros armazenam as informações manipuladas pela aplicação, enquanto os nós adicionam os metadados e relacionamentos necessários para inseri-los na lista.

De forma simplificada:

```text
Book
├── id
├── title
├── description
├── price
└── pages

Node
├── book
├── acess
├── last
└── next

List
├── begin
├── end
└── size
```

Essa separação permite que as informações pertencentes ao domínio do livro permaneçam independentes das informações necessárias para o funcionamento da estrutura encadeada.

<br>

## 🚀 Rodando o projeto localmente

### 1. Pré-requisitos

Para compilar o BiblioLink, é necessário possuir:

- um compilador compatível com C, como **GCC**;
- **GNU Make**;
- **Git** para clonar o repositório.

### 2. Clone o repositório

```bash
git clone https://github.com/gothlul/BiblioLink.git
cd BiblioLink
```

### 3. Compile o projeto

Utilize o `Makefile` disponível na raiz:

```bash
make
```

Durante o processo, os arquivos-fonte são compilados e vinculados para gerar o executável da aplicação.

O resultado da compilação é armazenado no diretório:

```text
bin/
```

### 4. Execute

Em ambientes Linux/macOS:

```bash
./bin/main
```

Em ambientes Windows, execute o binário correspondente gerado pelo compilador utilizado.

<br>

## 🧪 Natureza do projeto

O BiblioLink foi criado principalmente como um ambiente de **estudo e experimentação**.

A aplicação de gerenciamento de livros fornece um problema concreto sobre o qual conceitos normalmente estudados de forma isolada podem ser implementados e observados na prática.

A funcionalidade de reorganização por acessos não fazia parte do planejamento inicial. Ela surgiu durante o desenvolvimento da operação de busca e posteriormente foi incorporada como parte do comportamento da estrutura.

O projeto, portanto, registra também a evolução de uma implementação inicialmente acadêmica para uma pequena experimentação sobre como **estruturas de dados podem utilizar informações de uso para modificar seu próprio comportamento**.

<br>

## 📄 Licença

Projeto autoral. O código presente neste repositório é de autoria de [Lucas Rasoppi](https://github.com/gothlul) e foi desenvolvido com finalidade de estudo e experimentação em **Algoritmos e Estruturas de Dados**.

<br>
