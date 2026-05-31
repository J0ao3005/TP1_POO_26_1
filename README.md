# Sistema de Gerenciamento de Banco (BCC 221 - POO)

Este projeto consiste em um **Sistema de Gerenciamento de Banco** desenvolvido em C++ como parte do Trabalho Prático da disciplina de *BCC 221 - Programação Orientada a Objetos*. O sistema simula operações bancárias essenciais através de uma interface de linha de comando (CLI) intuitiva, empregando conceitos robustos de Programação Orientada a Objetos e persistência de dados em arquivos CSV.

---

##  Funcionalidades Implementadas

1. **Gestão de Entidades (Clientes e Gerentes):**
   * **Clientes:** Cadastro completo contendo nome, profissão, login, senha, remuneração mensal, tipo de conta (Corrente ou Poupança), taxa de rendimento (exclusiva para contas poupança) e saldo inicial.
   * **Gerentes:** Cadastro de administradores responsáveis por gerenciar carteiras exclusivas de clientes vinculados.
2. **Associação Dinâmica (Gerente -> Cliente):**
   * Vinculação direta de um cliente à carteira de um gerente específico.
3. **Módulo de Transações Financeiras:**
   * Suporte completo para operações de **Depósito**, **Saque** (com verificação automática de fundos) e **Transferência** entre contas.
   * Registro individual e cronológico de extratos associados a cada cliente.
4. **Persistência de Dados Automática (CSV):**
   * Salvamento estruturado de dados em arquivos `clientes.csv` e `gerentes.csv`.
   * Carregamento automatizado das listas de entidades ao iniciar o sistema.
5. **Funcionalidade Extra (Módulo de Cartão de Crédito):**
   * Criação assistida de cartões de crédito com limite pré-aprovado baseado na remuneração.
   * Flexibilidade para alteração de limites e simulação de compras parceladas.
   * Sistema de bloqueio e desbloqueio do cartão.
   * Pagamento de faturas com débito automático e integrado ao saldo em conta corrente, incluindo ajuste inteligente de pagamentos excedentes.

---

##  Estrutura de Diretórios do Projeto

O projeto adota uma arquitetura modularizada:

* `Header/` - Pasta com os cabeçalhos das classes (`.h`).
* `*.cpp` - Arquivos de implementação das classes e o `main.cpp`.

---

##  Instruções de Compilação

Para compilar o projeto, abra o terminal na pasta raiz do projeto (`TP1_POO_26_1/`) e execute o comando abaixo:

```bash
g++ -I./Header *.cpp -o SistemaBanco -Wall
