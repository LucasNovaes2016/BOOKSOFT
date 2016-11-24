/*-----------------------------------------------------------------------------------------------------------------------------

    Neste arquivo, está contido os cabeçalhos das funções para verificação e criação de logins e senhas.

  -----------------------------------------------------------------------------------------------------------------------------
*/



#ifndef LOGINS_H_INCLUDED
#define LOGINS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"

void criarLogin(char *tipo);

void criarSenha(char *login);

int loginFunc(char *login);//Verifica se o funcionario digitou o login correto - retorna 1 se verdade

int loginCliente(char *login);//Verifica se o cliente digitou o login correto - retorna 1 se verdade

int loginAdmn(char *login);//Verifica se o administrador digitou o login correto - retorna 1 se verdade

int catchSenha(char *user);//Verifica se a senha do usuário é válida

#endif // LOGINS_H_INCLUDED
