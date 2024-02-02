#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
#include <time.h>

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
} inicio_profissional, *pAuxProf, *pExcluiProf, *pLerProf;

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

/****************** FUNCAO SALVAR/LIMPAR PROFISSIONAL ******************/
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

/****************** FUNCAO LER ARQUIVO PROFISSIONAL ******************/
void lerProfissional() {
    char lido[500];
    int etapa=0;
    FILE *pont_arq;
    pont_arq = fopen("profissional.txt", "r");
    if(pont_arq) {
      pAuxProf = &inicio_profissional;
      while(!feof(pont_arq)) {
          if(fgets(lido, 500, pont_arq)) {
            lido[strlen(lido)-1] = '\0';
            switch(etapa) {
            case 0:
                pLerProf = &inicio_profissional;
                while(pLerProf->pProxProf) { //Percorre até o último registro
                    pLerProf = pLerProf->pProxProf;
                }
                pLerProf->pProxProf = new Profissional;// Cria um novo registro depois do último
                pLerProf->pProxProf->pAntProf = pLerProf; //Anterior do novo espaço recebe atual
                pLerProf = pLerProf->pProxProf; //Atual recebe próximo
                strcpy(pLerProf->matricula, lido);
            break;
            case 1:
                strcpy(pLerProf->cpf, lido);
                break;
            case 2:
                strcpy(pLerProf->nome, lido);
                break;
            case 3:
                strcpy(pLerProf->codigo, lido);
                break;
            case 4:
                pLerProf->numReg = atoi(lido);
                break;
            case 5:
                strcpy(pLerProf->sigla, lido);
                break;
            case 6:
                strcpy(pLerProf->tipo, lido);
                break;
            case 7:
                pLerProf->nascimentoProf.dia = atoi(lido);
                break;
            case 8:
                pLerProf->nascimentoProf.mes = atoi(lido);
                break;
            case 9:
                pLerProf->nascimentoProf.ano = atoi(lido);
                break;
            case 10:
                strcpy(pLerProf->email, lido);
                break;
            case 11:
                strcpy(pLerProf->fone, lido);
                etapa = -1;
                break;
            }
            etapa++;
          }
      }
    }

}

/****************** FUNCAO DE CABEÇALHO DE PROFISSIONAL ******************/
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

/****************** FUNCAO BUSCAR PROFISSIONAL POR MATRICULA, CPF OU NOME ******************/
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
    system("cls");
    switch(opcao) {
    case 1:
        gotoxy(20, 5);
        cout << "Matricula buscar: ";
        gets(chaveBuscar);
        while(pAuxProf->pProxProf) {
            pAuxProf = pAuxProf->pProxProf;
            indice = 0;
            indice = strcmp(pAuxProf->matricula, chaveBuscar);
            if(indice == 0) {
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
            indice = strcmp(pAuxProf->cpf, chaveBuscar);
            if(indice == 0) {
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
    system("cls");
}

/****************** FUNCAO ATUALIZAR PROFISSIONAL DA RAM PARA ARQUIVO ******************/
void resetarProfissional() {
    gravarProfissional(pExcluiProf, 1); //Limpar registros
    //Salva os registros em arquivo
    pExcluiProf = inicio_profissional.pProxProf;
    while(pExcluiProf) {
        gravarProfissional(pExcluiProf);
        pExcluiProf = pExcluiProf->pProxProf;
    }
}

/****************** FUNCAO EXCLUIR PROFISSIONAL ******************/
void excluirProfissional(Profissional *profissional) {
    if(profissional) {//Se não for nulo
        if(profissional->pProxProf) { //Não é o último da lista
            if(profissional->pAntProf != &inicio_profissional) { //Tem anterior
                pExcluiProf = profissional->pAntProf; //PExclui recebe o anterior do atual
                pExcluiProf->pProxProf = profissional->pProxProf; //Próximo do anterior recebe o proximo do atual
                profissional->pProxProf->pAntProf = pExcluiProf; //Anterior do próximo recebe anterior do atual
                delete profissional; //Exclui atual
            } else { //Não tem anterior
                inicio_profissional.pProxProf = profissional->pProxProf; //Início aponta para próximo do atual
                profissional->pProxProf->pAntProf = &inicio_profissional; //Anterior do próximo do atual aponta para início
                delete profissional;
            }
        } else { //É o último da lista
            if(profissional->pAntProf != &inicio_profissional) { // Tem anterior
                profissional->pAntProf->pProxProf = NULL; //Próximo do anterior recebe nulo
                delete profissional;
            } else { //Não tem anterior
                inicio_profissional.pProxProf = NULL;
                delete profissional;
            }
        }
        resetarProfissional();
    }
}

/****************** FUNCAO VALIDAR MATRÍCULA PROFISSIONAL ******************/
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

/****************** FUNCAO RECEBER PROFISSIONAL ******************/
void recebeProfissional() {
    char chave[20];
    pAuxProf = &inicio_profissional;
    while(pAuxProf->pProxProf) { //Percorre até o último registro da lista
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
            pAuxProf->pProxProf = new Profissional; //Cria um espaço no pPróximo do último
            pAuxProf->pProxProf->pAntProf = pAuxProf; //O pAnterior do novo espaço aponta para o atual
            pAuxProf = pAuxProf->pProxProf; //Atual aponta para o próximo
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

/****************** FUNCAO EXIBIR PROFISSIONAL ******************/
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

/****************** FUNCAO EXIBIR TODOS OS PROFISSIONAIS ******************/
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

/****************** FUNCAO MENU ALTERAR PROFISSIONAL ATRIBUTO ******************/
void menuAlterarProfissionalAtributo(Profissional *profissional) { //Altera um atributo específico do profissional
    int opcao;
    system("cls");
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

/****************** FUNCAO ALTERAR PROFISSIONAL TUDO ******************/
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
    resetarProfissional();
}

/****************** FUNCAO MENU ALTERAR PROFISSIONAL ******************/
void menuAlterarProfissinal() {
    int op;
    Profissional *pAltPro;
    gotoxy(20, 5);
    cout << "Como deseja alterar?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Tudo - 1";
    gotoxy(20, 9);
    cout << "Atributo - 2";
    gotoxy(20, 10);
    cin >> op;
    switch(op) {
    case 0:
        break;
    case 1:
        system("cls");
        pAltPro = escolherProfissional(); //Busca um profissional pela matricula, cpf ou nome
        system("cls");
        if(pAltPro) {
            cont_linha = 4;
            profissionalCabecalho();
            exibirProfissional(pAltPro);
            system("pause");
            system("cls");
            alterarProfissional(pAltPro);
        } else {
            cout << "Profissional não encontrado!";
            system("pause");
        }
        break;
    case 2:
        system("cls");
        pAltPro = escolherProfissional(); //Busca um profissional pela matricula, cpf ou nome
        system("cls");
        if(pAltPro) {
            system("cls");
            cont_linha = 4;
            profissionalCabecalho();
            exibirProfissional(pAltPro);
            system("pause");
            menuAlterarProfissionalAtributo(pAltPro);
        } else {
            cout << "Profissional não encontrado!";
            system("pause");
        }
        break;
    default:
        cout << "Opção inválida!";
        system("pause");
        break;
    }
}

/****************** FUNCAO COMPARA STRING PARA ORDENAÇÃO ******************/
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

/****************** FUNCAO TROCAR DADOS PROFISSIONAL ******************/
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

/****************** FUNCAO ORDENAR PROFISSIONAL ******************/
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

/****************** FUNCAO MENU EXIBIR PROFISSIONAL ******************/
void menuExibirProfissinal() {
    int op;
    Profissional *pExibePro;
    gotoxy(20, 5);
    cout << "Como deseja exibir?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Tudo - 1";
    gotoxy(20, 9);
    cout << "Buscar por atributo - 2";
    gotoxy(20, 10);
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
        pExibePro = escolherProfissional(); //Busca um profissional pela matricula, cpf ou nome
        system("cls");
        if(pExibePro) {
            cont_linha = 4;
            profissionalCabecalho();
            exibirProfissional(pExibePro);
        } else {
            cout << "Profissional não encontrado!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU EXCLUIR PROFISSIONAL ******************/
void menuExcluirProfissional() {
    int op;
    Profissional *pExcluiPro;
    gotoxy(20, 5);
    cout << "Como deseja excluir?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Tudo - 1";
    gotoxy(20, 9);
    cout << "Buscar por atributo - 2";
    gotoxy(20, 10);
    cin >> op;
    getchar();
    switch(op) {
    case 0:
        break;
    case 1:
        system("cls");
        pAuxProf = &inicio_profissional;
        while(pAuxProf->pProxProf) {
            pAuxProf = pAuxProf->pProxProf;
            excluirProfissional(pAuxProf);
        }
        break;
    case 2:
        system("cls");
        pExcluiPro = escolherProfissional(); //Busca um profissional pela matricula, cpf ou nome
        system("cls");
        if(pExcluiPro) {
            excluirProfissional(pExcluiPro);
        } else {
            cout << "Profissional não encontrado!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU ORDENAR PROFISSIONAL ******************/
void menuOrdenarProfissional() {
    int op;
    gotoxy(20, 5);
    cout << "Como deseja ordenar?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Por matrícula - 1";
    gotoxy(20, 9);
    cout << "Por cpf - 2";
    gotoxy(20, 10);
    cout << "Por nome - 3";
    gotoxy(20, 11);
    cin >> op;
    getchar();
    system("cls");
    switch(op) {
    case 0:
        break;
    case 1:
        ordenarProfissional();
        gotoxy(20, 5);
        cout << "ORDENADO POR MATRÍCULA\n";
        break;
    case 2:
        ordenarProfissional(2);
        gotoxy(20, 5);
        cout << "ORDENADO POR CPF\n";
        break;
    case 3:
        ordenarProfissional(3);
        gotoxy(20, 5);
        cout << "ORDENADO POR NOME\n";
        break;
    default:
        cout << "Opção inválida!\n";
        break;
    }
    system("pause");
}

/****************** FUNCAO MENU PROFISSIONAL ******************/
void menuProfissional() {
    int op;
    while(op != 0) {
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
            menuExcluirProfissional();
            break;
        case 5:
            system("cls");
            menuOrdenarProfissional();
            break;
        default:
            cout << "Opção inválida!";
            break;
        }
        system("cls");
    }
}

/****************** FUNCAO INFORMAÇÕES NA TELA ******************/
void informacoesTela() {
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    gotoxy(90, 3);
    printf("Data da sessão: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    lerProfissional();
    informacoesTela();
    menuProfissional();

    return 0;
}
