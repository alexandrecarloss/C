#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    char palavra[20];//usado na leitura do arquivo

    //Abrindo arquivo
    pont_arq = fopen("arquivo_palavra.txt", "w");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo arquivo_palavra.txt não pode ser abreto\n");
        exit(1); //Saindo do programa
    }

    printf("Escreva uma palavra para testar a gravação do arquivo: ");
    scanf("%s", palavra);

    //usando fprintf para armazenar a string no arquivo
    fprintf(pont_arq, "%s \n", palavra);

    //Fechando arquivo
    fclose(pont_arq);

    printf("Dados gravados com sucesso!");
    return 0;
}
