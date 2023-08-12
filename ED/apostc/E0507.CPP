/* *******************************************************************
			Programa: e0507.cpp
		 Proposito: Uso da estrutura switch
Ultima Revisao: 27/08/97
******************************************************************* */
#include <stdio.h>
#include <conio.h>
void main(){
	int tipo;
	float preco = 0.0;
	clrscr();
	puts("*** Turbo Cao Lanches *** \nFaca seu pedido!");
	puts("1: Da Casa \n2: Completo \n3: Simples \n4: Economico");
	do{
		printf("\nPedido: ");
		scanf("%d",&tipo);
	}while(tipo != 1 && tipo != 2 && tipo != 3 && tipo != 4);
	printf("\nSeu pedido:\n");
	switch (tipo) {
	case 1:
		puts("- bacon");
		puts("- ovo frito");
		preco += 0.60;
	case 2:
		puts("- queijo ralado");
		puts("- maionese");
		preco += 0.50;
	case 3:
		puts("- milho");
		puts("- ervilha");
		preco += 0.20;
	case 4:
		puts("- salsicha");
		puts("- pao");
		puts("- molho");
		preco += 1.0;
	}
	printf("\nTotal: $ %.2f   Bom Apetite!",preco);
}

