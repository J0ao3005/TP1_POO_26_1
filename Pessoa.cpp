#include "Pessoa.h"

Pessoa :: Pessoa (string nome, string trabalho, string login, string senha) :
    nome(nome), trabalho(trabalho), login(login), senha(senha) {}

string Pessoa :: getNome() {
    return nome;
}

string Pessoa :: getTrabalho() {
    return trabalho;
}

string Pessoa :: getLogin() {
    return login;
}

string Pessoa :: getSenha() {
    return senha;
}

void Pessoa :: exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
    cout << "Senha: " << senha << endl;
}

void Pessoa :: setNome(string nome) {
    this->nome = nome;
}

void Pessoa :: setTrabalho(string trabalho) {
    this->trabalho = trabalho;
}

void Pessoa :: setLogin(string login) {
    this->login = login;
}

void Pessoa :: setSenha(string senha) {
    this->senha = senha;
}