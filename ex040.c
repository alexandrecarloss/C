#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
int vetor[10], i = 0, opc = 0;

int geraaleatorio();
int geraaleatorio() {
    int i;
    /* srand(time(NULL)) objetiva inicializar o gerador de n�meros aleat�rios
    com o valor da fun��o time(NULL). Este por sua vez, � calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    at� a data atual.
    Desta forma, a cada execu��o o valor da "semente" ser� diferente.
    */
    srand(time(NULL));
    return(rand() % 100);
}

void menuopc() {
    printf("Como voc� deseja preencher a posi��o %i?\n", i);
    printf("Com um n�mero escolhido [1]\n");
    printf("Ou com um n�mero aleat�rio [2]\n");
    scanf("%i", &opc);
}

void inserir() {
    printf("Insira um n�mero: ");
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
                printf("Op��o %i inv�lida! Completo por aleat�rio.", opc);
                getch();
                aleatorio(i);
                break;


        }
    system("cls");
    }

    for(i = 0; i <= 9; i++) {
        printf("Vetor na posi��o %i = %d\n", i, vetor[i]);
    }


    return 0;
}
