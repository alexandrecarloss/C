#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    printf("Digite uma opção: ");
    scanf("%i", &opcao);
    switch(opcao) {
        case 1:
            printf("Você digitou a opção 1\n");
            break;
        case 2:
            printf("Você digitou a opção 2\n");
            break;
        default:
            printf("Nenhuma das opções");
    }
    return 0;
}
