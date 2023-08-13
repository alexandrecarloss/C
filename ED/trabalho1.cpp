#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <time.h> //necessário para usar localtime() e struct
using namespace std;

/*
Objetivo: construção de um Sistema de Empréstimo de Equipamentos
*/

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int minuto, horario;
} hora;

//definição da estrutura para setor
typedef struct {
   int codigo; //Primary key
   char fone[20];
   char nome[30];
} setor;

//definição da estrutura para servidor
typedef struct {
   int matricula, fone, *codSetor; //Matricula = Primary key, codSetor = Foreign key para setor
   char nome[30], cargo[2]; // Servidor: [T]: Técnico Administrativo; [P]: Professor.
   data dataNasc;
} servidor;

//definição da estrutura para emprestimo
typedef struct {
    int numero, *matServidor; //numero = primary key, matServidor = foreign key para servidor
    data dataSaida;
    hora horaSaida;
    char encerrado[2]; // [N] não [S] sim  que quer dizer que todos equipamentos foram devolvidos.
} emprestimo;

//definição da estrutura para devolucao
typedef struct {
    int *numEmprestimo, *numEquipamento; //numEmprestimo + numEquipamento = primaary Key, numEmprestimo = foreign key para emprestimo, numEquipamento = foreign key para equipamento
    data dataDev; //Quando o valor de data em Devolucao for null, ou seja, data is null então quer dizer que o equipamento ainda está emprestado.
    hora horario;
} devolucao;

//Definição da estrutura para equipamento
typedef struct {
    int *numero; //Primary key
    char nome[30], descricao[50], disponivel; //Disponível [N]: Não; [S]: Sim, que pode ser emprestado.
} equipamento;

//Procedimento para preencher setor
void dadoSetor(setor *setor) {
    //Padrão
    setor->codigo = 2;
    strcpy ( setor->fone, "12345678901" );
    strcpy ( setor->nome, "Aluno" );

    //Por leitura de teclado
    /*
    cout << "Informe o código do setor: ";
    scanf("%d", &setor->codigo);
    getchar();//Usado para consumir o caractere de quebra de linha que a função scanf() deixa no buffer

    cout << "Informe o nome do setor: ";
    gets(setor->nome);

    cout << "Informe o telefone do setor: ";
    gets(setor->fone);
    */
}

//Procedimento para imprimir setor
void imprimeSetor(setor setor) {
    cout << "\nInformações do setor";
    cout << "\nCódigo: " << setor.codigo;
    cout << "\nNome: " << setor.nome;
    cout << "\nFone: " << setor.fone;
}

//Procedimento para preencher dados de servidor
void dadoServidor(servidor *servidor, setor *setor) {
    //Padrão
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
    cout << "Informe a matrícula do servidor: ";
    scanf("%d", &servidor->matricula);
    getchar();//Usado para consumir o caractere de quebra de linha que a função scanf() deixa no buffer
    cout << "Informe o nome do servidor: ";
    gets(servidor->nome);
    cout << "Informe o dia, mês e ano de nascimento do servidor separados por espaço: ";
    scanf("%d%d%d", &servidor->dataNasc.dia, &servidor->dataNasc.mes, &servidor->dataNasc.ano);
    getchar();
    cout << "Informe o cargo do servidor: \n[T] = Técnico Administrativo \n[P] = Professor \n";
    scanf("%c", &servidor->cargo);
    getchar();
    servidor->codSetor = &setor->codigo;
    */
}

//Procedimento para imprimir dados do servidor
void impimeDadoServidor(servidor servidor) {
    cout << "\nInformações do servidor";
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
    if(comp = strcmp(servidor.cargo, "T") == 0) {
        cout << "Técnico Administrativo";
    }
    if(comp = strcmp(servidor.cargo, "P") == 0) {
        cout << "Professor";
    }
    cout << "\nCodSetor: " << *servidor.codSetor;
}

//Procedimento para preencher dados do empréstimo
void dadoEmprestimo(emprestimo *emprestimo, servidor *servidor) {
    //Padrão

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
    cout << "\nDados de empréstimo\n";
    cout << "Informe o número do empréstimo: ";
    scanf("%d", &emprestimo->numero);
    getchar();//Usado para consumir o caractere de quebra de linha que a função scanf() deixa no buffer
    emprestimo->matServidor = &servidor->matricula;
    cout << "Informe o dia, mês e ano da saída do equipamento separados por espaço: ";
    scanf("%d%d%d", &emprestimo->dataSaida.dia, &emprestimo->dataSaida.mes, &emprestimo->dataSaida.ano);
    cout << "Informe a hora e minuto de saída separados por espaço: ";
    scanf("%d%d", &emprestimo->horaSaida.horario, &emprestimo->horaSaida.minuto);
    getchar();
    cout << "Informe o estado do empréstimo: \n[N] = Não Encerrado \n[S] = Encerrado \n";
    scanf("%c", &emprestimo->encerrado);
    getchar();
    */
}

//Procedimento para imprimir dados do empréstimo
void imprimeDadoEmprestimo(emprestimo emprestimo) {
    cout << "\nInformações do empréstimo";
    cout << "\nNúmero: ";
    cout << emprestimo.numero;
    cout << "\nMatServidor: ";
    cout << *emprestimo.matServidor;
    cout << "\nDataSaída: ";
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
    if(comp = strcmp(emprestimo.encerrado, "S") == 0) {
        cout << "Encerrado";
    }
    if(comp = strcmp(emprestimo.encerrado, "N") == 0) {
        cout << "Não encerrado";
    }
}

//Procedimento para preencher dados de devolução
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
    imprimeDadoEmprestimo(emprestimo);
    devolucao d;
    equipamento e;

    return 0;
}
