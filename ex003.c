#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    float num1, num2, soma, subtrai;
    printf("Informe qual opera��o quer realizar 1 para soma ou 2 para subtra��o: ");
    scanf("%i", &escolha);

    if (escolha == 1) {
        printf("Soma\n");
        printf("Informe o n�mero real 1: ");
        scanf("%f", &num1);
        printf("Informe o n�mero real 2: ");
        scanf("%f", &num2);
        soma = num1 + num2;
        printf("A soma de %.2f + %.2f � %.2f", num1, num2, soma);
    }
    if (escolha == 2) {
        printf("Subtra��o\n");
        printf("Informe o n�mero real 1: ");
        scanf("%f", &num1);
        printf("Informe o n�mero real 2: ");
        scanf("%f", &num2);
        subtrai = num1 - num2;
        printf("A subtra��o de %.2f - %.2f � %.2f", num1, num2, subtrai);
    }

    if ((escolha != 1) & (escolha != 2)) {
            printf("Escolha Incorreta");
    }

    return(0);
}
