#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Exibir individualmente números "0" ou "1", conforme esta matriz 5x5:
    1 0 0 0 1
    1 0 0 0 1
    1 0 0 0 1
    1 0 0 0 1
    1 0 0 0 1*/

    //Definição de variáveis
    int i, j;

    //Escrevendo a matriz usando 2 for aninhados
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= 5; j++) {
            if((j == 1) || (j == 5)) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
