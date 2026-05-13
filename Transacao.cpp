#include "Transacao.h"
#include "Cliente.h"

Transacao :: Transacao (string tipo, double valor, string data, string horario, vector<Cliente*> clientes) :
    tipo(tipo), valor(valor), data(data), horario(horario), clientes(clientes) {}

string Transacao :: getTipo() {
    return tipo;
}

double Transacao :: getValor() {
    return valor;
}

string Transacao :: getData() {
    return data;
}

string Transacao :: getHorario() {
    return horario;
}

vector<Cliente*> Transacao :: getClientes() {
    return clientes;
}

void Transacao :: setValor(double valor) {
    this->valor = valor;
}

void Transacao :: setData(string data) {
    this->data = data;
}

void Transacao :: setHorario(string horario) {
    this->horario = horario;
}

void Transacao :: setClientes(Cliente* cliente) {
    this->clientes.push_back(cliente);
}

void Transacao :: exibirTransacao() {
    cout << "Tipo: " << tipo << endl;
    cout << "Valor: " << valor << endl;
    cout << "Data: " << data << endl;
    cout << "Horario: " << horario << endl;
    cout << "\nClientes envolvidos na transação:" << endl;
    for (Cliente* cliente : clientes) {
        cliente->exibirDados();
        cout << endl;
    }
}