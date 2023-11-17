#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int num, maior = 0;

    while(num != -1) {
        printf("Informe um número positivo (-1 para parar): ");
        scanf("%i", &num);
        if(num > maior) {
            maior = num;
        }
    }
    printf("O maior número informado foi: %i", maior);



    return 0;
}
