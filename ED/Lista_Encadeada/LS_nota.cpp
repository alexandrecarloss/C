/* Instituto Federal do Amazonas - IFAM
   Curso: Análise e Desenvolvimento de Sistemas
   Prof.: Sergio Augusto C. Bezerra

   Programa "LS_nota.cpp" para exemplificar uma lista simplesmente encadeada
   para guardar uma sequência de notas */

#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

   char resp;
   float valor;

   struct ListaNota {
     float nota;  /* valor da nota */
     struct ListaNota *prox_nota; /* ponteiro para proxima nota */
   } inicio, *no;

   system("cls");;
   printf("PROGRAMA PARA GUARDAR NOTAS EM UMA LISTA SIMPLESMENTE ENCADEADA\n");



   inicio.prox_nota = NULL; /* lista vazia */
   no = &inicio; /* aponta para o inicio da lista */


   do{
     no->prox_nota = (struct ListaNota *) malloc(sizeof(struct ListaNota));
     no = no->prox_nota;
     printf("\nDigite a nota: ");
     scanf("%f", &valor);
     no->nota = valor;
     no->prox_nota = NULL;

     printf("Deseja continuar? Sim[S] Nao[outra tecla]---->");
     cin >> resp;
   }while (resp == 'S'||resp == 's'); 

   /* Exibindo as notas da lista */
   no = inicio.prox_nota;

   printf("\nLISTA DAS NOTAS: ");
   while(no){
     printf("%.1f\t", no->nota);
     no = no->prox_nota;
   }
   printf("\n");
   system("pause");
   return 0;
}
