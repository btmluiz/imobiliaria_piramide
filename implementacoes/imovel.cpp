//
// Created by luiz on 17/09/2019.
//
#include "imovel.h"
#include "cliente.h"
#include <iostream>
#include <cstring>

using namespace std;

void newImovel(Imovel *&imovel, int *n, int codCliente, double aluguel, double iptu, Endereco* endereco, string situacao, int *imovelIncrement){
    auto *aux = new Imovel[(*n)+1];

    for(int i = 0; i < (*n); i++){
        aux[i] = imovel[i];
    }

    aux[(*n)].codImovel = (*imovelIncrement);
    aux[(*n)].codCliente = codCliente;
    aux[(*n)].aluguel = aluguel;
    aux[(*n)].iptu = iptu;
    aux[(*n)].endereco = (*endereco);
    aux[(*n)].situacao = situacao;

    if((*n) != 0)
        delete[] imovel;

    imovel = aux;
    (*n)++;
    (*imovelIncrement)++;
}

void imprimeImovel(Imovel *imovel, int n){
    cout << "#######################################" << endl;
    for(int i = 0; i < n; i++){
        string clienteStatus = (imovel[i].codCliente >= 0) ? to_string(imovel[i].codCliente) : "Sem morador";
        cout << "Codigo do Imovel: " << imovel[i].codImovel << endl;
        cout << "Codigo do Cliente: " << clienteStatus << endl;
        cout << "Valor do Aluguel: R$" << imovel[i].aluguel << endl;
        cout << "Valor do IPTU: R$" << imovel[i].iptu << endl;
        cout << "Endereco: Rua " << imovel[i].endereco.rua << ", N " << imovel[i].endereco.numero << endl;
        cout << "Bairro: " << imovel[i].endereco.bairro << ", " << imovel[i].endereco.cidade << "-" << imovel[i].endereco.estado << endl;
        cout << "CEP: " << imovel[i].endereco.cep << endl;
        cout << "Situacao: " << imovel[i].situacao << endl;
        cout << "#######################################" << endl;
    }
}

void consultaImovel(Imovel *imovel, int n, int cod){
    cout << "#######################################" << endl;
    for(int i = 0; i < n; i++){
        if(imovel[i].codImovel == cod) {
            string clienteStatus = (imovel[i].codCliente >= 0) ? to_string(imovel[i].codCliente) : "Sem morador";
            cout << "Codigo do Imovel: " << imovel[i].codImovel << endl;
            cout << "Codigo do Cliente: " << clienteStatus << endl;
            cout << "Valor do Aluguel: R$" << imovel[i].aluguel << endl;
            cout << "Valor do IPTU: R$" << imovel[i].iptu << endl;
            cout << "Endereco: Rua " << imovel[i].endereco.rua << ", N " << imovel[i].endereco.numero << endl;
            cout << "Bairro: " << imovel[i].endereco.bairro << ", " << imovel[i].endereco.cidade << "-"
                 << imovel[i].endereco.estado << endl;
            cout << "CEP: " << imovel[i].endereco.cep << endl;
            cout << "Situacao: " << imovel[i].situacao << endl;
            cout << "#######################################" << endl;
            break;
        }
    }
}

void addInquilino(Imovel *imovel, int n, int codImovel, int codCliente){
    int aux = verificarImovel(imovel, n, codImovel);
    if(aux >= 0){
        imovel[aux].codCliente =  codCliente;
        std::cout << "Adicionado com sucesso" << endl;
    } else
        std::cout << "Codigo invalido" << endl;
}

int verificarImovel(Imovel *imovel, int n, int cod){
    bool aux = -1;
    for(int i = 0; i < n; i++){
        if(imovel[i].codImovel == cod){
            aux = i;
            break;
        }
    }
    return aux;
}

void removerImovel (Imovel *&imovel, int *n, int cod){
    Imovel *aux = new Imovel[(*n)-1];
    int iaux = verificarImovel(imovel, (*n), cod);
    if(iaux != -1) {
        for (int i = 0; i < ((*n) - 1); ++i) {
            if (i >= iaux)
                aux[i] = imovel[i+1];
            else
                aux[i] = imovel[i];
        }

        delete[] imovel;

        imovel = aux;
        (*n)--;
        cout << "Imovel removido com sucesso" << endl;
    } else
        cout << "Imovel nao existe" << endl;
}

string repetirEspaco (string conteudo, int width, string repetidor){
    string aux = conteudo;
    for (int i = 0; i < width-conteudo.length(); ++i) {
        aux += repetidor;
    }
    return aux;
}

Endereco* newEndereco(string rua, int numero,string bairro, string cidade, string estado, string cep){
    Endereco* e = new Endereco;

    e->rua = rua;
    e->numero = numero;
    e->bairro = bairro;
    e->cidade = cidade;
    e->estado = estado;
    e->cep = cep;

    return e;
}