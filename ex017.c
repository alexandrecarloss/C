#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    /*Objetivo:
    Fa�a um algor�tmo para ler o valor do sal�rio e calcular quanto o trabalhador ir� receber,
    sabendo que dever� ser deduzido o imposto de renda*/

    //Defini��o de vari�veis
    float sal, deduzido, desconto, ir1, ir2, ir3, ir4;
    ir1 = 0.075;
    ir2 = 0.15;
    ir3 = 0.22;
    ir4 = 0.275;

    //Entrada de dados
    printf("Informe o sal�rio R$");
    scanf("%f", &sal);

    //Desconto de IR
    if(sal < 2112) {
        printf("O sal�rio l�quido n�o tem IR � R$%.2f", sal);
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
    printf("O sal�rio l�quido sem o IR � R$%.2f", deduzido);
    return 0;
    }
}
