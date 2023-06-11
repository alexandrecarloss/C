#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float num1, num2, res;
    int operacao, continuar = 1;

        while(continuar != 0) {
        printf("\t\tCALCULADORA\n\n");
        printf("Qual operação deseja fazer?\n1 = soma \t 2 = subtração \t 3 = multiplicação \t 4 = divisão\n\n");
        scanf("%i", &operacao);

        printf("Primeiro número: ");
        scanf("%f", &num1);
        printf("Segundo número: ");
        scanf("%f", &num2);

        switch(operacao) {
        case 1:
            res = num1 + num2;
            printf("Resultado da operação é: %.2f\n", res);
            break;
        case 2:
            res = num1 - num2;
            printf("Resultado da operação é: %.2f\n", res);
            break;
        case 3:
            res = num1 * num2;
            printf("Resultado da operação é: %.2f\n", res);
            break;
        case 4:
            if(num2 == 0) {
                printf("Não é possível dividir por 0!\n");
            } else {
                res = num1 / num2;
                printf("Resultado da operação é: %.2f\n", res);
            }
            break;
        default:
            printf("Operação inválida");
        }
        printf("Quer continuar?\n [1 = sim \t0 = não]");
        scanf("%i", &continuar);
        system("cls");
    }

    return 0;
}
