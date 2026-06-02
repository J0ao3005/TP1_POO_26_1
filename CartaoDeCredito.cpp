#include "CartaoDeCredito.h"

// Construtor: Inicializa o cartão com um limite inicial, fatura zerada e desbloqueado por padrão
CartaoDeCredito :: CartaoDeCredito (double limiteInicial) : 
    limite(limiteInicial), faturaAtual(0.0), bloqueado(false) {} 

// --- GETTERS ---
// Retorna o limite total de crédito do cartão
double CartaoDeCredito :: getLimite (){
    return limite;
}

// Retorna o valor atual da fatura (o quanto já foi gasto)
double CartaoDeCredito :: getfaturaAtual(){
    return faturaAtual;
}

// Retorna o status do cartão (true se bloqueado, false se liberado)
bool CartaoDeCredito :: getBloqueado(){
    return bloqueado;
}

// --- SETTERS E MÉTODOS DE AÇÃO ---

// Altera o limite total do cartão de crédito
void CartaoDeCredito :: alterarLimite (double novoLimite){
    this->limite = novoLimite;
}

// Bloqueia o cartão, impedindo novas compras
void CartaoDeCredito :: bloquear (){
    this->bloqueado = true;
}

// Desbloqueia o cartão, permitindo novas compras
void CartaoDeCredito :: desbloquear (){
    this->bloqueado = false;
}

// Método para processar uma compra no cartão
bool CartaoDeCredito :: realizarCompra (double valor, int parcelas){
    // Validação 1: Verifica se o cartão está bloqueado
    if(bloqueado){
        cout << "Erro: Cartão bloqueado!" << endl;
        return false;
    }

    // Validação 2: Verifica se o valor da compra ultrapassa o limite disponível
    if(faturaAtual + valor > limite){
        cout <<" Erro: Limite Insuficiente!" << endl;
        return false; // retorna false aqui para interromper a compra
    }

    // Adiciona o valor da compra à fatura atual
    faturaAtual += valor;

    cout <<" Compra de R$" << valor << " aprovada em " << parcelas << "x de R$" << (valor/parcelas) << "." << endl;
    return true;
}

// Método para abater o valor da fatura após um pagamento
void CartaoDeCredito :: pagarFatura (double valorPago){
    faturaAtual -= valorPago;
    
    // Tratamento de segurança: impede que a fatura fique com valor negativo
    if(faturaAtual < 0){
        faturaAtual = 0; 
    }
}