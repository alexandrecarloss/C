#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    char nome[100];
    int idade;
    float altura;
    pont_arq = fopen("teste.txt", "a");
    if(pont_arq) {
        printf("Digite nome, idade e altura: ");
        scanf("%100[^\n]%d%f", nome, &idade, &altura);
        fprintf(pont_arq, "%s \n", nome);
        fprintf(pont_arq, "%d \n", idade);
        fprintf(pont_arq, "%.2f \n", altura);
        //fprintf(pont_arq, "%s %d %.2f\n", nome, idade, altura);
        fclose(pont_arq);
    } else
        printf("\nERRO ao abrir arquivo!\n");




    pont_arq = fopen("teste.txt", "r");
    if(pont_arq){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(pont_arq, "%s%d%f", nome, &idade, &altura) != -1)
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");




    return 0;
}
