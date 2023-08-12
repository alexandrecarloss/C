#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vetor[5], i;
    for(i = 0; i < 5; i++) {
        printf("\nDigite o valor do vetor da posição[%d] = ",i);
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < 5; i++) {
        printf("O valor do vetor da posição[%d] = %d\n",i, vetor[i]);
    }
    return 0;
}
