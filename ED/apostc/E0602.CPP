/****************************************************************************
Programa: e0602.cpp
Proposito: Funcao de usuario escrita depois de programa principal
Ultima Revisao: 29/09/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
void main(){                // programa principal
	float max(float,float);   // prototipo da funcao max()
	float num1, num2;
	clrscr();
	puts("*** Valor maximo de dois reais ***");
	puts("Digite dois numeros");
	scanf("%f %f",&num1,&num2);
	printf("O maior valor e': %f",max(num1,num2));  // chamada a funcao
	getch();
}

float max(float a, float b){  // funcao max()
	if(a > b){
		return(a);
	}else{
		return(b);
	}
}
