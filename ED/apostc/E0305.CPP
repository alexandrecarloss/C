/* *******************************************************************
			Programa: e0305.cpp
		 Proposito: Operadores Relacionais e Logicos
Ultima Revisao: 22/07/97
******************************************************************* */
void main(){
	char c,d;
	int	 i,j;
	float r,s;
	int valor_logico;

	// Operadores Relacionais

	i = 5;
	j = 6;
	r = 2.3;
	s = 6.1;
	c = 'A';
	d = 'a';

	// Tipos iguais
	valor_logico = (i == j);
	valor_logico = (r != s);
	valor_logico = (i >  3);
	valor_logico = (c <  d);   // obs: 'A' = 65  'a' = 97
	valor_logico = (4 >= j);
	valor_logico = (i-5 > j*3);
	valor_logico = (2.6 != 4.8);
	valor_logico = (c  ==  'w'); // Obs.: 'w' = 119

	// Tipos diferentes
	valor_logico = (r <= i);
	valor_logico = (j ==  2.3);

	// Operadores Logicos
	valor_logico = r==s && c<d;
	valor_logico = i>45 || r!=s;
	valor_logico = !(c != d);

	// Quando termina a repeticao abaixo?
	i = 0;
	r = 1.0;
	do{
		r /= 2.0;
	}while( r > 1e-8 && i++ < 50);

}