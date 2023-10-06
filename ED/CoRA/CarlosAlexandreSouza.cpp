#include <iostream> //BIBLIOTECAS UTILIZADAS
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 10
#define TAMPKEY 10
using namespace std;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int cont_exibe = 1, cont_disciplina, cont_turma, cont_aluno;

typedef struct {
   int dia, mes, ano;
} Data;

typedef struct {
   char	codigo[10], nome[60];
   int ch;
}Disciplina;

typedef struct {
   char	disCodigo[10], alunoMatricula[10];
   int ano, faltas, situacao;
   float media, nota1, nota2, nota3, nota4;
} Turma;


typedef struct {
   char	matricula[10], nome[60];
   Data dataNasc;
} Aluno;

Disciplina disciplinas[TAM];
Turma turmas[TAM];
Aluno alunos[TAM];

void gravar_disciplina_arquivo() {
    FILE *pont_arq;
    int i;
    pont_arq = fopen("disciplina.txt", "a");
    if(pont_arq) {
        for(int pos = 0; pos < cont_disciplina; pos++) {
            for(i = 0; i < strlen(disciplinas[pos].nome); i++) {
                if(disciplinas[pos].nome[i] == ' ') {
                    disciplinas[pos].nome[i] = '_';
                }
            }
            fprintf(pont_arq, "%s \n", disciplinas[pos].codigo);
            fprintf(pont_arq, "%s \n", disciplinas[pos].nome);
            fprintf(pont_arq, "%d \n", disciplinas[pos].ch);
        }
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}

void ler_disciplina_arquivo() {
    FILE *pont_arq;
    int i, cont = 0;
    pont_arq = fopen("disciplina.txt", "r");
    if(pont_arq){
        while(fscanf(pont_arq, "%s%s%i", disciplinas[cont].codigo, disciplinas[cont].nome, &disciplinas[cont].ch) != EOF) {
            for(i = 0; i <= strlen(disciplinas[cont].nome); i++) {
                if(disciplinas[cont].nome[i] == '_') {
                    disciplinas[cont].nome[i] = ' ';
                }
            }
            cont_disciplina++;
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");

}

void cadastrar_aluno(){
    cout<<"\t---CADASTRO DE ALUNO---:";
    int sair = 0;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nMatrícula: ";
        scanf(" %[^\n]", pkey);
        for(int contador = 0; contador <= cont_aluno; contador++){
            if(strcmp(alunos[contador].matricula, pkey)!=0){
                if(contador == cont_aluno) {
                   strcpy(alunos[contador].matricula, pkey);
                }
                sair = 1;
            } else {
                cout << "Matrícula já existe!";
                sair = 0;
                break;
            }
        }
    }
    cout<<"\nNome: ";
    scanf(" %[^\n]",alunos[cont_aluno].nome);
    cout << "\nData de Nascimento";
    cout << "\nDia: ";
    scanf("%d",&alunos[cont_aluno].dataNasc.dia);
    cout << "\nMês: ";
    scanf("%d",&alunos[cont_aluno].dataNasc.mes);
    cout << "\nAno: ";
    scanf("%d",&alunos[cont_aluno].dataNasc.ano);
    cont_aluno++;
}

void editar_aluno(){
    cout<<"\t---EDITOR DE ALUNO---:";
    if(cont_aluno > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nMatrícula do aluno que quer editar: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_aluno; contador++){
            if(strcmp(alunos[contador].matricula, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Aluno não encontrado!";
                sair = 0;
                break;
            }
        }
    }
    cout << "\nNovos Dados\n";
    cout<<"\nMatricula nova: ";
    scanf(" %[^\n]", alunos[contador].matricula);
    cout<<"\nNome: ";
    scanf(" %[^\n]",alunos[contador].nome);
    cout << "\nData de Nascimento";
    cout << "\nDia: ";
    scanf("%d",&alunos[contador].dataNasc.dia);
    cout << "\nMês: ";
    scanf("%d",&alunos[contador].dataNasc.mes);
    cout << "\nAno: ";
    scanf("%d",&alunos[contador].dataNasc.ano);
    }
}

void excluir_aluno() {
    if(cont_aluno > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nMatrícula do aluno que quer excluir: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_aluno; contador++){
            if(strcmp(alunos[contador].matricula, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Aluno não encontrado!";
                sair = 0;
                break;
            }
        }
    }
    for(int i = contador; i <= cont_aluno; i++) {
            if(i==TAM){
                strcpy(alunos[contador].matricula, "");
                strcpy(alunos[contador].nome, "");
                alunos[contador].dataNasc.dia = 0;
                alunos[contador].dataNasc.mes = 0;
                alunos[contador].dataNasc.ano = 0;
            }else{
                alunos[i]=alunos[i+1];
            }
    }
    cont_aluno--;
    }
}

void menuAluno() {
    int opcao=0;
        while(opcao != 4) {
        system("cls");
        cout << "\nCadastrar [1] \nEditar [2]\nExcluir [3]\nRetornar [4]\n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            system("cls");
            cadastrar_aluno();
            break;
        case 2:
            system("cls");
            editar_aluno();
            break;
        case 3:
            system("cls");
            excluir_aluno();
            break;
        case 4:
            break;
        default:
            cout << "Opção inválida!\n\n";
            system("pause");
            break;
        }
    }
}

void cadastrar_disciplina(){
    cout<<"\t---CADASTRO DE DISCIPLINA---:";
    int sair = 0;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nCodigo: ";
        scanf(" %[^\n]", pkey);
        for(int contador = 0; contador <= cont_disciplina; contador++){
            if(strcmp(disciplinas[contador].codigo, pkey)!=0){
                if(contador == cont_disciplina) {
                   strcpy(disciplinas[contador].codigo, pkey);
                }
                sair = 1;
            } else {
                cout << "Codigo já existe!";
                sair = 0;
                break;
            }
        }
    }
    cout<<"\nNome: ";
    scanf(" %[^\n]",disciplinas[cont_disciplina].nome);
    cout << "\nCH: ";
    scanf("%d",&disciplinas[cont_disciplina].ch);
    cont_disciplina++;
}

void editar_disciplina(){
    cout<<"\t---EDITOR DE ALUNO---:";
    if(cont_disciplina > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\ncodigo da disciplina que quer editar: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_disciplina; contador++){
            if(strcmp(disciplinas[contador].codigo, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Disciplina não encontrado!";
                sair = 0;
                break;
            }
        }
    }
    cout << "\nNovos Dados\n";
    cout<<"\nCodigo novo: ";
    scanf(" %[^\n]", disciplinas[contador].codigo);
    cout<<"\nNome: ";
    scanf(" %[^\n]",disciplinas[contador].nome);
    cout << "\nCH: ";
    scanf("%d",&disciplinas[contador].ch);
    }
}

void excluir_disciplina() {
    if(cont_disciplina > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nCodigo da disciplina que quer excluir: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_disciplina; contador++){
            if(strcmp(disciplinas[contador].codigo, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Disciplina não encontrado!";
                sair = 0;
                break;
            }
        }
    }
    for(int i = contador; i <= cont_disciplina; i++) {
            if(i==TAM){
                strcpy(disciplinas[contador].codigo, "");
                strcpy(disciplinas[contador].nome, "");
                disciplinas[contador].ch = 0;
            }else{
                disciplinas[i]=disciplinas[i+1];
            }
    }
    cont_disciplina--;
    }
}

void menuDisciplina() {
    int opcao=0;
        while(opcao != 4) {
        system("cls");
        cout << "\nCadastrar [1] \nEditar [2]\nExcluir [3]\nRetornar [4]\n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            system("cls");
            cadastrar_disciplina();
            break;
        case 2:
            system("cls");
            editar_disciplina();
            break;
        case 3:
            system("cls");
            excluir_disciplina();
            break;
        case 4:
            break;
        default:
            cout << "Opção inválida!\n\n";
            system("pause");
            break;
        }
    }
}

void cadastrar_turma(){
    if((cont_aluno > 0) && (cont_disciplina > 0)) {
    cout<<"\t---CADASTRO DE TURMA---:";
    int sair = 0;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nMatricula do aluno: ";
        scanf(" %[^\n]", pkey);
        for(int contador = 0; contador <= cont_turma; contador++){
            if(strcmp(turmas[contador].alunoMatricula, pkey)!=0){
                if(contador == cont_turma) {
                   strcpy(turmas[contador].alunoMatricula, pkey);
                }
                sair = 1;
            } else {
                cout << "Matricula já está na turma!";
                sair = 0;
                break;
            }
        }
    }
    while(sair != 1) {
        cout<<"\nCódigo do aluno: ";
        scanf(" %[^\n]", pkey);
        for(int contador = 0; contador <= cont_turma; contador++){
            if(strcmp(turmas[contador].disCodigo, pkey)!=0){
                if(contador == cont_turma) {
                   strcpy(turmas[contador].disCodigo, pkey);
                }
                sair = 1;
            } else {
                cout << "Código já está na turma!";
                sair = 0;
                break;
            }
        }
    }
    cout << "\nAno: ";
    cin >> turmas[cont_turma].ano;
    cout << "\nFaltas: ";
    cin >> turmas[cont_turma].faltas;
    cout << "\nNota 1: ";
    cin >> turmas[cont_turma].nota1;
    cout << "\nNota 2: ";
    cin >> turmas[cont_turma].nota2;
    cout << "\nNota 3: ";
    cin >> turmas[cont_turma].nota3;
    cout << "\nNota 4: ";
    cin >> turmas[cont_turma].nota4;
    turmas[cont_turma].media = ((turmas[cont_turma].nota1 + turmas[cont_turma].nota2 + turmas[cont_turma].nota3 + turmas[cont_turma].nota4) / 4);
    if(turmas[cont_turma].media >= 6) {
        turmas[cont_turma].situacao = 0;
    } else {
        turmas[cont_turma].situacao = 1;
    }
    cont_turma++;
    }
}

void editar_turma(){
    cout<<"\t---EDITOR DE TURMA---:";
    if(cont_turma > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nCodigo de algum aluno dessa turma: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_turma; contador++){
            if(strcmp(turmas[contador].disCodigo, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Código não encontrado!\n";
                sair = 0;
                break;
            }
        }
    }
    cout << "\nNovos Dados\n";
    cout<<"\nCodigo novo: ";
    scanf(" %[^\n]", turmas[contador].disCodigo);
    cout<<"\nMatricula do aluno: ";
    scanf(" %[^\n]", turmas[contador].alunoMatricula);

    cout << "\nAno: ";
    cin >> turmas[contador].ano;
    cout << "\nFaltas: ";
    cin >> turmas[contador].faltas;
    cout << "\nNota 1: ";
    cin >> turmas[contador].nota1;
    cout << "\nNota 2: ";
    cin >> turmas[contador].nota2;
    cout << "\nNota 3: ";
    cin >> turmas[contador].nota3;
    cout << "\nNota 4: ";
    cin >> turmas[contador].nota4;
    turmas[contador].media = ((turmas[contador].nota1 + turmas[contador].nota2 + turmas[contador].nota3 + turmas[contador].nota4) / 4);
    if(turmas[contador].media >= 6) {
        turmas[contador].situacao = 0;
    } else {
        turmas[contador].situacao = 1;
    }
    }
}

void excluir_turma() {
    if(cont_turma > 0) {
    int sair = 0, contador;
    char pkey[TAMPKEY];
    while(sair != 1) {
        cout<<"\nCodigo de aluno da turma que quer excluir: ";
        scanf(" %[^\n]", pkey);
        for(contador = 0; contador <= cont_turma; contador++){
            if(strcmp(turmas[contador].disCodigo, pkey)==0){
                sair = 1;
                break;
            } else {
                cout << "Turma não encontrado!";
                sair = 0;
                break;
            }
        }
    }
    for(int i = contador; i <= cont_turma; i++) {
            if(i==TAM){
            strcpy(turmas[contador].alunoMatricula, "");
            strcpy(turmas[contador].disCodigo, "");
            turmas[contador].ano = 0;
            turmas[contador].faltas = 0;
            turmas[contador].media = 0;
            turmas[contador].nota1 = 0;
            turmas[contador].nota2 = 0;
            turmas[contador].nota3 = 0;
            turmas[contador].nota4 = 0;
            turmas[contador].situacao = 0;
            }else{
            turmas[i]=turmas[i+1];
            }
    }
    cont_turma--;
    }
}

void menuTurma() {
    int opcao=0;
        while(opcao != 4) {
        system("cls");
        cout << "\nCadastrar [1] \nEditar [2]\nExcluir [3]\nRetornar [4]\n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            system("cls");
            cadastrar_turma();
            break;
        case 2:
            system("cls");
            editar_turma();
            break;
        case 3:
            system("cls");
            excluir_turma();
            break;
        case 4:
            break;
        default:
            cout << "Opção inválida!\n\n";
            system("pause");
            break;
        }
    }
}

void relatorio() {
    cout<<"\nLista de disciplina(s)\n";
    cout<<"----------------------------------\n";
    cout<<"| Código     |Nome                   | CH\n";
    cout<<"----------------------------------\n";
    int pos_linha = 6;
    for(int contador = 0; contador < cont_disciplina; contador++) {
        gotoxy(1, pos_linha + contador);
        printf("%s", disciplinas[contador].codigo);
        gotoxy(15, pos_linha + contador);
        printf("%s      ", disciplinas[contador].nome);
        gotoxy(40, pos_linha + contador);
        printf("%d\n", disciplinas[contador].ch);

    }
    system("pause");
}

void menu() {
    int opcao=0;
        while(opcao != 5) {
        system("cls");
        cout << "Menu principal";
        cout << "\nAluno [1] \nDisciplina [2]\nTurma [3]\nRelatório [4]\nSair [5]\n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            system("cls");
            menuAluno();
            break;
        case 2:
            system("cls");
            menuDisciplina();
            break;
        case 3:
            system("cls");
            menuTurma();
            break;
        case 4:
            system("cls");
            relatorio();
            break;
        case 5:
            break;
        default:
            cout << "Opção inválida!\n\n";
            system("pause");
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    ler_disciplina_arquivo();
    menu();
    gravar_disciplina_arquivo();
    return 0;
}
