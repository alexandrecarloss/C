/* *******************************************************************
			Programa: e0301.cpp
		 Proposito: Operadores de atribuicao.
Ultima Revisao: 22/07/97
******************************************************************* */
void main(){

	// declaracao de variaveis
	char   c;
	int    i,j,k;
	float  f,g,h;
	double d;

	// Atribuicoes validas
	c = 'A';
	i = 7;
	f = 10.0;
	d = 4.32464869714159;

	// atribuicoes invalidas
//	12 = i;            // costante
//	f + d = d + f;     // expressao

	// Conversao de tipo sem perda de informacao
	i = c;       // valor ASCII de 'A' e' 65
	f = i;
	d = f;

	// Conversao de tipo com perda de informacao
	d = 74.5461836294756;
	f = d;
	i = f;
	i = 2.999999;  //Truncamento!

	// Estouro dos limites de um tipo
	i = 30000;
	i = i + 1000;
	i = i + 1000;
	i = i + 1000;   // Passou do limite!

	// Atribuicao multipla
	i = j = k = 4;
	f = g = h = 6.8;

	// Atribuicao multipla sem perda de informacao
	d = f = i = 20;

	// Atribuicao multipla com perda de informacao
	i = f = d = 3.09571648723667;

}