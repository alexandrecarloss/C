/* *******************************************************************
			Programa: e0403.cpp
		 Proposito: Uso das funcoes ao getchar() e putchar()
Ultima Revisao: 08/08/97
******************************************************************* */
#include <stdio.h>
void main(){
	char c;                          // declara caracter
	printf("\nDigite uma frase:\n");
	do{                              // faz...
		c = getchar();                 // leitura do 'buffer'
		if(c >= 97 && c <= 122){       // se c e' minusculo...
			c -= 32;                     // ...transforma em maiusculo
		}
		putchar(c);                    // impressao dos caracteres maiusculos
	}while (c != '\n');              // ...enquanto nao e' [enter]
}


