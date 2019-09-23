//
// Created by luiz on 17/09/2019.
//
#include "cliente.h"
#include <iostream>
#include "imovel.h"

using namespace std;

void newCliente(Cliente *&c, int *n, string nome, string cpf, int *clienteIncrement){
    Cliente* aux = new Cliente[(*n)+1];

    for (int i = 0; i < (*n); i++) {
        aux[i] = c[i];
    }

    aux[(*n)].cod_cliente = (*clienteIncrement);
    aux[(*n)].nome = nome;
    aux[(*n)].cpf = cpf;

    if((*n) != 0)
        delete[] c;

    c = aux;
    (*n)++;
    (*clienteIncrement)++;
}

void imprimeCliente(Cliente *c, int n){
    cout << "#######################" << endl;
    for(int i = 0; i < n; i++){
        cout << "Codigo do Cliente: " << c[i].cod_cliente << endl;
        cout << "Nome: " << c[i].nome << endl;
        cout << "CPF: " << c[i].cpf << endl;
        cout << "#######################" << endl;
    }
}

void consultaCliente(Cliente *c, int nC, int cod){
    cout << "#######################" << endl;
    for(int i = 0; i < nC; i++){
        if(c[i].cod_cliente == cod) {
            cout << "Codigo do Cliente: " << c[i].cod_cliente << endl;
            cout << "Nome: " << c[i].nome << endl;
            cout << "CPF: " << c[i].cpf << endl;
            cout << "#######################" << endl;
            break;
        }
    }
}

void removerCliente(Cliente *&c, int *n, int cod){
    Cliente *aux = new Cliente[(*n)-1];
    int iaux = posicaoCliente(c, (*n), cod);
    if(iaux != -1) {
        for (int i = 0; i < (*n) - 1; ++i) {
            if (i >= iaux)
                aux[i] = c[i + 1];
            else
                aux[i] = c[i];
        }

        delete[] c;

        c = aux;
        (*n)--;
        cout << "Cliente removido com sucesso" << endl;
    } else
        cout << "Cliente nao existe" << endl;
}

int posicaoCliente(Cliente *c, int n, int cod){
    for (int i = 0; i < n; ++i) {
        if(c[i].cod_cliente == cod)
            return i;
    }
    return -1;
}

bool verificarCliente(Cliente *c, int n, int cod){
    bool aux = true;
    for (int i = 0; i < n; i++) {
        cout << (c[i]).cod_cliente << cod << endl;
        if(c[i].cod_cliente == cod){
            aux = false;
            break;
        }
    }
    return aux;
}