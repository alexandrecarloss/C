#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Ler dois números inteiros e exibir se são iguais, o maior e o menor.*/

    //Definição de variáveis
    int num1, num2, soma;

    //Entrada de dados
    printf("Informe o primeiro número: ");
    scanf("%i", &num1);
    printf("Informe o segundo número: ");
    scanf("%i", &num2);

    if(num1 == num2) {
        printf("Os números são iguais: %i", num1);
    } else {
        if(num1 > num2) {
            printf("O 1°: %i é maior e o 2°: %i é menor", num1, num2);
        } else {
            printf("O 2°: %i é maior e o 1°: %i é menor", num2, num1);
        }
    }
    soma = num1 + num2;
    printf("\nA soma vale %i", soma);
    return 0;
}
