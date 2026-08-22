# 🏦 Sistema de Gerenciamento de Banco

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Conclu%C3%ADdo-brightgreen?style=for-the-badge)

Sistema de Gerenciamento de Banco desenvolvido em C++ como Trabalho Prático da disciplina **BCC 221 - Programação Orientada a Objetos** (UFOP). Simula operações bancárias essenciais através de uma interface de linha de comando (CLI), com persistência de dados em arquivos CSV.

## 📌 Índice

- [Funcionalidades](#️-funcionalidades)
- [Arquitetura (POO)](#-arquitetura-conceitos-de-poo-aplicados)
- [Estrutura do projeto](#-estrutura-do-projeto)
- [Como compilar e executar](#-como-compilar-e-executar)
- [Tecnologias](#️-tecnologias)

## ⚙️ Funcionalidades

| Opção no menu | Ação |
|---|---|
| 1 | Cadastrar cliente |
| 2 | Cadastrar gerente |
| 3 | Criar transação (depósito, saque ou transferência) |
| 4 | Ver extrato de um cliente |
| 5 | Associar um cliente à carteira de um gerente |
| 6 | Listar todos os clientes |
| 7 | Listar todos os gerentes |
| 8 | Salvar dados (CSV) e sair |
| 9 | Abrir o menu do cartão de crédito |
| 0 | Sair sem salvar |

### 💳 Módulo extra — Cartão de Crédito

- Criação com limite pré-aprovado com base na remuneração do cliente
- Alteração de limite
- Compras parceladas, com verificação automática de limite disponível
- Bloqueio e desbloqueio do cartão
- Pagamento de fatura com débito no saldo em conta e ajuste de excedentes

## 🧱 Arquitetura (conceitos de POO aplicados)

```
Pessoa  (classe base, com destrutor virtual e exibirDados() virtual)
 ├── Cliente
 └── Gerente

Gerente  1 ── N  Cliente          (carteira de clientes)
Cliente  1 ── 1  CartaoDeCredito  (associação opcional)
Transacao  N ── N  Cliente        (1 cliente em saque/depósito, 2 em transferência)
```

- **Herança:** `Cliente` e `Gerente` herdam de `Pessoa`.
- **Polimorfismo:** `exibirDados()` é virtual em `Pessoa` e sobrescrito (`override`) por `Cliente` e `Gerente`.
- **Composição/associação por ponteiros:** `Gerente` guarda um vetor de `Cliente*`, `Transacao` guarda os `Cliente*` envolvidos, `Cliente` guarda um `CartaoDeCredito*`.
- **Tratamento de exceções:** entradas inválidas no menu disparam `invalid_argument`, capturado em `main.cpp` sem derrubar o programa.
- **Persistência:** dados salvos e recarregados automaticamente via `clientes.csv` e `gerentes.csv`.

## 📁 Estrutura do projeto

```
TP1_POO_26_1/
├── Header/
│   ├── Pessoa.h
│   ├── Cliente.h
│   ├── Gerente.h
│   ├── Transacao.h
│   ├── CartaoDeCredito.h
│   └── Menu.h
├── Pessoa.cpp
├── Cliente.cpp
├── Gerente.cpp
├── Transacao.cpp
├── CartaoDeCredito.cpp
├── Menu.cpp
├── main.cpp
└── README.md
```

## 🚀 Como compilar e executar

Na pasta raiz do projeto:

```bash
g++ -I./Header *.cpp -o SistemaBanco -Wall
```

Depois, execute:

```bash
./SistemaBanco      # Linux/macOS
SistemaBanco.exe    # Windows
```

## 🛠️ Tecnologias

- **C++** — herança, polimorfismo, ponteiros e tratamento de exceções
- Persistência de dados em **CSV**

---

<sub>Trabalho da disciplina de BCC 221 - Programação Orientada a Objetos — UFOP</sub>
