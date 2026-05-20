#ifndef CARTAODECREDITO_H
#define CARTAODECREDITO_H

#include <iostream>

using namespace std;

class CartaoDeCredito{
    private:
        double limite;
        double faturaAtual;
        bool bloqueado;
    public:
        //Construtor
        CartaoDeCredito(double limiteInicial);

        //Getters
        double getLimite();
        double getfaturaAtual();
        bool getBloqueado();

        void alterarLimite (double novoLimite);
        void bloquear();
        void desbloquear();
        bool realizarCompra(double valor, int parcelas);
        void pagarFatura(double valorPago);

};

#endif // CARTAODECREDITO.H