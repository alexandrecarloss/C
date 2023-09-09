#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
   char	  nome[60], matricula_a[10],e_mail[60], turma[20],fone[15];
}Aluno;

Aluno alunos[3];
int cont_aluno;
char nome[20], matricula[11], e_mail[30], turma[20], fone[15];
void gravar_aluno_arquivo(int pos) {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int i;
    pont_arq = fopen("aluno.txt", "a");
    if(pont_arq) {
        fprintf(pont_arq, "%s \n", alunos[pos].matricula_a);
        fprintf(pont_arq, "%s \n", gets(nome));
        fprintf(pont_arq, "%s \n", alunos[pos].e_mail);
        fprintf(pont_arq, "%s \n", alunos[pos].turma);
        fprintf(pont_arq, "%s \n", alunos[pos].fone);
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}

void ler_aluno_arquivo() {
    //FILE *pont_arq;
    int i, cont = 0;
    ifstream(pont_arq);
    pont_arq.open("aluno.txt");
    string linha;
    if(pont_arq) {
        while(!pont_arq.eof()) {

            getline(pont_arq, linha);
            //strcpy(alunos[cont].matricula_a, linha);
            cout << "linha " << linha << endl;
            getline(pont_arq, linha);
            //strcpy(alunos[cont].nome, linha);
            cout << "linha " << linha << endl;
            getline(pont_arq, linha);
            //strcpy(alunos[cont].e_mail, linha);
            cout << "linha " << linha << endl;
            getline(pont_arq, linha);
            //strcpy(alunos[cont].turma, linha);
            cout << "linha " << linha << endl;
            getline(pont_arq, linha);
            //strcpy(alunos[cont].fone, linha);
            cout << "linha " << linha << endl;
        }
        pont_arq.close();
    }

  /*
        while(c != EOF) {
            c = getchar(), pont_arq;
            cout << "a";
            fgets(nome, strlen(nome), pont_arq);
            cout << nome;
            strcpy(alunos[cont].nome, nome);
            /*
            fgets(matricula);

            fgets(pont_arq, e_mail);
            fgets(pont_arq, turma);
            fgets(pont_arq, fone);
            strcpy(alunos[cont].fone, matricula;
            strcpy(alunos[cont].e_mail, e_mail);
            strcpy(alunos[cont].matricula_a, matricula);
            strcpy(alunos[cont].turma, turma);



            //printf("\nNome: %s\nMatrícula: %s \nE_mail: %s \nTurma: %s \nFone: %s\n", alunos[cont].nome, alunos[cont].matricula_a, alunos[cont].e_mail, alunos[cont].turma, alunos[cont].fone);
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
        */
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    ler_aluno_arquivo();
    //cout << "Matricula " << alunos[0].matricula_a;
    cout << "Nome: " << alunos[0].nome;
    /*
    cout << "E_mail " << alunos[0].e_mail;
    cout << "Turma " << alunos[0].turma;
    cout << "Fone " << alunos[0].fone;
    */
    return 0;
}
