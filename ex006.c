#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
/*
Objetivo: escrever uma quantidade x informada pelo usu�rio de n�meros 1 com linhas de no m�ximo 10 1s e ao total no m�ximo 100 1s
*/
//Declara��o de vari�veis
    int i, num;

    //Entrada de dados
    printf("Quantos n�meros 1s voc� quer exibir? (m�ximo 100) ");
    scanf("%i", &num);
    //Condi��o de limite
    if (num > 100) {
        printf("Valor excedeu o limite! Informe um valor at� 100\n");
        printf("Quantos n�meros 1s voc� quer exibir? (m�ximo 100)\n");
        scanf("%i", &num);
    } else {
        //La�o for que imprime o n�mero de vezes que o usu�rio informou
        for(i = 1; i <= num; i++) {
            printf("1 ");
            //Condi��o if para quebrar linha a cada 10
            if(i % 10 == 0) {
                printf("\n");
            }
        }
    }
    return 0;
}
