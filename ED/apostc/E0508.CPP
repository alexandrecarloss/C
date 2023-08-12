/* *******************************************************************
			Programa: e0508.cpp
		 Proposito: Uso da estrutura switch com break
Ultima Revisao: 27/08/97
******************************************************************* */
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#define DO  264   // definicao de escala musical
#define RE  297
#define MI  330
#define FA  352
#define SOL 396
#define LA  440
#define SI  495
void main(){
	int tecla;
  clrscr();
	puts("Digite teclas [z] [x] [c] [v] [b] [n] [m] para notas");
	puts("ou [esc] para sair");
	do{
    tecla = getch();   // leitura do teclado
		switch(tecla){     // conforme o valor de tecla...
		case 'z':          // se tecla = 'z'
			sound(DO);       // nota do
			break;           // cai fora do switch...
		case 'x':
			sound(RE);
			break;
		case 'c':
			sound(MI);
			break;
		case 'v':
			sound(FA);
			break;
	  case 'b':
			sound(SOL);
			break;
		case 'n':
			sound(LA);
			break;
		case 'm':
			sound(SI);
			break;
		}
		delay(200);        // toca por 200 ms
		nosound();         // desliga auto-falante
	}while(tecla != 27); // repete enquanto tecla != [esc]
}


