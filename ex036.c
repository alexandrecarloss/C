#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

float somar(float num1, float num2);
float subtrair(float num1, float num2);
float multiplicar(float num1, float num2);
float dividir(float num1, float num2);

float somar(float num1, float num2) {
    return num1 + num2;
}

float subtrair(float num1, float num2) {
    return num1 - num2;
}

float multiplicar(float num1, float num2) {
    return num1 * num2;
}

float dividir(float num1, float num2) {
    return num1 / num2;
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    float resultado = 0, num1 = 10, num2 = 2;
    resultado = multiplicar(num1, num2);
    printf("\nResultado = %.2f\n", resultado);
    return 0;
}
