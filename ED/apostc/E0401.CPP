/* *******************************************************************
			Programa: e0401.cpp
		 Proposito: Uso da funcao printf().
Ultima Revisao: 07/08/97
******************************************************************* */
#include <stdio.h> // biblioteca da funcao printf()!
#include <conio.h> // biblioteca da funcao clrscr()
void main(){
	int i = 12;
	int j = -35;
	int k = 9386;
	float r = 5.83;
	float s = -82.3;
	float t = 5467.75;
	char letra = 'a';
	char* nome = "Teste";

	clrscr();  // limpa tela

	// somente texto
	printf("Texto Exemplo");   // sem quebra de linha
	printf("Texto Exemplo");
	printf("Texto Exemplo");
	printf("Texto Exemplo");

	printf("\nTexto Exemplo"); // com quebra de linha
	printf("\nTexto Exemplo");
	printf("\nTexto Exemplo");
	printf("\nTexto Exemplo");

	// formato caracter
	printf("\n%c",letra);
	printf("\n%c",'b');

	// formato string
	printf("\n%s",nome);



	// texto e numero sem formatacao
	printf("\nJoaozinho tem %d amiguinhos!",i);
	printf("\nConsumo Medio: %f kWh",r);


	// Uso dos modificadores de formato
	printf("\n\nJustificacao a direita");
	printf("\n %6d  %12f",i,r);
	printf("\n %6d  %12f",j,s);
	printf("\n %6d  %12f",k,t);

	printf("\n\nJustificacao a esquerda");
	printf("\n %-6d  %-12f",i,r);
	printf("\n %-6d  %-12f",j,s);
	printf("\n %-6d  %-12f",k,t);

	printf("\n\nCom sinal");
	printf("\n %+6d  %+12f",i,r);
	printf("\n %+6d  %+12f",j,s);
	printf("\n %+6d  %+12f",k,t);

	printf("\n\nCom zeros");
	printf("\n %06d  %012f",i,r);
	printf("\n %06d  %012f",j,s);
	printf("\n %06d  %012f",k,t);

	printf("\n\nSem decimais, Com 3 decimais");
	printf("\n %6.0f  %8.3f", r,r);
	printf("\n %6.0f  %8.3f", s,s);
	printf("\n %6.0f  %8.3f", t,t);

	printf("\n\nDecimal, Hexa, Octal");
	printf("\n %6d  %6X  %6o",i,i,i);
	printf("\n %6d  %6X  %6o",k,k,k);
	printf("\n %6d  %6X  %6o",k+1,k+1,k+1);

	printf("\n\nPadrao, Cientifico");
	printf("\n %11f  %e", r,r);
	printf("\n %11f  %e", s,s);
	printf("\n %11f  %e", t,t);
}