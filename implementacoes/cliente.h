//
// Created by luiz on 17/09/2019.
//
#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H

struct Cliente {
    int cod_cliente;
    std::string nome;
    std::string cpf;
};

void newCliente(Cliente *&c, int *n, std::string nome, std::string cpf, int *clienteIncrement);
void imprimeCliente(Cliente *c, int n);
void consultaCliente(Cliente *c, int nC, int cod);
void removerCliente(Cliente *&c, int *n, int cod);
int posicaoCliente(Cliente *c, int n, int cod);
bool verificarCliente(Cliente *c, int n, int cod);

#endif