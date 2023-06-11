#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int i;
    for(i = 1; i<= 500; i++) {
        if((i % 2) == 0) {
            printf("N° par = %5i\n", i);
        } else {
            printf("N° ímpar = %3i\n", i);
        }
    }
    return 0;
}
