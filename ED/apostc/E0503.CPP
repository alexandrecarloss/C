/* *******************************************************************
			Programa: e0503.cpp
		 Proposito: Uso da estrutura for...
Ultima Revisao: 26/08/97
******************************************************************* */
// calculo da amplitude de um conjunto de valores.
#include <conio.h>
#include <stdio.h>
void main(){
	int i;             // contador de iteracao
	int num;           // numero de valores lidos
	float val;         // valor lido
	float max,min;     // valor maximo, valor minim
	clrscr();
	puts("Digite numeros reais...");
	puts("Quantos valores? ");
	scanf("%d",&num);                // leitura do numero de valores
	for(i = 1; i <= num; i++){       // laco iterativo para i de 1 a num
		printf("%d� valor: ",i);       // �	 leitura dos valores
		scanf("%f",&val);              // �
		if(i == 1){                    // �	 se 1a leitura...
			max = min = val;             // �	 inicializa valores
		}                              // �
		max = val > max ? val : max;   // �	 calcula maximo
		min = val < min ? val : min;   // �	 calcula minimo
	}                                // fim do laco
	printf("\nAmplitude: [%.3f , %.3f]",min,max);    // imprime min,max
}

