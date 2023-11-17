#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Objetivo: criar a variável com nome e senha inteira e atribuir um valor qualquer*/
    int comp, tentativa = 1;
    char senha[8] = "12345678", senha_usuario[] = "a";

    printf("\nsenha usuario = %c", senha_usuario);
    while((comp = strcmp(senha, senha_usuario)) < 0) {
        if (tentativa > 3) {
            printf("Você atingiu o limite máximo de tentativas!");
            return;
        }

        printf("\nTentativa %i informe a senha: ", tentativa);
        scanf("%c", &senha_usuario);
        printf("\nsenha usuario = %c", senha_usuario);

        tentativa++;
        if(comp = strcmp(senha, senha_usuario) == 0) {
            printf("Acesso altorizado");
        break;
        }
    }

    return 0;
}
