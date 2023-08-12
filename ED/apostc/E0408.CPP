/* *******************************************************************
			Programa: e0408.cpp
		 Proposito: Uso das funcoes clrscr(), clreol(), gotoxy(), window()
								e kbhit()
Ultima Revisao: 11/08/97
******************************************************************* */
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
void main(){
	int esq,sup,dir,inf;                                  // bordas
	char* tit = "Teste de video: Blocos coloridos";       // titulo
	char* rpe = "Pressione alguma tecla para terminar";   // rodape

	clrscr();                        // limpa tela
	textbackground(BLUE);            // seleciona cor de fundo de linha
	textcolor(WHITE);                // cor de letra

	gotoxy(1,1);                     // posiciona cursor no canto esquerdo
	clreol();                        // desenha fundo de linha
	gotoxy(40 - strlen(tit)/2, 1);   // posiciona cursor
	cprintf("%s",tit);               // escreve titulo centralizado

	gotoxy(1,25);                    // posiciona cursor no canto esquerdo
	clreol();                        // desenha fundo de linha
	gotoxy(40 - strlen(rpe)/2, 25);  // posiciona cursor
	cprintf("%s",rpe);               // escreve rodape centralizado

	do{
		delay(100);                    // pausa pra nao ficar muito ligeiro
		esq = 1 + random(80);          // esq <- [1  , 80]
		dir = esq + random(81-esq);    // dir <- [esq, 80]
		sup = 2 + random(23);          // sup <- [  2, 24]
		inf = sup + random(25-sup);    // inf <- [sup, 24]
		window(esq,sup,dir,inf);       // define janela
		textbackground(random(8));     // seleciona cor de fundo aleatoria
		clrscr();                      // preenche janela com cor
	}while(!kbhit());

	window(1,1,80,25);               // restaura janela
	textbackground(BLACK);           // restaura cor de fundo
	clrscr();                        // limpa tela
}