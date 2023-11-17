#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int i, j, nota, soma, rep = 0, apr = 0;
    float media;

    for(i = 1; i <= 50; i++) {
        printf("i = %i\n", i);
        for(j = 1; j <= 10; j++) {
            nota = j;
            printf("nota = %i\n", j);
            if(nota >= 6) {
                apr++;
            }
            soma += nota;
        }
    }
    media = soma / 500;
    rep = 500 - apr;
    printf("A média é: %.2f", media);
    printf("\nOs aprovados são: %i e os reprovados são %i:", apr, rep);
    return 0;
}
