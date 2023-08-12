#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void preencher_vet(int tamanho_vet, int *vetor);
void exibir_vet(int tamanho_vet, int *vetor);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int tamanho = 50;

    int vetor[tamanho];
    preencher_vet(tamanho, vetor);
    exibir_vet(tamanho, vetor);

    return 0;
}

void preencher_vet(int tamanho_vet, int *vetor) {
    int i;
    for(i = 0; i < tamanho_vet; i++) {
        vetor[i] = rand();
    }
}

void exibir_vet(int tamanho_vet, int *vetor) {
    int i;
    for(i = 0; i < tamanho_vet; i++) {
        printf("%i = %i\n", i + 1, vetor[i]);
    }
}
