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
    char texto_str[20];//usado na leitura do arquivo

    //Abrindo arquivo para somente leitura
    pont_arq = fopen("arquivo_palavra.txt", "r");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo arquivo_palavra.txt não pode ser abreto\n");
        exit(1); //Saindo do programa
    }

    //Enquanto não for fim de arquivo o Looping será executado
    //e será impresso o texto
    while(fgets(texto_str, 20, pont_arq) != NULL) {
        printf("%s\n", texto_str);
    }
    //Fechando arquivo
    fclose(pont_arq);

    system("pause");
    return 0;
}
