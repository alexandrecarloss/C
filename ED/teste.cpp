#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char a[10];
    strcpy(a, "a");
    int b = 1;
    strcat(a, b);

    printf("%s", a);
    return 0;
}
