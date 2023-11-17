#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: ler um número >= 10 e número <= 1000 e exibir a soma acumulativa dos termos na sua ordem crescente
    //Definição de variáveis
    int num, anterior = 0, i, atual = 0;

    //Entrada de dados
    printf("Informe o tamanho da sequencia de números da soma acumulativa (deve ser entre 10 e 31): ");
    scanf("%i", &num);

    //Verificação
    if ((num >= 10) && (num <= 32)) {
            //Laço de 1 até o número
        for(i = 1; i <= num; i++) {
            //Variável atual recebe o valor acumulado mais o valor da posição
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
            //Variável anterior acumula com o valor atual
            anterior += atual;
        }
    }
    return 0;
}
