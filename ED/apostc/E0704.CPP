/****************************************************************************
			Programa: e0704.cpp
		 Proposito: Mostra a passagem de vetores para funcoes.
Ultima Revisao: 20/10/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#define MAX 50

// ********************
// 1 Programa principal
// ********************
void main(){
	int i,n;
	float med,idade[MAX];      // declaracao do vetor idade
	float media(float[],int);  // prototipo de funcao
//                 À> prototipo de vetor!

// ********************
// 1.1 Leitura de dados
// ********************
	clrscr();

	do{
		printf("\nDigite o numero de alunos na turma: ");
		scanf("%d",&n);
	}while(n < 1 || n > MAX); // teste de limites!

	printf("\nDigite as idades dos alunos:\n");
	for(i=0 ; i<=(n-1) ; i++){
		printf("%d§ aluno: ",i+1);
		scanf("%f",&idade[i]);   // leitura dos elementos do vetor
	}

// *********************************************
// 1.2 Calculo da media e impressao de resultado
// *********************************************
	med = media(idade,n);          // passagem do vetor idade para a funcao
	printf("\nMedia: %.1f",med);   // resultado
	getch();                       // pausa
}

// ****************
// 2 rotina media()
// ****************
float media(float v[],int num){       // declaracao da funcao
	int i;
	float	soma = 0.0;
	for(i = 0; i <= num-1; i++){
		soma += v[i];                     // calcula soma
	}
	return(soma/num);                   // retorna media
}

