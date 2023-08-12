/* *******************************************************************
			Programa: e0405.cpp
		 Proposito: Uso da funcao getche()
Ultima Revisao: 08/08/97
******************************************************************* */
#include <stdio.h>
#include <conio.h>
void main(){
	int n = 0;                                 // contador de letras
	char c;                                    // caracter digitado
	printf("\nDigite uma frase:\n");
	do{                                        // faz...
		c = getche();                            // leitura do caracter
		n++;                                     // incrementa contador
	}while (c != '\r');                        // ...enquanto nao for [enter]
	printf("\nVoce digitou %d caracteres!",n-1);
}

