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

    printf("PROGRAMA DA TABUADA, INFORME O N�MERO QUE VOC� QUE VER NA TABUADA\n");
    scanf("%i", &num);
    printf("Voc� quer a tabuada de qual opera��o? (1 para soma, 2 para subtra��o, 3 para multiplica��o, 4 para divis�o): ");
    scanf("%i", &opera);
    if(opera == 1);

    for(i = 1; i <= 10; i++) {
        resulsoma = num + i;

        printf("%i + %i = %i\n", num, i, resulsoma);
    }
    return 0;
}
