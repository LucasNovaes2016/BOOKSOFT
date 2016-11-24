/*-----------------------------------------------------------------------------------------------------------------------------

    Neste arquivo, está contido os cabeçalhs das funções para exibição de menus.

  -----------------------------------------------------------------------------------------------------------------------------
*/


#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logins.h"
#include "produtos.h"

void menuInic(char *op);// Imprime na saída padrão o menu inicial

void menuInicInv(char *op);// Imprime na saída padrão o menu inicial com menssagem de erro

void menuCliente();// Imprime na saída padrão o menu para clientes

void menuFunc();// Imprime na saída padrão o menu para funcionários

void menuAdmn();// Imprime um menu secreto para administrador

void telaLogin(char tipo[20]);

void telaCriarLogin(char tipo[20]);

#endif // MENUS_H_INCLUDED
