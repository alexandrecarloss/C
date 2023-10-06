/* programa "alocmem1.c" para exemplificar a alocacao de memoria */
#include <stdio.h>
main(){

   int x, *p, *q;

   p = (int *) malloc(sizeof (int));
   *p = 5;
   q = p;
   printf("*p = %d  *q = %d\n", *p, *q);
   x = 10;
   *q = x;
   printf("*p = %d  *q = %d\n", *p, *q);
   p = (int *) malloc(sizeof (int));
   *p = 8;
   printf("*p = %d  *q = %d\n", *p, *q);

  
   getchar();
}
