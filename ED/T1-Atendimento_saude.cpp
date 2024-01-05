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
    cout << "Número registro: ";
    gotoxy(20, 10);
    cout << "Tipo: ";
    gotoxy(20, 11);
    cout << "Data de nascimento (dia mês ano): ";
    gotoxy(20, 12);
    cout << "E-mail: ";
    gotoxy(20, 13);
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
    gotoxy(37, 9);
    //scanf("%d", &pAuxProf->numReg);
    cin >> pAuxProf->numReg;
    getchar();
    gotoxy(26, 10);
    gets(pAuxProf->tipo);
    gotoxy(54, 11);
    cin >> pAuxProf->nascimentoProf.dia;
    gotoxy(57, 11);
    cin >> pAuxProf->nascimentoProf.mes;
    gotoxy(60, 11);
    cin >> pAuxProf->nascimentoProf.ano;
    getchar();
    gotoxy(28, 12);
    gets(pAuxProf->email);
    gotoxy(26, 13);
    gets(pAuxProf->fone);
}

void exibirProfissionais() {
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
        system("cls");
        profissionalCabecalho();
        gotoxy(31, 5);
        cout << pAuxProf->matricula;
        gotoxy(25, 6);
        cout << pAuxProf->cpf;
        gotoxy(26, 7);
        cout << pAuxProf->nome;
        gotoxy(38, 8);
        cout << pAuxProf->codigo;
        gotoxy(37, 9);
        cout << pAuxProf->numReg;
        gotoxy(26, 10);
        cout << pAuxProf->tipo;
        gotoxy(54, 11);
        cout << pAuxProf->nascimentoProf.dia << " " << pAuxProf->nascimentoProf.mes << " " << pAuxProf->nascimentoProf.ano;
        gotoxy(28, 12);
        cout << pAuxProf->email;
        gotoxy(26, 13);
        cout << pAuxProf->fone;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    profissionalCabecalho();
    recebeProfissional();
    system("cls");
    exibirProfissionais();
    return 0;
}
