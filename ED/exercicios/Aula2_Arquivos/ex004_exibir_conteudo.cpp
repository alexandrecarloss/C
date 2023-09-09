//lerarq.cpp
/* programa para exibir o conteúdo de um arquivo a
partir da linha de comando */
#include <stdio.h>
int main(int argc, char *argv[]){

int i;
FILE *pontarq; /* ponteiro do arquivo */
char linha[255]; /* linha do arquivo */
//clrscr();

if(( pontarq = fopen("teste.txt", "r")) == NULL)
    printf("Erro ao abrir o arquivo: %s \n", argv[1]);
else{
/* le e exibe cada linha do arquivo */
while(fgets(linha, sizeof(linha), pontarq))
    printf("%s", linha);

}
fclose(pontarq); /* fechar o arquivo */
printf("\nPressione qualquer tecla para sair! >>>");
getchar();
} /* fecha o programa principal */
