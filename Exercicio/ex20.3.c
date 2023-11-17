#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Objetivo: criar a variável com nome e senha inteira e atribuir um valor qualquer*/
    int senha = 1234, tentativa = 1, senha_usuario;


    while(senha != senha_usuario) {
        if (tentativa > 3) {
            printf("Você atingiu o limite máximo de tentativas!");
            return;
        }

        printf("Tentativa %i informe a senha: ", tentativa);
        scanf("%i", &senha_usuario);

        tentativa++;
        if(senha == senha_usuario) {
            printf("Acesso altorizado");
        break;
        }
    }

    return 0;
}
