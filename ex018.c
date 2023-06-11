#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Objetivo: Escreva um programa que lê o tamanho
    do lado de um quadrado e imprime um quadrado
    daquele tamanho com asteriscos. Seu programa deve
    funcionar para quadrados com lados de todos os tamanhos entre 1 e 20.*/
    int i = 1, lado;
    printf("Informe o tamanho do quadrado que quer imprimir: ");
    scanf("%i", &lado);
    while(i <= (lado * lado)) {
        printf("* ");
        if(i % lado == 0) {
            printf("\n");
        }
        i++;

    }


    return 0;
}
