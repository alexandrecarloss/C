#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>

using namespace std;
// gotoxy
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
 CursorPosition.X = x; // Locates column
 CursorPosition.Y = y; // Locates Row
 SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}
//ESTRUTURAS
struct Data{
   int dia, mes, ano;
};

struct Endereco {
    char logradouro[30], bairro[50], cidade[30], estado[15], cep[8];
    int numero;
};

struct Profissional {
   char matricula[20], cpf[11], nome[50], sigla[15], tipo[20], email[100], fone[15], codigo[15];
   struct Data nascimentoProf;
   int numReg, idade;
   Profissional *pProxProf, *pAntProf;
} inicio_profissional, *pAuxProf;

struct Cliente {
    char codigo[15], nome[50], email[100], fone[15], celular[15];
    struct Endereco endCliente;
    int idade;
    struct Data nascimento;
    Cliente *pProxCli, *pAntCli;
} inicio_cliente, *pAuxCli;

struct Atendimento {
    int numero;
    char matricula[15], codigo[10], descricao[500];
    struct Data dataAtendimento;
    Atendimento *pProxAten, *pAntAten;
} inicio_atendimento, *pAuxAten;

struct Proficao {
    char codigo[15], nome[50], sigla[10];
    Proficao *pProxProficao, *pAntProficao;
} inicio_proficao, *pAuxProficao;

//PROCEDIMENTOS

void gravarProfissional(Profissional *profissional, bool limpar = false){
    FILE *pont_arq;
    if(limpar) {
        pont_arq = fopen("profissional.txt", "w");
        return;
    } else{
        pont_arq = fopen("profissional.txt", "a");
    }
    if(pont_arq) {
        fprintf(pont_arq, "%s\n", profissional->matricula);
        fprintf(pont_arq, "%s\n", profissional->cpf);
        fprintf(pont_arq, "%s\n", profissional->nome);
        fprintf(pont_arq, "%d\n", profissional->numReg);
        fprintf(pont_arq, "%s\n", profissional->sigla);
        fprintf(pont_arq, "%s\n", profissional->tipo);
        fprintf(pont_arq, "%d\n", profissional->nascimentoProf.dia);
        fprintf(pont_arq, "%d\n", profissional->nascimentoProf.mes);
        fprintf(pont_arq, "%d\n", profissional->nascimentoProf.ano);
        fprintf(pont_arq, "%s\n", profissional->email);
        fprintf(pont_arq, "%s\n", profissional->fone);
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
    }
}

void profissionalCabecalho() {
    gotoxy(20, 5);
    cout << "Matrícula: ";
    gotoxy(20, 6);
    cout << "CPF: ";
    gotoxy(20, 7);
    cout << "Nome: ";
    gotoxy(20, 8);
    cout << "Código profissão: ";
    gotoxy(20, 9);
    cout << "Sigla: ";
    gotoxy(20, 10);
    cout << "Número registro: ";
    gotoxy(20, 11);
    cout << "Tipo: ";
    gotoxy(20, 12);
    cout << "Data de nascimento (dia mês ano): ";
    gotoxy(20, 13);
    cout << "E-mail: ";
    gotoxy(20, 14);
    cout << "Fone: ";
}

void recebeProfissional() {
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
    }
    pAuxProf->pProxProf = new Profissional;
    pAuxProf = pAuxProf->pProxProf;
    gotoxy(31, 5);
    gets(pAuxProf->matricula);
    gotoxy(25, 6);
    gets(pAuxProf->cpf);
    gotoxy(26, 7);
    gets(pAuxProf->nome);
    gotoxy(38, 8);
    gets(pAuxProf->codigo);
    //scanf(" %[^\n]", pAuxProf->codigo);
    gotoxy(27, 9);
    gets(pAuxProf->sigla);
    gotoxy(37, 10);
    //scanf("%d", &pAuxProf->numReg);
    cin >> pAuxProf->numReg;
    getchar();
    gotoxy(26, 11);
    gets(pAuxProf->tipo);
    gotoxy(54, 12);
    cin >> pAuxProf->nascimentoProf.dia;
    gotoxy(57, 12);
    cin >> pAuxProf->nascimentoProf.mes;
    gotoxy(60, 12);
    cin >> pAuxProf->nascimentoProf.ano;
    getchar();
    gotoxy(28, 13);
    gets(pAuxProf->email);
    gotoxy(26, 14);
    gets(pAuxProf->fone);
    gravarProfissional(pAuxProf);
}
void exibirProfissional(Profissional *profissional) { //Exibe o profissional indicado pela região de memória
    profissionalCabecalho();
    gotoxy(31, 5);
    cout << profissional->matricula;
    gotoxy(25, 6);
    cout << profissional->cpf;
    gotoxy(26, 7);
    cout << profissional->nome;
    gotoxy(38, 8);
    cout << profissional->codigo;
    gotoxy(27, 9);
    cout << profissional->sigla;
    gotoxy(37, 10);
    cout << profissional->numReg;
    gotoxy(26, 11);
    cout << profissional->tipo;
    gotoxy(54, 12);
    cout << profissional->nascimentoProf.dia << "/" << profissional->nascimentoProf.mes << "/" << profissional->nascimentoProf.ano;
    gotoxy(28, 13);
    cout << profissional->email;
    gotoxy(26, 14);
    cout << profissional->fone;
}

void exibirProfissionais() { //Exibe todos os profissionais
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
        system("cls");
        exibirProfissional(pAuxProf);
    }
}

void menuAlterarProfissional() { //Menu para escolher o atributo específico do profissional a ser alterado
    gotoxy(20, 3);
    cout << "MENU ALTERAR";
    gotoxy(20, 5);
    cout << "O que deseja alterar? ";
    gotoxy(15, 7);
    cout << "Cancelar - 0";
    gotoxy(15, 8);
    cout << "Matrícula - 1 ";
    gotoxy(15, 9);
    cout << "CPF - 2 ";
    gotoxy(15, 10);
    cout << "Nome - 3 ";
    gotoxy(15, 11);
    cout << "Número de registro - 4";
    gotoxy(15, 12);
    cout << "Sigla - 5 ";
    gotoxy(15, 13);
    cout << "Tipo - 6";
    gotoxy(15, 14);
    cout << "Data de nascimento - 7";
    gotoxy(15, 15);
    cout << "E-mail - 8";
    gotoxy(15, 16);
    cout << "Fone - 9";
}

void menuAlterarProfissionalEscolha(Profissional *profissional) { //altera um atributo específico do profissional
    int opcao;
    gotoxy(15, 17);
    cin >> opcao;
    getchar();
    switch(opcao) {
    case 0:
        break;
    case 1:
        gotoxy(20, 5);
        cout << "Matrícula: ";
        gets(profissional->matricula);
        break;
    case 2:
        gotoxy(20, 5);
        cout << "CPF: ";
        gets(profissional->cpf);
        break;
    case 3:
        gotoxy(20, 5);
        cout << "Nome: ";
        gets(profissional->nome);
        break;
    case 4:
        gotoxy(20, 5);
        cout << "Número de registro: ";
        cin >> profissional->numReg;
        break;
    case 5:
        gotoxy(20, 5);
        cout << "Sigla: ";
        gets(profissional->sigla);
        break;
    case 6:
        gotoxy(20, 5);
        cout << "Tipo: ";
        gets(profissional->tipo);
        break;
    case 7:
        gotoxy(20, 5);
        cout << "Data de nascimento (dia mês ano): ";
        gotoxy(54, 5);
        cin >> profissional->nascimentoProf.dia;
        gotoxy(57, 5);
        cin >> profissional->nascimentoProf.mes;
        gotoxy(60, 5);
        cin >> profissional->nascimentoProf.ano;
        break;
    case 8:
        gotoxy(20, 5);
        cout << "E-mail: ";
        gets(profissional->email);
        break;
    case 9:
        gotoxy(20, 5);
        cout << "Fone: ";
        gets(profissional->fone);
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    profissionalCabecalho();
    recebeProfissional();
    menuAlterarProfissional();
    menuAlterarProfissionalEscolha(pAuxProf);
    system("cls");
    exibirProfissionais();

    return 0;
}
