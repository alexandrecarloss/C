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
    char nome[100], n[100];
    int idade, i;
    float altura, a;
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

    int cont = 0;
    pont_arq = fopen("teste.txt", "r");
    if(pont_arq){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(pont_arq, "%s%d%f", nome, &idade, &altura) != EOF) {
            cout << "Registro: " << cont;
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");


    int opcao = 0;
    cont = -1;
    pont_arq = fopen("teste.txt", "r+");
    cout << "qual o registro quer alterar? \n";
    scanf("%d", &opcao);
    if(pont_arq){
        while(fscanf(pont_arq, "%s%d%f", nome, &idade, &altura) != EOF) {
            if(cont == opcao) {
                printf("Digite nome, idade e altura: ");
                scanf("%100[^\n]%d%f", n, &i, &a);
                fprintf(pont_arq, "%s - %s\n", nome, "as");
                strcpy(n, nome);
                //fprintf(pont_arq, "%d \n", idade);
                //fprintf(pont_arq, "%.2f \n", altura);
                /*
                fprintf(pont_arq, "%s \n", nome);
                fprintf(pont_arq, "%d \n", idade);
                fprintf(pont_arq, "%.2f \n", altura);
                */
            }
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");



    return 0;
}
