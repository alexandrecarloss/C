/****************************************************************************
Programa: e0603.cpp
Proposito: Programa principal. Funcao em arquivo separado
Ultima Revisao: 29/09/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#include "k:\curso_c\e0604.cpp"             // inclusao de funcao
void main(){                                // programa principal
	float num1, num2;
	clrscr();
  puts("*** Valor maximo de dois reais ***");
  puts("Digite dois numeros");
  scanf("%f %f",&num1,&num2);
  printf("O maior valor e': %f",max(num1,num2));  // chamada a funcao
  getch();
}
