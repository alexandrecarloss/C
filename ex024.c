#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int linha, coluna;
    for(linha = 1; linha <= 5; linha++) {
        for(coluna = 1; coluna <= 5; coluna++) {
            if((linha == 1) || (linha == 3) || (linha == 5)) {
                printf("1 ");
            } else {
            printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
