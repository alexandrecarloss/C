#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char nome[30];
    scanf("%s", &nome);
    printf(nome);
    return 0;
}
