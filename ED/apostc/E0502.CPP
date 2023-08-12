/* *******************************************************************
			Programa: e0502.cpp
		 Proposito: Uso da estrutura while
Ultima Revisao: 22/08/97
******************************************************************* */
#include <stdio.h>   // inclusao de bibliotecas
#include <math.h>
#define TOL 1.0e-14 // tolerancia
void main(){            // calculo da raiz quadrada pelo metodo de Newton
	double num;           // numero do qual se quer saber a raiz quadrada
	double raiz,raiz_ant; // estimativas da raiz
	puts("\nDigite um numero positivo: ");
	scanf("%lf",&num);
	raiz_ant = 0.0;                          // estimativas
	raiz = num;
	while(fabs(raiz - raiz_ant) > TOL){          // enquanto pouca precisao...
		raiz_ant = raiz;                       // salva estimativa anterior
		raiz = 0.5*(raiz_ant + num/raiz_ant);  // nova estimativa
	}
	printf("\nsqrt(%.1f) = %.14f",num,raiz); // imprime valores
}



