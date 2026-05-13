#include "Gerente.h"

Gerente :: Gerente (string nome, string trabalho, string login, string senha, vector<Cliente*> cliente) : 
    Pessoa(nome, trabalho, login, senha),cliente(cliente) {}

vector<Cliente*> Gerente :: getCliente() {
    return cliente;
}

void Gerente :: setCliente(vector<Cliente*> cliente) {
    this->cliente = cliente;
}

void Gerente :: adicionarCliente(Cliente * novoCliente){
    this->cliente.push_back(novoCliente);
}


// Método para exibir os dados do gerente
void Gerente :: exibirDados(){
    cout << "Nome: " << getNome() << endl;
    cout << "Trabalho: " << getTrabalho() << endl;
    cout << "Login: " << getLogin() << endl;
    cout << "Senha: " << getSenha() << endl;
    cout << "\nClientes: " << endl;
    
    for (Cliente* cliente : getCliente()) {
        cliente->exibirDados();
        cout <<"\n";
        cout << "------------------------" << endl;
    }
}