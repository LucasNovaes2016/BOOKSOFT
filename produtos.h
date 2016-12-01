/**
 * @file	main.cpp
 * @brief	Definicao de prototipos de classes referentes aos produtos
 * @author	Leonardo Dias, Lucas Novaes, Renan Kimura, Yuri Ferreira
 * @since	27/10/2016
 * @date	01/12/2016
 */
#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    LIMPEZA, PERECIVEL, NAO_PERECIVEL, ELETRONICO
}Category;

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int corredor;
    int prateleira;
}Localizacao;

typedef struct{
    Category category;
    int cod;
    char descricao[50];
    char fabricante[50];
    Localizacao local;
    double preco;
    Data validade;
}Produto;

void cadastrarProduto(Produto *produto);
Produto *lerProduto(Produto *produto);

Produto *buscarPorDes(Produto *produto, int tam);
Produto *buscarPorFab(Produto *produto, int tam);

Produto *ordMenPreco(Produto *produto, int tam);
Produto *ordQntEst(Produto *produto, int tam);
Produto *ordAlf(Produto *produto, int tam);
Produto *ordCat(Produto *produto, int tam);

#endif // PRODUTOS_H_INCLUDED
