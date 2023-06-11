#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*
    Objetivo: calcular o valor das parcelas de um empréstimo,
    se o valor da parcela for maior que 30% do salário o empréstimo não é concedido
    */

    //Declaração de variáveis
    int parcelas;
    float valparc, juro, montante, salario, emprestimo, j; //Valor da parcela

    //Entrada de dados
    printf("Informe o seu salário: R$");
    scanf("%f", &salario);
    printf("Informe o valor do empréstimo: R$");
    scanf("%f", &emprestimo);
    printf("Informe a quantidade de parcelas (em meses): ");
    scanf("%i", &parcelas);
    printf("Informe o juro ao mês: ");
    scanf("%f", &juro);
    //Tratamento de informações
    valparc = emprestimo / parcelas;
    juro = juro / 100;
    printf("emprestimo %f\n parcelas %i\n juro %f\n", emprestimo, parcelas, juro);
    j = parcelas * emprestimo  * juro;
    montante = j + valparc;
    //verificação da possibilidade de empréstimo
    if(valparc > (salario * 0.3)) {
        printf("Emprestimo negado ");
    } else {
        //caso seja consedido valor da parcela é informado
        printf("O valor da parcela é R$%.2f", valparc);
        printf("\nO valor com juros é R$%.2f", montante);
    }
    return 0;
}
