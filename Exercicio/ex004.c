#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Objetivo: ler o nome de um produto e perguntar se é unidade ou peso,
se for unidade pergunta o preço da unidade e a quantidade de unidades,
se for peso: pergunta o peso por quilo e a quantidade de quilos,
no final exibir o as informações dadas e o preço final.
*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Definição de variáveis
    char produto[25], ctipoProduto[25];
    int quantidade, comparar;
    float preco_unit, preco_quilo, peso, valor_final;

    //Entrada de dados
    printf(" Digite o nome do produto: ");
    gets(produto); /* Le string produto*/
    printf("\n Digite o tipo de produto (unit ou peso)?: ");
    gets(ctipoProduto); /* Lê string ctipoProduto*/

    printf("\n\n As strings lidas sao:\n %s \n %s", produto, ctipoProduto); /* Imprime as strings*/
    comparar = strcmp(ctipoProduto, "unit");//Compara se a tipo é igual a unit o valor de comparar recebe 0

    if (comparar == 0){ //Condição que verifica se ctipoProduto é unit
        printf("\n\n Tipo Unitário: %s ",ctipoProduto ); /* Imprime as strings se for do tipo peso unitário*/
        printf("Qual o valor unitário? R$");
        scanf("%f", &preco_unit); //Lê o valor da unidade
        printf("Qual a quantidade? ");
        scanf("%i", &quantidade); //Lê a quantidade
        valor_final = preco_unit * quantidade; //Calcula o valor final
        printf("O valor final é: R$%.2f\n", valor_final); //Informa o valor final
    } else {
        printf("\n\n Tipo peso variável: %s ",ctipoProduto ); /* Imprime as strings se for do tipo peso
        variável*/
        printf("Qual o preço do quilo? R$");
        scanf("%f", &preco_quilo); //Lê o valor do quilo
        printf("Qual o peso? ");
        scanf("%f", &peso); //Lê o peso
        valor_final = preco_quilo * peso; //Calcula o valor final
        printf("O valor final é: R$%.2f\n", valor_final); //Informa o valor final
    }
    return 0;
}
