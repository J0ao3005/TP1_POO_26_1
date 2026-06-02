#include "Cliente.h"
#include "Transacao.h"
#include "CartaoDeCredito.h"

// Construtor: Inicializa os atributos herdados de Pessoa e os atributos específicos do Cliente
Cliente :: Cliente (string nome, string dataDeNascimento, string trabalho, string login, string senha, double remuneracao, string tipoDeConta, double taxaDeRendimento, double saldo) : 
    Pessoa(nome, trabalho, login, senha), dataDeNascimento(dataDeNascimento), remuneracao(remuneracao), tipoDeConta(tipoDeConta), taxaDeRendimento(taxaDeRendimento), saldo(saldo) {}

// --- GETTERS ---
string Cliente :: getDataDeNascimento() {
    return dataDeNascimento;
}

double Cliente :: getRemuneracao() {
    return remuneracao;
}

string Cliente :: getTipoDeConta() {
    return tipoDeConta;
}

// Retorna o vetor contendo o histórico de transações (extrato) do cliente
vector<Transacao*> Cliente :: getExtrato() {
    return transacoes;
}

double Cliente :: getSaldo() {
    return saldo;
}

double Cliente :: getRendimento() {
    return taxaDeRendimento;
}

// --- SETTERS ---
// Método utilitário para copiar dados de um objeto Pessoa genérico
void Cliente :: setCliente (Pessoa* cliente) {
    setNome(cliente->getNome());
    setTrabalho(cliente->getTrabalho());
    setLogin(cliente->getLogin());
    setSenha(cliente->getSenha());
}

// Adiciona uma nova transação ao histórico do cliente
void Cliente :: setTransacao(Transacao* transacao) {
    transacoes.push_back(transacao);
}

void Cliente :: setTipoDeConta(string tipoDeConta) {
    this->tipoDeConta = tipoDeConta;
}

void Cliente :: setSaldo(double saldo) {
    this->saldo = saldo;
}

void Cliente :: setRendimento(double taxaDeRendimento) {
    this->taxaDeRendimento = taxaDeRendimento;
}

void Cliente :: setDataDeNascimento(string dataDeNascimento) {
    this->dataDeNascimento = dataDeNascimento;
}
    
// --- MÉTODOS DE EXIBIÇÃO E ASSOCIAÇÃO ---

// Sobrescrita (override) do método exibirDados da classe base Pessoa
void Cliente :: exibirDados() {
    cout << "Nome: " << getNome() << endl;
    cout << "Data de Nascimento: " << getDataDeNascimento() << endl;
    cout << "Trabalho: " << getTrabalho() << endl;
    cout << "Login: " << getLogin() << endl;
    cout << "Tipo de Conta: " << getTipoDeConta() << endl;
    cout << "Saldo: R$" << getSaldo() << endl;
    cout << "Taxa de Rendimento: " << getRendimento() * 100 << "%" << endl;
}

// Associa um objeto CartaoDeCredito ao Cliente (Ponto Extra)
void Cliente :: setCartao (CartaoDeCredito * novoCartao){
    this->cartao = novoCartao;
}

// Retorna o ponteiro do cartão de crédito associado ao cliente
CartaoDeCredito * Cliente :: getCartao (){
    return cartao;
}