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

struct Profissao {
    char codigo[15], nome[50], sigla[10];
    Profissao *pProxProfissao, *pAntProfissao;
} inicio_profissao, *pAuxProfissao, *pLerProfissao, *pExcluiProfissao;

struct Profissional {
   char matricula[20], cpf[11], nome[50], tipo[20], email[100], fone[15];
   struct Data nascimentoProf;
   int numReg, idade;
   struct Profissao *profissao;
   Profissional *pProxProf, *pAntProf;
} inicio_profissional, *pAuxProf, *pExcluiProf, *pLerProf;

struct Cliente {
    char codigo[15], nome[50], email[100], fone[15], celular[15];
    struct Endereco endCliente;
    int idade;
    struct Data nascimento;
    Cliente *pProxCli, *pAntCli;
} inicio_cliente, *pAuxCli, *pLerCli, *pExcluiCli;

struct Atendimento {
    int numero;
    char matricula[15], codigo[15], descricao[500];
    struct Data dataAtendimento;
    Atendimento *pProxAten, *pAntAten;
} inicio_atendimento, *pAuxAten, *pLerAten, *pExcluiAten;



int cont_linha;
time_t mytime = time(NULL);
struct tm tm = *localtime(&mytime);

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

//////////////////////////////////////////////////////////////////////////////
                            //Profissão

/****************** FUNCAO SALVAR/LIMPAR PROFISSAO ******************/
void gravarProfissao(Profissao *profissao, bool limpar = false){
    FILE *pont_arq;
    if(limpar) {
        pont_arq = fopen("profissao.txt", "w");
        return;
    } else{
        pont_arq = fopen("profissao.txt", "a");
    }
    if(pont_arq) {
        fprintf(pont_arq, "%s\n", profissao->codigo);
        fprintf(pont_arq, "%s\n", profissao->nome);
        fprintf(pont_arq, "%s\n", profissao->sigla);
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
    }
}

/****************** FUNCAO LER ARQUIVO PROFISSAO ******************/
void lerProfissao() {
    char lido[500];
    int etapa=0;
    FILE *pont_arq;
    pont_arq = fopen("profissao.txt", "r");
    if(pont_arq) {
      pAuxProfissao = &inicio_profissao;
      while(!feof(pont_arq)) {
          if(fgets(lido, 500, pont_arq)) {
            lido[strlen(lido)-1] = '\0';
            switch(etapa) {
            case 0:
                pLerProfissao = &inicio_profissao;
                while(pLerProfissao->pProxProfissao) { //Percorre até o último registro
                    pLerProfissao = pLerProfissao->pProxProfissao;
                }
                pLerProfissao->pProxProfissao = new Profissao;// Cria um novo registro depois do último
                pLerProfissao->pProxProfissao->pAntProfissao = pLerProfissao; //Anterior do novo espaço recebe atual
                pLerProfissao = pLerProfissao->pProxProfissao; //Atual recebe próximo
                strcpy(pLerProfissao->codigo, lido);
            break;
            case 1:
                strcpy(pLerProfissao->nome, lido);
                break;
            case 2:
                strcpy(pLerProfissao->sigla, lido);
                pLerProfissao->pProxProfissao = NULL;
                etapa = -1;
                break;
            }
            etapa++;
          }
      }
    }
}

/****************** FUNCAO DE CABEÇALHO DE PROFISSAO ******************/
void profissaoCabecalho() {
    cont_linha++;
    gotoxy(20, cont_linha);
    for(int i = 0; i <= 40; i++) {
        cout << "-";
    }
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Código: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Nome: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Sigla: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    for(int i = 0; i <= 40; i++) {
        cout << "-";
    }
    cont_linha = cont_linha - 4;
}

/****************** FUNCAO BUSCAR PROFISSÃO POR CÓDIGO OU NOME ******************/
Profissao* escolherProfissao(bool inserir = false) { //Retorna um cliente escolhido ou nulo
    pAuxProfissao = &inicio_profissao;
    char chaveBuscar[50];
    int opcao, indice = 0;
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Buscar por ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Código - 1";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Nome - 2";
    cont_linha++;
    gotoxy(20, cont_linha);
    cin >> opcao;
    getchar();
    cont_linha++;
    //system("cls");
    switch(opcao) {
    case 1:
        gotoxy(20, cont_linha);
        cout << "Código buscar: ";
        gets(chaveBuscar);
        while(pAuxProfissao->pProxProfissao) {
            pAuxProfissao = pAuxProfissao->pProxProfissao;
            indice = 0;
            indice = strcmp(pAuxProfissao->codigo, chaveBuscar);
            if(indice == 0) {
                return pAuxProfissao;
                break;
            }
        }
        break;
    case 2:
        gotoxy(20, cont_linha);
        cout << "Nome buscar: ";
        gets(chaveBuscar);
        while(pAuxProfissao->pProxProfissao) {
            pAuxProfissao = pAuxProfissao->pProxProfissao;
            indice = 0;
            indice = existe(pAuxProfissao->nome, chaveBuscar, indice);
            if(indice != -1) {
                return pAuxProfissao;
                break;
            }
        }
        break;
    default:
        gotoxy(20, cont_linha);
        cout << "Opção inválida!";
        system("pause");
        break;
    }
    system("cls");
}

/****************** FUNCAO ATUALIZAR PROFISSÃO DA RAM PARA ARQUIVO ******************/
void resetarProfissao() {
    gravarProfissao(pExcluiProfissao, 1); //Limpar registros
    //Salva os registros em arquivo
    pExcluiProfissao = inicio_profissao.pProxProfissao;
    while(pExcluiProfissao) {
        gravarProfissao(pExcluiProfissao);
        pExcluiProfissao = pExcluiProfissao->pProxProfissao;
    }
}

/****************** FUNCAO EXCLUIR PROFISSÃO ******************/
void excluirProfissao(Profissao *profissao) {
    if(profissao) {//Se não for nulo
        if(profissao->pProxProfissao) { //Não é o último da lista
            if(profissao->pAntProfissao != &inicio_profissao) { //Tem anterior
                pExcluiProfissao = profissao->pAntProfissao; //PExclui recebe o anterior do atual
                pExcluiProfissao->pProxProfissao = profissao->pProxProfissao; //Próximo do anterior recebe o proximo do atual
                profissao->pProxProfissao->pAntProfissao = pExcluiProfissao; //Anterior do próximo recebe anterior do atual
                delete profissao; //Exclui atual
            } else { //Não tem anterior
                inicio_profissao.pProxProfissao = profissao->pProxProfissao; //Início aponta para próximo do atual
                profissao->pProxProfissao->pAntProfissao = &inicio_profissao; //Anterior do próximo do atual aponta para início
                delete profissao;
            }
        } else { //É o último da lista
            if(profissao->pAntProfissao != &inicio_profissao) { // Tem anterior
                profissao->pAntProfissao->pProxProfissao = NULL; //Próximo do anterior recebe nulo
                delete profissao;
            } else { //Não tem anterior
                inicio_profissao.pProxProfissao = NULL;
                delete profissao;
            }
        }
        resetarProfissao();
    }
}

/****************** FUNCAO VALIDAR CÓDIGO PROFISSÃO ******************/
bool verificaCodigoProfissao(char chave[20]) {
    Profissao *pExisteProfissao;
    pExisteProfissao = &inicio_profissao;
    while(pExisteProfissao->pProxProfissao) {
        pExisteProfissao = pExisteProfissao->pProxProfissao;
        if(strcmp(chave, pExisteProfissao->codigo) == 0) {
            return true;
        }
    }
    return false;
}

/****************** FUNCAO RECEBER PROFISSÃO ******************/
void recebeProfissao() {
    char chave[20];
    pAuxProfissao = &inicio_profissao;
    while(pAuxProfissao->pProxProfissao) { //Percorre até o último registro da lista
        pAuxProfissao = pAuxProfissao->pProxProfissao;
    }
    while(true) {
        //system("cls");
        //cont_linha = 4;
        profissaoCabecalho();
        cont_linha++;
        gotoxy(28, cont_linha);
        gets(chave);
        if(verificaCodigoProfissao(chave)) {
            gotoxy(20, 15);
            cout << "Código já existente!";
            system("pause");
        } else {
            pAuxProfissao->pProxProfissao = new Profissao; //Cria um espaço no pPróximo do último
            pAuxProfissao->pProxProfissao->pAntProfissao = pAuxProfissao; //O pAnterior do novo espaço aponta para o atual
            pAuxProfissao = pAuxProfissao->pProxProfissao; //Atual aponta para o próximo
            strcpy(pAuxProfissao->codigo, chave);
            break;
        }
    }
    cont_linha++;
    gotoxy(26, cont_linha);
    gets(pAuxProfissao->nome);
    cont_linha++;
    gotoxy(27, cont_linha);
    gets(pAuxProfissao->sigla);
    gravarProfissao(pAuxProfissao);
}

/****************** FUNCAO EXIBIR PROFISSÃO ******************/
void exibirProfissao(Profissao *profissao) {
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << profissao->codigo;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << profissao->nome;
    cont_linha++;
    gotoxy(27, cont_linha);
    cout << profissao->sigla;
}

/****************** FUNCAO EXIBIR TODAS AS PROFISSÕES ******************/
void exibirProfissoes() {
    pAuxProfissao = &inicio_profissao;
    //system("cls");
    //cont_linha = 4;
    while(pAuxProfissao->pProxProfissao) {
        pAuxProfissao = pAuxProfissao->pProxProfissao;
        profissaoCabecalho();
        exibirProfissao(pAuxProfissao);
    }
}

/****************** FUNCAO MENU ALTERAR PROFISSÃO ATRIBUTO ******************/
void menuAlterarProfissaoAtributo(Profissao *profissao) { //Altera um atributo específico de profissão
    int opcao;
    system("cls");
    gotoxy(20, 3);
    cout << "MENU ALTERAR";
    gotoxy(20, 5);
    cout << "O que deseja alterar? ";
    gotoxy(15, 7);
    cout << "Cancelar - 0";
    gotoxy(15, 8);
    cout << "Código - 1 ";
    gotoxy(15, 9);
    cout << "Nome - 2 ";
    gotoxy(15, 10);
    cout << "Sigla - 3 ";
    gotoxy(15, 11);
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
            cout << "Código: ";
            gotoxy(28, 5);
            gets(chave);
            if(verificaCodigoProfissao(chave)) {
                gotoxy(20, 6);
                cout << "Código já existente!";
                system("pause");
            } else {
                strcpy(profissao->codigo, chave);
                break;
            }
        }
        break;
    case 2:
        gotoxy(20, 5);
        cout << "Nome: ";
        gets(profissao->nome);
        break;
    case 3:
        gotoxy(20, 5);
        cout << "Sigla: ";
        gets(profissao->sigla);
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO ALTERAR PROFISSÃO TUDO ******************/
void alterarProfissao(Profissao *profissao) {
    char chave[20];
    while(true) {
        system("cls");
        cont_linha = 4;
        profissaoCabecalho();
        gotoxy(28, 5);
        gets(chave);
        if(verificaCodigoProfissao(chave)) {
            gotoxy(20, 15);
            cout << "Código já existente!";
            system("pause");
        } else {
            strcpy(profissao->codigo, chave);
            break;
        }
    }
    gotoxy(26, 6);
    gets(profissao->nome);
    gotoxy(27, 7);
    gets(profissao->sigla);
    resetarProfissao();
}

/****************** FUNCAO MENU ALTERAR PROFISSÃO******************/
void menuAlterarProfissao() {
    int op;
    Profissao *pAltProfissao;
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
        pAltProfissao = escolherProfissao(); //Busca uma profissão pela código ou nome
        system("cls");
        if(pAltProfissao) {
            cont_linha = 4;
            profissaoCabecalho();
            exibirProfissao(pAltProfissao);
            system("pause");
            system("cls");
            alterarProfissao(pAltProfissao);
        } else {
            cout << "Profissão não encontrada!";
            system("pause");
        }
        break;
    case 2:
        system("cls");
        pAltProfissao = escolherProfissao(); //Busca uma profissão pelo codigo ou nome
        system("cls");
        if(pAltProfissao) {
            system("cls");
            cont_linha = 4;
            profissaoCabecalho();
            exibirProfissao(pAltProfissao);
            system("pause");
            menuAlterarProfissaoAtributo(pAltProfissao);
        } else {
            cout << "Profissão não encontrada!";
            system("pause");
        }
        break;
    default:
        cout << "Opção inválida!";
        system("pause");
        break;
    }
}

/****************** FUNCAO TROCAR DADOS PROFISSÃO ******************/
void trocarDadosProfissao(Profissao *pAtribui, Profissao *pRecebe) { //Troca os atributos de dois ponteiros de profissão
    strcpy(pRecebe->codigo, pAtribui->codigo);
    strcpy(pRecebe->nome, pAtribui->nome);
    strcpy(pRecebe->sigla, pAtribui->sigla);
}

/****************** FUNCAO ORDENAR PROFISSÃO ******************/
void ordenarProfissao(int tipo = 1) { //Ordenar default 1 por codigo, 2 por nome
    Profissao *pOrdProfissao, *pSubsProfissao = new Profissao;
    pAuxProfissao = &inicio_profissao;
    while(pAuxProfissao->pProxProfissao) {
        pAuxProfissao = pAuxProfissao->pProxProfissao;
        if(pAuxProfissao->pProxProfissao) {
            pOrdProfissao = pAuxProfissao->pProxProfissao;
            while(pOrdProfissao) {
                if(tipo == 1) {
                    if(comparaString(pAuxProfissao->codigo, pOrdProfissao->codigo)) {
                        //trocar
                        trocarDadosProfissao(pOrdProfissao, pSubsProfissao);
                        trocarDadosProfissao(pAuxProfissao, pOrdProfissao);
                        trocarDadosProfissao(pSubsProfissao, pAuxProfissao);
                    }
                } else if(tipo == 2) {
                    if(comparaString(pAuxProfissao->nome, pOrdProfissao->nome)) {
                        //trocar
                        trocarDadosProfissao(pOrdProfissao, pSubsProfissao);
                        trocarDadosProfissao(pAuxProfissao, pOrdProfissao);
                        trocarDadosProfissao(pSubsProfissao, pAuxProfissao);
                    }
                pOrdProfissao = pOrdProfissao->pProxProfissao;
                }
            }
        }
    }
}

/****************** FUNCAO MENU EXIBIR PROFISSÃO ******************/
void menuExibirProfissao() {
    int op;
    Profissao *pExibeProfissao;
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
        exibirProfissoes();
        break;
    case 2:
        system("cls");
        pExibeProfissao = escolherProfissao();
        system("cls");
        if(pExibeProfissao) {
            cont_linha = 4;
            profissaoCabecalho();
            exibirProfissao(pExibeProfissao);
        } else {
            cout << "Profissão não encontrada!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU EXCLUIR PROFISSÃO ******************/
void menuExcluirProfissao() {
    int op;
    Profissao *pExcluiProfissao;
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
        pExcluiProfissao = &inicio_profissao;
        while(pExcluiProfissao->pProxProfissao) {
            pExcluiProfissao = pExcluiProfissao->pProxProfissao;
            excluirProfissao(pExcluiProfissao);
        }
        break;
    case 2:
        system("cls");
        pExcluiProfissao = escolherProfissao(); //Busca uma profissão pelo codigo ou nome
        system("cls");
        if(pExcluiProfissao) {
            excluirProfissao(pExcluiProfissao);
        } else {
            cout << "Profissão não encontrada!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU ORDENAR PROFISSÃO ******************/
void menuOrdenarProfissao() {
    int op;
    gotoxy(20, 5);
    cout << "Como deseja ordenar?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Por código - 1";
    gotoxy(20, 9);
    cout << "Por nome - 2";
    gotoxy(20, 10);
    cin >> op;
    getchar();
    system("cls");
    switch(op) {
    case 0:
        break;
    case 1:
        ordenarProfissao();
        gotoxy(20, 5);
        cout << "ORDENADO POR CÓDIGO\n";
        break;
    case 2:
        ordenarProfissao(2);
        gotoxy(20, 5);
        cout << "ORDENADO POR NOME\n";
        break;
    default:
        cout << "Opção inválida!\n";
        break;
    }
    system("pause");
}

/****************** FUNCAO MENU PROFISSÃO ******************/
void menuProfissao() {
    int op;
    while(op != 0) {
        gotoxy(20, 3);
        cout << "MENU PROFISSÃO";
        gotoxy(20, 5);
        cout << "O que deseja fazer: ";
        gotoxy(20, 7);
        cout << "Voltar - 0";
        gotoxy(20, 8);
        cout << "Adicionar profissão - 1";
        gotoxy(20, 9);
        cout << "Exibir profissão - 2";
        gotoxy(20, 10);
        cout << "Alterar profissão - 3";
        gotoxy(20, 11);
        cout << "Remover profissão - 4";
        gotoxy(20, 12);
        cout << "Ordenar profissão - 5";
        gotoxy(20, 13);
        cin >> op;
        getchar();
        switch(op) {
        case 0:
            break;
        case 1:
            system("cls");
            cont_linha = 4;
            profissaoCabecalho();
            recebeProfissao();
            break;
        case 2:
            system("cls");
            menuExibirProfissao();
            cont_linha = cont_linha+2;
            gotoxy(20, cont_linha);
            system("pause");
            break;
        case 3:
            system("cls");
            menuAlterarProfissao();
            break;
        case 4:
            system("cls");
            menuExcluirProfissao();
            break;
        case 5:
            system("cls");
            menuOrdenarProfissao();
            break;
        default:
            cout << "Opção inválida!";
            break;
        }
        system("cls");
    }
}

/****************** FUNCAO DE DEFINIR PROFISSÃO DO FUNCIONÁRIO ******************/
void SetProfissao(Profissional *profissional) {
    int op;
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "DEFINIR PROFISSÃO";
    exibirProfissoes();
    cont_linha++;
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Adicionar - 1";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Escolher - 2";
    cont_linha++;
    gotoxy(20, cont_linha);
    cin >> op;
    getchar();
    system("cls");
    cont_linha = 5;
    profissional->profissao = new Profissao;
    switch(op) {
    case 1:
        gotoxy(20, cont_linha);
        cout << "Insira uma profissão";
        cont_linha++;
        recebeProfissao();
        cont_linha++;
        pAuxProfissao = escolherProfissao();
        if(pAuxProfissao){
            trocarDadosProfissao(pAuxProfissao, profissional->profissao);
        }
        break;
    case 2:
        if(inicio_profissao.pProxProfissao) {
            pAuxProfissao = escolherProfissao();
            if(pAuxProfissao){
                trocarDadosProfissao(pAuxProfissao, profissional->profissao);
            }
        } else {
            gotoxy(20, cont_linha);
            cout << "Não existem profissões cadastradas insira uma profissão";
            cont_linha++;
            recebeProfissao();
            cont_linha++;
            pAuxProfissao = escolherProfissao();
            if(pAuxProfissao){
                trocarDadosProfissao(pAuxProfissao, profissional->profissao);
            }
        }
        break;
    default:
        cont_linha++;
        gotoxy(20, cont_linha);
        cout << "Opção inválida!";
        system("pause");
        system("cls");
        SetProfissao(profissional);
        break;
    }

}

/****************** FUNCAO ATRIBUIR PROFISSÃO POR CÓDIGO ******************/
Profissao* atribuirProfissao(char chaveBuscar[20]) {
    pAuxProfissao = &inicio_profissao;
    while(pAuxProfissao->pProxProfissao) {
        pAuxProfissao = pAuxProfissao->pProxProfissao;
        if(strcmp(pAuxProfissao->codigo, chaveBuscar) == 0) {
                cout<< pAuxProfissao->nome;
            return pAuxProfissao;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
                            //PROFISSIONAL

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
        fprintf(pont_arq, "%s\n", profissional->profissao->codigo);
        fprintf(pont_arq, "%d\n", profissional->numReg);
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
                //pLerProfissao = new Profissao;
                pLerProfissao = atribuirProfissao(lido);
                if(pLerProfissao) {
                    trocarDadosProfissao(pLerProfissao, pLerProf->profissao);
                    cout << pLerProf->profissao->nome;
                } else {
                    cout << "erro";
                }
                system("pause");
                break;
            case 4:
                pLerProf->numReg = atoi(lido);
                break;
            case 5:
                strcpy(pLerProf->tipo, lido);
                break;
            case 6:
                pLerProf->nascimentoProf.dia = atoi(lido);
                break;
            case 7:
                pLerProf->nascimentoProf.mes = atoi(lido);
                break;
            case 8:
                pLerProf->nascimentoProf.ano = atoi(lido);
                break;
            case 9:
                strcpy(pLerProf->email, lido);
                break;
            case 10:
                strcpy(pLerProf->fone, lido);
                etapa = -1;
                pLerProf->idade = tm.tm_year + 1900 - pLerProf->nascimentoProf.ano;
                if(pLerProf->nascimentoProf.mes > tm.tm_mon + 1) {
                    pLerProf->idade--;
                } else if(pLerProf->nascimentoProf.mes == tm.tm_mon + 1){
                    if(pLerProf->nascimentoProf.dia < tm.tm_mday) {
                        pLerProf->idade--;
                    }
                }
                break;
            }
            etapa++;
          }
      }
    }
}

/****************** FUNCAO DE CABEÇALHO DE PROFISSIONAL ******************/
void profissionalCabecalho(int tipo = 1) {
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
    cout << "Nome profissão: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Sigla profissão: ";
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
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Idade: ";
    cont_linha = cont_linha - 11;
}

/****************** FUNCAO DE CABEÇALHO DE PROFISSIONAL INSERIR ******************/
void profissionalCabecalhoInserir(int tipo = 1) {
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
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Profissão: ";
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
        profissionalCabecalhoInserir();
        cont_linha = 4;
        cont_linha++;
        gotoxy(31, cont_linha);
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
    cont_linha++;
    gotoxy(25, cont_linha);
    gets(pAuxProf->cpf);
    cont_linha++;
    gotoxy(26, cont_linha);
    gets(pAuxProf->nome);
    cont_linha++;
    gotoxy(37, cont_linha);
    cin >> pAuxProf->numReg;
    getchar();
    cont_linha++;
    gotoxy(26, cont_linha);
    gets(pAuxProf->tipo);
    cont_linha++;
    gotoxy(54, cont_linha);
    cin >> pAuxProf->nascimentoProf.dia;
    gotoxy(57, cont_linha);
    cin >> pAuxProf->nascimentoProf.mes;
    gotoxy(60, cont_linha);
    cin >> pAuxProf->nascimentoProf.ano;
    getchar();
    cont_linha++;
    gotoxy(28, cont_linha);
    gets(pAuxProf->email);
    cont_linha++;
    gotoxy(26, cont_linha);
    gets(pAuxProf->fone);
    pAuxProf->idade = tm.tm_year + 1900 - pAuxProf->nascimentoProf.ano;
    if(pAuxProf->nascimentoProf.mes > tm.tm_mon + 1) {
        pAuxProf->idade--;
    } else if(pAuxProf->nascimentoProf.mes == tm.tm_mon + 1){
        if(pAuxProf->nascimentoProf.dia < tm.tm_mday) {
            pAuxProf->idade--;
        }
    }
    cont_linha++;
    gotoxy(38, cont_linha);
    SetProfissao(pAuxProf);
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
    gotoxy(36, cont_linha);
    cout << profissional->profissao->codigo;
    cont_linha++;
    gotoxy(37, cont_linha);
    cout << profissional->profissao->sigla;
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
    cont_linha++;
    gotoxy(27, cont_linha);
    cout << profissional->idade;
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
    cout << "Profissão - 3 ";
    gotoxy(15, 12);
    cout << "Número de registro - 4";
    gotoxy(15, 13);
    cout << "Sigla - 5 ";
    gotoxy(15, 14);
    cout << "Tipo - 6";
    gotoxy(15, 15);
    cout << "Data de nascimento - 7";
    gotoxy(15, 16);
    cout << "E-mail - 8";
    gotoxy(15, 17);
    cout << "Fone - 9";
    gotoxy(15, 18);
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
        cout << "Profissão: ";
        pAuxProfissao = escolherProfissao();
        trocarDadosProfissao(pAuxProfissao, profissional->profissao);
        break;
    case 5:
        gotoxy(20, 5);
        cout << "Número de registro: ";
        cin >> profissional->numReg;
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
        profissional->idade = tm.tm_year + 1900 - profissional->nascimentoProf.ano;
        if(profissional->nascimentoProf.mes > tm.tm_mon + 1) {
            profissional->idade--;
        } else if(profissional->nascimentoProf.mes == tm.tm_mon + 1){
            if(profissional->nascimentoProf.dia < tm.tm_mday) {
                profissional->idade--;
            }
        }
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
    pAuxProfissao = escolherProfissao();
    trocarDadosProfissao(pAuxProfissao, profissional->profissao);
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
    profissional->idade = tm.tm_year + 1900 - profissional->nascimentoProf.ano;
    if(profissional->nascimentoProf.mes > tm.tm_mon + 1) {
        profissional->idade--;
    } else if(profissional->nascimentoProf.mes == tm.tm_mon + 1){
        if(profissional->nascimentoProf.dia < tm.tm_mday) {
            profissional->idade--;
        }
    }
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

/****************** FUNCAO TROCAR DADOS PROFISSIONAL ******************/
void trocarDadosProf(Profissional *pAtribui, Profissional *pRecebe) { //Troca os atributos de dois ponteiros de profissional
    int num;
    strcpy(pRecebe->matricula, pAtribui->matricula);
    strcpy(pRecebe->cpf, pAtribui->cpf);
    strcpy(pRecebe->nome, pAtribui->nome);
    pRecebe->profissao = pAtribui->profissao;
    num = pRecebe->numReg;
    pRecebe->numReg = pAtribui->numReg;
    pAtribui->numReg = num;
    strcpy(pRecebe->tipo, pAtribui->tipo);
    pRecebe->nascimentoProf = pAtribui->nascimentoProf;
    strcpy(pRecebe->email, pAtribui->email);
    strcpy(pRecebe->fone, pAtribui->fone);
}

/****************** FUNCAO ORDENAR PROFISSIONAL ******************/
void ordenarProfissional(int tipo = 1) { //Ordenar default 1 por matricula, 2 por cpf, 3 por nome
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
        pExcluiPro = &inicio_profissional;
        while(pExcluiPro->pProxProf) {
            pExcluiPro = pExcluiPro->pProxProf;
            excluirProfissional(pExcluiPro);
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
    gotoxy(90, 3);
    printf("Data da sessão: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}


//////////////////////////////////////////////////////////////////////////////
                            //Cliente
/****************** FUNCAO SALVAR/LIMPAR CLIENTE ******************/
void gravarCliente(Cliente *cliente, bool limpar = false){
    FILE *pont_arq;
    if(limpar) {
        pont_arq = fopen("cliente.txt", "w");
        return;
    } else{
        pont_arq = fopen("cliente.txt", "a");
    }
    if(pont_arq) {
        fprintf(pont_arq, "%s\n", cliente->codigo);
        fprintf(pont_arq, "%s\n", cliente->nome);
        fprintf(pont_arq, "%d\n", cliente->nascimento.dia);
        fprintf(pont_arq, "%d\n", cliente->nascimento.mes);
        fprintf(pont_arq, "%d\n", cliente->nascimento.ano);
        fprintf(pont_arq, "%s\n", cliente->email);
        fprintf(pont_arq, "%s\n", cliente->fone);
        fprintf(pont_arq, "%s\n", cliente->celular);
        fprintf(pont_arq, "%s\n", cliente->endCliente.logradouro);
        fprintf(pont_arq, "%d\n", cliente->endCliente.numero);
        fprintf(pont_arq, "%s\n", cliente->endCliente.bairro);
        fprintf(pont_arq, "%s\n", cliente->endCliente.cidade);
        fprintf(pont_arq, "%s\n", cliente->endCliente.estado);
        fprintf(pont_arq, "%s\n", cliente->endCliente.cep);
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
    }
}

/****************** FUNCAO LER ARQUIVO CLIENTE ******************/
void lerCliente() {
    char lido[500];
    int etapa=0;
    FILE *pont_arq;
    pont_arq = fopen("cliente.txt", "r");
    if(pont_arq) {
      pLerCli = &inicio_cliente;
      while(!feof(pont_arq)) {
          if(fgets(lido, 500, pont_arq)) {
            lido[strlen(lido)-1] = '\0';
            switch(etapa) {
            case 0:
                pLerCli = &inicio_cliente;
                while(pLerCli->pProxCli) { //Percorre até o último registro
                    pLerCli = pLerCli->pProxCli;
                }
                pLerCli->pProxCli = new Cliente;// Cria um novo registro depois do último
                pLerCli->pProxCli->pAntCli = pLerCli; //Anterior do novo espaço recebe atual
                pLerCli = pLerCli->pProxCli; //Atual recebe próximo
                strcpy(pLerCli->codigo, lido);
            break;
            case 1:
                strcpy(pLerCli->nome, lido);
                break;
            case 2:
                pLerCli->nascimento.dia = atoi(lido);
                break;
            case 3:
                pLerCli->nascimento.mes = atoi(lido);
                break;
            case 4:
                pLerCli->nascimento.ano = atoi(lido);
                break;
            case 5:
                strcpy(pLerCli->email, lido);
                break;
            case 6:
                strcpy(pLerCli->fone, lido);
                break;
            case 7:
                strcpy(pLerCli->celular, lido);
                break;
            case 8:
                strcpy(pLerCli->endCliente.logradouro, lido);
                break;
            case 9:
                pLerCli->endCliente.numero = atoi(lido);
                break;
            case 10:
                strcpy(pLerCli->endCliente.bairro, lido);
                break;
            case 11:
                strcpy(pLerCli->endCliente.cidade, lido);
                break;
            case 12:
                strcpy(pLerCli->endCliente.estado, lido);
                break;
            case 13:
                strcpy(pLerCli->endCliente.cep, lido);
                etapa = -1;
                pLerCli->idade = tm.tm_year + 1900 - pLerCli->nascimento.ano;
                if(pLerCli->nascimento.mes > tm.tm_mon + 1) {
                    pLerCli->idade--;
                } else if(pLerCli->nascimento.mes == tm.tm_mon + 1){
                    if(pLerCli->nascimento.dia < tm.tm_mday) {
                        pLerCli->idade--;
                    }
                }
                break;
            }
            etapa++;
          }
      }
    }

}

/****************** FUNCAO DE CABEÇALHO DE CLIENTE ******************/
void clienteCabecalho() {
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Código: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Nome: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Data de nascimento (dia mês ano): ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "E-mail: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Fone: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Celular: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Logradouro: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Número: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Bairro: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Cidade: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Estado: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "CEP: ";
    cont_linha++;
    gotoxy(20, cont_linha);
    cout << "Idade: ";
    cont_linha = cont_linha - 13;
}

/****************** FUNCAO BUSCAR CLIENTE POR CÓDIGO OU NOME ******************/
Cliente* escolherCliente() { //Retorna um cliente escolhido ou nulo
    pAuxCli = &inicio_cliente;
    char chaveBuscar[50];
    int opcao, indice = 0;
    gotoxy(20, 5);
    cout << "Buscar por ";
    gotoxy(20, 6);
    cout << "Código - 1";
    gotoxy(20, 7);
    cout << "Nome - 2";
    gotoxy(20, 8);
    cin >> opcao;
    getchar();
    system("cls");
    switch(opcao) {
    case 1:
        gotoxy(20, 5);
        cout << "Código buscar: ";
        gets(chaveBuscar);
        while(pAuxCli->pProxCli) {
            pAuxCli = pAuxCli->pProxCli;
            indice = 0;
            indice = strcmp(pAuxCli->codigo, chaveBuscar);
            if(indice == 0) {
                //exibirProfissional(pAuxProf);
                return pAuxCli;
                break;
            }
        }
        break;
    case 2:
        gotoxy(20, 5);
        cout << "Nome buscar: ";
        gets(chaveBuscar);
        while(pAuxCli->pProxCli) {
            pAuxCli = pAuxCli->pProxCli;
            indice = 0;
            indice = existe(pAuxCli->nome, chaveBuscar, indice);
            if(indice != -1) {
                //exibirProfissional(pAuxProf);
                return pAuxCli;
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

/****************** FUNCAO ATUALIZAR CLIENTE DA RAM PARA ARQUIVO ******************/
void resetarCliente() {
    gravarCliente(pExcluiCli, 1); //Limpar registros
    //Salva os registros em arquivo
    pExcluiCli = inicio_cliente.pProxCli;
    while(pExcluiCli) {
        gravarCliente(pExcluiCli);
        pExcluiCli = pExcluiCli->pProxCli;
    }
}

/****************** FUNCAO EXCLUIR CLIENTE ******************/
void excluirCliente(Cliente *cliente) {
    if(cliente) {//Se não for nulo
        if(cliente->pProxCli) { //Não é o último da lista
            if(cliente->pAntCli != &inicio_cliente) { //Tem anterior
                pExcluiCli = cliente->pAntCli; //PExclui recebe o anterior do atual
                pExcluiCli->pProxCli = cliente->pProxCli; //Próximo do anterior recebe o proximo do atual
                cliente->pProxCli->pAntCli = pExcluiCli; //Anterior do próximo recebe anterior do atual
                delete cliente; //Exclui atual
            } else { //Não tem anterior
                inicio_cliente.pProxCli = cliente->pProxCli; //Início aponta para próximo do atual
                cliente->pProxCli->pAntCli = &inicio_cliente; //Anterior do próximo do atual aponta para início
                delete cliente;
            }
        } else { //É o último da lista
            if(cliente->pAntCli != &inicio_cliente) { // Tem anterior
                cliente->pAntCli->pProxCli = NULL; //Próximo do anterior recebe nulo
                delete cliente;
            } else { //Não tem anterior
                inicio_cliente.pProxCli = NULL;
                delete cliente;
            }
        }
        resetarCliente();
    }
}

/****************** FUNCAO VALIDAR CÓDIGO CLIENTE ******************/
bool verificaCodigoCliente(char chave[20]) {
    Cliente *pExisteClie;
    pExisteClie = &inicio_cliente;
    while(pExisteClie->pProxCli) {
        pExisteClie = pExisteClie->pProxCli;
        if(strcmp(chave, pExisteClie->codigo) == 0) {
            return true;
        }
    }
    return false;
}

/****************** FUNCAO RECEBER CLIENTE ******************/
void recebeCliente() {
    char chave[20];
    pAuxCli = &inicio_cliente;
    while(pAuxCli->pProxCli) { //Percorre até o último registro da lista
        pAuxCli = pAuxCli->pProxCli;
    }
    while(true) {
        system("cls");
        cont_linha = 4;
        clienteCabecalho();
        gotoxy(28, 5);
        gets(chave);
        if(verificaCodigoCliente(chave)) {
            gotoxy(20, 15);
            cout << "Código já existente!";
            system("pause");
        } else {
            pAuxCli->pProxCli = new Cliente; //Cria um espaço no pPróximo do último
            pAuxCli->pProxCli->pAntCli = pAuxCli; //O pAnterior do novo espaço aponta para o atual
            pAuxCli = pAuxCli->pProxCli; //Atual aponta para o próximo
            strcpy(pAuxCli->codigo, chave);
            break;
        }
    }
    gotoxy(26, 6);
    gets(pAuxCli->nome);
    gotoxy(54, 7);
    cin >> pAuxCli->nascimento.dia;
    gotoxy(57, 7);
    cin >> pAuxCli->nascimento.mes;
    gotoxy(60, 7);
    cin >> pAuxCli->nascimento.ano;
    getchar();
    gotoxy(28, 8);
    gets(pAuxCli->email);
    gotoxy(26, 9);
    gets(pAuxCli->fone);
    gotoxy(29, 10);
    gets(pAuxCli->celular);
    gotoxy(32, 11);
    gets(pAuxCli->endCliente.logradouro);
    gotoxy(28, 12);
    cin >> pAuxCli->endCliente.numero;
    getchar();
    gotoxy(28, 13);
    gets(pAuxCli->endCliente.bairro);
    gotoxy(28, 14);
    gets(pAuxCli->endCliente.cidade);
    gotoxy(28, 15);
    gets(pAuxCli->endCliente.estado);
    gotoxy(25, 16);
    gets(pAuxCli->endCliente.cep);
    pAuxCli->idade = tm.tm_year + 1900 - pAuxCli->nascimento.ano;
    if(pAuxCli->nascimento.mes > tm.tm_mon + 1) {
        pAuxCli->idade--;
    } else if(pAuxCli->nascimento.mes == tm.tm_mon + 1){
        if(pAuxCli->nascimento.dia < tm.tm_mday) {
            pAuxCli->idade--;
        }
    }
    gravarCliente(pAuxCli);
}

/****************** FUNCAO EXIBIR CLIENTE ******************/
void exibirCliente(Cliente *cliente) { //Exibe o cliente indicado pela região de memória
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->codigo;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << cliente->nome;
    cont_linha++;
    gotoxy(54, cont_linha);
    cout << cliente->nascimento.dia << "/" << cliente->nascimento.mes << "/" << cliente->nascimento.ano;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->email;
    cont_linha++;
    gotoxy(26, cont_linha);
    cout << cliente->fone;
    cont_linha++;
    gotoxy(29, cont_linha);
    cout << cliente->celular;
    cont_linha++;
    gotoxy(32, cont_linha);
    cout << cliente->endCliente.logradouro;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->endCliente.numero;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->endCliente.bairro;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->endCliente.cidade;
    cont_linha++;
    gotoxy(28, cont_linha);
    cout << cliente->endCliente.estado;
    cont_linha++;
    gotoxy(25, cont_linha);
    cout << cliente->endCliente.cep;
    cont_linha++;
    gotoxy(27, cont_linha);
    cout << cliente->idade;
}

/****************** FUNCAO EXIBIR TODOS OS CLIENTES ******************/
void exibirClientes() { //Exibe todos os clientes
    pAuxCli = &inicio_cliente;
    system("cls");
    cont_linha = 4;
    while(pAuxCli->pProxCli) {
        pAuxCli = pAuxCli->pProxCli;
        clienteCabecalho();
        exibirCliente(pAuxCli);
    }
}

/****************** FUNCAO MENU ALTERAR CLIENTE ATRIBUTO ******************/
void menuAlterarClienteAtributo(Cliente *cliente) { //Altera um atributo específico do cliente
    int opcao;
    system("cls");
    gotoxy(20, 3);
    cout << "MENU ALTERAR";
    gotoxy(20, 5);
    cout << "O que deseja alterar? ";
    gotoxy(15, 7);
    cout << "Cancelar - 0";
    gotoxy(15, 8);
    cout << "Código - 1 ";
    gotoxy(15, 9);
    cout << "Nome - 2 ";
    gotoxy(15, 10);
    cout << "Data de nascimento - 3 ";
    gotoxy(15, 11);
    cout << "E-mail - 4";
    gotoxy(15, 12);
    cout << "Fone - 5 ";
    gotoxy(15, 13);
    cout << "Celular - 6";
    gotoxy(15, 14);
    cout << "Logradouro - 7";
    gotoxy(15, 15);
    cout << "Número - 8";
    gotoxy(15, 16);
    cout << "Bairro - 9";
    gotoxy(15, 17);
    cout << "Cidade - 10";
    gotoxy(15, 18);
    cout << "Estado - 11";
    gotoxy(15, 19);
    cout << "CEP - 12";
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
            cout << "Código: ";
            gotoxy(28, 5);
            gets(chave);
            if(verificaCodigoCliente(chave)) {
                gotoxy(20, 6);
                cout << "Código já existente!";
                system("pause");
            } else {
                strcpy(cliente->codigo, chave);
                break;
            }
        }
        break;
    case 2:
        gotoxy(20, 5);
        cout << "Nome: ";
        gets(cliente->nome);
        break;
    case 3:
        gotoxy(20, 5);
        cout << "Data de nascimento (dia mês ano): ";
        gotoxy(54, 5);
        cin >> cliente->nascimento.dia;
        gotoxy(57, 5);
        cin >> cliente->nascimento.mes;
        gotoxy(60, 5);
        cin >> cliente->nascimento.ano;
        cliente->idade = tm.tm_year + 1900 - cliente->nascimento.ano;
        if(cliente->nascimento.mes > tm.tm_mon + 1) {
            cliente->idade--;
        } else if(cliente->nascimento.mes == tm.tm_mon + 1){
            if(cliente->nascimento.dia < tm.tm_mday) {
                cliente->idade--;
            }
        }
        break;
    case 4:
        gotoxy(20, 5);
        cout << "E-mail: ";
        gets(cliente->email);
        break;
    case 5:
        gotoxy(20, 5);
        cout << "Fone: ";
        gets(cliente->fone);
        break;
    case 6:
        gotoxy(20, 5);
        cout << "Celular: ";
        gets(cliente->celular);
        break;
    case 7:
        gotoxy(20, 5);
        cout << "Logradouro: ";
        gets(cliente->endCliente.logradouro);
        break;
    case 8:
        gotoxy(20, 5);
        cout << "Número: ";
        cin >> cliente->endCliente.numero;
        break;
    case 9:
        gotoxy(20, 5);
        cout << "Bairro: ";
        gets(cliente->endCliente.bairro);
        break;
    case 10:
        gotoxy(20, 5);
        cout << "Cidade: ";
        gets(cliente->endCliente.cidade);
        break;
    case 11:
        gotoxy(20, 5);
        cout << "Estado: ";
        gets(cliente->endCliente.estado);
        break;
    case 12:
        gotoxy(20, 5);
        cout << "CEP: ";
        gets(cliente->endCliente.cep);
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO ALTERAR CLIENTE TUDO ******************/
void alterarCliente(Cliente *cliente) {
    char chave[20];
    while(true) {
        system("cls");
        cont_linha = 4;
        clienteCabecalho();
        gotoxy(28, 5);
        gets(chave);
        if(verificaCodigoCliente(chave)) {
            gotoxy(20, 15);
            cout << "Código já existente!";
            system("pause");
        } else {
            strcpy(cliente->codigo, chave);
            break;
        }
    }
    gotoxy(26, 6);
    gets(cliente->nome);
    gotoxy(54, 12);
    cin >> cliente->nascimento.dia;
    gotoxy(57, 12);
    cin >> cliente->nascimento.mes;
    gotoxy(60, 12);
    cin >> cliente->nascimento.ano;
    getchar();
    gotoxy(27, 7);
    gets(cliente->email);
    gotoxy(26, 8);
    gets(cliente->fone);
    gotoxy(29, 9);
    gets(cliente->celular);
    gotoxy(32, 10);
    gets(cliente->endCliente.logradouro);
    gotoxy(28, 10);
    cin >> cliente->endCliente.numero;
    gotoxy(28, 10);
    gets(cliente->endCliente.bairro);
    gotoxy(28, 10);
    gets(cliente->endCliente.cidade);
    gotoxy(28, 10);
    gets(cliente->endCliente.estado);
    gotoxy(25, 10);
    gets(cliente->endCliente.cep);

    cliente->idade = tm.tm_year + 1900 - cliente->nascimento.ano;
    if(cliente->nascimento.mes > tm.tm_mon + 1) {
        cliente->idade--;
    } else if(cliente->nascimento.mes == tm.tm_mon + 1){
        if(cliente->nascimento.dia < tm.tm_mday) {
            cliente->idade--;
        }
    }
    resetarCliente();
}

/****************** FUNCAO MENU ALTERAR CLIENTE ******************/
void menuAlterarCliente() {
    int op;
    Cliente *pAltCli;
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
        pAltCli = escolherCliente(); //Busca um cliente pela matricula ou nome
        system("cls");
        if(pAltCli) {
            cont_linha = 4;
            clienteCabecalho();
            exibirCliente(pAltCli);
            system("pause");
            system("cls");
            alterarCliente(pAltCli);
        } else {
            cout << "Cliente não encontrado!";
            system("pause");
        }
        break;
    case 2:
        system("cls");
        pAltCli = escolherCliente(); //Busca um cliente pela matricula ou nome
        system("cls");
        if(pAltCli) {
            system("cls");
            cont_linha = 4;
            clienteCabecalho();
            exibirCliente(pAltCli);
            system("pause");
            menuAlterarClienteAtributo(pAltCli);
        } else {
            cout << "Cliente não encontrado!";
            system("pause");
        }
        break;
    default:
        cout << "Opção inválida!";
        system("pause");
        break;
    }
}

/****************** FUNCAO TROCAR DADOS CLIENTE ******************/
void trocarDadosCliente(Cliente *pAtribui, Cliente *pRecebe) { //Troca os atributos de dois ponteiros de cliente
    strcpy(pRecebe->codigo, pAtribui->codigo);
    strcpy(pRecebe->nome, pAtribui->nome);
    pRecebe->nascimento = pAtribui->nascimento;
    strcpy(pRecebe->email, pAtribui->email);
    strcpy(pRecebe->fone, pAtribui->fone);
    strcpy(pRecebe->celular, pAtribui->celular);
    pRecebe->endCliente = pAtribui->endCliente;
}

/****************** FUNCAO ORDENAR CLIENTE ******************/
void ordenarCliente(int tipo = 1) { //Ordenar default 1 por codigo, 2 por nome
    Cliente *pOrdCli, *pSubsCli = new Cliente;
    pAuxCli = &inicio_cliente;
    while(pAuxCli->pProxCli) {
        pAuxCli = pAuxCli->pProxCli;
        if(pAuxCli->pProxCli) {
            pOrdCli = pAuxCli->pProxCli;
            while(pOrdCli) {
                if(tipo == 1) {
                    if(comparaString(pAuxCli->codigo, pOrdCli->codigo)) {
                        //trocar
                        trocarDadosCliente(pOrdCli, pSubsCli);
                        trocarDadosCliente(pAuxCli, pOrdCli);
                        trocarDadosCliente(pSubsCli, pAuxCli);
                    }
                } else if(tipo == 2) {
                    if(comparaString(pAuxCli->nome, pOrdCli->nome)) {
                        //trocar
                        trocarDadosCliente(pOrdCli, pSubsCli);
                        trocarDadosCliente(pAuxCli, pOrdCli);
                        trocarDadosCliente(pSubsCli, pAuxCli);
                    }
                pOrdCli = pOrdCli->pProxCli;
                }
            }
        }
    }
}

/****************** FUNCAO MENU EXIBIR CLIENTE ******************/
void menuExibirCliente() {
    int op;
    Cliente *pExibeCli;
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
        exibirClientes();
        break;
    case 2:
        system("cls");
        pExibeCli = escolherCliente(); //Busca um cliente pelo codigo ou nome
        system("cls");
        if(pExibeCli) {
            cont_linha = 4;
            clienteCabecalho();
            exibirCliente(pExibeCli);
        } else {
            cout << "Cliente não encontrado!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU EXCLUIR CLIENTE ******************/
void menuExcluirCliente() {
    int op;
    Cliente *pExcluiCli;
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
        pExcluiCli = &inicio_cliente;
        while(pExcluiCli->pProxCli) {
            pExcluiCli = pExcluiCli->pProxCli;
            excluirCliente(pExcluiCli);
        }
        break;
    case 2:
        system("cls");
        pExcluiCli = escolherCliente(); //Busca um cliente pelo código ou nome
        system("cls");
        if(pExcluiCli) {
            excluirCliente(pExcluiCli);
        } else {
            cout << "Cliente não encontrado!";
        }
        break;
    default:
        cout << "Opção inválida!";
        break;
    }
}

/****************** FUNCAO MENU ORDENAR CLIENTE ******************/
void menuOrdenarCliente() {
    int op;
    gotoxy(20, 5);
    cout << "Como deseja ordenar?";
    gotoxy(20, 7);
    cout << "Cancelar - 0";
    gotoxy(20, 8);
    cout << "Por código - 1";
    gotoxy(20, 9);
    cout << "Por nome - 2";
    gotoxy(20, 10);
    cin >> op;
    getchar();
    system("cls");
    switch(op) {
    case 0:
        break;
    case 1:
        ordenarCliente();
        gotoxy(20, 5);
        cout << "ORDENADO POR CÓDIGO\n";
        break;
    case 2:
        ordenarCliente(2);
        gotoxy(20, 5);
        cout << "ORDENADO POR NOME\n";
        break;
    default:
        cout << "Opção inválida!\n";
        break;
    }
    system("pause");
}

/****************** FUNCAO MENU CIENTE ******************/
void menuCliente() {
    int op;
    while(op != 0) {
        gotoxy(20, 3);
        cout << "MENU CLIENTE";
        gotoxy(20, 5);
        cout << "O que deseja fazer: ";
        gotoxy(20, 7);
        cout << "Voltar - 0";
        gotoxy(20, 8);
        cout << "Adicionar cliente - 1";
        gotoxy(20, 9);
        cout << "Exibir cliente - 2";
        gotoxy(20, 10);
        cout << "Alterar cliente - 3";
        gotoxy(20, 11);
        cout << "Remover cliente - 4";
        gotoxy(20, 12);
        cout << "Ordenar cliente - 5";
        gotoxy(20, 13);
        cin >> op;
        getchar();
        switch(op) {
        case 0:
            break;
        case 1:
            system("cls");
            cont_linha = 4;
            clienteCabecalho();
            recebeCliente();
            break;
        case 2:
            system("cls");
            menuExibirCliente();
            cout << "\n";
            system("pause");
            break;
        case 3:
            system("cls");
            menuAlterarCliente();
            break;
        case 4:
            system("cls");
            menuExcluirCliente();
            break;
        case 5:
            system("cls");
            menuOrdenarCliente();
            break;
        default:
            cout << "Opção inválida!";
            break;
        }
        system("cls");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    lerProfissao();
    lerProfissional();
    lerCliente();
    informacoesTela();
    //menuProfissao();
    menuProfissional();
    menuCliente();
    return 0;
}
