#include "Cliente.h"
#include "Transacao.h"
#include "CartaoDeCredito.h"

Cliente :: Cliente (string nome, string trabalho, string login, string senha, double remuneracao, string tipoDeConta, double taxaDeRendimento, double saldo) : 
    Pessoa(nome, trabalho, login, senha), remuneracao(remuneracao), tipoDeConta(tipoDeConta), taxaDeRendimento(taxaDeRendimento), saldo(saldo) {}

double Cliente :: getRemuneracao() {
    return remuneracao;
}

string Cliente :: getTipoDeConta() {
    return tipoDeConta;
}

vector<Transacao*> Cliente :: getExtrato() {
    return transacoes;
}

double Cliente :: getSaldo() {
    return saldo;
}

double Cliente :: getRendimento() {
    return taxaDeRendimento;
}

void Cliente :: setCliente (Pessoa* cliente) {
    setNome(cliente->getNome());
    setTrabalho(cliente->getTrabalho());
    setLogin(cliente->getLogin());
    setSenha(cliente->getSenha());
}

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

void Cliente :: exibirDados() {
    cout << "Nome: " << getNome() << endl;
    cout << "Trabalho: " << getTrabalho() << endl;
    cout << "Login: " << getLogin() << endl;
    cout << "Tipo de Conta: " << getTipoDeConta() << endl;
    cout << "Saldo: R$" << getSaldo() << endl;
    cout << "Taxa de Rendimento: " << getRendimento() * 100 << "%" << endl;
}

void Cliente :: setCartao (CartaoDeCredito * novoCartao){
    this->cartao = novoCartao;
}

CartaoDeCredito * Cliente :: getCartao (){
    return cartao;
}