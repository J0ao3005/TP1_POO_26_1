#include "Gerente.h"

// Construtor: Inicializa os atributos da classe base Pessoa e o vetor de clientes administrados
Gerente :: Gerente (string nome, string trabalho, string login, string senha, vector<Cliente*> cliente) : 
    Pessoa(nome, trabalho, login, senha),cliente(cliente) {}

// --- GETTER E SETTER ---

// Retorna a lista completa de clientes associados ao gerente
vector<Cliente*> Gerente :: getCliente() {
    return cliente;
}

// Substitui a lista de clientes atual por uma nova
void Gerente :: setCliente(vector<Cliente*> cliente) {
    this->cliente = cliente;
}

// --- MÉTODOS DE ASSOCIAÇÃO E EXIBIÇÃO ---

// Adiciona um único cliente (ponteiro) à carteira do gerente
void Gerente :: adicionarCliente(Cliente * novoCliente){
    this->cliente.push_back(novoCliente);
}

// Sobrescrita (override) do método exibirDados da classe base Pessoa
void Gerente :: exibirDados(){
    cout << "Nome: " << getNome() << endl;
    cout << "Trabalho: " << getTrabalho() << endl;
    cout << "Login: " << getLogin() << endl;
    cout << "Senha: " << getSenha() << endl;
    cout << "\nClientes vinculados a este gerente: " << endl;
    
    // Itera sobre o vetor de clientes associados e invoca o exibirDados() de cada um
    for (Cliente* cliente : getCliente()) {
        cliente->exibirDados();
        cout <<"\n";
        cout << "------------------------" << endl;
    }
}