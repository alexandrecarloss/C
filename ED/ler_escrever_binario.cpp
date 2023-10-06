#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <windows.h>

using namespace std;
typedef struct {
   char	nome[60];
   int ano_aluno;
}Aluno;

Aluno aluno;



void gravarAluno(){
    FILE *pont_arq;
    pont_arq = fopen("aluno.txt", "w");
    if(pont_arq) {
        fprintf(pont_arq, "%s \n", aluno.nome);
        fprintf(pont_arq, "%d \n", aluno.ano_aluno);
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
    }
    system("pause");
}

void lerAluno(){
    FILE *pont_arq;
    pont_arq = fopen("aluno.txt", "r");
    int contarq = 0;
    char lido[500];
    if(pont_arq) {
        while(!feof(pont_arq)) {
            if(fgets(lido, 500, pont_arq)) {
                cout << lido;
                switch(contarq) {
                case 0:
                    strcpy(aluno.nome, lido);
                    break;
                case 1:
                    aluno.ano_aluno = atoi(lido);
                    contarq = -1;
                    break;
                }
                contarq++;
            }
        }
        cout << "\naluno: " << aluno.nome << aluno.ano_aluno;
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
    }
    system("pause");
}

void criarAluno(){
    cout << "Nome: ";
    scanf(" %[^\n]", aluno.nome);
    cout << "Ano: ";
    cin >> aluno.ano_aluno;
    cout << aluno.nome << " " << aluno.ano_aluno;
    gravarAluno();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    lerAluno();
    //criarAluno();
    return 0;
}
