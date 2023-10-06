/* Instituto Federal do Amazonas - IFAM
   Curso: Análise e Desenvolvimento de Sistemas
   Prof.: Sergio Augusto C. Bezerra
   Programa "LS_INS01.CPP" para exemplificar uma lista simplesmente encadeada
   para guardar a matricula e o nome dos alunos com duas notas de uma
   determinada disciplina, alem do calculo da media.
*/

#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y);
/****************** VARIAVEIS GLOBAIS ******************/
   char resp;
   int linha,col;

   struct Aluno {
     int matricula;   /* numeros de 1 a no maximo 40 */
     char nome[50];
     float nota1, nota2, media;  /* valor da nota */
     struct Aluno *pProx; /* ponteiro para proxima nota */
   } inicio, *pAux;

/****************** FUNCAO gotoXY posicionamento ******************/
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

/****************** FUNCAO PRINCIPAL ******************/

int main(){

/*** Inicio da Lista ***/

   inicio.pProx = NULL; /* lista vazia */
   pAux = &inicio; /* aponta para o inicio da lista */

   do{
     system("cls");
     pAux->pProx = new Aluno; //) (struct Aluno *) malloc(sizeof(struct Aluno)); //   new(Aluno);
     pAux = pAux->pProx;
     gotoXY(3,5);
     cout << "PROGRAMA PARA GERENCIAR A MATRICULA, O NOME E AS NOTAS";
     cout << "\nDE UM ALUNO EM UMA DISCIPLINA USANDO UMA LISTA SIMPLESMENTE ENCADEADA\n";
     cout << "\nMatricula: ";
     cin >> pAux->matricula;
     cout << "\nNome do Aluno: ";
     fflush(stdin);
     gets(pAux->nome);
     cout << "\nNota1: ";
     cin >> pAux->nota1;
     cout << "\nNota2: ";
     cin >> pAux->nota2;
     pAux->media = (pAux->nota1 + pAux->nota2)/2;

     pAux->pProx = NULL;

     cout << "Deseja continuar? Sim[S] Nao[outra tecla]---->";
     cin >> resp;
     resp = toupper(resp);
   }while (resp == 'S');

   /* Exibindo as notas da lista */

     system("cls");
     pAux = inicio.pProx;
     gotoXY(1,10);
     cout << "Matricula";
     gotoXY(15,10);
     cout << "Nome";
     gotoXY(50,10);
     cout << "Nota1";
     gotoXY(60,10);
     cout << "Nota2";
     gotoXY(70,10);
     cout << "Media";
     linha=12;
     while(pAux){
       gotoXY(1,linha);
       cout << pAux->matricula;
       gotoXY(15,linha);
       cout << pAux->nome;
       gotoXY(50,linha);
       cout << pAux->nota1;
       gotoXY(60,linha);
       cout << pAux->nota2;
       gotoXY(70,linha);
       cout << pAux->media;
       pAux = pAux->pProx;
       linha++;
     }
    printf("\n");
	system("pause");
   //printf("\nPressione uma tecla para terminar >>>>");
   return 0;
}


