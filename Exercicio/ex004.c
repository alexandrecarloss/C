#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Objetivo: ler o nome de um produto e perguntar se � unidade ou peso,
se for unidade pergunta o pre�o da unidade e a quantidade de unidades,
se for peso: pergunta o peso por quilo e a quantidade de quilos,
no final exibir o as informa��es dadas e o pre�o final.
*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Defini��o de vari�veis
    char produto[25], ctipoProduto[25];
    int quantidade, comparar;
    float preco_unit, preco_quilo, peso, valor_final;

    //Entrada de dados
    printf(" Digite o nome do produto: ");
    gets(produto); /* Le string produto*/
    printf("\n Digite o tipo de produto (unit ou peso)?: ");
    gets(ctipoProduto); /* L� string ctipoProduto*/

    printf("\n\n As strings lidas sao:\n %s \n %s", produto, ctipoProduto); /* Imprime as strings*/
    comparar = strcmp(ctipoProduto, "unit");//Compara se a tipo � igual a unit o valor de comparar recebe 0

    if (comparar == 0){ //Condi��o que verifica se ctipoProduto � unit
        printf("\n\n Tipo Unit�rio: %s ",ctipoProduto ); /* Imprime as strings se for do tipo peso unit�rio*/
        printf("Qual o valor unit�rio? R$");
        scanf("%f", &preco_unit); //L� o valor da unidade
        printf("Qual a quantidade? ");
        scanf("%i", &quantidade); //L� a quantidade
        valor_final = preco_unit * quantidade; //Calcula o valor final
        printf("O valor final �: R$%.2f\n", valor_final); //Informa o valor final
    } else {
        printf("\n\n Tipo peso vari�vel: %s ",ctipoProduto ); /* Imprime as strings se for do tipo peso
        vari�vel*/
        printf("Qual o pre�o do quilo? R$");
        scanf("%f", &preco_quilo); //L� o valor do quilo
        printf("Qual o peso? ");
        scanf("%f", &peso); //L� o peso
        valor_final = preco_quilo * peso; //Calcula o valor final
        printf("O valor final �: R$%.2f\n", valor_final); //Informa o valor final
    }
    return 0;
}
