#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: fazer uma matriz identidade de tamanho informado pelo usuário
    //Declaração de variável
    int i, tamanho;

    //Entrada de dados: número de linha e coluna da matriz
    printf("Informe o tamanho da matriz identidade (número de linha ou coluna): ");
    scanf("%i", &tamanho);

    //Laço de repetiçao de 1 até o tamanho ao quadrado
    for(i = 1; i<= (tamanho * tamanho); i++) {
        //Condição para o número 1 na matriz
        if((i + tamanho) % (tamanho + 1) == 0) {
            printf("1 ");
        //Senão imprime o número 0
        } else {
            printf("0 ");
        }
        //A cada vez que o número de repetição for divizível pelo tamanho da linha pula uma linha
        if(i % tamanho == 0) {
            printf("\n");
        }

    }
    return 0;
}
