#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Cliente.h"
#include "Gerente.h"
#include "Transacao.h"

using namespace std;

class Menu {
    private:

        // Vetores para armazenar clientes, gerentes e transações
        vector<Cliente*> Todosclientes;
        vector<Gerente*> gerentes;
        vector<Transacao*> transacoes;

    public:


        void exibirMenu(); 
        void cadastrarCliente();
        void listarClientes();

        void cadastrarGerente();
        void listarGerentes();

        void associarGerenteCliente();
        void extratoCliente();
        void criarTransacao();

        ~Menu();

        void salvarDados();

};

#endif // MENU_H