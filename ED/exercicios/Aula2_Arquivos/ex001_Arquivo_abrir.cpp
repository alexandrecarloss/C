//abrearq.cpp
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    FILE *pontarq; /* define um ponteiro para a estrutura FILE */
    /* abre o arquivo e faz o ponteiro apontar p/ o buffer */
    pontarq = fopen("TEXTO.txt", "r");
    if(pontarq == NULL)
    cout << "\nErro ao abrir o arquivo";
    else{
    cout << "\nO arquivo foi aberto com sucesso!";
    /* fecha o arquivo */
    fclose(pontarq);
    }
    cout << "\nPressione qualquer teclar para sair! >>>";
    getchar();
    return 0;
}
