/****************************************************************************
			Programa: e0706.cpp
		 Proposito: Mostra a manipulacao de vetores de 2 dimensoes.
Ultima Revisao: 20/10/97
****************************************************************************/
#include <conio.h>
#include <stdio.h>
#define MAX 5

// ********************
// 1 Programa principal
// ********************
void main(){
	int a[MAX][MAX];	// vetor bidimensional!!
	int n,m;          // numero de linhas(n) e colunas(m) da matriz
	int c,l;          // contadoes de iteracao
	void impmtz(int[MAX][MAX],int,int); // funcao de impressao de matriz
	void transp(int[MAX][MAX],int,int); // funcao de transposicao de matriz

	// titulo
	clrscr();
	puts("Transposicao de Matrizes");

	// leitura da ordem da matriz
	do{
		puts("Digite o numero de LINHAS da matriz:");
		scanf("%d",&n);
	}while(n < 1 || n > MAX);
	do{
		puts("Digite o numero de COLUNAS da matriz:");
		scanf("%d",&m);
	}while(m < 1 || m > MAX);

	// leitura dos elementos da matriz
	puts("Digite os elementos (INTEIROS) da matriz:");
	for(l = 0 ; l <= n-1 ; l++){
		for(c = 0 ; c <= m-1 ; c++){
			printf("\na[%d][%d]: ",l+1,c+1);
			scanf("%d",&a[l][c]);
//                À> elemento do vetor
		}
	}

	// impressao da matriz original
	clrscr();
	puts("Matriz original:");
	impmtz(a,n,m);

	// transposicao
	transp(a,n,m);

	// impressao da matriz transposta
	puts("Matriz Transposta:");
	impmtz(a,m,n);
	getch(); // pausa
}

// *****************
// 2 rotina impmtz()
// *****************
void impmtz(int matriz[MAX][MAX], int max_lin,int max_col){
	int i,j;
	for(i = 0 ; i <= max_lin-1 ; i++){    // para todas as linhas...
		puts("\n");                         // quebra linha
		for(j = 0 ; j <= max_col-1 ; j++){  // para todas as colunas...
			printf("%3d ",matriz[i][j]);      // imprime elemento
		}
	}
	puts("\n");
}

// *****************
// 3 rotina transp()
// *****************
void transp(int matriz[MAX][MAX], int max_lin,int max_col){
	int i,j,temp;
	for(i = 0 ; i <= max_lin-1 ; i++){    // para todas as linhas...
		for(j = i ; j <= max_col-1 ; j++){  // para todas as colunas j >= i
			temp = matriz[i][j];              // troca: m[i][j] <-> m[j][i]
			matriz[i][j] = matriz[j][i];
			matriz[j][i] = temp;
		}
	}
}