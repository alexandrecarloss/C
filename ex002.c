#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char SENHA[8] = "esqueci2";
    char palpite[8];
    int comp;
    printf("Tente adivinhar a senha de 8 d�gitos com letras e n�meros: ");
    scanf("%s", &palpite);
    comp = strcmp(SENHA, palpite);
    if (comp < 0) {
        printf("Login aceito\n");
    } else {
        printf("Login falhou\n");
    }
    printf("O palpite � %s", palpite);

    return 0;
}
