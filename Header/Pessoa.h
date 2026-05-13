#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
    private:
        string nome;
        string trabalho;
        string login;
        string senha;
    public:

        // Construtor
        Pessoa(string nome, string trabalho, string login, string senha);

        // Getters
        string getNome();
        string getTrabalho();
        string getLogin();
        string getSenha();

        // Método virtual para exibir os dados da pessoa
        virtual void exibirDados();

        // Setters
        void setNome(string);
        void setTrabalho(string);
        void setLogin(string);
        void setSenha(string);

        virtual ~Pessoa() {} // Destrutor virtual

};

#endif // PESSOA_H