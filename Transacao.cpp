#include "Transacao.h"
#include "Cliente.h"

// Construtor: Inicializa a transação com os metadados (tipo, valor, data, hora) e a lista de ponteiros dos clientes envolvidos
Transacao :: Transacao (string tipo, double valor, string data, string horario, vector<Cliente*> clientes) :
    tipo(tipo), valor(valor), data(data), horario(horario), clientes(clientes) {}

// --- GETTERS ---
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

// Retorna o vetor contendo os ponteiros dos clientes que participaram desta transação (1 para saque/depósito, 2 para transferência)
vector<Cliente*> Transacao :: getClientes() {
    return clientes;
}

// --- SETTERS ---
void Transacao :: setValor(double valor) {
    this->valor = valor;
}

void Transacao :: setData(string data) {
    this->data = data;
}

void Transacao :: setHorario(string horario) {
    this->horario = horario;
}

// Adiciona um novo cliente (ponteiro) à lista de envolvidos nesta transação
void Transacao :: setClientes(Cliente* cliente) {
    this->clientes.push_back(cliente);
}

// --- MÉTODOS DE EXIBIÇÃO ---
// Imprime os detalhes financeiros e aciona o polimorfismo para exibir os dados dos clientes
void Transacao :: exibirTransacao() {
    cout << "Tipo: " << tipo << endl;
    cout << "Valor: R$" << valor << endl;
    cout << "Data: " << data << endl;
    cout << "Horario: " << horario << endl;
    cout << "\nClientes envolvidos na transação:" << endl;
    
    // Itera sobre o vetor de clientes e invoca a função exibirDados() de cada um
    for (Cliente* cliente : clientes) {
        cliente->exibirDados();
        cout << endl;
    }
}