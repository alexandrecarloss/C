#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <time.h> //necess�rio para usar localtime() e struct
using namespace std;

/*
Objetivo: constru��o de um Sistema de Empr�stimo de Equipamentos
*/

typedef struct {
    int dia = NULL, mes = NULL, ano = NULL;
} data;

typedef struct {
    int minuto, horario;
} hora;

//defini��o da estrutura para setor
typedef struct {
   int codigo; //Primary key
   char fone[20];
   char nome[30];
} setor;

//defini��o da estrutura para servidor
typedef struct {
   int matricula, fone, *codSetor; //Matricula = Primary key, codSetor = Foreign key para setor
   char nome[30], cargo[2]; // Servidor: [T]: T�cnico Administrativo; [P]: Professor.
   data dataNasc;
} servidor;

//defini��o da estrutura para emprestimo
typedef struct {
    int numero, *matServidor; //numero = primary key, matServidor = foreign key para servidor
    data dataSaida;
    hora horaSaida;
    char encerrado[2]; // [N] n�o [S] sim  que quer dizer que todos equipamentos foram devolvidos.
} emprestimo;

//defini��o da estrutura para devolucao
typedef struct {
    int *numEmprestimo, *numEquipamento; //numEmprestimo + numEquipamento = primaary Key, numEmprestimo = foreign key para emprestimo, numEquipamento = foreign key para equipamento
    data dataDev; //Quando o valor de data em Devolucao for null, ou seja, data is null ent�o quer dizer que o equipamento ainda est� emprestado.
    hora horaDev;
} devolucao;

//Defini��o da estrutura para equipamento
typedef struct {
    int numero; //Primary key
    char nome[30], descricao[50], disponivel[2]; //Dispon�vel [N]: N�o; [S]: Sim, que pode ser emprestado.
} equipamento;

//Procedimento para preencher setor
void dadoSetor(setor *setor) {
    //Padr�o
    setor->codigo = 2;
    strcpy ( setor->fone, "12345678901" );
    strcpy ( setor->nome, "Aluno" );

    //Por leitura de teclado
    /*
    cout << "Informe o c�digo do setor: ";
    scanf("%d", &setor->codigo);
    getchar();//Usado para consumir o caractere de quebra de linha que a fun��o scanf() deixa no buffer

    cout << "Informe o nome do setor: ";
    gets(setor->nome);

    cout << "Informe o telefone do setor: ";
    gets(setor->fone);
    */
}

//Procedimento para imprimir setor
void imprimeSetor(setor setor) {
    cout << "\nInforma��es do setor";
    cout << "\nC�digo: " << setor.codigo;
    cout << "\nNome: " << setor.nome;
    cout << "\nFone: " << setor.fone;
}

//Procedimento para preencher dados de servidor
void dadoServidor(servidor *servidor, setor *setor) {
    //Padr�o
    servidor->matricula = 5;
    strcpy ( servidor->nome, "Servidor 1" );
    servidor->dataNasc.dia = 1;
    servidor->dataNasc.mes = 12;
    servidor->dataNasc.ano = 2000;
    strcpy(servidor->cargo, "T");
    servidor->codSetor = &setor->codigo;


    /*
    //Por leitura de teclado
    cout << "\nCadastro de servidor\n";
    cout << "Informe a matr�cula do servidor: ";
    scanf("%d", &servidor->matricula);
    getchar();//Usado para consumir o caractere de quebra de linha que a fun��o scanf() deixa no buffer
    cout << "Informe o nome do servidor: ";
    gets(servidor->nome);
    cout << "Informe o dia, m�s e ano de nascimento do servidor separados por espa�o: ";
    scanf("%d%d%d", &servidor->dataNasc.dia, &servidor->dataNasc.mes, &servidor->dataNasc.ano);
    getchar();
    cout << "Informe o cargo do servidor: \n[T] = T�cnico Administrativo \n[P] = Professor \n";
    scanf("%c", &servidor->cargo);
    getchar();
    servidor->codSetor = &setor->codigo;
    */
}

//Procedimento para imprimir dados do servidor
void impimeDadoServidor(servidor servidor) {
    cout << "\nInforma��es do servidor";
    cout << "\nMatricula: ";
    cout << servidor.matricula;
    cout << "\nNome: ";
    cout << servidor.nome;
    cout << "\nDataNasc: ";
    cout << servidor.dataNasc.dia;
    cout << "/";
    cout << servidor.dataNasc.mes;
    cout << "/";
    cout << servidor.dataNasc.ano;
    cout << "\nCargo: ";
    int comp;
    if((comp = strcmp(servidor.cargo, "T")) == 0) {
        cout << "T�cnico Administrativo";
    }
    if((comp = strcmp(servidor.cargo, "P")) == 0) {
        cout << "Professor";
    }
    cout << "\nCodSetor: " << *servidor.codSetor;
}

//Procedimento para preencher dados do empr�stimo
void dadoEmprestimo(emprestimo *emprestimo, servidor *servidor) {
    //Padr�o

    emprestimo->numero = 1;
    emprestimo->matServidor = &servidor->matricula;
    emprestimo->dataSaida.dia = 1;
    emprestimo->dataSaida.mes = 2;
    emprestimo->dataSaida.ano = 2023;
    emprestimo->horaSaida.horario = 12;
    emprestimo->horaSaida.minuto = 20;
    strcpy(emprestimo->encerrado, "S");

    /*
    //Por leitura de teclado
    cout << "\nDados de empr�stimo\n";
    cout << "Informe o n�mero do empr�stimo: ";
    scanf("%d", &emprestimo->numero);
    getchar();//Usado para consumir o caractere de quebra de linha que a fun��o scanf() deixa no buffer
    emprestimo->matServidor = &servidor->matricula;
    cout << "Informe o dia, m�s e ano da sa�da do equipamento separados por espa�o: ";
    scanf("%d%d%d", &emprestimo->dataSaida.dia, &emprestimo->dataSaida.mes, &emprestimo->dataSaida.ano);
    getchar();
    cout << "Informe a hora e minuto de sa�da separados por espa�o: ";
    scanf("%d%d", &emprestimo->horaSaida.horario, &emprestimo->horaSaida.minuto);
    getchar();
    cout << "Informe o estado do empr�stimo: \n[N] = N�o Encerrado \n[S] = Encerrado \n";
    scanf("%c", &emprestimo->encerrado);
    getchar();
    */
}

//Procedimento para imprimir dados do empr�stimo
void imprimeDadoEmprestimo(emprestimo emprestimo) {
    cout << "\nInforma��es do empr�stimo";
    cout << "\nN�mero: ";
    cout << emprestimo.numero;
    cout << "\nMatServidor: ";
    cout << *emprestimo.matServidor;
    cout << "\nDataSa�da: ";
    cout << emprestimo.dataSaida.dia;
    cout << "/";
    cout << emprestimo.dataSaida.mes;
    cout << "/";
    cout << emprestimo.dataSaida.ano;
    cout << "\nHoraSaida: ";
    cout <<  emprestimo.horaSaida.horario;
    cout << ":";
    cout << emprestimo.horaSaida.minuto;
    cout << "\nEstado: ";
    int comp;
    if((comp = strcmp(emprestimo.encerrado, "S")) == 0) {
        cout << "Encerrado";
    }
    if((comp = strcmp(emprestimo.encerrado, "N")) == 0) {
        cout << "N�o encerrado";
    }
}

//Procedimento para preencher dados de equipamento
void dadoEquipamento(equipamento *equipamento) {
    //Padr�o

    equipamento->numero = 9;
    strcpy(equipamento->nome, "Nome do equipamento 9");
    strcpy(equipamento->descricao, "Descri��o do equipamento 9");
    strcpy(equipamento->disponivel, "S"); //Indica que est� dispon�vel para empr�stimo

    /*
    //Por leitura de teclado
    cout << "\nDados de equipamento\n";
    cout << "Informe o n�mero do equipamento: ";
    scanf("%d", &equipamento->numero);
    getchar();//Usado para consumir o caractere de quebra de linha que a fun��o scanf() deixa no buffer
    cout << "Informe o nome do equipamento: ";
    gets(equipamento->nome);
    cout << "Informe a descri��o do equipamento: ";
    gets(equipamento->descricao);
    cout << "Informe o estado do equipamento: \n[N] = N�o dispon�vel \n[S] = Dispon�vel \n";
    scanf("%c", &equipamento->disponivel);
    getchar();
    */
}

//Procedimento para imprimir os dados do equipamento
void imprimeDadoEquipamento(equipamento equipamento) {
    cout << "\nInforma��es do equipamento";
    cout << "\nN�mero: ";
    cout << equipamento.numero;
    cout << "\nNome: ";
    cout << equipamento.nome;
    cout << "\nDescri��o: ";
    cout << equipamento.descricao;
    cout << "\nEstado: ";
    int comp;
    if((comp = strcmp(equipamento.disponivel, "S")) == 0) {
        cout << "Dispon�vel";
    }
    if((comp = strcmp(equipamento.disponivel, "N")) == 0) {
        cout << "N�o dispon�vel";
    }
}

//Procedimento para preencher dados de devolu��o
void dadoDevolucao(devolucao *devolucao, emprestimo *emprestimo, equipamento *equipamento) {
    //Padr�o

    devolucao->numEmprestimo = &emprestimo->numero;
    devolucao->numEquipamento = &equipamento->numero;
    devolucao->dataDev.dia = 1;
    devolucao->dataDev.mes = 3;
    devolucao->dataDev.ano = 2021;
    devolucao->horaDev.horario = 15;
    devolucao->horaDev.minuto = 53;

    /*
    //Por leitura de teclado
    cout << "\nDados de devolu��o\n";
    devolucao->numEmprestimo = &emprestimo.numero;
    devolucao->numEquipamento = &equipamento.numero;
    cout << "Informe o dia, m�s e ano da devolu��o do equipamento separados por espa�o: ";
    scanf("%d%d%d", &devolucao->dataDev.dia, &devolucao->dataDev.mes, &devolucao->dataDev.ano);
    getchar();
    cout << "Informe a hora e minuto de devolu��o separados por espa�o: ";
    scanf("%d%d", &devolucao->horaDev.horario, &devolucao->horaDev.minuto);
    getchar();
    */
}

//Procedimento para imprimir dados de devolu��o
void imprimeDadoDevolucao(devolucao devolucao) {
    cout << "\nInforma��es de devolu��o";
    cout << "\nN�mero empr�stimo: ";
    cout << *devolucao.numEmprestimo;
    cout << "\nN�mero equipamento: ";
    cout << *devolucao.numEquipamento;
    cout << "\nData devolu��o: ";
    cout << devolucao.dataDev.dia;
    cout << "/";
    cout << devolucao.dataDev.mes;
    cout << "/";
    cout << devolucao.dataDev.ano;
    cout << "\nHora devolu��o: ";
    cout <<  devolucao.horaDev.horario;
    cout << ":";
    cout <<  devolucao.horaDev.minuto;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    setor a;
    dadoSetor(&a);
    //imprimeSetor(a);
    servidor servidor;
    dadoServidor(&servidor, &a);
    //impimeDadoServidor(servidor);
    emprestimo emprestimo;
    dadoEmprestimo(&emprestimo, &servidor);
    //imprimeDadoEmprestimo(emprestimo);
    equipamento equipamento;
    dadoEquipamento(&equipamento);
    imprimeDadoEquipamento(equipamento);

    devolucao devolucao;

    dadoDevolucao(&devolucao, &emprestimo, &equipamento);
    imprimeDadoDevolucao(devolucao);

    return 0;
}
