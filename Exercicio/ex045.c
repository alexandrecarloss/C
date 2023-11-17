#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAX 5

int vetor[MAX];
void preencherVetor();
void exibirVetor();
void palindromo();

void preencherVetor() {
    int i;
    for(i = 0; i < MAX; i ++){
        //vetor[i] = rand() % 5;
        scanf("%i", &vetor[i]);
        //vetor[i] = 1;
    }
}

void exibirVetor() {
    int i;
    for(i = 0; i < MAX; i ++){
        printf("%d - O valor da posição[%d] = %d\n", i  + 1, i, vetor[i]);
    }
}

void palindromo() {
    int i, cont = 1, palindromo = 0;
    for(i = 0; i < MAX/2; i++) {
        if (vetor[i] != vetor[(MAX) - cont]) {
                palindromo = 1;
            }
        cont++;
    }
    if (palindromo == 0) {
        printf("\nPalindromo\n");
    } else {
        printf("\nNão é Palíndromo\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    //int qtd=500, valorInicial=601;
    preencherVetor();
    exibirVetor();
    palindromo();
    getchar();
    return 0;
}
