#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Calcular e exibir o resultado de f(x) = 5x + 12, para "x" variando de 1 até 200.000*/

    //Definição de variáveis
    int x, i;

    printf("Calculando a função f(x) = 5x + 12\n");
    for(i = 1; i <= 200000; i++) {
        x = 5 * i + 12;
        printf("f(%i) = %i\n", i, x);
    }
    return 0;
}
