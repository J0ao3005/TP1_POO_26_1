#include "CartaoDeCredito.h"

CartaoDeCredito :: CartaoDeCredito (double limiteInicial) : 
    limite(limiteInicial), faturaAtual(0.0), bloqueado(false) {} 

double CartaoDeCredito :: getLimite (){
    return limite;
}

double CartaoDeCredito :: getfaturaAtual(){
    return faturaAtual;
}

bool CartaoDeCredito :: getBloqueado(){
    return bloqueado;
}

void CartaoDeCredito :: alterarLimite (double novoLimite){
    this->limite = novoLimite;
}

void CartaoDeCredito :: bloquear (){
    this->bloqueado = true;
}

void CartaoDeCredito :: desbloquear (){
    this->bloqueado = false;
}

bool CartaoDeCredito :: realizarCompra (double valor, int parcelas){
    if(bloqueado){
        cout << "Erro: Cartão bloqueado!" << endl;
        return false;
    }

    if(faturaAtual + valor > limite){
        cout <<" Erro: Limite Insuficiente!" << endl;
    }

    faturaAtual += valor;

    cout <<" Compra de R$" << valor << " aprovada em" << parcelas << "x de R$" << (valor/parcelas) << "." << endl;
    return true;
}

void CartaoDeCredito :: pagarFatura (double valorPago){
    faturaAtual -= valorPago;
    if(faturaAtual < 0){
        faturaAtual = 0; // Evita fatura negativa
    }
}