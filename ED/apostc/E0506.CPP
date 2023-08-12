/* *******************************************************************
			Programa: e0506.cpp
		 Proposito: Uso da estrutura if...else if
Ultima Revisao: 26/08/97
******************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(){
	int palpite;                  // palpite do usuario
  int numero;                   // numero do computador
  randomize();                  // inicializador do geredor aleatorio
  numero = random(10);          // escolhe numero aleatorio
	puts("\nEscolhi um numero. Adivinha qual e'?\n");
  scanf("%d",&palpite);         // leitura do palpite
	if(palpite > numero){         // se chute alto...
		puts("Chute alto!");        // mensagem
	}else if(palpite < numero){   // ...senao se chute baixo...
		puts("Chute baixo!");       // mensagem
	}else{                        // senao acertou
		puts("Acertou!");           // mensagem
	}
}
