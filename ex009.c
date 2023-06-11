#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: exibir a contagem regressiva de um número informado pelo usuário até 0 em cada linha
    //Definição de variáveis
    int num, i;

    //Entrada de dados
    printf("Informe o número que deseja ver na contagem regressiva: ");
    scanf("%i", &num);

    //Laço for
    for(i = num; i >= 0; i--) {
        printf("\n%i", i);
    }

    return 0;
}
