#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
int vetor[10], i = 0, opc = 0;

int geraaleatorio();
int geraaleatorio() {
    int i;
    /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
    */
    srand(time(NULL));
    return(rand() % 100);
}

void menuopc() {
    printf("Como você deseja preencher a posição %i?\n", i);
    printf("Com um número escolhido [1]\n");
    printf("Ou com um número aleatório [2]\n");
    scanf("%i", &opc);
}

void inserir() {
    printf("Insira um número: ");
    scanf("%i", &vetor[i]);
}

void aleatorio(int i) {
    vetor[i] = geraaleatorio();
}


int main() {
    setlocale(LC_ALL, "Portuguese");


    for(i; i <= 9; i++){
        menuopc();
        switch (opc) {
            case 1:
                inserir();
                break;
            case 2:
               aleatorio(i);
               break;
            default:
                printf("Opção %i inválida! Completo por aleatório.", opc);
                getch();
                aleatorio(i);
                break;


        }
    system("cls");
    }

    for(i = 0; i <= 9; i++) {
        printf("Vetor na posição %i = %d\n", i, vetor[i]);
    }


    return 0;
}
