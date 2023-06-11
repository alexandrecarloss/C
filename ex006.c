#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
/*
Objetivo: escrever uma quantidade x informada pelo usuário de números 1 com linhas de no máximo 10 1s e ao total no máximo 100 1s
*/
//Declaração de variáveis
    int i, num;

    //Entrada de dados
    printf("Quantos números 1s você quer exibir? (máximo 100) ");
    scanf("%i", &num);
    //Condição de limite
    if (num > 100) {
        printf("Valor excedeu o limite! Informe um valor até 100\n");
        printf("Quantos números 1s você quer exibir? (máximo 100)\n");
        scanf("%i", &num);
    } else {
        //Laço for que imprime o número de vezes que o usuário informou
        for(i = 1; i <= num; i++) {
            printf("1 ");
            //Condição if para quebrar linha a cada 10
            if(i % 10 == 0) {
                printf("\n");
            }
        }
    }
    return 0;
}
