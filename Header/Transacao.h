#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Cliente; // Declaração antecipada da classe Cliente

class Transacao {
    private:
        string tipo;
        double valor;
        string data;
        string horario;
        vector <Cliente*> clientes;
    public:

        // Construtor
        Transacao(string tipo, double valor, string data, string horario, vector<Cliente*> clientes);

        // Getters
        string getTipo();
        double getValor();
        string getData();
        string getHorario();
        vector<Cliente*> getClientes();

        // Setters
        void setValor(double);
        void setData(string);
        void setHorario(string);
        void setClientes(Cliente*);

        // Método para exibir os dados da transação
        void exibirTransacao();

};

#endif // TRANSICAO_H