#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
        /*Objetivo:
    Não realizar a leitura de notas pelo teclado
    faça um algoritmo que analize de 1 ate 500
    notas que estão respectivamente a essa ordem
    ao final exibir quantos estão aprovados (nota >= 6)
    e a média das notas*/

    //Definição de variáveis
    float media;
    int i, n = 1, nota, soma, rep=0, apr=0;

    //Laço de 1 até 500
    for(i = 1; i <= 500; i++) {
        printf("x = %i\n", i);
        //Nota recebe o valor de uma variável auxiliar n
        nota = n;
        printf("nota = %i\n", nota);
        //Soma das notas recebe o próprio valor mais a nota atual
        soma+= nota;
        //Variável auxiliar n soma mais 1 para acompanhar o laço
        n++;
        //Verificação dos aprovados e reprovados
        if(nota >= 6) {
            apr++;
        } else{
            rep++;
        }
        //Reinicialização da contagem da variável auxiliar toda vez que passar de 10
        if(n > 10) {
            n = 1;
        }
    }
    //Cálculo da média
    media = soma / 500;
    printf("A quantidade de aprovados é: %i, reprovados: %i", apr, rep);
    printf("\nA média é: %.2f", media);

    return(0);
}
