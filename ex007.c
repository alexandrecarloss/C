#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*
    Objetivo: calcular o valor das parcelas de um empr�stimo,
    se o valor da parcela for maior que 30% do sal�rio o empr�stimo n�o � concedido
    */

    //Declara��o de vari�veis
    int parcelas;
    float valparc, juro, montante, salario, emprestimo, j; //Valor da parcela

    //Entrada de dados
    printf("Informe o seu sal�rio: R$");
    scanf("%f", &salario);
    printf("Informe o valor do empr�stimo: R$");
    scanf("%f", &emprestimo);
    printf("Informe a quantidade de parcelas (em meses): ");
    scanf("%i", &parcelas);
    printf("Informe o juro ao m�s: ");
    scanf("%f", &juro);
    //Tratamento de informa��es
    valparc = emprestimo / parcelas;
    juro = juro / 100;
    printf("emprestimo %f\n parcelas %i\n juro %f\n", emprestimo, parcelas, juro);
    j = parcelas * emprestimo  * juro;
    montante = j + valparc;
    //verifica��o da possibilidade de empr�stimo
    if(valparc > (salario * 0.3)) {
        printf("Emprestimo negado ");
    } else {
        //caso seja consedido valor da parcela � informado
        printf("O valor da parcela � R$%.2f", valparc);
        printf("\nO valor com juros � R$%.2f", montante);
    }
    return 0;
}
