#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Faça um algorítmo para ler o valor do salário e calcular quanto o trabalhador irá receber,
    sabendo que deverá ser deduzido o imposto de renda*/

    //Definição de variáveis
    float sal, deduzido, desconto, ir1, ir2, ir3, ir4;
    ir1 = 0.075;
    ir2 = 0.15;
    ir3 = 0.22;
    ir4 = 0.275;

    //Entrada de dados
    printf("Informe o salário R$");
    scanf("%f", &sal);

    //Desconto de IR
    if(sal < 2112) {
        printf("O salário líquido não tem IR é R$%.2f", sal);
    } else {
    if((sal >= 2112,01) && (sal <= 2826,65)) {
        desconto = sal * ir1;
        deduzido = sal - desconto;
    }
    if((sal >= 2826,66) && (sal <= 3751,05)) {
        desconto = sal * ir2;
        deduzido = sal - desconto;
    }
    if((sal >= 3751,06) && (sal <= 4664,68)) {
        desconto = sal * ir3;
        deduzido = sal - desconto;
    }
    if(sal > 4664,68) {
        desconto = sal * ir4;
        deduzido = sal - desconto;
    }
    printf("O salário líquido sem o IR é R$%.2f", deduzido);
    return 0;
    }
}
