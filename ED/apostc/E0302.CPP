/* *******************************************************************
			Programa: e0302.cpp
		 Proposito: Operadores Aritmeticos
Ultima Revisao: 22/07/97
******************************************************************* */
void main(){
	char   c1, c2;
	int    i1, i2;
	float  f1, f2, f3;

	// Expressoes validas
	i1 = 10 + 50 - 2;
	i2 = i1 % 3;
	f1 = 3.8 * 2.1;
	f2 = 53.5 / f1;

	// Expressao invalida
//	i1 = f1 % 2;     // O operador % so' aceita inteiros!
	f1 = f1 / 0.0;   // O divisor e' zero!

	// Casting
	i1 = (int)f1 % 2;     // Obseserve que f1 continua sendo float
												// somente o valor foi convertido.

	// Conversao de tipo
	i1 = 17;
	i2 = 4;
	f1 = 17.0;
	f2 = 4.0;
									// operandos       resultado

	f3 = f1 / f2;   // float / float   float
	f3 = f1 / i2;   // float / int     float
	f3 = i1 / f2;   // int   / float   float
	f3 = i1 / i2;   // int   / int     int       Resultado truncado!
	f3 = (float)i1 / (float)i2;               // Resultado correto!

	// Operando caracter
	c1 = 65;   // valor ASCII
	c2 = 'M';
	c1 = c1 + 1;
	c2 = c2 + 32;

	// Precedencia de operadores: Verifique o resultado

	i1 = 3 - 5 * 7 % 2;
	i2 = 40 / 2 / 2 / 2;
	f1 = 4.0 * 3.0 - 6.0 / 2.0 + 2.0;

}