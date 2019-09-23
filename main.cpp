#include <iostream>
#include <limits>
#include "implementacoes/cliente.h"
#include "implementacoes/imovel.h"

void getCin(int *opt);
void getCin(double *opt);
void getCin(std::string *opt);
void imprimeFatura(Imovel *imovel, int n, int cod, Cliente *cliente, int nC);

int main() {
    int nC = 0;
    int nI = 0;
    int clienteIncrement = 1;
    int imovelIncrement = 1;
    Cliente *clientes;
    Imovel *imoveis;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        int opt;
        std::cout << "######### Imobiliaria Piramide #########" << std::endl;
        std::cout << "1 - Consultar" << std::endl;
        std::cout << "2 - Adicionar" << std::endl;
        std::cout << "3 - Remover" << std::endl;
        std::cout << "4 - Imprimir Fatura" << std::endl;
        std::cout << "9 - Encerrar programa" << std::endl;
        std::cout << "Digite sua opcao: ";
        getCin(&opt);

        if(opt == 1){
            while(true) {
                std::cout << "############### Consulta ###############" << std::endl;
                std::cout << "1 - Cliente" << std::endl;
                std::cout << "2 - Imovel" << std::endl;
                std::cout << "3 - Lista de Clientes" << std::endl;
                std::cout << "4 - Lista de Imoveis" << std::endl;
                std::cout << "9 - Voltar" << std::endl;
                std::cout << "Digite a sua opcao: ";
                getCin(&opt);

                if (opt == 1) {
                    std::cout << "########### Consultar Cliente ###########" << std::endl;
                    if (nC <= 0)
                        std::cout << "Nenhum cliente cadastrado" << std::endl;
                    else {
                        std::cout << "Digite o codigo do Cliente: ";
                        getCin(&opt);
                        consultaCliente(clientes, nC, opt);
                    }
                } else if (opt == 2) {
                    std::cout << "########### Consultar Imovel ###########" << std::endl;
                    if (nI <= 0)
                        std::cout << "Nenhum imovel cadastrado" << std::endl;
                    else {
                        std::cout << "Digite o codigo do Cliente: ";
                        getCin(&opt);
                        consultaImovel(imoveis, nI, opt);
                    }
                } else if (opt == 3) {
                    std::cout << "########### Lista de Clientes ###########" << std::endl;
                    if (nC <= 0)
                        std::cout << "Nenhum cliente cadastrado" << std::endl;
                    else
                        imprimeCliente(clientes, nC);
                } else if (opt == 4) {
                    std::cout << "########### Lista de Imoveis ###########" << std::endl;
                    if (nI <= 0)
                        std::cout << "Nenhum imovel cadastrado" << std::endl;
                    else
                        imprimeImovel(imoveis, nI);
                } else if(opt == 9){
                    break;
                } else {
                    std::cout << "########################################" << std::endl;
                    std::cout << "Opcao invalida" << std::endl;
                }
            }
        } else if (opt == 2){
            while(true) {
                std::cout << "############### Adicionar ###############" << std::endl;
                std::cout << "1 - Cliente" << std::endl;
                std::cout << "2 - Imovel" << std::endl;
                std::cout << "3 - Inquilino" << std::endl;
                std::cout << "9 - Voltar" << std::endl;
                std::cout << "Digite sua opcao: ";
                getCin(&opt);

                if (opt == 1) {
                    std::cout << "########### Adicionar Cliente ###########" << std::endl;
                    std::string nome, cpf;
                    std::cout << "Digite o nome: ";
                    std::getline(std::cin, nome);
                    std::cout << "Digite o cpf: ";
                    std::cin >> cpf;
                    newCliente(clientes, &nC, nome, cpf, &clienteIncrement);
                } else if (opt == 2) {
                    std::cout << "########### Adicionar Imovel ###########" << std::endl;
                    int numero, cod;
                    double aluguel, iptu;
                    std::string rua, bairro, cidade, estado, cep, situacao;

                    std::cout << "Digite o valor do aluguel: ";
                    getCin(&aluguel);
                    std::cout << "Digite o valor do IPTU: ";
                    getCin(&iptu);
                    std::cout << "Agora informe o endereco" << std::endl;
                    std::cout << "Rua: ";
                    getCin(&rua);
                    std::cout << "Numero: ";
                    getCin(&numero);
                    std::cout << "Bairro: ";
                    getCin(&bairro);
                    std::cout << "Cidade: ";
                    getCin(&cidade);
                    std::cout << "Estado: ";
                    getCin(&estado);
                    std::cout << "CEP: ";
                    getCin(&cep);

                    std::cout << "Deseja atribuir um morador?" << std::endl;
                    std::cout << "1 - Sim" << std::endl;
                    std::cout << "2 - Nao" << std::endl;
                    std::cout << "Digite sua opcao: ";
                    getCin(&opt);

                    if(opt == 1){
                        std::cout << "Digite o codigo do cliente";
                        getCin(&cod);
                        std::cout << "Digite a situacao";
                        getCin(&situacao);
                    } else {
                        cod = -1;
                        situacao = "Disponivel";
                    }

                    newImovel(imoveis, &nI, cod, aluguel, iptu, newEndereco(rua, numero, bairro, cidade, estado, cep), situacao, &imovelIncrement);
                } else if(opt == 3) {
                    std::cout << "########## Adicionar Inquilino ##########" << std::endl;
                    int codImovel, codCliente;
                    std::cout << "Digite o codigo do cliente: ";
                    getCin(&codCliente);
                    if (verificarCliente(clientes, nC, codCliente)){
                        std::cout << "Codigo de cliente invalido" << std::endl;
                        continue;
                    }
                    std::cout << "Digite o codigo do imovel: " << std::endl;
                    getCin(&codImovel);
                    addInquilino(imoveis, nI, codImovel, codCliente);
                } else if(opt == 9){
                    break;
                } else {
                    std::cout << "########################################" << std::endl;
                    std::cout << "Opcao invalida" << std::endl;
                }
            }
        } else if (opt == 3){
            while(true) {
                std::cout << "############### Remover ###############" << std::endl;
                std::cout << "1 - Cliente" << std::endl;
                std::cout << "2 - Imovel" << std::endl;
                std::cout << "3 - Inquilino" << std::endl;
                std::cout << "9 - Voltar" << std::endl;
                std::cout << "Digite sua opcao: ";
                getCin(&opt);

                if (opt == 1) {
                    std::cout << "########### Remover  Cliente ###########" << std::endl;
                    if (nC > 0) {
                        std::cout << "Digite o codigo do cliente: ";
                        getCin(&opt);
                        if(verificarCliente(clientes, nC, opt))
                            removerCliente(clientes, &nC, opt);
                    } else {
                        std::cout << "Nenhum Cliente cadastrado" << std::endl;
                    }
                } else if (opt == 2) {
                    std::cout << "############ Remover Imovel ############" << std::endl;
                    if (nI > 0){
                        std::cout << "Digite o codigo do imovel: ";
                        getCin(&opt);
                        removerImovel(imoveis, &nI, opt);
                    } else
                        std::cout << "Nenhum Imovel cadastrado" << std::endl;
                } else if(opt == 3){
                    std::cout << "############ Remover Imovel ############" << std::endl;
                    if (nI > 0) {
                        std::cout << "Digite o codigo do imovel: ";
                        getCin(&opt);
                        addInquilino(imoveis, nI, opt, -1);
                    }
                } else if(opt == 9){
                    break;
                } else {
                    std::cout << "########################################" << std::endl;
                    std::cout << "Opcao invalida" << std::endl;
                }
            }
        } else if (opt == 4){
            std::cout << "########### Imprimir  Fatura ###########" << std::endl;
            std::cout << "Digite o codigo do imovel: ";
            getCin(&opt);
            imprimeFatura(imoveis, nI, opt, clientes, nC);
        } else if (opt == 9){
            std::cout << "########## Encerrar  Programa ##########" << std::endl;
            std::cout << "Ao encerrar o programa todos" << std::endl <<"os dados serao apagados" << std::endl;
            std::cout << "1 - Sim" << std::endl;
            std::cout << "2 - Nao" << std::endl;
            std::cout << "Deseja encerra-lo? ";
            std::cin >> opt;
            if(opt == 1) {
                std::cout << "Encerrando ..." << std::endl;
                break;
            }
        } else {
            std::cout << "########################################" << std::endl;
            std::cout << "Opcao invalida" << std::endl;
        }
    }
#pragma clang diagnostic pop
//    newCliente(clientes, &nC, "Luiz", "12501579437");
//    //imprimeCliente(clientes, nC);
//    consultaCliente(clientes, nC, 0);
//    newImovel(imoveis, &nI, 0, 550, 10, end, "Adiemplente");
//    //imprimeImovel(imoveis, nI);
//    consultaImovel(imoveis, nI, 0);
    return 0;
}

void imprimeFatura(Imovel *imovel, int n, int cod, Cliente *cliente, int nC){
    int aux = verificarImovel(imovel, n, cod);

    if(aux >= 0){
        int clienteCod = verificarCliente(cliente, nC, imovel[aux].codCliente);
        if(clienteCod >= 0) {
            std::string nome = cliente[clienteCod].nome;
            std::string cpf = cliente[clienteCod].cpf;
            double aluguel = imovel[aux].aluguel, iptu = imovel[aux].iptu;
            double banco, adm, total, padm;

            if (aluguel <= 1000)
                banco = 1.50;
            else
                banco = 0.95;

            if (aluguel <= 500)
                padm = 8;
            else if (aluguel <= 2000)
                padm = 5;
            else
                padm = 3;
            adm = (padm * aluguel) / 100;
            total = aluguel + iptu + banco + adm;

            std::cout << "╔════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║                Imobiliaria Piramide                ║" << std::endl;
            std::cout << "║                                                    ║" << std::endl;
            std::cout << "║   " << repetirEspaco("Aluguel", 35, " ")
                 << repetirEspaco(std::to_string(aluguel), 52 - 28 - std::to_string(aluguel).length(), " ") << "║" << std::endl;
            std::cout << "║   " << repetirEspaco("IPTU", 35, " ")
                 << repetirEspaco(std::to_string(iptu), 52 - 29 - std::to_string(iptu).length(), " ") << "║" << std::endl;
            std::cout << "║   " << repetirEspaco("Banco", 35, " ")
                 << repetirEspaco(std::to_string(banco), 52 - 30 - std::to_string(banco).length(), " ") << "║" << std::endl;
            std::cout << "║   " << repetirEspaco("Administracao", 35, " ")
                 << repetirEspaco(std::to_string(adm), 52 - 29 - std::to_string(adm).length(), " ") << "║" << std::endl;
            std::cout << "║   " << repetirEspaco("Total", 35, " ")
                 << repetirEspaco(std::to_string(total), 52 - 29 - std::to_string(adm).length(), " ") << "║" << std::endl;
            std::cout << "║                                                    ║" << std::endl;
            std::cout << "╠" << repetirEspaco("", 52, "═") << "╣" << std::endl;
            std::cout << "║" << repetirEspaco("  Dados do pagador:", 52, " ") << "║" << std::endl;
            std::cout << "║   Nome: " << repetirEspaco(nome, 43, " ") << "║" << std::endl;
            std::cout << "║   CPF: " << repetirEspaco(cpf, 44, " ") << "║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════╝" << std::endl;
        } else
            std::cout << "Nao ha inquilino nesse imovel" << std::endl;
    } else {
        std::cout << "Imovel nao exite" << std::endl;
    }
}

void getCin(int *opt){
    std::cin >> (*opt);
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}

void getCin(double *opt){
    std::cin >> (*opt);
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}

void getCin(std::string *opt){
    //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, *opt);
}