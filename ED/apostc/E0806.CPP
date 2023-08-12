/****************************************************************************
			Programa: e0806.cpp
		 Proposito: Ponteiro como argumento de funcao.
Ultima Revisao: 05/11/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#include <math.h>

// ********************
// 1 Programa principal
// ********************
void main(){
	void round(float *); // prototipo de funcao
	float num;           // declarando uma variavel real
	float *p = &num;     // declarando um ponteiro real (com o endereco de num)

	clrscr();
	printf("Digite um numero real para se arredondado: ");
	scanf("%f",p);
//           À> observe a sintaxe alternativa para scanf("%f",&num);

	round(p);
//      À> observe a passagem do ponteiro com o endereco de num

	printf("\nNumero Arredondado: %.2f ",*p);
//                                      À>  conteudo do endereco apontado

	getch();
}

// ****************
// 2 rotina round()
// ****************
void round(float *q){
//               À> recebe ponteiro
	*q = floor(*q + 0.5); // arredonda para baixo ou para cima!

}
