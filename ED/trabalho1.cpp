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

void data_hora() {
    //definição da estrutura para data
    //ponteiro para struct que armazena data e hora
  struct tm *data_hora_atual;

  //variável do tipo time_t para armazenar o tempo em segundos
  time_t segundos;

  //obtendo o tempo em segundos
  time(&segundos);

  //para converter de segundos para o tempo local
  //utilizamos a função localtime
  data_hora_atual = localtime(&segundos);

  //para acessar os membros de uma struct usando o ponteiro
  //utilizamos o operador -> no nosso caso temos:
  //data_hora_atual->membro_da_struct
    /*
  //Acessando dados convertidos para a struct data_hora_atual
  printf("\nDia..........: %d\n", data_hora_atual->tm_mday);

  //para retornar o mês corretamente devemos adicionar +1
  //como vemos abaixo
  printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);

  //para retornar o ano corretamente devemos adicionar 1900
  //como vemos abaixo
  printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);

  printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);
  printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);

  /* Obtendo os valores da struct data_hora_atual
    e formatando a saída de dados no formato
    hora: minuto: segundo

  Para não ficar um printf muito longo em uma única linha
  de comando, quebrei a impressão em 3 partes mostrando
  uma informação em cada linha
  */
  /*
  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo

  /* Obtendo os valores da struct data_hora_atual
     e formatando a saída de dados no formato dia/mes/ano

     Para não ficar um printf muito longo em uma única
     linha de comando, quebrei a impressão em 3 partes
     sendo uma informação em cada linha

  //dia do mês
  printf("\nData ........: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano
  */
}

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int segundo, minuto, horario;
} hora;

//definição da estrutura para setor
typedef struct {
   int codigo;
   char fone[20];
   char nome[30];
} setor;

//definição da estrutura para servidor
typedef struct {
   int matricula, fone, *codSetor;
   char nome[30], cargo; // Servidor: [T]: Técnico Administrativo; [P]: Professor.
   data dataNasc;
} servidor;

//definição da estrutura para emprestimo
typedef struct {
    int numero, *matServidor;
    data dataSaida;
    hora horaSaida;
    char encerrado; // [N] não [S] sim  que quer dizer que todos equipamentos foram devolvidos.
} emprestimo;

//definição da estrutura para devolucao
typedef struct {
    int *numEmprestimo, *numEquipamento;
    data dataDev; //Quando o valor de data em Devolucao for null, ou seja, data is null então quer dizer que o equipamento ainda está emprestado.
    hora horario;
} devolucao;

//definição da estrutura para equipamento
typedef struct {
    int *numero;
    char nome[30], descricao[50], disponivel; //Disponível [N]: Não; [S]: Sim, que pode ser emprestado.
} equipamento;

//Procedimento para preencher setor
void dadoSetor(setor *setor) {
    //Padrão
    setor->codigo = 1;
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
    cout << "Informações do setor";
    cout << "\nCódigo: " << setor.codigo;
    cout << "\nNome: " << setor.nome;
    cout << "\nFone: " << setor.fone;
}

void dadoServidor(servidor *servidor, setor setor) {
    servidor->matricula = 1;
    strcpy ( servidor->nome, "Servidor 1" );
    servidor->dataNasc.dia = 1;
    servidor->dataNasc.mes = 12;
    servidor->dataNasc.ano = 2000;
    servidor->cargo = 'T'; //Para incluir um único char é preciso usar aspas simples
    servidor->codSetor = &setor.codigo;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    setor a;
    dadoSetor(&a);
    //imprimeSetor(a);
    servidor servidor;

    dadoServidor(&servidor, a);
    cout << "Informações do servidor";
    cout << "\nmatricula: ";
    cout << servidor.matricula;
    cout << "\nNome: ";
    cout << servidor.nome;
    cout << "\ndataNasc: ";
    cout << servidor.dataNasc.dia;
    cout << "/";
    cout << servidor.dataNasc.mes;
    cout << "/";
    cout << servidor.dataNasc.ano;
    cout << "\nCargo: " << servidor.cargo;
    cout << "\ncodSetor: " << *servidor.codSetor;
    emprestimo c;
    devolucao d;
    equipamento e;

    return 0;
}
