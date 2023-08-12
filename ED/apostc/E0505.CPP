/* *******************************************************************
			Programa: e0505.cpp
		 Proposito: Uso da estrutura if...else
Ultima Revisao: 26/08/97
******************************************************************* */
#include <stdio.h>
void main(){
	float a,b,c;                             // parametros de ax^2+bx+c=0
	float delta;                             // descriminante: b^2-4ac
	puts("\nBaskara");
	puts("Digite valores para a, b, c: ");
	scanf("%f %f %f",&a,&b,&c);              // leitura dos parametros
	delta = b * b - 4. * a * c;              // calculo do discriminante
	printf("Descriminante: %f", delta);
	if(delta >= 0.0){                        // se delta e' positivo...
		puts("  Raizes Reais");                // raizes reais
	}else{                                   // ...senao...
		puts("  Raizes Complexas");            // raizes complexas
	}
}