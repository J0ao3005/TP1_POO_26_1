#ifndef GERENTE_H
#define GERENTE_H

#include <vector>
#include <iostream>

#include "Pessoa.h"
#include "Cliente.h"

class Gerente : public Pessoa {
    private:
        vector<Cliente*> cliente;
    public:
        //Construtor
        Gerente(string nome, string trabalho, string login, string senha, vector<Cliente*> cliente);

        // Getters
        vector<Cliente*> getCliente();

        // Setters
        void setCliente(vector<Cliente*>);

        // Método para adicionar um único cliente á carteira do gerente
        void adicionarCliente(Cliente*);

        // Método para exibir os dados do gerente
        void exibirDados() override;

};

#endif // GERENTE_H