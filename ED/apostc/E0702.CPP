/****************************************************************************
			Programa: e0702.cpp
		 Proposito: Mostra acesso de elementos dentro e fora de um vetor
Ultima Revisao: 17/10/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
void main(){
	int i;
	int val[5];   // declaracao do vetor 'val' de 5 elementos

	// ********************
	// 1 Leitura de valores
	// ********************
	clrscr();
	puts("Digite alguns numeros inteiros:");
	for(i = 0; i <= 4; i++){       // somente 5 valores sao lidos
		printf("%d§ valor: ",i+1);   // chamada do valor
		scanf("%d",&val[i]);         // o valor e' lido
	}

	// **********************
	// 2 Impressao de valores
	// **********************
	clrscr();
	puts("Estes sao os valores lidos: ");
	for(i = 0; i <= 4 ; i++){            // acesso a elementos DENTRO do vetor!
		printf("val[%d]: %d\n",i,val[i]);  // impressao dos valores
	}

	puts("\n...Mas nada impede o acesso a estes valores: ");
	for(i = -5; i <= -1 ; i++){           // acesso a elementos FORA do vetor!
		printf("val[%d]: %d\n",i,val[i]);   // impressao dos valores
	}

	for(i = 5; i <= 10 ; i++){            // acesso a elementos FORA do vetor!
		printf("val[%d]: %d\n",i,val[i]);   // impressao dos valores
	}

	getch();
}
