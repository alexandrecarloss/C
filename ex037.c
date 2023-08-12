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

float tabuada(float num1) {
    printf("\t\t\tTABUADA\n");
    int i = 1;
    float som, sub, mul, div;
    for(i; i <= 10; i++) {
        som = somar(num1, i);
        sub = subtrair(num1, i);
        mul = multiplicar(num1, i);
        div = dividir(num1, i);
        printf("%3.2f + %i = %6.2f \t%3.2f - %i = %6.2f \t%3.2f x %i = %6.2f \t%3.2f / %i = %6.2f\n", num1, i, som, num1, i, sub, num1, i, mul, num1, i, div);

    }
}

int main() {
    float num = 0;
    setlocale(LC_ALL, "Portuguese");
    printf("Qual número deseja aplicar na tabuada das 4 operações até 10? ");
    scanf("%f", &num);
    tabuada(num);
    /*float resultado = 0, num1 = 10, num2 = 2;
    resultado = multiplicar(num1, num2);
    printf("\nResultado = %.2f\n", resultado);
    */
    return 0;
}
