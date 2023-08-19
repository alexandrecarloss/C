#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void) {
    setlocale(LC_ALL, "Portuguese");

    //Exemplo de uso da função fputc(put character)
    //a cada chamada da função fputc grava um caractere no arquivo.
    setlocale(LC_ALL, "Portuguese");

    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    char frase[50];
    int i, tamanho;

    //Abrindo arquivo para gravação
    pont_arq = fopen("arquivo1.txt", "w");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo arquivo1.txt não pode ser abreto\n");
        exit(1); //Saindo do programa
    }

    printf("Digite a frase a ser gravada no arquivo!");
    gets(frase);

    //verificando a quantidade de caracteres da string frase
    tamanho = strlen(frase);

    //gravando caractere por caractere
    for(i=0; i < tamanho; i++) {
        fputc(frase[i], pont_arq);
    }

    //Fechando arquivo
    fclose(pont_arq);


    system("pause");
    return 0;
}
