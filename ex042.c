#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void geravetor(int i, int num, int *vetor);
void exibevetor(int i, int *vetor);

int main() {
    int i, num, vetor[500];
    setlocale(LC_ALL, "Portuguese");
    geravetor(i, num, vetor);
    exibevetor(i, vetor);
    return 0;
}

void geravetor(int i, int num, int *vetor) {
    for(i = 0; i <= 500; i++) {
        num = 0;
        while(num < 800) {
            printf("Informe um n�mero inteiro maior que 800: ");
            scanf("%i", &num);

            if(num < 800) {
                printf("N�mero inv�lido! ");
            } else {
                vetor[i] = num;
                printf("Valor %i adicionado � posi��o %i ", vetor[i], i);
                getch();
            }

        }
        system("cls");
    }
}

void exibevetor(int i, int *vetor) {
for(i = 0; i <= 500; i++) {
    printf("%i = %i\n", i, vetor[i]);
}
}
