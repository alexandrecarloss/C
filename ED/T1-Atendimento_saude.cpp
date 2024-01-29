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

int cont_linha;

//PROCEDIMENTOS
/****************** FUNCAO CONTADOR DE OCORRÊNCIA ******************/
int existe(char *str1, char *str2, int id) { //Passa a string que pode conter a substring, a substring e a posição em que começa a verificação
    int i, j = 0;
    for(i = id; i < strlen(str1); i++){ //Percorre a string da posição id até o final
        if(toupper(str1[i]) == toupper(str2[j])) //Se a letra atual é igual a letra da sobstring j++
            j++;
        else //Senão é uma palavra diferente e j = 0
            j = 0;
        if(j == strlen(str2)) //retorna a posição em que termina a substring na string
            return i;
    }
    return -1; //Não encontrou substring na string
}

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
        fprintf(pont_arq, "%s\n", profissional->codigo);
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
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Matrícula: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "CPF: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Nome: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Código profissão: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Sigla: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Número registro: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Tipo: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Data de nascimento (dia mês ano): ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "E-mail: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Fone: ";
    cont_linha = cont_linha - 10;
}

Profissional* escolherProfissional() { //Retorna um profissional escolhido ou nulo
    pAuxProf = &inicio_profissional;
    char chaveBuscar[50];
    int opcao, indice = 0;
    gotoxy(20, 5);
    cout << "Buscar por ";
    gotoxy(20, 6);
    cout << "Matrícula - 1";
    gotoxy(20, 7);
    cout << "CPF - 2";
    gotoxy(20, 8);
    cout << "Nome - 3";
    gotoxy(20, 9);
    cin >> opcao;
    getchar();
    switch(opcao) {
    case 1:
        gotoxy(20, 5);
        cout << "Matricula buscar: ";
        gets(chaveBuscar);
        while(pAuxProf->pProxProf) {
            pAuxProf = pAuxProf->pProxProf;
            indice = 0;
            indice = existe(pAuxProf->matricula, chaveBuscar, indice);
            if(indice != -1) {
                //exibirProfissional(pAuxProf);
                return pAuxProf;
                break;
            }
        }
        break;
    case 2:
        gotoxy(20, 5);
        cout << "CPF buscar: ";
        gets(chaveBuscar);
        while(pAuxProf->pProxProf) {
            pAuxProf = pAuxProf->pProxProf;
            indice = 0;
            indice = existe(pAuxProf->cpf, chaveBuscar, indice);
            if(indice != -1) {
                //exibirProfissional(pAuxProf);
                return pAuxProf;
                break;
            }
        }
        break;
    case 3:
        gotoxy(20, 5);
        cout << "Nome buscar: ";
        gets(chaveBuscar);
        while(pAuxProf->pProxProf) {
            pAuxProf = pAuxProf->pProxProf;
            indice = 0;
            indice = existe(pAuxProf->nome, chaveBuscar, indice);
            if(indice != -1) {
                //exibirProfissional(pAuxProf);
                return pAuxProf;
                break;
            }
        }
        break;
    default:
        gotoxy(20, 5);
        cout << "Opção inválida!";
        system("pause");
        break;
    }

}

void excluirProfissional(Profissional *profissinal) {
    if(profissinal) { //Se não for nulo
        pAuxProf = profissinal->pProxProf;
        pAuxProf->pAntProf = profissinal->pAntProf; //Proximo aponta para anterior
        profissinal->pAntProf->pProxProf = pAuxProf; //Anterior aponta para o próximo
        gravarProfissional(profissinal, 1); //Limpar registros

        //Salva os registros em arquivo
        pAuxProf = inicio_profissional.pProxProf;
        while(pAuxProf) {
            gravarProfissional(pAuxProf);
            pAuxProf = pAuxProf->pProxProf;
        }
    } else {
        cout << "Profissional não encontrado";
    }
}

bool verificaMatriculaProfissional(char chave[20]) {
    Profissional *pExisteProf;
    pExisteProf = &inicio_profissional;
    while(pExisteProf->pProxProf) {
        pExisteProf = pExisteProf->pProxProf;
        if(strcmp(chave, pExisteProf->matricula) == 0) {
            return true;
        }
    }
    return false;
}

void recebeProfissional() {
    char chave[20];
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
    }
    while(true) {
        system("cls");
        cont_linha = 4;
        profissionalCabecalho();
        gotoxy(31, 5);
        gets(chave);
        if(verificaMatriculaProfissional(chave)) {
            gotoxy(20, 15);
            cout << "Matrícula já existente!";
            system("pause");
        } else {
            pAuxProf->pProxProf = new Profissional;
            pAuxProf->pProxProf->pAntProf = pAuxProf;
            pAuxProf = pAuxProf->pProxProf;
            strcpy(pAuxProf->matricula, chave);
            break;
        }
    }
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
    cont_linha++;
    gotoxy(31, cont_linha);
    cout << profissional->matricula;
    cont_linha++;
    gotoxy(25, cont_linha);
    cout << profissional->cpf;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << profissional->nome;
    cont_linha++;
    gotoxy(38, cont_linha);
    cout << profissional->codigo;
    cont_linha++;
    gotoxy(27, cont_linha);
    cout << profissional->sigla;
    cont_linha++;
    gotoxy(37, cont_linha);
    cout << profissional->numReg;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << profissional->tipo;
    cont_linha++;
    gotoxy(54, cont_linha);
    cout << profissional->nascimentoProf.dia << "/" << profissional->nascimentoProf.mes << "/" << profissional->nascimentoProf.ano;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << profissional->email;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << profissional->fone;
}

void exibirProfissionais() { //Exibe todos os profissionais
    pAuxProf = &inicio_profissional;
    system("cls");
    cont_linha = 4;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
        profissionalCabecalho();
        exibirProfissional(pAuxProf);
    }
}

void menuAlterarProfissionalAtributo(Profissional *profissional) { //Altera um atributo específico do profissional
    int opcao;
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
    gotoxy(15, 17);
    cin >> opcao;
    getchar();
    switch(opcao) {
    case 0:
        break;
    case 1:
        char chave[20];
        while(true) {
            system("cls");
            gotoxy(20, 5);
            cout << "Matrícula: ";
            gotoxy(31, 5);
            gets(chave);
            if(verificaMatriculaProfissional(chave)) {
                gotoxy(20, 6);
                cout << "Matrícula já existente!";
                system("pause");
            } else {

                strcpy(profissional->matricula, chave);
                break;
            }
        }
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

void alterarProfissional(Profissional *profissional) {
    char chave[20];
    while(true) {
        system("cls");
        cont_linha = 4;
        profissionalCabecalho();
        gotoxy(31, 5);
        gets(chave);
        if(verificaMatriculaProfissional(chave)) {
            gotoxy(20, 15);
            cout << "Matrícula já existente!";
            system("pause");
        } else {
            strcpy(profissional->matricula, chave);
            break;
        }
    }
    gotoxy(25, 6);
    gets(profissional->cpf);
    gotoxy(26, 7);
    gets(profissional->nome);
    gotoxy(38, 8);
    gets(profissional->codigo);
    gotoxy(27, 9);
    gets(profissional->sigla);
    gotoxy(37, 10);
    cin >> profissional->numReg;
    getchar();
    gotoxy(26, 11);
    gets(profissional->tipo);
    gotoxy(54, 12);
    cin >> profissional->nascimentoProf.dia;
    gotoxy(57, 12);
    cin >> profissional->nascimentoProf.mes;
    gotoxy(60, 12);
    cin >> profissional->nascimentoProf.ano;
    getchar();
    gotoxy(28, 13);
    gets(profissional->email);
    gotoxy(26, 14);
    gets(profissional->fone);
    gravarProfissional(profissional);
}

void menuAlterarProfissinal() {
    int op;
    gotoxy(20, 5);
    cout << "Como deseja alterar?";
    gotoxy(20, 7);
    cout << "Tudo - 1";
    gotoxy(20, 8);
    cout << "Atributo - 2";
    gotoxy(20, 9);
    cin >> op;
    switch(op) {
    case 0:
        break;
    case 1:
        system("cls");
        alterarProfissional(escolherProfissional());
        break;
    case 2:
        system("cls");
        menuAlterarProfissionalAtributo(escolherProfissional());
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

bool comparaString(char *str1, char *str2) { //Retorna 1(true) se a primeira for maior e 0(false) se a segunda for maior ou iguais
    int menorTam;
    if(strlen(str1) > strlen(str2)) {
        menorTam = strlen(str2);
    } else {
        menorTam = strlen(str1);
    }
    for(int i = 0; i < menorTam; i++) {
        if(toupper(str1[i]) > toupper(str2[i])) {
            return true;
        } else if(toupper(str1[i]) < toupper(str2[i])) {
            return false;
        }
    }
    if(strlen(str1) > strlen(str2)) {
        return true;
    } else {
        return false;
    }
}

void trocarDadosProf(Profissional *pAtribui, Profissional *pRecebe) { //Troca os atributos de dois ponteiros de profissional
    int num;
    strcpy(pRecebe->matricula, pAtribui->matricula);
    strcpy(pRecebe->cpf, pAtribui->cpf);
    strcpy(pRecebe->nome, pAtribui->nome);
    strcpy(pRecebe->codigo, pAtribui->codigo);
    num = pRecebe->numReg;
    pRecebe->numReg = pAtribui->numReg;
    pAtribui->numReg = num;
    strcpy(pRecebe->sigla, pAtribui->sigla);
    strcpy(pRecebe->tipo, pAtribui->tipo);
    pRecebe->nascimentoProf = pAtribui->nascimentoProf;
    strcpy(pRecebe->email, pAtribui->email);
    strcpy(pRecebe->fone, pAtribui->fone);
}

void ordenarProfissional(int tipo = 1) { //Ordenar default 1 por matricula, 2 por cpf, 3 pro nome
    Profissional *pOrdProf, *pSubisProf = new Profissional;
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) {
        pAuxProf = pAuxProf->pProxProf;
        if(pAuxProf->pProxProf) {
            pOrdProf = pAuxProf->pProxProf;
            while(pOrdProf) {
                if(tipo == 1) {
                    if(comparaString(pAuxProf->matricula, pOrdProf->matricula)) {
                        //trocar
                        trocarDadosProf(pOrdProf, pSubisProf);
                        trocarDadosProf(pAuxProf, pOrdProf);
                        trocarDadosProf(pSubisProf, pAuxProf);
                    }
                } else if(tipo == 2) {
                    if(comparaString(pAuxProf->cpf, pOrdProf->cpf)) {
                        //trocar
                        trocarDadosProf(pOrdProf, pSubisProf);
                        trocarDadosProf(pAuxProf, pOrdProf);
                        trocarDadosProf(pSubisProf, pAuxProf);
                    }
                } else if(tipo == 3) {
                    if(comparaString(pAuxProf->nome, pOrdProf->nome)) {
                        //trocar
                        trocarDadosProf(pOrdProf, pSubisProf);
                        trocarDadosProf(pAuxProf, pOrdProf);
                        trocarDadosProf(pSubisProf, pAuxProf);
                    }
                }
                pOrdProf = pOrdProf->pProxProf;
            }
        }
    }
}

void menuExibirProfissinal() {
    int op;
    gotoxy(20, 5);
    cout << "Como deseja exibir?";
    gotoxy(20, 7);
    cout << "Tudo - 1";
    gotoxy(20, 8);
    cout << "Buscar por atributo - 2";
    gotoxy(20, 9);
    cin >> op;
    getchar();
    switch(op) {
    case 0:
        break;
    case 1:
        system("cls");
        exibirProfissionais();
        break;
    case 2:
        system("cls");
        exibirProfissional(escolherProfissional());
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

void menuProfissional() {
    int op;
    while(op != 0) {
        system("cls");
        gotoxy(20, 3);
        cout << "MENU PROFISSIONAL";
        gotoxy(20, 5);
        cout << "O que deseja fazer: ";
        gotoxy(20, 7);
        cout << "Voltar - 0";
        gotoxy(20, 8);
        cout << "Adicionar profissional - 1";
        gotoxy(20, 9);
        cout << "Exibir profissional - 2";
        gotoxy(20, 10);
        cout << "Alterar profissional - 3";
        gotoxy(20, 11);
        cout << "Remover profissional - 4";
        gotoxy(20, 12);
        cout << "Ordenar profissional - 5";
        gotoxy(20, 13);
        cin >> op;
        getchar();
        switch(op) {
        case 0:
            break;
        case 1:
            system("cls");
            cont_linha = 4;
            profissionalCabecalho();
            recebeProfissional();
            break;
        case 2:
            system("cls");
            menuExibirProfissinal();
            cout << "\n";
            system("pause");
            break;
        case 3:
            system("cls");
            menuAlterarProfissinal();
            break;
        case 4:
            system("cls");
            excluirProfissional(escolherProfissional());
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Opção inválida!";
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    menuProfissional();

    return 0;
}
