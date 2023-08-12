/* *******************************************************************
			Programa: e0402.cpp
		 Proposito: Uso da funcao scanf()
Ultima Revisao: 08/08/97
******************************************************************* */
#include <stdio.h> // biblioteca das funcoes scanf() e printf()
void main(){
	char* nome;
	int   cod;
	float preco;
	int dia,mes,ano;

	// leitura individual
	printf("\nDigite o nome do item: ");  // texto de aviso (prompt)
	scanf("%s",nome);                     // leitura do dado
	printf("Digite o codigo do item: ");
	scanf("%d",&cod);
	printf("Digite o preco do item: ");
	scanf("%f",&preco);

	// leitura conjunta
	printf("\nDigite o nome, codigo e preco do item: ");
	scanf("%s %d %f",nome,&cod,&preco);

	// leitura conjunta com supressao
	printf("\nDigite o nome, codigo e preco do item: ");
	scanf("%s %d %*f",nome,&cod,&preco); // apos a leitura,'preco' nao e' alterado


	// leitura segmentada
	printf("\nDigite sua data de nascimento (ddmmaa): ");
	scanf("%2d %2d %2d",&dia,&mes,&ano);
	printf("\nVoce nasceu em %d de %d de 19%d!",dia,mes,ano);

}

