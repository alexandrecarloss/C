#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Objetivo: criar a variável com nome e senha inteira e atribuir um valor qualquer*/
    int comp2 = 1, comp = 1;
    char inome[60], nome[60] = "alexandre", isenha[8], senha[8] = "12348765";



    while((comp != 0) || (comp2 != 0)) {
        printf("\nInforme o nome: ");
        scanf("%s", &inome);

        printf("\nInforme a senha: ");
        scanf("%s", &isenha);

        comp = strcmp(inome, nome);
        comp2 = strcmp(isenha, senha);
    }
    printf("%i %i", comp, comp2);
    printf("Acesso altorizado");

    return 0;
}
