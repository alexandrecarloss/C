/****************************************************************************
Programa: e0601.cpp
Proposito: Funcao de usuario escrita antes de programa principal
Ultima Revisao: 29/09/97
*****************************************************************************/
#include <conio.h>
#include <stdio.h>
float max(float a, float b){         // funcao max()
	if(a > b){
		return(a);
	}else{
		return(b);
	}
}

void main(){                         // programa principal
	float num1,num2,m;
	clrscr();
	puts("*** Valor maximo de dois reais ***");
	puts("Digite dois numeros:");
	scanf("%f %f",&num1,&num2);
	m = max(num1,num2);                // chamada da funcao
	printf("O maior valor e': %f",m);
	getch();
}