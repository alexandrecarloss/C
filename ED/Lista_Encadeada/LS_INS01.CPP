/* Instituto Federal do Amazonas - IFAM
   Curso: Análise e Desenvolvimento de Sistemas
   Prof.: Sergio Augusto C. Bezerra
   Programa "LS_INS01.CPP" para exemplificar uma lista simplesmente encadeada
   para guardar a matricula e o nome dos alunos com duas notas de uma
   determinada disciplina, alem do calculo da media.
*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//#include <alloc>
#include <conio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}


/****************** VARIAVEIS GLOBAIS ******************/

   char resp;
   int linha,col;

   struct Aluno {
     int matricula;   /* numeros de 1 a no maximo 40 */
     char nome[50];
     float nota1, nota2, media;  /* valor da nota */
     struct Aluno *pProx; /* ponteiro para proxima nota */
   } inicio, *pAux;

/****************** FUNCAO PRINCIPAL ******************/


int main(void){

/*** Inicio da Lista ***/

   inicio.pProx = NULL; /* lista vazia */
   pAux = &inicio; /* aponta para o inicio da lista */

   do{
    system("cls");
     //clrscr();
     pAux->pProx = new(Aluno);
     pAux = pAux->pProx;
     gotoxy(3,5);
     cout << "PROGRAMA PARA GERENCIAR A MATRICULA, O NOME E AS NOTAS";
     cout << "\nDE UM ALUNO EM UMA DISCIPLINA USANDO UMA LISTA SIMPLESMENTE ENCADEADA\n";
     cout << "\nMatricula: ";
     cin >> pAux->matricula;
     cout << "\nNome do Aluno: ";
     gets(pAux->nome);
     cout << "\nNota1: ";
     cin >> pAux->nota1;
     cout << "\nNota2: ";
     cin >> pAux->nota2;
     pAux->media = (pAux->nota1 + pAux->nota2)/2;

     pAux->pProx = NULL;

     cout << "Deseja continuar? Sim[S] Nao[outra tecla]---->";
     resp = toupper(getch());
   }while (resp == 'S');

   /* Exibindo as notas da lista */

     system("cls");
     //clrscr();
     pAux = inicio.pProx;
     gotoxy(1,10);
     cout << "Matricula";
     gotoxy(15,10);
     cout << "Nome";
     gotoxy(50,10);
     cout << "Nota1";
     gotoxy(60,10);
     cout << "Nota2";
     gotoxy(70,10);
     cout << "Media";
     linha=12;
     while(pAux){
       gotoxy(1,linha);
       cout << pAux->matricula;
       gotoxy(15,linha);
       cout << pAux->nome;
       gotoxy(50,linha);
       cout << pAux->nota1;
       gotoxy(60,linha);
       cout << pAux->nota2;
       gotoxy(70,linha);
       cout << pAux->media;
       pAux = pAux->pProx;
       linha++;
     }

   getchar();
   printf("\nPressione uma tecla para terminar >>>>");
   getchar();
}
