#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int cont = 0, i;
    while(cont < 10) {
        if((cont % 2) == 0) {
            printf("N° par = %i\n", cont);
        } else {
            for(i=0; i < 10; i++) {
                printf("Contador interno = %i\n", i+1);
            }

        }
        cont++;
    }
    return 0;
}
