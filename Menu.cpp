#include "Menu.h"

#include <cctype>
#include <algorithm>

// Implementação dos métodos da classe Menu
void Menu :: exibirMenu(){
    cout << "\t ====== SISTEMA DE GERENCIAMENTO DE BANCO ======" << endl;
    cout << "1. Cadastrar cliente" << endl;
    cout << "2. Cadastrar gerente" << endl;
    cout << "3. Criar transação" << endl;
    cout << "4. Exibir extrato de um cliente" << endl;
    cout << "5. Associar gerente a cliente" << endl;
    cout << "6. Listar clientes" << endl;
    cout << "7. Listar gerentes" << endl;
    cout << "8. Salvar dados e sair" << endl;
    cout << "0. Sair" << endl;
    cout << "\t ================================================" << endl;
    cout << "Escolha uma opção: ";
}

// Método para cadastrar um cliente
void Menu :: cadastrarCliente() {
    // Lógica para cadastrar cliente
    cout << "\n --- CADASTRO DE CLIENTE --- \n" << endl;
    string nome, trabalho, login, senha, tipoDeConta;
    double remuneracao, taxaDeRendimento = 0.0, saldo;

    cin.ignore(); // Limpar o buffer do cin

    // Solicitar informações do cliente
    cout << "Nome completo: ";
    getline(cin, nome);

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

    transform(tipoDeConta.begin(), tipoDeConta.end(), tipoDeConta.begin(), ::tolower);

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

    try{
        // Cria um novo cliente e adicionar à lista
        Cliente* novoCliente = new Cliente(nome, trabalho, login, senha, remuneracao, tipoDeConta, taxaDeRendimento, saldo);
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
    cout << "\n --- LISTA DE CLIENTES --- \n" << endl;
    if(Todosclientes.empty()){
        cout << "Nenhum cliente cadastrado." << endl;
    } else {
        for (const auto& cliente : Todosclientes) {
            cliente->exibirDados();
            cout << endl;
        }
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

    vector<Cliente*> clientesIniciais;

    Gerente* gerente = new Gerente (nome, trabalho, login, senha, clientesIniciais);
    gerentes.push_back(gerente);

    cout << ">>> Gerente cadastrado com sucesso! <<<" << endl;
}

void Menu :: listarGerentes(){

    cout << "\n --- LISTA DE GERENTES --- \n" << endl;
    if(gerentes.empty()){
        cout << "Nenhum gerente cadastrado." << endl;
    } else {
        for (const auto& gerente : gerentes) {
            gerente->exibirDados();
            cout << endl;
        }
    }

}

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
    cout << Todosclientes[idCliente]->getNome() << "agora é cliente de: " << gerentes[idGerente]->getNome() <<"." << endl;;
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

            cout << "\n >> CLientes disponíveis: ";
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

// Método para listar os clientes cadastrados
Menu :: ~Menu() {
    // Liberar memória alocada para clientes
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