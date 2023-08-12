/****************************************************************************
			Programa: e0810.cpp
		 Proposito: Mostrar o uso de ponteiro para funcao
Ultima Revisao: 14/11/97
****************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <math.h>

// ***********
// 1 Principal
// ***********
void main(){

	// ***************
	// 1.1 Declaracoes
	// ***************
	int round(float);  // prototipo da funcao
	float r;           // numero para ser arredondado
	int i;             // numero arredondado
	int (*p)(float);   // declaracao de ponteiro para funcao
	p = &round;        // ponteiro recebe o endereco da funcao

	// ********************
	// 1.2 Entrada de dados
	// ********************
	clrscr();
	puts("Arredondamento de numeros.");
	puts("\nDigite um numero real para ser arredondado: ");
	scanf("%f",&r);

	// ******************
	// 1.3 Arredondamento
	// ******************
	i = (*p)(r); // uso do ponteiro para funcao: esta instrucao e'
							 // totalmente equivalente a instrucao: i = round(r);

	// ***************************
	// 1.4 Impressao de resultados
	// ***************************
	printf("\nnumero arredondado: %d",i);
	printf("\n\nPausa: pressione alguma tecla para continuar...");
	getch();
}

// ****************
// 2 Rotina round()
// ****************
int round(float q){ // definicao da funcao: nada de novo !
	return((int)floor(q+0.5));
}
