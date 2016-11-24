#include "produtos.h"

void cadastrarProduto(Produto *produto){
    FILE *f;
    lerProduto(produto);
    f = fopen("produtos.prdt","a");
    fprintf(f, "%i; %s; %i; %.2lf; %s; %i/%i; %i/%i/%i\n",
            produto->category, produto->descricao, produto->cod, produto->preco, produto->fabricante,
            produto->local.prateleira, produto->local.corredor,
            produto->validade.dia, produto->validade.mes, produto->validade.ano);
    fclose(f);
}

Produto *lerProduto(Produto *produto){
    int cat;

    printf("Escolha a categoria do produto:\n");
    printf("1 - Limpeza\n");
    printf("2 - Alimento perecivel\n");
    printf("3 - Alimento nao-perecivel\n");
    printf("4 - Eletronico\n");
    scanf("%i", &cat);
    produto->category = cat;
    printf("Descricao:");
    scanf("%s", produto->descricao);
    printf("\nCodigo:");
    scanf("%i", &produto->cod);
    printf("\nPreco:");
    scanf("%lf", &produto->preco);
    printf("\nFabricante/Fornecedor:");
    scanf("%s", produto->fabricante);
    printf("\nCorredor:");
    scanf("%i", &produto->local.corredor);
    printf("\nPrateleira:");
    scanf("%i", &produto->local.prateleira);
    printf("\nData de validade:");
    scanf("%i %i %i", &produto->validade.dia, &produto->validade.mes, &produto->validade.ano);
    return produto;
}

Produto *buscarPorDes(Produto *produto, int tam){
    return produto;
}

Produto *buscarPorFab(Produto *produto, int tam){
    return produto;
}

Produto *ordMenPreco(Produto *produto, int tam){
    return produto;
}

Produto *ordQntEst(Produto *produto, int tam){
    return produto;
}

Produto *ordAlf(Produto *produto, int tam){
    return produto;
}

Produto *ordCat(Produto *produto, int tam){
    return produto;
}


void SalvarProduto(Produto *produto)
{
    FILE* file;
    file = fopen("produtos.prdt", "r");




     fscanf(file, "%d %s %d %lf %s %d/%d %d/%d/%d\n", &produto->category, &produto->descricao, &produto->cod, &produto->preco, &produto->fabricante, &produto->local.prateleira, &produto->local.corredor, &produto->validade.dia, &produto->validade.mes, &produto->validade.ano);




  fclose(file);
}



