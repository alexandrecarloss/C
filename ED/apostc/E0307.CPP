/* *******************************************************************
			Programa: e0307.cpp
		 Proposito: Funcoes de Biblioteca
Ultima Revisao: 23/07/97
******************************************************************* */

//	Exercicio: O programa abaixo foi escrito usando varias funcoes
//	disponiveis do C. Procure, na ajuda on-line, informacoes sobre as
//	funcoes usadas...

#include <conio.h>   // inclusao das bibliotecas
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>
void main(){
	char* titulo = "* * *   P r o g r a m a   E x e m p l o   * * *";
	char tecla;    // tecla pressionada pelo usuario
	int tam;       // tamanho do titulo
	int col;       // coluna inicial de impressao do titulo
	int cont;      // flag de continuacao do laco
	float num;     // numero aleatorio
	float val;     // valor calculado

	do{       // inicia laco repetitivo...

		// *********************
		// 1 Titulo Centralizado
		// *********************
		clrscr();                  // limpa a tela
		tam = strlen(titulo);      // calcula o tamanho do titulo.
		col = 40 - tam / 2;        // calcula a coluna de inicio
		gotoxy(col,1);             // posiciona o cursor
		printf(titulo);            // imprime o titulo

		// ******************
		// 2 Numero aleatorio
		// ******************
		randomize();                               // inicia gerador aleatorio
		num = (float)random(1000) / 100.0;         // gera numero
		printf("\n\n Numero: %f",num);             // imprime escolha
		getch();                                   // pausa

		// ********************
		// 3 Faz algumas contas
		// ********************
		val = sin(num);                          // seno
		printf("\n sin( %f ) = %f",num,val);     // imprime
		getch();                                 // pausa

		val = ceil(num);                         // arredonda para cima
		printf("\n ceil( %f ) = %f",num,val);    // imprime
		getch();                                 // pausa

		val = floor(num);                        // arredonda para baixo
		printf("\n floor( %f ) = %f",num,val);   // imprime
		getch();                                 // pausa

		val = log(num);                          // logaritmo natural
		printf("\n ln( %f ) = %f",num,val);        // imprime
		getch();																 // pausa

		val = sqrt(num);                         // raiz quadrada
		printf("\n sqrt( %f ) = %f",num,val);    // imprime
		getch();                                 // pausa

		// ***********
		// 4 Continua?
		// ***********
		printf("\n Continua ? ");       // imprime mensagem
		tecla = getch();                // recebe caracter do teclado
		tecla = toupper(tecla);         // transforma em maiusculo
		cont = (tecla == 'S') ? 1 : 0;  // se for 'S' continua

	}while(cont);   // ... fim do laco de repeticao

	// *******
	// 5 Saida
	// *******
	clrscr();                       // limpa tela
	sound(440);                     // emite um som de 300 Hz...
	delay(100);                     // ... por 100 ms...
	nosound();                      // ... e para.
	printf("\n Volte Sempre!");     // mensagem

}                                 // fim do programa