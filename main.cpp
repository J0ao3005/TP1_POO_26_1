#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

// Bibliotecas Próprias
#include "Menu.h"
#include "Pessoa.h"
#include "Cliente.h"
#include "Gerente.h"
#include "Transacao.h"
#include "CartaoDeCredito.h"

using namespace std;

// Função principal: Ponto de entrada estruturado do sistema bancário
int main(){

    // Instanciação do objeto controlador principal (Menu)
    Menu meuMenu;

    // Loop principal de execução da Interface de Linha de Comando (CLI)
    do {
        int opcao;
        meuMenu.exibirMenu(); // Renderiza o painel visual
        
        // Bloco de tratamento de exceções para garantir a robustez contra entradas inválidas
        try {
            
            // Verifica se o usuário digitou letras ou caracteres especiais ao invés de números (int)
            if(!(cin >> opcao)) {
                // Restaura o estado de erro do cin
                cin.clear();
                
                // Limpa o lixo de memória do buffer de leitura até a próxima quebra de linha
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                
                // Dispara (throw) uma exceção do tipo invalid_argument
                throw invalid_argument("Entrada Invalida! Por favor, digite apenas números.\n");
            }
            
            // Controle de Fluxo: Direciona a execução para o método correspondente no controlador Menu
            switch (opcao) {
                case 1:
                    meuMenu.cadastrarCliente();
                    break;
                case 2:
                    meuMenu.cadastrarGerente();
                    break;
                case 3:
                    meuMenu.criarTransacao();
                    break;
                case 4:
                    meuMenu.extratoCliente();
                    break;
                case 5:
                    meuMenu.associarGerenteCliente();
                    break;
                case 6:
                    meuMenu.listarClientes();
                    break;
                case 7:
                    meuMenu.listarGerentes();
                    break;
                case 8:
                    meuMenu.salvarDados(); // Aciona a persistência CSV
                    cout << "Saindo do sistema..." << endl;
                    return 0; // Encerra o loop e o programa com sucesso (código 0)
                case 9:
                    meuMenu.menuCartao(); // Abre o sub-menu do módulo extra
                    break;
                case 0:
                    cout << "Saindo do sistema..." << endl;
                    return 0;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
            }
        }
        
        // Catch: Captura a exceção disparada pelo throw e informa o usuário sem encerrar o programa
        catch (const invalid_argument& e) {
            cerr << "[ERRO DE SISTEMA] " << e.what() << endl;
        }

    } while (true); // Loop infinito, quebrado apenas pelos returns nos cases 8 e 0

    return 0;
}