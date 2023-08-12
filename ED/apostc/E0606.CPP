/**************************************
 Programa exemplo e0606.cpp
 ***************************************/

// ******************
// programa principal
// ******************
#include <conio.h>
#include <stdio.h>
void main(){                  // declaracao da funcao principal
	long double n,f;             // declaracao de variaveis
	long double fat(unsigned n); // declaracao da funcao fat()
	clrscr();
	do{   // leitura do numero
		puts("Digite um numero positivo para o calculo do fatorial");
		printf("numero: ");
		scanf("%Lf",&n);
	}while(n < 0.0 || n > 1000.0);
	f = fat(n);   // chamada a funcao fat()
	printf("\n%.0Lf! = %Le",n,f);   // impressao do resultado
};

// ************
// rotina fat()
// ************
long double fat(unsigned n){// declaracao da funcao
	long double valor;        // fdeclaracao de variavel temporaria
	if(n == 0.0){             // se fim da recursao...
		valor = 1.0;            // ... calcula ultimo valor.
	}else{                    // senao...
		valor = n * fat(n-1.0); // ... chama fat(n-1).
	};
	return(valor);            // retorna valor.
};

