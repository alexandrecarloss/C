/* *******************************************************************
			Programa: e0303.cpp
		 Proposito: Operadores de atribuicao aritmetica
Ultima Revisao: 22/07/97
******************************************************************* */
void main(){
	char    c;
	int   i,j;
	float r,s;

	i = 0;
	j = 100;
	r = -3.47;
	s = 546.764;
	c = 'A';

	// Operadores arimeticos
	c += 2;            // c = c + 2
	i -= 4;            // i = i - 4
	j %= 7;            // j = j % 7
	r *= 7.9;          // r = r * 7.9
	s /= r - 1.5;       // s = s / (r - 1.5)

}