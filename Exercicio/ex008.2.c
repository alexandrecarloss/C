#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: fazer uma matriz identidade de tamanho informado pelo usu�rio
    //Declara��o de vari�vel
    int i, tamanho;

    //Entrada de dados: n�mero de linha e coluna da matriz
    printf("Informe o tamanho da matriz identidade (n�mero de linha ou coluna): ");
    scanf("%i", &tamanho);

    //La�o de repeti�ao de 1 at� o tamanho ao quadrado
    for(i = 1; i<= (tamanho * tamanho); i++) {
        //Condi��o para o n�mero 1 na matriz
        if((i + tamanho) % (tamanho + 1) == 0) {
            printf("1 ");
        //Sen�o imprime o n�mero 0
        } else {
            printf("0 ");
        }
        //A cada vez que o n�mero de repeti��o for diviz�vel pelo tamanho da linha pula uma linha
        if(i % tamanho == 0) {
            printf("\n");
        }

    }
    return 0;
}
