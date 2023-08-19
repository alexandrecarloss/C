#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void) {
    setlocale(LC_ALL, "Portuguese");
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;

    //Abrindo arquivo
    pont_arq = fopen("arquivo.txt", "a");

    //Fechando arquivo
    fclose(pont_arq);

    //Mensagem para o usuário
    printf("O arquivo foi criado com sucesso!\n");
    system("pause");

    return 0;
}
