#include "Menu.h"
#include "CartaoDeCredito.h"

#include <cctype>
#include <algorithm>

// Construtor: Inicializa o sistema já tentando carregar o estado salvo no disco (CSV)
Menu :: Menu() {
    carregarDados();
}

// --- INTERFACE ---
// Implementação dos métodos da classe Menu
void Menu :: exibirMenu(){
    cout << "\n\t ====== SISTEMA DE GERENCIAMENTO DE BANCO ======" << endl;
    cout << "1. Cadastrar cliente" << endl;
    cout << "2. Cadastrar gerente" << endl;
    cout << "3. Criar transação" << endl;
    cout << "4. Exibir extrato de um cliente" << endl;
    cout << "5. Associar gerente a cliente" << endl;
    cout << "6. Listar clientes" << endl;
    cout << "7. Listar gerentes" << endl;
    cout << "8. Salvar dados e sair" << endl;
    cout << "9. Gerenciar Cartão de Crédito" << endl;
    cout << "0. Sair" << endl;
    cout << "\t ================================================" << endl;
    cout << "Escolha uma opção: ";
}


// --- MÉTODOS DE CADASTRO E LISTAGEM ---
void Menu :: cadastrarCliente() {
    // Lógica para cadastrar cliente
    cout << "\n --- CADASTRO DE CLIENTE --- \n" << endl;
    string nome,dataNascimento ,trabalho, login, senha, tipoDeConta;
    double remuneracao, taxaDeRendimento = 0.0, saldo;

    cin.ignore(); // Limpa o buffer do cin para evitar pulos indesejados no getline

    // Solicitar informações do cliente
    cout << "Nome completo: ";
    getline(cin, nome);

    cout << "Data de Nascimento (DD//MM/AAAA): ";
    getline(cin, dataNascimento);

    cout << "Trabalho: ";
    getline(cin, trabalho);

    cout << "Login: ";
    getline(cin, login);

    cout << "Senha: ";
    getline(cin, senha);

    cout << "Remuneração mensal: R$";
    cin >> remuneracao;

    cout << "Tipo de conta (corrente/poupança): ";
    cin >> tipoDeConta;

    // Utiliza a biblioteca <algorithm> da STL para converter o texto para minúsculas
    // Isso evita erros se o usuário digitar "Poupança", "POUPANÇA" ou "poupança"
    transform(tipoDeConta.begin(), tipoDeConta.end(), tipoDeConta.begin(), ::tolower);

    // Validação de entrada
    while(tipoDeConta != "poupança" && tipoDeConta != "corrente"){
        cout << "Opção Invalida! Digite 'corrente' ou 'poupança': ";
        cin >> tipoDeConta;
        transform(tipoDeConta.begin(), tipoDeConta.end(), tipoDeConta.begin(), ::tolower);
    }
    
    if (tipoDeConta == "poupança") {
        cout << "Taxa de rendimento mensal (em %): ";
        cin >> taxaDeRendimento;
        taxaDeRendimento /= 100; // Converter para decimal
    }

    cout << "Saldo inicial: R$";
    cin >> saldo;

    // Bloco Try-Catch para instanciar o objeto com segurança
    try{
        // Cria um novo cliente e adicionar à lista
        Cliente* novoCliente = new Cliente(nome, dataNascimento,trabalho, login, senha, remuneracao, tipoDeConta, taxaDeRendimento, saldo);
        Todosclientes.push_back(novoCliente);
        cout << " >>> Cliente cadastrado com sucesso! <<< \n" << endl;
    }

    catch (const invalid_argument& e){
        // Se o construtor do cliente recusar os dados, ele cai aqui
        cerr << "\n Falha ao criar cliente: " << e.what() << endl;
        cerr << "Por favor, refaça o cadastro com dados válidos." << endl;
    }


}

void Menu :: listarClientes(){
    cout << "\n --- BUSCAR CLIENTE --- \n" << endl;
    if(Todosclientes.empty()){
        cout << "Nenhum cliente cadastrado." << endl;
        return; // Interrompe o método prematuramente se o vetor estiver vazio
    }

    cin.ignore();
    string nomeBusca;

    cout <<"Digite o nome exato do cliente que deseja buscar: "<< endl;
    getline(cin, nomeBusca);

    bool encontrou = false;
    for(Cliente* cliente : Todosclientes){
        if(cliente->getNome() == nomeBusca){
            cout <<"\n--- Dados do Cliente ---" << endl;
            cliente->exibirDados(); // Aciona o polimorfismo
            encontrou = true;
            break; // Para a busca assim que encontrar
        }
    }

    if(!encontrou){
        cout << "Erro: Cliente não encontrado no sistema!" << endl;
    }
}

void Menu :: cadastrarGerente(){
    cout << "\n--- CADASTRO DE GERENTE ---" << endl;
    string nome, trabalho, senha, login;

    cin.ignore();

    cout << "Nome Completo: ";
    getline(cin, nome);

    cout << "Trabalho (Cargo/Setor): ";
    getline(cin, trabalho);

    cout << "Login: ";
    getline(cin, login);

    cout << "Senha: ";
    getline(cin, senha);

    vector<Cliente*> clientesIniciais; // Inicializa a carteira de clientes vazia

    // Alocação dinâmica e armazenamento no vetor correspondente
    Gerente* gerente = new Gerente (nome, trabalho, login, senha, clientesIniciais);
    gerentes.push_back(gerente);

    cout << ">>> Gerente cadastrado com sucesso! <<<" << endl;
}

void Menu :: listarGerentes(){
    cout << "\n --- BUSCAR GERENTE --- \n" << endl;
    if(gerentes.empty()){
        cout << "Nenhum gerente cadastrado." << endl;
    }

    cin.ignore();
    string nomeBusca;

    cout <<"Digite o nome exato do gerente que deseja buscar: "<< endl;
    getline(cin, nomeBusca);

    bool encontrou = false;
    for(Gerente* gerente : gerentes){
        if(gerente->getNome() == nomeBusca){
            cout <<"\n--- Dados do Gerente ---" << endl;
            gerente->exibirDados();
            encontrou = true;
            break;
        }
    }

    if(!encontrou){
        cout << "Erro: Gerente não encontrado no sistema!" << endl;
    }
}

// --- MÉTODOS DE ASSOCIAÇÃO E TRANSAÇÃO ---

// Cria o vínculo de agregação entre a classe Gerente e a classe Cliente
void Menu :: associarGerenteCliente(){
    cout << "\n --- ASSOCIAR GERENTE A CLIENTE ---" << endl;

    if(gerentes.empty() || Todosclientes.empty()){
        cout << "Erro: Você precisa adicionar ao menos um gerente e um cliente primeiro!" << endl;
        return;
    }

    cout << "\nLista de Gerentes Disponíveis:" << endl;
    for(size_t i = 0; i < gerentes.size(); i++){
        cout << "[" << i << "] - Nome: " << gerentes[i]->getNome() << " | Setor: " << gerentes[i]->getTrabalho() << endl;
    }

    int idGerente;
    cout << "Digite o número do Gerente Desejado: ";
    cin >> idGerente;

    // Validação de acesso ao vetor (evita segmentation fault)
    if(idGerente < 0 || idGerente >= (int)gerentes.size()){
        cout << "Erro: Gerente inválido." << endl;
        return;
    }

    cout <<"\nLista de Clientes Disponíveis" << endl;
    for(size_t i = 0; i < Todosclientes.size(); i++){
        cout << "[" << i << "] - Nome: " << Todosclientes[i]->getNome() << " | Conta: " << Todosclientes[i]->getTipoDeConta() << endl;
    }

    int idCliente;
    cout << "Digite o número do Cliente Desejado: ";
    cin >> idCliente;

    if(idCliente < 0 || idCliente >= (int)Todosclientes.size()){
        cout << "Erro: Cliente inválido." << endl;
        return;
    }

    // Adicionando o cliente especifico a lista do gerente
    gerentes[idGerente]-> adicionarCliente(Todosclientes[idCliente]);

    cout << "\n >> Associação realizada com sucesso! <<" << endl;
    cout << Todosclientes[idCliente]->getNome() << " agora é cliente de: " << gerentes[idGerente]->getNome() <<"." << endl;;
}

void Menu :: extratoCliente(){
    cout << "\n --- EXTRATOS DE CLIENTES ---" << endl;

    if(Todosclientes.empty()){
        cout<<"Erro: É necessário ter ao menos um cliente registrado." << endl;
        return;
    }

    cout << " >> Clientes disponíveis\n";
    for(size_t i = 0; i < Todosclientes.size(); i++){
        cout << "[" << i << "] - Nome: " << Todosclientes[i]->getNome() <<  endl;
    }

    int idCliente;
    cout << "Digite o número do Cliente Desejado: ";
    cin >> idCliente;

    if(idCliente < 0 || idCliente >= (int)Todosclientes.size()){
        cout << "Erro: Cliente inválido." << endl;
        return;
    }

    // Lista de transações do cliente escolhido
    vector <Transacao*> extratoDoCliente = Todosclientes[idCliente]->getExtrato();

    if(extratoDoCliente.empty()){
       cout << "\n Este cliente ainda não realizou nenhuma transação." << endl;
    } else {
        cout << "\n >> Extrato de " << Todosclientes[idCliente]->getNome() << " <<" << endl;

        for(Transacao * t : extratoDoCliente){
            t->exibirTransacao();
            cout << "-----------------------------------" << endl;
        }
    }
}

// Método central da lógica bancária: Manipula saldos e histórico
void Menu :: criarTransacao(){
    cout <<"\n --- NOVA TRANSAÇÃO --- " << endl;

    if(Todosclientes.empty()){
        cout << "Erro: Nenhum cliente cadastrado para realizar transações!" << endl;
        return;
    }

    // Variáveis necessárias para um transação
    double valor;
    string tipo, data, horario;
    vector<Cliente*> clientesEnvolvidos;

    cin.ignore();
    cout << "Selecione o tipo de Transação (Deposito, Saque, Transferência): ";
    getline(cin, tipo);

    // Padronizando a string para minúsculo para facilitar a comparação
    transform(tipo.begin(), tipo.end(), tipo.begin(), :: tolower);

    while (tipo != "deposito" && tipo != "saque" && tipo != "transferencia"){
        cout << "Opção invalida! Digite 'deposito', 'saque' ou 'transferencia'." << endl;
        getline(cin,tipo);
        // Padronizando a string para minúsculo para facilitar a comparação
        transform(tipo.begin(), tipo.end(), tipo.begin(), :: tolower);
    }

    cout << "Valor: R$";
    cin >> valor;
    cin.ignore();

    cout << "DATA (DD/MM/AAAA): ";
    getline(cin, data);

    cout << "Horário (HH:MM): ";
    getline(cin, horario);

    // Lógica de Depoisito e Saque (1 Cliente)
    if(tipo == "deposito" || tipo == "saque")
    {
        cout << "\n >> CLientes disponíveis:\n";
        for(size_t i = 0; i < Todosclientes.size(); i++){
            cout << "[" << i << "] - Nome: " << Todosclientes[i]->getNome() << " | Saldo Atual: R$" << Todosclientes[i]->getSaldo() << endl;
        }

        int id;
        cout << "Digite o número do cliente: ";
        cin >> id;

        if(id < 0 || id >= (int)Todosclientes.size()){
            cout << "Erro: Cliente inválido." << endl;
            return;
        }

        Cliente * clienteEscolhido = Todosclientes[id];
        clientesEnvolvidos.push_back(clienteEscolhido);

        //Atualizando o saldo
        if(tipo == "deposito")
        {
            clienteEscolhido->setSaldo(clienteEscolhido->getSaldo() + valor);
        } else if (tipo == "saque")
        {
            //Validando o saldo
            if(clienteEscolhido->getSaldo() < valor){
                cout << "Erro: Saldo insuficiente para o saque." << endl;
                return;
            }
            clienteEscolhido->setSaldo(clienteEscolhido->getSaldo() - valor);
        }
    } else if (tipo == "transferencia")
        { // Lógica de transferencia (2 clientes)
        
            if(Todosclientes.size() < 2){
                cout << "Erro: É necessário ter pelo menos 2 clientes para uma transferência." << endl;
                return;
            }

            cout << "\n >> CLientes disponíveis: \n";
            for(size_t i = 0; i < Todosclientes.size(); i++){
                cout << "[" << i << "] - Nome: " << Todosclientes[i]->getNome() << " | Saldo Atual: R$" << Todosclientes[i]->getSaldo() << endl;
            }

            int idOrigem, idDestino;
            cout << "Digite o número do cliente que vai ENVIAR o dinheiro: ";
            cin >> idOrigem;
            cout << "Digite o número do cliente que vai RECEBER o dinheiro: ";
            cin >> idDestino;

            if(idOrigem < 0 || idOrigem >= (int)Todosclientes.size() || idDestino < 0 || idDestino >= (int)Todosclientes.size()){
                cout << "Erro: CLientes inválidos." << endl;
                return;
            }

            Cliente * remetente = Todosclientes[idOrigem];
            Cliente * destinatario = Todosclientes[idDestino];

            if(remetente->getSaldo() < valor){
                cout<< "Erro: Saldo insuficiente para transfêrencia." << endl;
                return;
            }

            // Subtrai do remetente e soma no destinatário
            remetente->setSaldo (remetente->getSaldo() - valor);
            destinatario->setSaldo(destinatario->getSaldo() + valor);

            // Adicionando os dois valores no vetor de transação
            clientesEnvolvidos.push_back(remetente);
            clientesEnvolvidos.push_back(destinatario);


        } else {
            cout << "Erro: Tipo de transação inválido." << endl;
            return;
        }


        // -- Finalizando e salvando todas as transações
        Transacao * novaTransacao = new Transacao (tipo,valor,data,horario, clientesEnvolvidos);

        //Salva na lista geral do banco
        transacoes.push_back(novaTransacao);

        //Salva no extrato particular de cada cliente envolvido
        for(Cliente * c : clientesEnvolvidos){
            c->setTransacao(novaTransacao);
        }

        cout << "\n >> Transação realizada com sucesso! <<" << endl;


}

// Destrutor: Fundamental em POO para limpar a memória alocada dinamicamente (Heap) com 'new'
Menu :: ~Menu() {
    // Itera sobre os vetores e libera a memória para evitar vazamento (Memory Leaks)
    for (Cliente* cliente : Todosclientes) {
        delete cliente;
    }
    Todosclientes.clear();

    // Liberar memória alocada para gerentes
    for (Gerente* gerente : gerentes) {
        delete gerente;
    }
    gerentes.clear();

    // Liberar memória alocada para transações
    for (Transacao* transacao : transacoes) {
        delete transacao;
    }
    transacoes.clear();
}

void Menu :: salvarDados(){
    cout << "\n --- SALVANDO DADOS NO DISCO ---" << endl;

    //1. Salvando clientes
    // Salva caso o arquivo não existam, ou apaga e reescreve caso já exista
    ofstream arquivoClientes("clientes.csv");

    if(arquivoClientes.is_open()){
        for(Cliente *c : Todosclientes){
            arquivoClientes << c->getNome() << ","
                            << c->getDataDeNascimento() << ","
                            << c->getTrabalho() << ","
                            << c->getLogin() << ","
                            << c->getSenha() << ","
                            << c->getRemuneracao() << ","
                            << c->getTipoDeConta() << ","
                            << c->getRendimento() << ","
                            << c->getSaldo() << "\n";
        }

        arquivoClientes.close(); // fechando o arquivo
        cout << "[OK] Dados dos clientes salvos em 'clientes.csv" << endl;
    } else {
        cerr << "[ERRO]: Não foi possivel criar o arquivo clientes.csv!" << endl;
    }

    //2. Salvando gerentes
    ofstream arquivoGerentes("gerentes.csv");

    if(arquivoGerentes.is_open()){
        for(Gerente *g : gerentes){
            arquivoGerentes << g->getNome() << ","
                            << g->getTrabalho() << ","
                            << g-> getLogin() << ","
                            << g->getSenha() << "\n";
        }

        arquivoGerentes.close(); // fechando o arquivo
        cout <<"[OK] Dados dos gerentes salvos em 'gerentes.csv" << endl;
    } else {
        cerr << "[ERRO]: Não foi possivel criar o arquivo gerente.csv!" << endl;
    }

    cout << "\n >> Todos os dados foram salvos com sucesso! <<" << endl;
}

void Menu :: carregarDados(){
    string linha, dados;

    // Carregando clientes
    ifstream arquivoClientes("clientes.csv");
    if(arquivoClientes.is_open()){
        while(getline(arquivoClientes, linha)){
            stringstream ss(linha);
            vector<string> campos;

            // Separando as linhas por virgula
            while (getline(ss, dados, ',')){
                campos.push_back(dados);
            }

            // Atribuindo os campos (na mesma ordem que foram salvos)
            if(campos.size() >= 9){
                string nome = campos[0];
                string dataNascimento = campos[1];
                string trabalho = campos[2];
                string login = campos[3];
                string senha = campos[4];
                double remuneracao = stod(campos[5]); // converte string para double
                string tipoDeConta = campos[6];
                double taxa = stod(campos[7]);
                double saldo = stod(campos[8]);

                Cliente *c = new Cliente (nome, dataNascimento, trabalho, login, senha, remuneracao, tipoDeConta, taxa, saldo);
                Todosclientes.push_back(c);
            }
        }
        arquivoClientes.close();
        cout << "[SISTEMA]: Clientes carregados com sucesso." << endl;
    }

    // Carregandos gerentes
    ifstream arquivoGerentes("gerentes.csv");
    if(arquivoGerentes.is_open()){
        while(getline(arquivoGerentes, linha)){
            stringstream ss(linha);
            vector<string> campos;

            while (getline(ss, dados, ',')){
                campos.push_back(dados);

                if(campos.size() >= 4){
                    vector<Cliente *> clientesVazio;
                    Gerente *g = new Gerente(campos[0], campos[1], campos[2], campos[3], clientesVazio);
                    gerentes.push_back(g);
                }
            }
            arquivoGerentes.close();
            cout << "[SISTEMA]: Gerentes carregados com sucesso" << endl;
        }
    }
}

void Menu :: menuCartao(){
    cout <<"\n --- GERENCIAMENTO DE CARTÃO DE CRÉDITO ---" << endl;

    if(Todosclientes.empty()){
        cout <<"Erro: Nenhum cliente cadastrado." << endl;
        return;
    }

    //1. Seleciona o cliente primeiro
    cout <<"\n >>> Clientes Disponíveis:\n";
    for(size_t i = 0; i < Todosclientes.size(); i++){
        cout << "[" << i << "] - Nome: " << Todosclientes[i]->getNome() << endl;
    }

    int idCliente;
    cout <<"Digite o número do cliente: ";
    cin >> idCliente;

    if(idCliente < 0 || idCliente >= (int)Todosclientes.size()){
        cout <<"Erro: Cliente Inválido." << endl;
        return;
    }

    Cliente * clienteAtual = Todosclientes[idCliente];
    int opcaoCartao;

    //2. Sub-Menu do Cartão
    do{
        cout << "\n\t === CARTÃO DE " << clienteAtual->getNome() << " ===" << endl;
        cout << "1. Criar Cartão de Crédito" << endl;
        cout << "2. Alterar Limite" << endl;
        cout << "3. Realizar Compra Parcelada" << endl;
        cout << "4. Ver e Pagar Fatura" << endl;
        cout << "5. Bloquear / Desbloquear Cartão" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "\t ==========================================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcaoCartao;

        CartaoDeCredito * cartao = clienteAtual -> getCartao(); // Pegando o cartão

        switch (opcaoCartao){
            case 1: { // Cria o cartão
                if(cartao != nullptr){
                    cout << "Este cliente já possui um cartão de crédito!" << endl;
                } else {
                    // Defindo o limite inicial de acordo com a remuneração
                    double limiteCalculado = clienteAtual -> getRemuneracao() * 0.5;
                    CartaoDeCredito* novoCartao = new CartaoDeCredito(limiteCalculado);
                    clienteAtual->setCartao(novoCartao);

                    cout << ">>> Cartão criado com sucesso! Limite pré-aprovado: R$" << limiteCalculado << " <<<" << endl;

                }
                break;
            }
            case 2: { // Alterar o limite
                if(cartao == nullptr){
                    cout << "Erro: Cliente não possui cartão." << endl;
                    break;
                }

                double novoLimite;
                cout <<"Limite atual: R$" << cartao->getLimite() << endl;
                cout <<"Digite o novo limite: R$";
                cin >> novoLimite;
                cartao->alterarLimite(novoLimite);
                cout << "Limite alterado com sucesso! <<<" << endl;
                break;
            }
            case 3: { // Realizar Compra
                if(cartao == nullptr){
                    cout << "Erro: Cliente não possui cartão." << endl;
                    break;
                }

                double valor;
                int parcelas;

                cout <<"Valor de compra: R$";
                cin >> valor;
                cout <<"Número de parcelas: ";
                cin >> parcelas;

                if(parcelas <= 0){
                    parcelas = 1;
                }

                cartao->realizarCompra(valor, parcelas);
                break;
            }
            case 4: { // Paga fatura
                if(cartao == nullptr){
                    cout << "Erro: Cliente não possui cartão." << endl;
                    break;
                }

                cout <<"\nFatura atual: R$" << cartao->getfaturaAtual() << endl;
                cout <<"Saldo em conta: R$" << clienteAtual->getSaldo() << endl;

                if(cartao->getfaturaAtual() <= 0){
                    cout <<"A fatura já está zerada!" << endl;
                    break;
                }


                double valorPagamento;
                cout <<"Digite o valor que deseja pagar: R$";
                cin >> valorPagamento;

                //Caso o valor de pagamento seja maior do que a divida, o sistema corrige o valor
                if(valorPagamento > cartao->getfaturaAtual()){
                    cout<< "[Aviso]: Valor maior que a fatura! Ajustando o pagamento para o total da dívida: R$" << cartao->getfaturaAtual() << endl;
                    valorPagamento = cartao->getfaturaAtual();
                }

                //Validação
                if(valorPagamento > clienteAtual->getSaldo()){
                    cout <<"Erro: Saldo em conta insuficiente para esse pagamento." << endl;       
                } else if (valorPagamento <= 0) {
                    cout <<"Valor inválido." << endl;
                } else {
                    //Atualizando o saldo do cliente
                    clienteAtual->setSaldo(clienteAtual->getSaldo() - valorPagamento);

                    //Abatendo o valor na fatura do cartão
                    cartao->pagarFatura(valorPagamento);

                    cout << ">>> Pagamento realizado! Novo saldo em conta: R$" << clienteAtual->getSaldo() << " <<<" << endl;                    
                }
                break;
            }
            case 5: {
                if(cartao == nullptr){
                    cout << "Erro: Cliente não possui cartão." << endl;
                    break;
                }

                // Toggle para inverter o status de bloqueio do cartão
                if(cartao->getBloqueado()){
                    cartao->desbloquear();
                    cout << ">>> Cartão DESBLOQUEADO com sucesso. <<<" << endl;
                } else {
                    cartao->bloquear();
                    cout << ">>> Cartão BLOQUEADO com sucesso. <<<" << endl;
                }
                break;
            }
            case 0:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout <<"Opção Inválida" << endl;
        }

    } while(opcaoCartao != 0);
}