#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Calcular e exibir o resultado de f(x) = 5x + 12, para "x" variando de 1 at� 200.000*/

    //Defini��o de vari�veis
    int x, i;

    printf("Calculando a fun��o f(x) = 5x + 12\n");
    for(i = 1; i <= 200000; i++) {
        x = 5 * i + 12;
        printf("f(%i) = %i\n", i, x);
    }
    return 0;
}
