#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Objetivo: exibir a contagem regressiva de um n�mero informado pelo usu�rio at� 0 em cada linha
    //Defini��o de vari�veis
    int num, i;

    //Entrada de dados
    printf("Informe o n�mero que deseja ver na contagem regressiva: ");
    scanf("%i", &num);

    //La�o for
    for(i = num; i >= 0; i--) {
        printf("\n%i", i);
    }

    return 0;
}
