/****************************************************************************
			Programa: e0804.cpp
		 Proposito: Verificar a diferenca entre passagem de  dados  por  VALOR  e
								por REFERENCIA.
Ultima Revisao: 05/11/97
****************************************************************************/
#include <stdio.h>
#include <conio.h>
// ********************
// 1 programa principal
// ********************
void main(){
	void funcao_1(int);    // prototipo da funcao_1
	void funcao_2(int*);   // prototipo da funcao_2

	int a = 5;  // declaramos uma variavel inteira
	clrscr();

	puts("\n\nPressione alguma tecla para continuar a cada passo...");

	getch();
	printf("\nvalor da variavel ANTES de chamar a funcao_1");
	printf("\na: %d",a);
	funcao_1(a);   // passagem por VALOR
//         À> passa valor
	getch();
	printf("\nvalor da variavel DEPOIS de chamar a funcao_1");
	printf("\na: %d (NAO ALTEROU!)",a);

	getch();
	printf("\n\nvalor da variavel ANTES de chamar a funcao_2");
	printf("\na: %d",a);
	funcao_2(&a); // passagem por REFERENCIA
//         À> passa endereco
	getch();
	printf("\nvalor da variavel DEPOIS de chamar a funcao_2");
	printf("\na: %d (ALTEROU!)",a);

	getch();

}

// **********
// 2 funcao_1
// **********
void funcao_1(int v){
//                À> declaracao de VARIAVEL
	getch();
	printf("\nvalor da variavel ao CHEGAR na funcao_1");
	printf("\na: %d",v);

	v = v + 1; // alterando o valor da variavel

	getch();
	printf("\nvalor da variavel ao SAIR na funcao_1");
	printf("\na: %d",v);
}

// **********
// 3 funcao_2
// **********
void funcao_2(int *p){
//                À> declaracao de PONTEIRO
	getch();
	printf("\nvalor da variavel ao CHEGAR na funcao_2");
	printf("\na: %d",*p);

	*p = *p + 1; // alterando o conteudo do ponteiro

	getch();
	printf("\nvalor da variavel ao SAIR na funcao_2");
	printf("\na: %d",*p);
}