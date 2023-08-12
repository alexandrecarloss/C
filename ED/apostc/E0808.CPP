/****************************************************************************
			Programa: e0808.cpp
		 Proposito: Mostrar a manipulacao de strings.
Ultima Revisao: 14/11/97
****************************************************************************/
#include <stdio.h>
#include <string.h>   // biblioteca para manipulacao de strings
#include <conio.h>
void main(){

	// ***************
	// 1 Inicializacao
	// ***************
	char nome[80];              // vetor
	char *frase = "Ola', ";     // ponteiro
	int i;

	// *****************
	// 2 Leitura do nome
	// *****************
	clrscr();
	puts("Manipulacao de strings");
	puts("Digite seu nome:");
	i = 0;
	do{
		nome[i] = getche();         // leitura da tecla
		if(nome[i] == '\r'){        // se pressionou [enter]...
			nome[i] = '\0';           // troca por \0
		}
	}while(nome[i++] != '\0');

	// ************************
	// 3 Impressao centralizada
	// ************************
	strcat(frase,nome);            // concatena (justapoe) duas strings
	gotoxy(40-strlen(frase)/2,12); // imprime centralizado
//          À> funcao da biblioteca string.h: calcula comprimento da string
	printf("%s",frase);
	getch();
}