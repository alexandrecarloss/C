#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char produto[25], ctipoProduto[25];
    int quantidade, comparar;
    float preco_unit, preco_quilo, peso, valor_final;

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
