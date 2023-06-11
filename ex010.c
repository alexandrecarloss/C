#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: exibir os números inteiros em 5 colunas de 10 em 10
    //Declaração de variáveis
    int num, sequencia, i;

    for(num = 1; num <= 5; num++) {
        sequencia = num * 10;
        printf("%i - %i - ", num, sequencia);
        for(i = 1; i <= 3; i++) {
            sequencia += 10;
            if(i < 3) {
                printf("%i - ", sequencia);
            } else {
                printf("%i", sequencia);
            }

        }
        printf("\n");
    }
    return 0;
}
