/* *******************************************************************
			Programa: e0407.cpp
		 Proposito: Uso das funcoes sound(), delay() e nosound()
Ultima Revisao: 11/08/97
******************************************************************* */
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#define T 250
void main(){
	clrscr();
	textbackground(BLUE);
	textcolor(WHITE + BLINK);
	cprintf("Hino do Grˆmio");

	printf("\nAt‚ a p‚ nos iremos,...");
	sound(660);delay(2*T);
	sound(550);delay(T);
	sound(495);delay(T);
	sound(440);delay(2*T);
	sound(495);delay(T);
	sound(550);delay(T);
	sound(495);delay(2*T);
	sound(330);delay(6*T);

	printf("\b\b\b para o que der e vier.");
	sound(660);delay(2*T);
	sound(550);delay(T);
	sound(495);delay(T);
	sound(440);delay(2*T);
	sound(495);delay(T);
	sound(550);delay(T);
	sound(495);delay(6*T);

	printf("\nMas o certo, ‚ que n¢s estaremos...");
	sound(550);delay(T);
	sound(594);delay(T);
	sound(660);delay(2*T);
	sound(634);delay(T);
	sound(660);delay(T);
	sound(704);delay(2*T);
	sound(660);delay(T);
	sound(704);delay(T);
	sound(844);delay(2*T);
	sound(734);delay(4*T);

	printf("\b\b\b com o Grˆmio, onde o Grˆmio estiver!");
	sound(550);delay(T);
	sound(594);delay(T);
	sound(660);delay(2*T);
	sound(734);delay(T);
	sound(660);delay(T);
	sound(495);delay(2*T);
	sound(594);delay(T);
	sound(550);delay(T);
	sound(440);delay(4*T);
	nosound();
}

