#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: ler um n�mero >= 10 e n�mero <= 1000 e exibir a soma acumulativa dos termos na sua ordem crescente
    //Defini��o de vari�veis
    int num, anterior = 0, i, atual = 0;

    //Entrada de dados
    printf("Informe o tamanho da sequencia de n�meros da soma acumulativa (deve ser entre 10 e 31): ");
    scanf("%i", &num);

    //Verifica��o
    if ((num >= 10) && (num <= 32)) {
            //La�o de 1 at� o n�mero
        for(i = 1; i <= num; i++) {
            //Vari�vel atual recebe o valor acumulado mais o valor da posi��o
            atual = anterior + i;
            //Imprime o valor atual
            if (i < num) {
               printf("%i, ", atual);
            } else {
                printf("%i.", atual);
            }
            if(i % 1 == 0) {
                printf("\n");
            }
            //Vari�vel anterior acumula com o valor atual
            anterior += atual;
        }
    }
    return 0;
}
