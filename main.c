#include "menus.h"

int main()
{
    char op[15];
    menuInic(op);

    Produto *ponteiro;
    Produto produto;
    ponteiro = &produto;

    SalvarProduto(ponteiro);

     printf("Categoria: %d\n", ponteiro->category);
     printf("Fabricante: %s\n", ponteiro->fabricante);
     printf("Código: %d\n", ponteiro->cod);
     printf("Corredor/Prateleira: %d/%d\n", ponteiro->local.corredor, ponteiro->local.prateleira);





    return 0;
}
