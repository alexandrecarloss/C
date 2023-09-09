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
    FILE *pont_arq;
    int i = 0, cont = 0;
    pont_arq = fopen("aluno.txt", "r");
    char linha[255];
    if(pont_arq) {
        while(fgets(linha, sizeof(linha), pont_arq)) {
            if(i == 0) {
                cout << "Registro: " << cont << " " << "Linha: " << i << " " << linha << endl;
                strcpy(alunos[cont].matricula_a, linha);
            }
            if(i == 1) {
                cout << "Registro: " << cont << " " << "Linha: " << i << " " << linha << endl;
                strcpy(alunos[cont].nome, linha);
            }
            if(i == 2) {
                cout << "Registro: " << cont << " " << "Linha: " << i << " " << linha << endl;
                strcpy(alunos[cont].e_mail, linha);
            }
            if(i == 3) {
                cout << "Registro: " << cont << " " << "Linha: " << i << " " << linha << endl;
                strcpy(alunos[cont].turma, linha);
            }
            if(i == 4) {
                cout << "Registro: " << cont << " " << "Linha: " << i << " " << linha << endl;
                strcpy(alunos[cont].fone, linha);
                i = -1;
                cont++;
            }
            i++;

        }
        fclose(pont_arq); /* fechar o arquivo */
    } else
        printf("\nERRO ao abrir arquivo!\n");
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    ler_aluno_arquivo();
    //cout << "Matricula " << alunos[0].matricula_a;
    cout << "Nome: " << alunos[0].nome;
    cout << "\nNome: " << alunos[1].nome;
    /*
    cout << "E_mail " << alunos[0].e_mail;
    cout << "Turma " << alunos[0].turma;
    cout << "Fone " << alunos[0].fone;
    */
    return 0;
}
