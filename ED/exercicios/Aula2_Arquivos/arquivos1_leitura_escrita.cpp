#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");
    //Criando uma vari�vel ponteiro para o arquivo
    FILE *pont_arq;
    int r;
    char texto_str[51];//usado na leitura do arquivo

    //Abrindo arquivo para grava��o
    pont_arq = fopen("arquivo2.txt", "w");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo arquivo2.txt n�o pode ser abreto\n");
        exit(1); //Saindo do programa
    }

    //Gravando no arquivo
    r = fputs("Programando em Linguagem C, verificando grava��o de texto.", pont_arq);

    //Verificando se os dados foram gravados com sucesso
    if(r == EOF) { //Na maioria dos sitemas EOF = -1
        printf("Erro ao tentar gravar os dados!\n");
    } else {
        printf("Dados gravados com sucesso!\n");
    }

    //Fechando arquivo
    fclose(pont_arq);

    printf("\nLeitura dos dados gravados no arquivo \n");
    //Abrindo o arquivo para leitura
    pont_arq = fopen("arquivo2.txt", "r");

    //Enquanto n�o for fim do arquivo o loop ser� executado
    //e ser� lido o conte�do do arquivo e impresso com printf

    while(fgets(texto_str, 50, pont_arq) != NULL) {
        printf("%s\n", texto_str);
    }

    //Fechando arquivo
    fclose(pont_arq);


    system("pause");
    return 0;
}
