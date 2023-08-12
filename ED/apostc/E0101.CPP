/* *******************************************************************
			Programa: e0101.cpp
		 Proposito: Calcula a raiz quadrada de um numero real positivo
								maior que 1.0 com precisao PREC (0.00001).
Ultima Revisao: 16/06/97
******************************************************************* */

#define MAX 100       // numero maximo de iteracoes
#define PREC 0.000001 // precisao da raiz
void main(){          // inicia programa principal...
	float num 					// numero do qual se quer saber a raiz quadrada
	float raiz;         // aproximacao para raiz de num
	float inf, sup;     // intervalo que contem a raiz procurada
	do{
		printf("\n\nDigite um numero real positivo: ");
		scanf("%f",&num;
	}while(num <= 1.0);   // aceita somente positivo maior que 1.0!
	inf = 0.0;            // inicializa intervalo inicial de busca
	sup = num;
	i = 0;                       // inicializa contador
	do{                          // faca...
		i = i + 1;                 // incrementa contador
		raiz = 0.5 * (inf + sup);  // faz estimativa de raiz
		if(raiz*raiz > num){       // se chute foi alto...
			sup = raiz;              // baixa limite superior
		}else{                     // ...senao...
			inf = raiz;              // sobe limite inferior
		};
	}while( (sup-inf) > PREC && i < MAX);  // enquanto intervalo grande
	raiz = 0.5 * (inf + sup);              // estima a raiz
	printf("Raiz: %f +- %f",raizPREC);    // imprime o valor da raiz
};  // fim do programa
