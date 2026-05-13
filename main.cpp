#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

#include "Menu.h"

#include "Pessoa.h"
#include "Cliente.h"
#include "Gerente.h"
#include "Transacao.h"

using namespace std;

int main(){

    Menu meuMenu;

    do {
        int opcao;
        meuMenu.exibirMenu();
        try{
            
            // Verifica se o usuário digitou letras ao invés de números
            if(!(cin >> opcao)) {
                cin.clear();
                // Limpando o lixo no buffer de leitura
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                // Exceção de erro!
                throw invalid_argument("Entrada Invalida! Por favor, digite apenas números.\n");
                
            }
            
            // Controle de Fluxo
            switch (opcao) {
                case 1:
                    // Lógica para cadastrar cliente
                    meuMenu.cadastrarCliente();
                    break;
                case 2:
                    // Lógica para cadastrar gerente
                    meuMenu.cadastrarGerente();
                    break;
                case 3:
                    // Lógica para criar transação
                    break;
                case 4:
                    // Lógica para exibir extrato de um cliente
                    break;
                case 5:
                    // Lógica para associar gerente a cliente
                    meuMenu.associarGerenteCliente();
                    break;
                case 6:
                    // Lógica para listar clientes
                    meuMenu.listarClientes();
                    break;
                case 7:
                    // Lógica para listar gerentes
                    meuMenu.listarGerentes();
                    break;
                case 8:
                    // Lógica para salvar dados e sair
                    break;
                case 0:
                    cout << "Saindo do sistema..." << endl;
                    return 0;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
            }
        }
        
        // Captura o erro de digitação de letras
        catch (const invalid_argument& e) {
            cerr << "[ERRO DE SISTEMA] " << e.what() << endl;
        }

    } while (true);

    return 0;
}