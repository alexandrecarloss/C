#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>

using namespace std;

void gravar_aluno_arquivo(int pos) {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int tamString, i;
    pont_arq = fopen("aluno.txt", "a");
    if(pont_arq) {
        tamString = strlen(alunos[pos].nome);
        for(i = 0; i < tamString; i++) {
            if(alunos[pos].nome[i] == ' ') {
                alunos[pos].nome[i] = '_';
            }
        }
        fprintf(pont_arq, "%s \n", alunos[pos].nome);
        fprintf(pont_arq, "%s \n", alunos[pos].matricula_a);
        fprintf(pont_arq, "%s \n", alunos[pos].e_mail);
        fprintf(pont_arq, "%s \n", alunos[pos].turma);
        fprintf(pont_arq, "%s \n", alunos[pos].fone);
        fclose(pont_arq);
        printf("%s", alunos[pos].e_mail);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}

void ler_aluno_arquivo(int pos) {
    FILE *pont_arq;
    int tamString, i;
    int cont = 0;
    pont_arq = fopen("aluno.txt", "r");
    if(pont_arq){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(pont_arq, "%s%s%s%s%s", alunos[pos].nome, alunos[pos].matricula_a, alunos[pos].e_mail, alunos[pos].turma, alunos[pos].fone) != EOF) {
            for(i = 0; i <= tamString; i++) {
                if(alunos[pos].nome[i] == '_') {
                    //strcpy(nome[i], espaco);
                    alunos[pos].nome[i] = ' ';
                }
            }
            strcpy(alunos[cont].fone, alunos[pos].fone);
            strcpy(alunos[cont].e_mail, alunos[pos].e_mail);
            strcpy(alunos[cont].matricula_a, alunos[pos].matricula_a);
            strcpy(alunos[cont].turma, alunos[pos].turma);
            strcpy(alunos[cont].nome, alunos[pos].nome);
            printf("\nNome: %s\nMatrícula: %s \nE_mail: %s \nTurma: %s \nFone: %s\n", alunos[pos].nome, alunos[pos].matricula_a, alunos[pos].e_mail, alunos[pos].turma, alunos[pos].fone);
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

typedef struct {
   char	  nome[60], matricula_a[10], e_mail[60], turma[20],fone[15];
}Aluno;

Aluno alunos[3];


int main() {
    setlocale(LC_ALL, "Portuguese");
    int pos = 0;
    strcpy(alunos[pos].fone, "939205825");
    //strcpy(alunos[pos].e_mail, "gdgs");
    strcpy(alunos[pos].matricula_a, "2023020310");
    strcpy(alunos[pos].nome, "Carlos Alexandre Souza");
    strcpy(alunos[pos].turma, "TADS");
    //Criando uma variável ponteiro para o arquivo
    //printf("email: %s", alunos[pos].e_mail);
    FILE *pont_arq;
    int tamString, i;
    pont_arq = fopen("aluno.txt", "a");
    if(pont_arq) {
        tamString = strlen(alunos[pos].nome);
        for(i = 0; i < tamString; i++) {
            if(alunos[pos].nome[i] == ' ') {
                alunos[pos].nome[i] = '_';
            }
        }
        fprintf(pont_arq, "%s \n", alunos[pos].nome);
        fprintf(pont_arq, "%s \n", alunos[pos].matricula_a);
        //fprintf(pont_arq, "%s \n", alunos[pos].e_mail);
        fprintf(pont_arq, "%s \n", alunos[pos].turma);
        fprintf(pont_arq, "%s \n", alunos[pos].fone);
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }

    int cont = 0;
    pont_arq = fopen("aluno.txt", "r");
    if(pont_arq){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(pont_arq, "%s%s%s%s", alunos[pos].nome, alunos[pos].matricula_a, alunos[pos].turma, alunos[pos].fone) != EOF) {
            for(i = 0; i <= tamString; i++) {
                if(alunos[pos].nome[i] == '_') {
                    //strcpy(nome[i], espaco);
                    alunos[pos].nome[i] = ' ';
                }
            }
            cout << "Registro: " << cont;
            printf("\nNome: %s\nMatrícula: %s\nTurma: %s\nFone: %s\n", alunos[pos].nome, alunos[pos].matricula_a, alunos[pos].turma, alunos[pos].fone);
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
    return 0;
}
