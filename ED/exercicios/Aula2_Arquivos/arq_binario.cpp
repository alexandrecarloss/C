#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void) {
    setlocale(LC_ALL, "Portuguese");
    char ch[15] = "Teste geral";
    int valor[15] = {1, 2, 3, 4, 6, 7, 8, 9,10, 12, 13, 14, 15};


    //Criando uma variável ponteiro para o arquivo
    FILE *ptrArq;

    //Abrindo arquivi
    ptrArq = fopen("binario.bin", "wb");

    if(ptrArq != NULL) {
        printf("Arquivo criado com sucesso!");
    } else {
        printf("\n\nErro: O arquivo binario.bin não pode ser abreto\n");
        system("pause");
        exit(1);
    }

    //Gravando os dados no arquivo usando a função fwrite
    //Sintaxe: fwrite(&variavel, numero_de_bytes, num_registros, arquivo);
    fwrite(ch, sizeof(char), 15, ptrArq);
    fwrite(valor, sizeof(int), 15, ptrArq);


    //Fechando arquivo
    fclose(ptrArq);

    system("pause");

    return 0;
}
