/**************************************
 Programa exemplo e0807.cpp
 Cap.8 ex. 07
 Vetores
***************************************/
#include <conio.h>
#include <stdio.h>
#define MAX 10
void main(){
	int a[MAX][MAX];	 // <- vetor bidimensional!!
	int n,c,l,temp;

	// titulo
	clrscr();
	puts("Transposicao de Matrizes");

	// leitura da ordem da matriz
	do{
		puts("Digite a ordem do sistema:");
		scanf("%d",&n);
	}while(n<1 || n > MAX);

	// leitura dos elementos da matriz
	puts("Digite os elementos da matriz:");
	for(l = 0 ; l <= n-1 ; l++){
		for(c = 0 ; c <= n-1 ; c++){
			printf("\na[%d][%d]: ",l+1,c+1);
			scanf("%d",&a[l][c]);
		};
	};

	// impressao da matriz original
	clrscr();
	puts("Matriz original:");
	for(l = 0 ; l <= n-1 ; l++){
		for(c = 0 ; c <= n-1 ; c++){
			gotoxy(1+c*5,l+3);
			printf("%4d",a[l][c]);
		};
	};

	// transposicao da matriz
	for(l = 0 ; l <= n-1 ; l++){
		for(c = l ; c <= n-1 ; c++){
			temp = a[l][c];
			a[l][c] = a[c][l];
			a[c][l] = temp;
		};
	};

	// impressao da matriz tranposta
	puts("\n\nMatriz transposta:");
	for(l = 0 ; l <= n-1 ; l++){
		for(c = 0 ; c <= n-1 ; c++){
			gotoxy(1+c*5,l+6+n);
			printf("%4d",a[l][c]);
		};
	};

};