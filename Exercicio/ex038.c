#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

float fatorial(float num);
float fatorial(float num) {
    float i = num, tot = 1, cont = num - 1;
    printf("%.2f! = %.0f", num, i);
    for(i; i >= 1; i--) {
        tot = tot * i;
        if(cont > 0) {
            printf(" x %.0f ", cont);
            cont--;
        }

    }
    printf("= %.2f", tot);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    fatorial(5);
    return 0;
}
