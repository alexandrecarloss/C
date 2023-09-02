#include <iostream> //BIBLIOTECAS UTILIZADAS
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define  TAMCURSOS 10//CONSTANTES UTILIZADAS
#define  TAMALUNOS 1000
#define  TAMARMARIOS 800
#define  TAMFUNCIONARIOS 5
#define  TAMRESERVAS 800
#define TAMPKEY 10
using namespace std;
//Novas variáveis solicitadas

typedef struct {
   int dia, mes, ano;
} Data;

typedef struct {
   int horario, minuto;
} Hora;

typedef struct {
   char	  nome[60], COD[TAMPKEY];
} Curso;

typedef struct {
   char	  nome[60], matricula_a[TAMPKEY],e_mail[60], turma[20],fone[15];
}Aluno;

typedef struct {
   char	  nome[60], matricula_f[TAMPKEY],e_mail[60], senha[30],fone[15], user[60];
}Funcionario;

typedef struct {
   char	  cod_curso[TAMPKEY], matricula[TAMPKEY];
   int ano;
   Data inicio, fim;
}Aluno_Curso;

typedef struct {
   char	  estado[100],disponivel[3];
   int num_armario;
} Armario;

typedef struct {
   char	  cod_reserva[TAMPKEY],mat_aluno[TAMPKEY],mat_funcionario[TAMPKEY];
   int numero_armario;
   Data data_rec, data_dev;
} Reserva;

//variaveis globais utilizadas

Funcionario funcionarios[TAMFUNCIONARIOS];
Armario armarios[TAMARMARIOS];
Reserva reservas[TAMRESERVAS];
Curso cursos[TAMCURSOS];
Aluno_Curso a_cursos[TAMALUNOS];
Aluno alunos[TAMALUNOS];
int cont_funcionario, cont_armario, cont_reserva, cont_curso, cont_aluno;
//Funções


void ler_aluno_arquivo() {
    FILE *pont_arq;
    int tamString, i, cont = 0;
    pont_arq = fopen("aluno.txt", "r");
    if(pont_arq){
         //printf("\nDados lidos do arquivo aluno.txt:\n");
        while(fscanf(pont_arq, "%s%s%s%s%s", alunos[cont].nome, alunos[cont].matricula_a, alunos[cont].e_mail, alunos[cont].turma, alunos[cont].fone) != EOF) {
            for(i = 0; i <= strlen(alunos[cont].nome); i++) {
                if(alunos[cont].nome[i] == '_') {
                    alunos[cont].nome[i] = ' ';
                }
            }
            strcpy(alunos[cont].nome, alunos[cont].nome);
            //printf("\nNome: %s\nMatrícula: %s \nE_mail: %s \nTurma: %s \nFone: %s\n", alunos[cont].nome, alunos[cont].matricula_a, alunos[cont].e_mail, alunos[cont].turma, alunos[cont].fone);
            cont++;
            cont_aluno++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

void gravar_aluno_arquivo() {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int i;
    pont_arq = fopen("aluno.txt", "w");
    if(pont_arq) {
        for(int pos = 0; pos <= cont_aluno; pos++) {
            for(i = 0; i < strlen(alunos[pos].nome); i++) {
                if(alunos[pos].nome[i] == ' ') {
                    alunos[pos].nome[i] = '_';
                }
            }
            fprintf(pont_arq, "%s \n", alunos[pos].nome);
            fprintf(pont_arq, "%s \n", alunos[pos].matricula_a);
            fprintf(pont_arq, "%s \n", alunos[pos].e_mail);
            fprintf(pont_arq, "%s \n", alunos[pos].turma);
            fprintf(pont_arq, "%s \n", alunos[pos].fone);
        }
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}


void ler_funcionario_arquivo() {
    FILE *pont_arq;
    int i, cont = 0;
    pont_arq = fopen("funcionario.txt", "r");
    if(pont_arq){
        //printf("\nDados lidos do arquivo funcionario.txt:\n");
        while(fscanf(pont_arq, "%s%s%s%s%s%s", funcionarios[cont].nome, funcionarios[cont].matricula_f, funcionarios[cont].e_mail, funcionarios[cont].senha, funcionarios[cont].fone, funcionarios[cont].user) != EOF) {
            for(i = 0; i <= strlen(funcionarios[cont].nome); i++) {
                if(funcionarios[cont].nome[i] == '_') {
                    funcionarios[cont].nome[i] = ' ';
                }
            }
            strcpy(funcionarios[cont].nome, funcionarios[cont].nome);
            cont_funcionario++;
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

void gravar_funcionario_arquivo() {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int i;
    pont_arq = fopen("funcionario.txt", "w");
    if(pont_arq) {
        for(int pos = 0; pos <= cont_funcionario; pos++) {
            for(i = 0; i <= strlen(funcionarios[pos].nome); i++) {
                if(funcionarios[pos].nome[i] == ' ') {
                    funcionarios[pos].nome[i] = '_';
                }
            }
            fprintf(pont_arq, "%s \n", funcionarios[pos].nome);
            fprintf(pont_arq, "%s \n", funcionarios[pos].matricula_f);
            fprintf(pont_arq, "%s \n", funcionarios[pos].e_mail);
            fprintf(pont_arq, "%s \n", funcionarios[pos].senha);
            fprintf(pont_arq, "%s \n", funcionarios[pos].fone);
            fprintf(pont_arq, "%s \n", funcionarios[pos].user);
        }
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}


void ler_armario_arquivo() {
    FILE *pont_arq;
    int cont = 0, i;
    pont_arq = fopen("armario.txt", "r");
    if(pont_arq){
        //printf("\nDados lidos do arquivo armario.txt:\n");
        while(fscanf(pont_arq, "%s%s%i", armarios[cont].estado, armarios[cont].disponivel, &armarios[cont].num_armario) != EOF) {
            cont_armario++;
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

void gravar_armario_arquivo() {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int i;
    pont_arq = fopen("armario.txt", "w");
    if(pont_arq) {
        for(int pos = 0; pos <= cont_armario; pos++) {
            fprintf(pont_arq, "%s \n", armarios[pos].estado);
            fprintf(pont_arq, "%s \n", armarios[pos].disponivel);
            fprintf(pont_arq, "%d \n", armarios[pos].num_armario);
        }
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}


void ler_curso_arquivo() {
    FILE *pont_arq;
    int cont = 0, i;
    pont_arq = fopen("curso.txt", "r");
    if(pont_arq){
        //printf("\nDados lidos do arquivo curso.txt:\n");
        while(fscanf(pont_arq, "%s%s", cursos[cont].nome, cursos[cont].COD) != EOF) {
            for(i = 0; i <= strlen(cursos[cont].nome); i++) {
                if(cursos[cont].nome[i] == '_') {
                    cursos[cont].nome[i] = ' ';
                }
            }
            strcpy(cursos[cont].nome, cursos[cont].nome);
            cont_curso++;
            cont++;
        }
        fclose(pont_arq);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

void gravar_curso_arquivo() {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    int i;
    pont_arq = fopen("curso.txt", "w");
    if(pont_arq) {
        for(int pos = 0; pos <= cont_curso; pos++){
            for(i = 0; i < strlen(cursos[pos].nome); i++) {
                if(cursos[pos].nome[i] == ' ') {
                    cursos[pos].nome[i] = '_';
                }
            }
            fprintf(pont_arq, "%s \n", cursos[pos].nome);
            fprintf(pont_arq, "%s \n", cursos[pos].COD);
        }
        fclose(pont_arq);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
}

void cadastrar_curso(){
    cout<<"\n\t---CADASTRO DE CURSO---:";
    cout<<"\nNome: ";
     scanf(" %[^\n]",cursos[cont_curso].nome);
    cout<<"\nCódigo: ";
     scanf(" %[^\n]",cursos[cont_curso].COD);
    cout<<"\n\tCURSO CADASTRADO!!";
    cont_curso++;

}

void cadastrar_armario(){
    cout<<"\t---CADASTRO DE ARMÁRIO---: ";
    cout<<"\nEstado: ";
    scanf(" %[^\n]",armarios[cont_armario].estado);
    cout<<"\nDisponível? [S] Sim [N] Não\n";
    scanf(" %[^\n]",armarios[cont_armario].disponivel);
    cout<<"\nNúmero: ";
    cin>>armarios[cont_armario].num_armario;
    cout<<"\n\tARMÁRIO CADASTRADO!!";
    cont_armario++;

}

void cadastrar_funcionario(){
    cout<<"\t---CADASTRO DE FUNCIONÁRIO---:";
    cout<<"\nNome: ";
    scanf(" %[^\n]",funcionarios[cont_funcionario].nome);
    cout<<"\nMatrícula: ";
    scanf(" %[^\n]",funcionarios[cont_funcionario].matricula_f);
    cout<<"\nUsuário: ";
    scanf(" %[^\n]",funcionarios[cont_funcionario].user);
    cout<<"\nE-mail: ";
    scanf(" %[^\n]",funcionarios[cont_funcionario].e_mail);
    cout<<"\nFone: ";
    scanf(" %[^\n]",funcionarios[cont_funcionario].fone);
    cout<<"\nSenha de acesso \tOBS:(Lembre-se da senha informada!)\t(Max:30 caracteres)\n";
    scanf(" %[^\n]",funcionarios[cont_funcionario].senha);
    cout<<"\n\tFUNCIONÁRIO CADASTRADO!!";
    cont_funcionario++;

}
/*
void reservar_armario(){
    int cont;
    fflush(stdin);
    cout<<"\nInforme a matrícula do funcionário: ";
    gets(reservas[cont_reserva].mat_funcionario);
    cout<<"\nInforme a matrícula do aluno: ";
    gets(reservas[cont_reserva].mat_aluno);
    cout<<"\nQual o código dessa reserva: ";
    gets(reservas[cont_reserva].cod_reserva);
    cout<<"\nInforme o número do armário: ";
    cin>>reservas[cont_reserva].numero_armario;
    for(cont=0;cont<cont_aluno;cont++){
        if(reservas[cont_reserva].mat_aluno==a_cursos[cont].matricula){
            reservas[cont_reserva].data_rec=a_cursos[cont].inicio;
            reservas[cont_reserva].data_dev=a_cursos[cont].fim;
        }
     }
    cout<<"\n\tARMÁRIO RESERVADO!!";
}
*/
void reservar_armario(char matAluno[TAMPKEY], char matFunc[TAMPKEY]){
    int cont;
    strcpy(reservas[cont_reserva].mat_funcionario, matFunc);
    strcpy(reservas[cont_reserva].mat_aluno, matAluno);
    cout<<"\nQual o código dessa reserva: ";
    gets(reservas[cont_reserva].cod_reserva);
    reservas[cont_reserva].numero_armario = cont_aluno;
    for(cont=0;cont<cont_aluno;cont++){
        if(reservas[cont_reserva].mat_aluno==a_cursos[cont].matricula){
            reservas[cont_reserva].data_rec=a_cursos[cont].inicio;
            reservas[cont_reserva].data_dev=a_cursos[cont].fim;
        }
     }
    cout<<"\n\tARMÁRIO RESERVADO!!";
}

int pergunta(){
    int op, para;
    while(op != 5){
        cout<<"\n1-Funcionário\n2-Aluno\n3-Armário\n4-Curso\n5-Voltar\n:";
        cin >> op;
        switch(op){
            case 1:
                return op;
                break;
            case 2:
                return op;
                break;
            case 3:
                return op;
                break;
            case 4:
                return op;
                break;
            case 5:
                return op;
                break;
            default:
                system("cls");
                cout << "Opção inválida!\n";
                system("pause");
            break;
            }
    }
}


int buscar(int opcao) {
    int arm_busc, contador;
    char matricula_a_busc[TAMPKEY], matricula_f_busc[TAMPKEY], cod_busc[TAMPKEY];
        switch(opcao){
            case 1:
                system("cls");
                cout<<"\n\tInforme a matrícula  do funcionário\n: ";
                scanf(" %[^\n]",matricula_f_busc);
                for(contador = 0; contador <= cont_funcionario; contador++){
                    if(strcmp(funcionarios[contador].matricula_f, matricula_f_busc)==0){
                       return contador;
                    } else {
                        system("cls");
                        cout << "Funcionário não encontrado!";
                    }
                }
                break;
            case 2:
                system("cls");
                 cout<<"\n\tInforme a Matrícula do aluno\n: ";
                 scanf(" %[^\n]",matricula_a_busc);
                 for(contador = 0; contador < cont_aluno; contador++){
                    if(strcmp(alunos[contador].matricula_a,matricula_a_busc)==0){
                        return contador;
                    } else {
                        system("cls");
                        cout << "Aluno não encontrado!";
                    }
                }
                break;
            case 3:
                system("cls");
                 cout<<"\n\tInforme o número do armário\n: ";
                cin>>arm_busc;
                for(contador = 0; contador < cont_armario; contador++){
                    if(armarios[contador].num_armario=arm_busc){
                            return contador;
                    } else {
                        system("cls");
                        cout << "Armário não encontrado!";
                    }
                }
                break;
            case 4:
                system("cls");
                 cout<<"\n\tInforme o Cod do curso\n: ";
                 scanf(" %[^\n]",cod_busc);
                 for(contador = 0;contador < cont_curso; contador++){
                    if(strcmp(cursos[contador].COD,cod_busc)==0){
                       return contador;
                    } else {
                        system("cls");
                        cout << "Curso não encontrado!";
                    }
                }
                break;
        }
}


void exibir_curso(int pos){
    if(cont_curso==0){
        cout<<"\nNão existem cursos cadastrados";
    }
    printf("\n--------Curso número %i---------------------------\n", pos+1);
            cout<< " \nCOD: " << cursos[pos].COD;
            cout << "\nNome: " << cursos[pos].nome;
            cout<<"\n";
}

void exibir_funcionario(int pos) {
    if(cont_funcionario==0){
        cout<<"\nNão existem funcionários cadastrados";
    }
    printf("\n--------Funcionário número %i---------------------------\n", pos+1);
            cout<< " \nMatrícula: " << funcionarios[pos].matricula_f;
            cout << "\nNome: " << funcionarios[pos].nome;
            cout << "\nUser: " << funcionarios[pos].user;
            cout << "\nE-mail: " << funcionarios[pos].e_mail;
            cout << "\nFone: " << funcionarios[pos].fone;
           cout<<"\n";
}

void exibir_armario(int pos) {
    if(cont_armario==0){
        cout<<"\nNão existem armários cadastrados";
    }
    printf("\n--------Armário número %i---------------------------\n", pos+1);
            cout << "\nNúmero: " << armarios[pos].num_armario;
            cout<< " \nDisponível :" << armarios[pos].disponivel;
            cout<< " \nEstado :" << armarios[pos].estado;
            cout<<"\n";
}

void exibir_aluno(int pos) {
    if(cont_aluno==0){
        cout<<"\nNão existem alunos cadastrados";
    }
    printf("\n--------Aluno número %i---------------------------\n", pos+1);
            cout << "\nMatrícula: " << alunos[pos].matricula_a;
            cout << "\nNome: " << alunos[pos].nome;
            cout << "\nEmail: " << alunos[pos].e_mail;
            cout << "\nFone: " << alunos[pos].fone;
            cout << "\nTurma: " << alunos[pos].turma;
            cout<<"\n";
}


void exibir(int escolha){
    int op=escolha, tipo=0, contador;
    while(escolha!=5){
    switch(escolha){
    case 1:
        while(tipo<1 || tipo>2){
        cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
        cin>>tipo;
        }
        if(tipo==1){
            for(contador=0;contador<cont_funcionario;contador++){
                exibir_funcionario(contador);
                }
            }else{
                exibir_funcionario(buscar(op));
            }
            escolha=5;
        break;
    case 2:
        while(tipo<1 || tipo>2){
        cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
        cin>>tipo;
        }
        if(tipo==1){
            for(contador=0;contador<cont_aluno;contador++){
                exibir_aluno(contador);
            }
            }else{
                exibir_aluno(buscar(op));
            }
        escolha=5;
        break;
    case 3:
         while(tipo<1 || tipo>2){
          cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
          cin>>tipo;
        }
        if(tipo==1){
            for(contador=0;contador<cont_armario;contador++){
                exibir_armario(contador);
            }
            }else{
                exibir_armario(buscar(op));
            }
            escolha=5;
        break;
    case 4:
        while(tipo<1 || tipo>2){
        cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
        cin>>tipo;
        }
        if(tipo==1){
            for(contador=0;contador<cont_curso;contador++){
                exibir_curso(contador);
            }
            }else{
                exibir_curso(buscar(op));
            }
            escolha=5;
            break;
          }
        }
 }



void escolher_curso(){
    int cont;
    cout<<"\nLISTA DE CURSOS CADASTRADOS:";
    for(cont=0;cont<cont_curso;cont++){
    exibir_curso(cont);
    }
    cout<<"\nEscolha o COD correspondente\n:";
    fflush(stdin);
    gets(a_cursos[cont_aluno].cod_curso);
}


void cadastrar_aluno(){
    cout<<"\t---CADASTRO DE ALUNO---: ";
    cout<<"\nNome:";
    scanf(" %[^\n]",alunos[cont_aluno].nome);
    cout<<"\nMatrícula: ";
    scanf(" %[^\n]",alunos[cont_aluno].matricula_a);
    strcpy(a_cursos[cont_aluno].matricula,alunos[cont_aluno].matricula_a);
    cout<<"\nTurma:";
    scanf(" %[^\n]",alunos[cont_aluno].turma);
    cout<<"\nFone para contato: ";
    scanf(" %[^\n]",alunos[cont_aluno].fone);
    cout<<"\nE-mail: ";
    scanf(" %[^\n]",alunos[cont_aluno].e_mail);
    cout<<"\nAno de entrada no curso: ";
    cin>>a_cursos[cont_aluno].inicio.ano;
    cout<<"\nAno previsto de término do curso:";
    cin>>a_cursos[cont_aluno].fim.ano;
    if(cont_curso == 0) {
        printf("\nAinda não existem cursos cadastrados, cadastre um novo curso \n");
        cadastrar_curso();
    }
    escolher_curso();
    cout<<"\nAno cursado: ";
    cin >>a_cursos[cont_aluno].ano;

    reservar_armario(alunos[cont_aluno].matricula_a, funcionarios[buscar(1)].matricula_f);
    cout<<"\n\tALUNO CADASTRADO!!";
    cont_aluno++;

}

void cadastrar(int op_c){
    while(op_c!=5){
    switch(op_c){
    case 1:
        cadastrar_funcionario();
        op_c=5;
    break;
    case 2:
        cadastrar_aluno();
        op_c=5;
        break;
    case 3:
        cadastrar_armario();
        op_c=5;
        break;
    case 4:
        cadastrar_curso();
        op_c=5;
    break;
    }
  }
}

void armarios_disponiveis() {
    if(cont_armario==0){
        cout<<"\nNão existem armários cadastrados";
    }
    for(int i = 0; i <= cont_armario; i++) {
        printf("\n--------Armário número %i---------------------------\n", i+1);
        cout << "Número: " << armarios[i].num_armario;
        cout << "\nDisponível: " << armarios[i].disponivel;
        cout << "\nEstado: " << armarios[i].estado;
    }
}

void exibir_termo_compromisso() {
    //Criando uma variável ponteiro para o arquivo
    FILE *pont_arq;
    char c;
    //Abrindo arquivo para gravação
    pont_arq = fopen("termo_compromisso.txt", "r");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo termo_compromisso.txt não pode ser aberto\n");
        exit(1); //Saindo do programa
    }
    //Faça
    while((c = fgetc(pont_arq)) != EOF) {
        putchar(c);
    }
     //Fechando arquivo
    fclose(pont_arq);
}


void menuAluno() {
    int opcao;
    while(opcao != 4) {
        cout << "\nBem vindo aluno\n";
        cout << "O que você quer fazer? ";
        cout << "\nVer armários disponíveis [1] \nTermo de compromisso [2] \nVer avisos [3] \nVoltar [4]\n";
       scanf("%d", &opcao);
       getchar();
        switch(opcao) {
        case 1:
            system("cls");
            armarios_disponiveis();
            system("pause");
            break;
        case 2:
            system("cls");
            exibir_termo_compromisso();
            system("pause");
            break;
        case 3:
            system("cls");
            //verAvisos();
            system("pause");
            break;
        case 4:
            system("cls");
            system("pause");
            break;
        default:
            cout << "Opção inválida! ";
            system("pause");
            break;
        }
    }
}

void excluir_armario(int pos) {
    int i;
    for(int i = pos; i <=cont_armario; i++) {
            if(i==TAMARMARIOS){
            armarios[i].num_armario=0;
            strcpy(armarios[i].estado, "");
            strcpy(armarios[i].disponivel, "");
        }
        else{
           armarios[i] = armarios[i+1];
        }
    }
    cout << "Armário excluído com sucesso!";
    cont_armario--;
}

void excluir_curso(int pos) {
    int i;
    for(int i = pos; i <= cont_curso; i++) {
            if(i==TAMCURSOS){
            strcpy(cursos[i].nome, "");
            strcpy(cursos[i].COD, "");
        }
        else{
           cursos[i] = cursos[i+1];
        }
    }
    cout << "Curso excluído com sucesso!";
}

void excluir_aluno(int pos) {
    int i;
    for(int i = pos; i <= cont_aluno; i++) {
            if(i==TAMALUNOS){
            strcpy(alunos[i].matricula_a, "");
            strcpy(alunos[i].nome, "");
            strcpy(alunos[i].e_mail, "");
            strcpy(alunos[i].fone, "");
            strcpy(alunos[i].turma, "");
        }
        else{
           alunos[i] = alunos[i+1];
        }
    }
    cout << "Aluno excluído com sucesso!";
    cont_aluno--;
}

void excluir_funcionario(int pos) {
    int i;
    for(int i = pos; i <= cont_funcionario; i++) {
            if(i==TAMFUNCIONARIOS){
            strcpy(funcionarios[i].matricula_f, "");
            strcpy(funcionarios[i].nome, "");
            strcpy(funcionarios[i].e_mail, "");
            strcpy(funcionarios[i].senha, "");
            strcpy(funcionarios[i].user, "");
            strcpy(funcionarios[i].fone, "");
            }else{
            funcionarios[i]=funcionarios[i+1];
            }
    }
    cout << "Funcionário excluído com sucesso!";
    cont_funcionario--;
}

void excluir(int escolha){
    int op=escolha;
    while(escolha!=5){
    switch(escolha){
    case 1:
        excluir_funcionario(buscar(op));
        escolha=5;
        break;
    case 2:
        excluir_aluno(buscar(op));
        escolha=5;
        break;
    case 3:
        excluir_armario(buscar(op));
        escolha=5;
        break;
    case 4:
        excluir_curso(buscar(op));
        escolha=5;
         break;

    }
  }
}

void login() {

}

void alterar(int escolha){
    int op=escolha;
    int pos= buscar(escolha);
    switch(op){
        case 1:
        cout<<"\t---RECADASTRO DE FUNCIONÁRIO---:";
        cout<<"\nNome: ";
        scanf(" %[^\n]",funcionarios[pos].nome);
        cout<<"\nMatrícula: ";
        scanf(" %[^\n]",funcionarios[pos].matricula_f);
        cout<<"\nUsuário: ";
        scanf(" %[^\n]",funcionarios[pos].user);
        cout<<"\nE-mail: ";
        scanf(" %[^\n]",funcionarios[pos].e_mail);
        cout<<"\nFone: ";
        scanf(" %[^\n]",funcionarios[pos].fone);
        cout<<"\nSenha de acesso\tOBS:(Lembre-se da senha informada!)\t(Max:30 caracteres)\n";
        scanf(" %[^\n]",funcionarios[pos].senha);
        cout<<"\n\tFUNCIONÁRIO RECADASTRADO!!";
          break;
        case 2:
        cout<<"\t---RECADASTRO DE ALUNO---: ";
        cout<<"\nNome:";
        scanf(" %[^\n]",alunos[pos].nome);
        cout<<"\nMatrícula: ";
        scanf(" %[^\n]",alunos[pos].matricula_a);
        strcpy(a_cursos[pos].matricula,alunos[pos].matricula_a);
        cout<<"\nTurma:";
        scanf(" %[^\n]",alunos[pos].turma);
        cout<<"\nFone para contato: ";
        scanf(" %[^\n]",alunos[pos].fone);
        cout<<"\nE-mail: ";
        scanf(" %[^\n]",alunos[pos].e_mail);
        cout<<"\nAno de entrada no curso: ";
        cin>>a_cursos[pos].inicio.ano;
        cout<<"\nAno previsto de término do curso:";
        cin>>a_cursos[pos].fim.ano;
        if(cont_curso == 0) {
        printf("\nAinda não existem cursos cadastrados, cadastre um novo curso \n");
        cadastrar_curso();
        }
        escolher_curso();
        cout<<"\nAno cursado: ";
        cin >>a_cursos[pos].ano;
        cout<<"\n\tALUNO RECADASTRADO!!";
            break;
          case 3:
        cout<<"\t---RECADASTRO DE ARMÁRIO---: ";
        cout<<"\nEstado: ";
        scanf(" %[^\n]",armarios[pos].estado);
        cout<<"\nDisponível? [S] Sim [N] Não\n";
        scanf(" %[^\n]",armarios[pos].disponivel);
        cout<<"\nNúmero: ";
        cin>>armarios[pos].num_armario;
        cout<<"\n\tARMÁRIO RECADASTRADO!!";
            break;
           case 4:
        cout<<"\n\t---RECADASTRO DE CURSO---:";
        cout<<"\nNome: ";
        scanf(" %[^\n]",cursos[pos].nome);
        cout<<"\nCódigo: ";
        scanf(" %[^\n]",cursos[pos].COD);
        cout<<"\n\tCURSO RECADASTRADO!!";
        gravar_curso_arquivo();
            break;
        }
}

void menuFuncionario() {
    int opcao;
    if(cont_funcionario == 0) {
        cadastrar_funcionario();
    }
    while(opcao != 0) {
        system("cls");
        cout << "Bem vindo funcionário\n";
        cout << "\nO que você quer fazer? ";
        cout << "\nVoltar [0] \nCadastrar[1]\nExcluir [2]\nAlterar[3]\nExibir[4]\n:";
       scanf("%d", &opcao);
        switch(opcao) {
        case 0:
            system("cls");
            cout << "Voltando ao menu principal...\n";
            system("pause");
            break;
        case 1:
            system("cls");
            cout<<"\n\tO que quer cadastrar?";
            cadastrar(pergunta());
            cout << "\n";
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"\n\tO que quer excluir?";
            excluir(pergunta());
            cout << "\n";
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"\n\tO que quer alterar?";
            alterar(pergunta());
            cout << "\n";
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"\n\tO que quer exibir?";
            exibir(pergunta());
            cout << "\n";
            system("pause");
            break;
        default:
            cout << "Opção inválida! ";
            break;
        }
    }
}

void menu(){
    int opcao;
    while(opcao != 3) {
        system("cls");
        cout << "\nQuem está acessando? ";
        cout << "\nAluno [1] \nFuncionário [2]\nSair [3]\n:";
       scanf("%d", &opcao);
       //getchar();
        switch(opcao) {
        case 1:
            system("cls");
            menuAluno();
            break;
        case 2:
            system("cls");
            menuFuncionario();
            break;
        case 3:
            cout << "Tchau";
            break;
        default:
            cout << "Opção inválida! ";
            break;
        }
    }
}

int main() {
    setlocale( LC_ALL, "portuguese" );
    cout << "Lendo dados dos arquivos aguarde...";
    ler_funcionario_arquivo();
    ler_aluno_arquivo();
    ler_armario_arquivo();
    ler_curso_arquivo();
    menu();
    gravar_aluno_arquivo();
    gravar_armario_arquivo();
    gravar_curso_arquivo();
    gravar_funcionario_arquivo();
}
