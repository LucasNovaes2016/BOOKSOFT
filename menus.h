/*-----------------------------------------------------------------------------------------------------------------------------

    Neste arquivo, est� contido os cabe�alhs das fun��es para exibi��o de menus.

  -----------------------------------------------------------------------------------------------------------------------------
*/


#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logins.h"
#include "produtos.h"

void menuInic(char *op);// Imprime na sa�da padr�o o menu inicial

void menuInicInv(char *op);// Imprime na sa�da padr�o o menu inicial com menssagem de erro

void menuCliente();// Imprime na sa�da padr�o o menu para clientes

void menuFunc();// Imprime na sa�da padr�o o menu para funcion�rios

void menuAdmn();// Imprime um menu secreto para administrador

void telaLogin(char tipo[20]);

void telaCriarLogin(char tipo[20]);

#endif // MENUS_H_INCLUDED
