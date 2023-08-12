/****************************************************************************
			Programa: e0703.cpp
		 Proposito: Mostra declaracao de vetor com tamanho parametrizado
Ultima Revisao: 17/10/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5         // definicao do parametro MAX
											 // Experimente alterar este valor!
void main(){
	int i=3;
	int valor[MAX];   // declaracao do vetor usando MAX

	randomize();
	clrscr();
	printf("Calculo de %d numeros aleatorios:",MAX);
	for(i = 0; i <= MAX-1; i++){         // somente MAX valores sao calculados
		valor[i] = 1+random(100);
		printf("\n%3d:  %d",i+1,valor[i]); // o valor e' impresso
	}
	getch();
}
