#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    printf("Digite uma op��o: ");
    scanf("%i", &opcao);
    switch(opcao) {
        case 1:
            printf("Voc� digitou a op��o 1\n");
            break;
        case 2:
            printf("Voc� digitou a op��o 2\n");
            break;
        default:
            printf("Nenhuma das op��es");
    }
    return 0;
}
