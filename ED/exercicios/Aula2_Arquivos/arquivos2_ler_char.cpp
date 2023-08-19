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
    char c;

    //Abrindo arquivo para gravação
    pont_arq = fopen("arquivo1.txt", "r");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo arquivo1.txt não pode ser abreto\n");
        exit(1); //Saindo do programa
    }

    printf("Lendo e exibindo os dados do arquivo\n\n");

    //Faça
    while((c = fgetc(pont_arq)) != EOF) {
        putchar(c);
    }
    /*
    do {
        //Faz a leitura do caractere do arquivo apontado por pont_arq
        c = fgetc(pont_arq);

        //Exibe o caractere lido na tela
        //printf("%c", c);
    } while(c != EOF); //Enquanto não for final de arquivo (End Of File)
*/


    //Fechando arquivo
    fclose(pont_arq);


    //system("pause");
    return 0;
}
