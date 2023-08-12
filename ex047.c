#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define maxlinha 2
#define maxcoluna 2

int main() {
    setlocale(LC_ALL, "Portuguese");
    int matriz[maxlinha][maxcoluna], linha, coluna;
    printf("\n---------Preenchendo a Matriz-----------\n\n");
    for(linha = 0; linha < maxlinha; linha++){
        for(coluna = 0; coluna < maxcoluna; coluna++) {
            printf("Digite o valor de matriz[%d][%d] = ", linha, coluna);
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    printf("\n---------Valores da Matriz----------\n\n");
    for(linha = 0; linha < maxlinha; linha++){
        for(coluna = 0; coluna < maxcoluna; coluna++) {
            printf("matriz[%d][%d] = %d ", linha, coluna, matriz[linha][coluna]);
        }
        printf("\n");
    }


    return 0;
}
