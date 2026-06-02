#include "Pessoa.h"

// Construtor: Inicializa os atributos fundamentais da classe base abstrata
Pessoa :: Pessoa (string nome, string trabalho, string login, string senha) :
    nome(nome), trabalho(trabalho), login(login), senha(senha) {}

// --- GETTERS ---
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

// --- MÉTODOS DE EXIBIÇÃO ---
// Método virtual: Pode ser sobrescrito (override) pelas classes derivadas (Cliente e Gerente)
void Pessoa :: exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Trabalho: " << trabalho << endl;
    cout << "Login: " << login << endl;
    cout << "Senha: " << senha << endl;
}

// --- SETTERS ---
// Seguem o princípio do encapsulamento, permitindo alteração segura dos atributos privados
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