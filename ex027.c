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
        printf("Qual opera��o deseja fazer?\n1 = soma \t 2 = subtra��o \t 3 = multiplica��o \t 4 = divis�o\n\n");
        scanf("%i", &operacao);

        printf("Primeiro n�mero: ");
        scanf("%f", &num1);
        printf("Segundo n�mero: ");
        scanf("%f", &num2);

        switch(operacao) {
        case 1:
            res = num1 + num2;
            printf("Resultado da opera��o �: %.2f\n", res);
            break;
        case 2:
            res = num1 - num2;
            printf("Resultado da opera��o �: %.2f\n", res);
            break;
        case 3:
            res = num1 * num2;
            printf("Resultado da opera��o �: %.2f\n", res);
            break;
        case 4:
            if(num2 == 0) {
                printf("N�o � poss�vel dividir por 0!\n");
            } else {
                res = num1 / num2;
                printf("Resultado da opera��o �: %.2f\n", res);
            }
            break;
        default:
            printf("Opera��o inv�lida");
        }
        printf("Quer continuar?\n [1 = sim \t0 = n�o]");
        scanf("%i", &continuar);
        system("cls");
    }

    return 0;
}
