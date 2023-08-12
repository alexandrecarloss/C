/****************************************************************************
			Programa: e0701.cpp
		 Proposito: Manipula vetores
Ultima Revisao: 20/10/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
void main(){
	int total[5] = {0,0,0,0,0};    // inicializacao por lista
	char letra[80];                // declaracao de vetor
	char vogal[5];                 // declaracao de vetor
	vogal[0]='a';                  // inicializacao por elemento
	vogal[1]='e';
	vogal[2]='i';
	vogal[3]='o';
	vogal[4]='u';
	int i,j;             // contadores

	clrscr();
	puts("Digite uma frase de teste:");

	i=0;
	do{                             // faz a leitura das teclas...
		letra[i] = tolower(getche()); // i-esimo elemento de 'letra' recebe tecla
		for(j=0; j<=4; j++){          // para todas as vogais...
			if(letra[i] == vogal[j]){   // se tecla digitada e' vogal...
				total[j]++;               // incrementa i-esimo contador
			}
		}
	}while(letra[i++] != '\r');     // ... enquanto nao for [enter]

	puts("\nTotal de vogais digitadas:");
	for(i=0; i<=4; i++){                     // para todas as vogais...
		printf("%c: %d \n",vogal[i],total[i]); // imprime totais
	}

	getch();        // pausa
}
