/****************************************************************************
			Programa: e0803.cpp
		 Proposito: Operacoes com ponteiros
Ultima Revisao: 10/11/97
****************************************************************************/
#include <stdio.h>
#include <conio.h>
void main(){
	char *pi,*pf,*p;  // declaracao de ponteiro

	// *******************
	// 1 Selecao de janela
	// *******************
	clrscr();
	textcolor(YELLOW);
	gotoxy(1,1);
	cprintf("Descarregando o conteudo da memoria: (Segmento de Dados)");
	gotoxy(1,25);
	cprintf("Pressione BARRA DE ESPACO para pausa...");
	window(1,2,80,24);
	textcolor(LIGHTGRAY);

	// ***********************************
	// 2 Descarregando conteudo da memoria
	// ***********************************
	pi = (char*)0x0000; // primeiro endereco da memoria (atribuicao direta)
	pf = (char*)0xFFFF; // ultimo endereco
	p = pi;             // inicializa ponteiro (atribuicao de ponteiro)
	do{
		++p;                 // incrementa contador (incremento de ponteiro)
		if( *p != '\a'){     // nao imprime sinal sonoro...
			cprintf("%c", *p); // imprime caracter do bloco de memoria
		}
		if(kbhit()){   // se tecla pressionada...
			getch();     // limpa buffer
			getch();     // espera para seguir
		}
	}while(p < pf);  // ...ate' ultimo endereco (comparacao de ponteiros)

	// ************************************
	// 3 Termina e restaura cores originais
	// ************************************
	window(1,1,80,25);
	gotoxy(1,25);
	clreol();
	textcolor(CYAN);
	cprintf("\aOk!");
	getch();
	textcolor(LIGHTGRAY);
	clrscr();
}
