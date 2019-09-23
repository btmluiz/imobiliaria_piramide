//
// Created by luiz on 17/09/2019.
//
#include <cstring>
#include "cliente.h"
#ifndef IMOVEL_H
#define IMOVEL_H

typedef struct endereco {
    std::string rua;
    int numero;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;
} Endereco;

struct Imovel {
    int codImovel;
    int codCliente;
    double aluguel;
    double iptu;
    Endereco endereco;
    std::string situacao;
};

void newImovel(Imovel *&imovel, int *n, int codCliente, double aluguel, double iptu, Endereco* endereco, std::string situacao, int *imovelIncrement);
void imprimeImovel(Imovel *imovel, int n);
void consultaImovel(Imovel *imovel, int n, int cod);
void addInquilino(Imovel *imovel, int n, int codImovel, int codCliente);
int verificarImovel(Imovel *imovel, int n, int cod);
void removerImovel (Imovel *&imovel, int *n, int cod);
std::string repetirEspaco (std::string conteudo, int width, std::string repetidor);
Endereco* newEndereco(std::string rua, int numero, std::string bairro, std::string cidade, std::string estado, std::string cep);

#endif