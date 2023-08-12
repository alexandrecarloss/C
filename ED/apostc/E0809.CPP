/****************************************************************************
			Programa: e0809.cpp
		 Proposito: Mostrar a alocacao dinamica de memoria.
Ultima Revisao: 14/11/97
****************************************************************************/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <alloc.h>  // biblioteca das funcoes de gerenciamento de memoria

// ********************
// 1 Programa principal
// ********************
void main(){
	int i;                    // contador
	int n;                    // tamanho do vetor
	float *val;               // declaracao de ponteiro
	float media(float[],int); // declaracao de funcao

	// **********************
	// 1.1 Leitura de valores
	// **********************
	clrscr();
	puts("Calculo da Media de um Conjunto de Valores");
	do{
		puts("\nDigite o numero (n > 1) de valores: ");
		scanf("%d",&n);
	}while(n < 1);

	// ***********************
	// 1.2 Alocacao de memoria
	// ***********************
	val = (float *)malloc(n*sizeof(float)); // Alocacao Dinamica de Memoria!
	if(val == NULL){
		puts("Desculpe, NAO ha' memoria disponivel!");
		getch();
		exit(1);
	}

	// *****************************************
	// 1.3 Leitura de valores e calculo da media
	// *****************************************
	puts("\n Digite os valores:");
	for(i = 0; i <= n-1; i++){
		printf("\n%d§ valor: ",i+1);
		scanf("%f",&val[i]);          // leitura dos elementos do vetor
	}
	printf("\nMedia: %.2f",media(val,n));  // impressao do resultado

	// ********************************************
	// 1.4 Liberacao de memoria e saida do programa
	// ********************************************
	free(val);  // liberacao do espaco de memoria
	puts("\n\nPressione qualquer tecla para continuar...");
	getch();
}

// ****************
// 2 Rotina media()
// ****************
float media(float vet[],int q){   // declaracao da funcao
	int i;
	float	soma = 0.0;
	for(i = 0; i <= q-1; i++){
		soma += vet[i];   // adiciona elemento do vetor
	}
	return(soma/q);
}

