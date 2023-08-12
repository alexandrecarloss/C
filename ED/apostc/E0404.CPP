/* *******************************************************************
			Programa: e0404.cpp
		 Proposito: Uso da funcao getch()
Ultima Revisao: 08/08/97
******************************************************************* */
#include <conio.h>
#include <stdio.h>
void main(){
	int c,d;   // codigos
	printf("\n Pressione uma tecla ou combinacao de teclas:");
	printf("\n Pressione [esc] para terminar! ");
	do{                                           // faz...
		c = getch();                                // leitura do primeiro codigo.
		if(c == 0){                                 // se for codigo extendido...
			d = getch();                              // le segundo codigo.
			printf("\n %3d %3d codigo extendido",c,d);// imprime codigo extendido
		}else{
			printf("\n %3d     codigo normal",c);     // imprime codigo normal
		};
	}while (c != 27);                             // ...enquanto nao for [esc]
}
