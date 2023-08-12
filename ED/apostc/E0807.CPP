/****************************************************************************
			Programa: e0807.cpp
		 Proposito: Mostrar equivalencia entre ponteiros e vetores.
Ultima Revisao: 14/11/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
void main(){
	float vet[5] = {1.1,2.2,3.3,4.4,5.5}; // declarando uma vetor real
	int i;   // declarando um contador (DEVE ser inteiro!)
	clrscr();

	// *****************************
	// 1. Impressao de uma tabelinha
	// *****************************
	printf("cont.   valor          valor              endereco        endereco");
	for(i = 0 ; i <= 4 ; i++){
		printf("\ni = %d"             ,i);            // contador
		printf("   vet[%d] = %.1f"    ,i, vet[i]   ); // valor (com vetor)
		printf("   *(vet + %d) = %.1f",i, *(vet+i) ); // valor (com ponteiro)
		printf("   &vet[%d] = %X"     ,i, &vet[i]  ); // endereco (com vetor)
		printf("   (vet + %d) = %X"   ,i, vet+i    ); // endereco (com ponteiro)
	}
	puts("\n\nObserve que os ENDERECOS sao ESPACADOS de 4 em 4 bytes...");

	puts("\n\nPressione alguma tecla para continuar...");
	getch();
}
