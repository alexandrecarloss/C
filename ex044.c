#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void preencher_vet(int posicao, int *vetor, int valor);
void exibir_vet(int *vetor);
int receber_pos(int posicao);
int receber_val(int valor);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int tamanho = 25, vetor[25], posicao, valor;

    posicao = receber_pos(posicao);
    valor = receber_val(valor);

    vetor[posicao] = valor;


    preencher_vet(posicao, vetor, valor);
    exibir_vet(vetor);

    return 0;
}

int receber_pos(int posicao) {
    printf("Informe uma posição entre 0 e 24: ");
    scanf("%i", &posicao);
    return posicao;
}

int receber_val(int valor) {
    printf("Informe um valor inteiro para essa posição: ");
    scanf("%i", &valor);
    return valor;
}
void preencher_vet(int pos, int *vetor, int valor) {
    int i = 0, num = valor;
    for(i = pos; i >= 0; i--) {
        vetor[i] = num;
        num--;
    }
    num = valor;
    i = 0;
    for(i = pos; i < 25; i++) {
        vetor[i] = num;
        num++;
    }
}

void exibir_vet(int *vetor) {
    int i;
    for(i = 0; i < 25; i++) {
        printf("%i = %i\n", i, vetor[i]);
    }
}
