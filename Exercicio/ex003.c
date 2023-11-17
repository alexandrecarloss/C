#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    float num1, num2, soma, subtrai;
    printf("Informe qual operação quer realizar 1 para soma ou 2 para subtração: ");
    scanf("%i", &escolha);

    if (escolha == 1) {
        printf("Soma\n");
        printf("Informe o número real 1: ");
        scanf("%f", &num1);
        printf("Informe o número real 2: ");
        scanf("%f", &num2);
        soma = num1 + num2;
        printf("A soma de %.2f + %.2f é %.2f", num1, num2, soma);
    }
    if (escolha == 2) {
        printf("Subtração\n");
        printf("Informe o número real 1: ");
        scanf("%f", &num1);
        printf("Informe o número real 2: ");
        scanf("%f", &num2);
        subtrai = num1 - num2;
        printf("A subtração de %.2f - %.2f é %.2f", num1, num2, subtrai);
    }

    if ((escolha != 1) & (escolha != 2)) {
            printf("Escolha Incorreta");
    }

    return(0);
}
