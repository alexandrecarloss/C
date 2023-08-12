/* *******************************************************************
			Programa: e0504.cpp
		 Proposito: Uso da estrutura if...
Ultima Revisao: 26/08/97
******************************************************************* */
#include <dos.h>             // inclusao de bibliotecas
#include <conio.h>
#include <stdio.h>
void main(){
	int i;                     // contador
	clrscr();
	puts("Jogo do Pim!");
	for(i = 1; i <= 20; i++){  // para i de 1 a 20...
		printf("\n%2d...",i);    // imprime numero
		if(i%4 == 0){            // se multiplo de 4...
			sound(600);            // ³  Pim!
			delay(50);             // ³
			nosound();             // ³
		}                        // fim se
		delay(500);              // espera
	}
  puts("Oba! Ganhei o premio!");
}