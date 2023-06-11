#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
        /*Objetivo:
    N�o realizar a leitura de notas pelo teclado
    fa�a um algoritmo que analize de 1 ate 500
    notas que est�o respectivamente a essa ordem
    ao final exibir quantos est�o aprovados (nota >= 6)
    e a m�dia das notas*/

    //Defini��o de vari�veis
    float media;
    int i, n = 1, nota, soma, rep=0, apr=0;

    //La�o de 1 at� 500
    for(i = 1; i <= 500; i++) {
        printf("x = %i\n", i);
        //Nota recebe o valor de uma vari�vel auxiliar n
        nota = n;
        printf("nota = %i\n", nota);
        //Soma das notas recebe o pr�prio valor mais a nota atual
        soma+= nota;
        //Vari�vel auxiliar n soma mais 1 para acompanhar o la�o
        n++;
        //Verifica��o dos aprovados e reprovados
        if(nota >= 6) {
            apr++;
        } else{
            rep++;
        }
        //Reinicializa��o da contagem da vari�vel auxiliar toda vez que passar de 10
        if(n > 10) {
            n = 1;
        }
    }
    //C�lculo da m�dia
    media = soma / 500;
    printf("A quantidade de aprovados �: %i, reprovados: %i", apr, rep);
    printf("\nA m�dia �: %.2f", media);

    return(0);
}
