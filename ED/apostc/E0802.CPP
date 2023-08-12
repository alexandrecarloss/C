/****************************************************************************
			Programa: e0802.cpp
		 Proposito: Mostrar manipulacao de ponteiros
Ultima Revisao: 05/11/97
****************************************************************************/
#include <stdio.h>
#include <conio.h>
void main(){
	float a,b;  // declaramos duas variaveis reais
	float  *p;  // declaramos um ponteiro real

	clrscr();
	puts("Digite um numero real (a): ");
	scanf("%f",&a);
//           À> armazenamos o numero lido no ENDERECO de (a)

	p = &a;   // atribuimos ao ponteiro (p) o endereco de (a)
	b = *p;   // atribuimos a (b) o conteudo do endereco apontado por (p)
						// Isto equivale a: b = a;

	printf("\n  a:  %.2f  \tConteudo de a", a);
	printf("\n &a:  %X  \tEndereco de a",&a);
	printf("\n  p:  %X  \tConteudo de p (endereco apontado por p)", p);
	printf("\n &p:  %X  \tEndereco de p",&p); //
	printf("\n *p:  %.2f  \tConteudo do endereco apontado por p",*p);
	printf("\n  b:  %.2f  \tConteudo de b", b);
	printf("\n &b:  %X  \tEndereco de b",&b);

	puts("\n\nPressione alguma tecla para continuar...");
	getch();

}