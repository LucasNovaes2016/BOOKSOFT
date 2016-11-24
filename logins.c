/*-----------------------------------------------------------------------------------------------------------------------------

    Neste arquivo, está contido os códigos das funções para verificação e criação de logins e senhas.

  -----------------------------------------------------------------------------------------------------------------------------
*/


#include "logins.h"

void criarLogin(char *tipo){
    FILE *f;
    char login[16];
    char fString[16];
    strcpy(fString, tipo);
    scanf("%s", login);
    strcat(fString, login);
    f = fopen("log.in","a");
    fprintf(f, "%s:", fString);
    fclose(f);
}

void criarSenha(char *login){
    FILE *f;
    char senha[50];
    char fString[16];
    strcpy(fString, login);
    scanf("%s", senha);
    strcat(fString, login);
    f = fopen("passwords.psw","a");
    fprintf(f, "%s : ", fString);
    fclose(f);
}

int loginFunc(char *login){//Verifica se o funcionario digitou o login correto - retorna 1 se verdade
    FILE *f;
    char flogin[16];
    char result[20];
    char c;
    f = fopen("log.in","r");
    while(1)
    {
        c = fgetc(f);
        if( c == ':' )
        {
            break ;
        }
        sprintf(flogin, "%c", c);
    }
    strcat(result, "cliente");
    strcat(result, login);
    fclose(f);
    return strcmp(result, flogin);
}

int loginCliente(char *login){//Verifica se o cliente digitou o login correto - retorna 1 se verdade
    FILE *f;
    char flogin[16];
    char result[20];
    char c;
    f = fopen("log.in","r");
    while(1)
    {
        c = fgetc(f);
        if( c == ':' )
        {
            break ;
        }
        sprintf(flogin, "%c", c);
    }
    strcat(result, "cliente");
    strcat(result, login);
    fclose(f);
    return strcmp(result, flogin);
}

int loginAdmn(char *login){//Verifica se o administrador digitou o login correto - retorna 1 se verdade
    FILE *f;
    char flogin[16];
    char result[20];
    char c;
    f = fopen("log.in","r");
    while(1)
    {
        c = fgetc(f);
        if( c == ':' )
        {
            break ;
        }
        sprintf(flogin, "%c", c);
    }
    strcat(result, "cliente");
    strcat(result, login);
    fclose(f);
    return strcmp(result, flogin);
}

int catchSenha(char *user){//Verifica se a senha do usuário é válida
    FILE *f;
    char senha[50];
    char result[50];
    char fsenha[50];
    char c;
    f = fopen("passwords.psw","r");
    scanf("%s", senha);
    strcpy(result, user);
    strcat(senha, result);
    while(1)
    {
        c = fgetc(f);
        if( c == ':' )
        {
            break ;
        }
        sprintf(fsenha, "%c", c);
    }
    fclose(f);
    return strcmp(senha, fsenha);
}

