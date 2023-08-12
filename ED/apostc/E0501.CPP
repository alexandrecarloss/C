/* *******************************************************************
			Programa: e0501.cpp
		 Proposito: Uso da estrutura do...while
Ultima Revisao: 18/08/97
******************************************************************* */
#include <stdio.h>
void main(){
	unsigned int i,n,fat;
	do{                               // leitura do numero
		puts("\nDigite um inteiro entre 0 e 10: ");
		scanf("%u",&n);
	}while(n < 0 || n > 10);          // repete a leitura se n < 0 e n > 10
	fat = 1;
	i = 1;                            // contador de iteracoes
	do{                               // calculo do fatorial
		fat *= i;                       // fat = fat * i
	}while(i++ <= n);                 // repete multiplicacao se i < n
	printf("\n %u! = %u",n,fat);
}
