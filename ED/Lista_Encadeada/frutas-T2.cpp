#include <iostream>
#include <stdio.h>
#include <new>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct Fruta {
     char nome[60], descricao[500];
     struct Fruta *pProx;
     int pesquisada;
} frutas, *pAux_fruta;

struct Dicionario {
     char inicial;
     int quant, pos;
     struct Dicionario *pProx;
     struct Dicionario *pAnt;
     Fruta inicio_fruta;
} inicio_dicio, *pAux_dicio;

//************************Variáveis globais
char palavra[60], inicial;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
 CursorPosition.X = x; // Locates column
 CursorPosition.Y = y; // Locates Row
 SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

void gravar(){
}

void ler(){
}//função onde devemos ordenar a partir do arquivo;

int inicial_existe(){
}//verificação da inicial para inserir

void inserir_fruta(){
    pAux_dicio = &inicio_dicio;
    gotoxy(0, 1);
    cout << "Informe a fruta que deseja inserir: ";
    gotoxy(0, 2);
    cout << "Descrição da fruta: ";
    gotoxy(37, 1);
    fflush(stdin);
    gets(palavra);
    while((pAux_dicio->pProx) && (pAux_dicio->inicial != palavra[0])){
        //cout << pAux_dicio->inicial;
        pAux_dicio = pAux_dicio->pProx;
    }
    cout << "Aqui";
    if(pAux_dicio->inicial != palavra[0]) { //Inicial não encontrada
        pAux_dicio->pProx = new Dicionario; //Cria novo nodo para essa inicial
        pAux_dicio = pAux_dicio->pProx;
        pAux_dicio->inicial = palavra[0];
        pAux_dicio->pProx = NULL;
    }
    //Validar palavra
    pAux_fruta = &pAux_dicio->inicio_fruta;
    while((pAux_fruta->pProx) && (strcmp(pAux_fruta->nome, palavra) != 0)) {
        pAux_fruta = pAux_fruta->pProx;
    }
    if(strcmp(pAux_fruta->nome, palavra) == 0) { //Palavra já inserida
        cout << "Fruta já inserida!";
    } else { //Cria espaço para nova fruta
        pAux_dicio->quant++;
        pAux_fruta->pProx = new Fruta;
        pAux_fruta = pAux_fruta->pProx;
        strcpy(pAux_fruta->nome, palavra);
        gotoxy(21, 2);
        fflush(stdin);
        gets(pAux_fruta->descricao);
        pAux_fruta->pesquisada = 0;
    }
    pAux_dicio = NULL;
    pAux_fruta = NULL;
}

Fruta* buscar(){
}

 void excluir_inicial(){
 }

 void excluir_fruta(){
 }

 void menu_excluir(){
 }

 void alterar(){
 }

 void exibir_inicial(){ //todas palavras de tal letra
    cout << "Inicial: ";
    cin >> inicial;
 }


  void exibir_fruta(){
  }


  void exibir_relevancia(){
  }//exibir quantas vezes foram buscadas todas da lista

    void listar_remisso(){
  }//exibir como tá no arquivo

  void menu_exibir(){
  }

 void ordenar(){
 }//escolhe como serão ordenadas as palavras(alfabética, criação e randomica);

void menu(){
    int op=1;
    do{
            system("cls");
       cout<<"\t\tO QUE DESEJA FAZER?\n";
       cout<<"SAIR-0\nINSERIR FRUTA(S)-1\nEXIBIR DICIONÁRIO-2\nEXCLUIR FRUTA(S)-3\nALTERAR FRUTA(S)-4\nPESQUISAR FRUTA-5\n:";
       cin>>op;
       switch(op){
       case 0:
           system("cls");
           cout<<"TCHAU";
       break;
       case 1:
           system("cls");
           inserir_fruta();
           system("pause");
       break;
       case 2:
           system("cls");
           system("pause");
       break;
       case 3:
           system("cls");
           system("pause");
       break;
       case 4:
           system("cls");
           system("pause");
       break;
       case 5:
           system("cls");
           system("pause");
       break;
       default:
        cout<<"\nOpção inválida, tente novamente!\n";
        system("pause");
       break;
       }
    }while(op!=0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
}
