#include<stdio.h>
#include<conio.h>
int main(void)
{
  char nome[61];

  printf("Digite seu nome: ");
  scanf("%s",nome);

  printf("O nome armazenado foi: %s", nome);

  getch();
  return 0;
}
/*#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char str1[2] = "ra", str2[15] = "b";
    int ret;

    ret = strcmp(str1, str2);
    printf("str1 = %c, str2 = %c ret = %i\n", str1, str2, ret);
    if(ret < 0) {
        printf("str1 is less then str2");
    } else if (ret > 0) {
        printf("str2 is less then str1");
    } else {
        printf("str1 is equal to str2");
    }
    return 0;
}
*/
/*#include <stdio.h>
#include <string.h>
#include <locale.h>
int main () {
    setlocale(LC_ALL, "Portuguese");
  char *str1 = "b";
  char *str2 = "a";
  int ret;

  ret = strcmp(str1, str2);

  if(ret > 0)
  {
    printf("str1 é maior");
  }
  else if(ret < 0)
  {
    printf("str2 é maior");
  }
  else
  {
    printf("As duas palavras são iguais");
  }

  printf("\nstr1 = %c, str2 = %c ret = %i\n", str1, str2, ret);
  return(0);
}
*/

