/* *******************************************************************
			Programa: e0406.cpp
		 Proposito: Uso das funcoes cprintf(), textbackground() e
								textcolor()
Ultima Revisao: 08/08/97
******************************************************************* */
#include <conio.h>
void main(){
	int cl;	                   // cor de letra
	int cf;	                   // cor de fundo
	clrscr();                  // limpa tela
	cf = BLACK;                // cor de fundo preta
	do{                        // faz...
		textbackground(cf);      // ativa cor de fundo
		cl = BLACK;              // cor de letra preta
		do{                      // faz...
			textcolor(cl);         // ativa cor de texto
			cprintf(" Teste ");    // imprime teste de cor
		}while(++cl <= WHITE);   // enquanto nao e' ultima cor de letra
	}while(++cf <= LIGHTGRAY); // enquanto nao e' ultima cor de fundo

	cf = BLACK;
	do{
		textbackground(cf);
		cl = BLACK;
		do{
			textcolor(cl + BLINK); // ativa letra piscante
			cprintf(" Teste ");
		}while(++cl <= WHITE);
	}while(++cf <= LIGHTGRAY);

	textbackground(BLACK); // ativa fundo padrao
	textcolor(LIGHTGRAY);  // ativa letra padrao
}
