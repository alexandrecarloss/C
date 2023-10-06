/* programa "alocmem2.c" para exemplificar a liberacao de memoria */
#include <stdio.h>
#include <stdlib.h>

int main(){

   int *p, *q;

   p = (int *) malloc(sizeof (int));
   *p = 20;
   printf("*p = %d \n", *p);
   q = (int *) malloc(sizeof (int));
   *q = 30;
   printf("*q = %d \n", *q);
   free(p);
   printf("*p = %d \n", *p);
   p = q;
   q = (int *) malloc(sizeof (int));
   *q = 50;
   printf("*p = %d  *q = %d\n", *p, *q);
 
   getchar();
   return 0;
}
