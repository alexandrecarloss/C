#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int i, num;


    printf("Quantos n�meros 1s voc� quer exibir? (m�ximo 100) ");
    scanf("%i", &num);
    if (num > 100) {
        printf("Valor excedeu o limite! Informe um valor at� 100");
    }
    printf(num);
    for(i = 1; i == num; i++) {
        printf("1 ");

    }
    return 0;
}
