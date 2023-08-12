#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Protótipos
float somar(float num1, float num2);
float multsomas(float num1, float num2);

//Implementar
float somar(float num1, float num2) {
    return num1 + num2;
}

float multsomas(float num1, float num2) {
    int i;
    float soma = 0;
    for(i = 1; i <= num2; i++) {
        soma = somar(num1, soma);
    }
    return soma;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    float resultado = 0, num1 = 0, num2 = 2;
    resultado = multsomas(num1, num2);
    printf("\nResultado = %.2f\n", resultado);




    return 0;
}
