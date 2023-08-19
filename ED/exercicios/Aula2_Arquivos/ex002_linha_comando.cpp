//linhacom.cpp

#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
int main(int argc, char *argv[]){
    int i;
    //clrscr();
    cout << "\n Trabalhando com numero de argumentos na linha de comando";
    /* Exibindo a linha de comando */
    for (i=0; i<argc; ++i)
    cout << "\n argv[" << i << "] aponta para: " << argv[i];
    cout << "\n Pressione ENTER para sair! >>>";
    getch();
} /* fecha o programa principal */
