#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char a[2] = "a";
    int resul = strcmp(a, "a");
    printf("%d", resul);
    return 0;
}
