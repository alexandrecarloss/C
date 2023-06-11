#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void aumento(float *sal) {
    *sal += 500;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    float salario = 1300;

    printf("Salário: R$%.2f", salario);
    aumento(&salario);
    printf("\nSalário novo: R$%.2f", salario);



    return 0;
}
