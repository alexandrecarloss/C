#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Ler dois n�meros inteiros e exibir se s�o iguais, o maior e o menor.*/

    //Defini��o de vari�veis
    int num1, num2, soma;

    //Entrada de dados
    printf("Informe o primeiro n�mero: ");
    scanf("%i", &num1);
    printf("Informe o segundo n�mero: ");
    scanf("%i", &num2);

    if(num1 == num2) {
        printf("Os n�meros s�o iguais: %i", num1);
    } else {
        if(num1 > num2) {
            printf("O 1�: %i � maior e o 2�: %i � menor", num1, num2);
        } else {
            printf("O 2�: %i � maior e o 1�: %i � menor", num2, num1);
        }
    }
    soma = num1 + num2;
    printf("\nA soma vale %i", soma);
    return 0;
}
