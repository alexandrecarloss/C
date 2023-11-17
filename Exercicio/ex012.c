#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int num, i;
    printf("Informe o número da tabuada: ");
    scanf("%d", &num);
    for(i = 1; i <= 10; i++) {
        printf("\n%2d X %2i = %4i", num, i, i * num);


    }
    printf("\n");
    system("pause");
    return 0;
}
