#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int i;
    int num;
    int opera;
    int tipo;
    int resulsoma;

    printf("PROGRAMA DA TABUADA, INFORME O NÚMERO QUE VOCÊ QUE VER NA TABUADA\n");
    scanf("%i", &num);
    printf("Você quer a tabuada de qual operação? (1 para soma, 2 para subtração, 3 para multiplicação, 4 para divisão): ");
    scanf("%i", &opera);
    if(opera == 1);

    for(i = 1; i <= 10; i++) {
        resulsoma = num + i;

        printf("%i + %i = %i\n", num, i, resulsoma);
    }
    return 0;
}
