#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>

#include "Pessoa.h"

class Transacao; // Declaração antecipada da classe Transacao

class Cliente: public Pessoa {
    private:
        double remuneracao;
        string tipoDeConta;
        double taxaDeRendimento;
        double saldo;
        vector <Transacao*> transacoes;
    public:

        // Construtor
        Cliente(string nome, string trabalho, string login, string senha, double remuneracao, string tipoDeConta, double taxaDeRendimento, double saldo);

        // Getters
        double getRemuneracao();
        string getTipoDeConta();
        vector<Transacao*> getExtrato();
        double getSaldo();
        double getRendimento();

        // Setters
        void setCliente (Pessoa*);
        void setTransacao(Transacao*);
        void setTipoDeConta(string);
        void setSaldo(double);
        void setRendimento(double);

        // Método para exibir os dados do cliente
        void exibirDados() override;
};

#endif // CLIENTE_H