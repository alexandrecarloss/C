#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float nota;
    int i,apr = 0, rep = 0;
    for(i = 1; i <= 10; i++) {
        printf("Informe a nota %i: ", i);
        scanf("%f", &nota);

        if(nota >= 6){
            printf("Aprovado!\n");
            apr++;
        } else {
            printf("Tem que fazer exame final!\n");
            rep++;
        }
    }
    printf("O número de aprovados é: %i, e reprovados é: %i", apr, rep);
    return 0;
}
