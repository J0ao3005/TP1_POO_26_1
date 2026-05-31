#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>

#include "Pessoa.h"

class Transacao; // Declaração antecipada da classe Transacao
class CartaoDeCredito;

class Cliente: public Pessoa {
    private:
        string dataDeNascimento;
        double remuneracao;
        string tipoDeConta;
        double taxaDeRendimento;
        double saldo;
        vector <Transacao*> transacoes;
        CartaoDeCredito * cartao;
    public:

        // Construtor
        Cliente(string nome, string dataDeNascimento, string trabalho, string login, string senha, double remuneracao, string tipoDeConta, double taxaDeRendimento, double saldo);
        // Getters
        double getRemuneracao();
        string getTipoDeConta();
        vector<Transacao*> getExtrato();
        double getSaldo();
        double getRendimento();
        string getDataDeNascimento();

        // Setters
        void setCliente (Pessoa*);
        void setTransacao(Transacao*);
        void setTipoDeConta(string);
        void setSaldo(double);
        void setRendimento(double);
        void setDataDeNascimento(string);

        // Método para exibir os dados do cliente
        void exibirDados() override;

        void setCartao (CartaoDeCredito *novoCartao);
        CartaoDeCredito *getCartao();
};

#endif // CLIENTE_H