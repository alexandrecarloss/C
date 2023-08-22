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
using namespace std;
//Novas vari�veis solicitadas

typedef struct {
   int dia, mes, ano;
} Data;

typedef struct {
   int horario, minuto;
} Hora;

typedef struct {
   char	  nome[60], COD[7];
} Curso;

typedef struct {
   char	  nome[60], matricula_a[10],e_mail[60], turma[20],fone[15];
}Aluno;

typedef struct {
   char	  nome[60], matricula_f[10],e_mail[60], senha[30],fone[15], user[60];
}Funcionario;

typedef struct {
   char	  cod_curso[6], matricula[10];
   int ano;
   Data inicio, fim;
}Aluno_Curso;

typedef struct {
   char	  estado[100],disponivel[3];
   int num_armario;
} Armario;

typedef struct {
   char	  cod_reserva[10],mat_aluno[10],mat_funcionario[10];
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
int cont_funcionario, cont_armario, cont_reserva, cont_curso=0, cont_alunos;
//Fun��es


void cadastrar_curso(){
    fflush(stdin);
    cout<<"\n\t---CADASTRO DE CURSO---:";
    cout<<"\nNome: ";
    gets(cursos[cont_curso].nome);
    cout<<"\nC�digo: ";
    gets(cursos[cont_curso].COD);
    cout<<"\n\tCURSO CADASTRADO!!";
    cont_curso++;
}

void cadastrar_armario(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE ARM�RIO---: ";
    cout<<"\nEstado: ";
    gets(armarios[cont_armario].estado);
    cout<<"\nDispon�vel? [S] Sim [N] N�o\n";
    gets(armarios[cont_armario].disponivel);
    cout<<"\nN�mero: ";
    cin>>armarios[cont_armario].num_armario;
    cout<<"\n\tARM�RIO CADASTRADO!!";
    cont_armario++;
}

void cadastrar_funcionario(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE FUNCION�RIO---:";
    cout<<"\nNome: ";
    gets(funcionarios[cont_funcionario].nome);
    cout<<"\nMatr�cula: ";
    gets(funcionarios[cont_funcionario].matricula_f);
    cout<<"\nUsu�rio: ";
    gets(funcionarios[cont_funcionario].user);
    cout<<"\nE-mail: ";
    gets(funcionarios[cont_funcionario].e_mail);
    cout<<"\nFone: ";
    gets(funcionarios[cont_funcionario].fone);
    cout<<"\nSenha de acesso \tOBS:(Lembre-se da senha informada!)\t(Max:30 caracteres)\n";
    gets(funcionarios[cont_funcionario].senha);
    cout<<"\n\tFUNCION�RIO CADASTRADO!!";
    cont_funcionario++;
}

void reservar_armario(){
    int cont;
    fflush(stdin);
    cout<<"\nInforme a matr�cula do funcion�rio: ";
    gets(reservas[cont_reserva].mat_funcionario);
    cout<<"\nInforme a matr�cula do aluno: ";
    gets(reservas[cont_reserva].mat_aluno);
    cout<<"\nQual o c�digo dessa reserva: ";
    gets(reservas[cont_reserva].cod_reserva);
    cout<<"\nInforme o n�mero do arm�rio: ";
    cin>>reservas[cont_reserva].numero_armario;
    for(cont=0;cont<cont_alunos;cont++){
        if(reservas[cont_reserva].mat_aluno==a_cursos[cont].matricula){
            reservas[cont_reserva].data_rec=a_cursos[cont].inicio;
            reservas[cont_reserva].data_dev=a_cursos[cont].fim;
        }
     }
    cout<<"\n\tARM�RIO RESERVADO!!";
}

int buscar() {
    int opcao=0, arm_busc, contador;
    char matricula_a_busc[10], matricula_f_busc[10], cod_busc[7];
    while(opcao!=5) {
        cout<<"\n1-Funcion�rio\n2-Aluno\n3-Arm�rio\n4-Curso\n5-Voltar\n: ";
        cin >> opcao;
        switch(opcao){
            case 1:
                system("cls");

                cout<<"\n\tInforme a matr�cula  do funcion�rio\n: ";
                scanf(" %[^\n]",matricula_f_busc);
                for(contador = 0; contador < cont_funcionario; contador++){
                    if(strcmp(funcionarios[contador].matricula_f, matricula_f_busc)==0){
                        return contador;
                    } else {
                        cout << "Funcion�rio n�o encontrado!";
                    }
                }

            break;
            case 2:
                system("cls");
                 cout<<"\n\tInforme a Matr�cula do aluno\n: ";
                 scanf(" %[^\n]",matricula_a_busc);
                 for(contador = 0; contador < cont_alunos; contador++){
                    if(strcmp(alunos[contador].matricula_a,matricula_a_busc)==0){
                        return contador;
                    } else {
                        cout << "Aluno n�o encontrado!";
                    }
                }
            break;
            case 3:
                system("cls");
                 cout<<"\n\tInforme o n�mero do arm�rio\n: ";
                cin>>arm_busc;
                for(contador = 0; contador < cont_armario; contador++){
                    if(armarios[contador].num_armario=arm_busc){
                       return contador;
                    } else {
                        cout << "Arm�rio n�o encontrado!";
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
                        cout << "Curso n�o encontrado!";
                    }
                }
            break;
            case 5:
                system("cls");
            break;
            default:
                cout << "Op��o inv�lida! ";
                system("pause");
                system("cls");
            break;
        }
    }
}

void exibir_curso(){
    if(cont_curso == 0) {
        cout << "\nN�o h� cursos cadastrados!\n";
    } else {
        int cont;
        for (cont = 0; cont < cont_curso; cont++){
            cout<< " \nCOD: " << cursos[cont].COD;
            cout << "\nNome: " << cursos[cont].nome;
        }
    }
}

void exibir_funcionario() {
    if(cont_funcionario == 0) {
        cout << "N�o h� funcion�rios cadastrados!\n";
    } else {
        int cont;
        for (cont = 0; cont < cont_funcionario; cont++){
            cout<< " \nMatr�cula: " << funcionarios[cont].matricula_f;
            cout << "\nNome: " << funcionarios[cont].nome;
            cout << "\nUser: " << funcionarios[cont].user;
            cout << "\nE-mail: " << funcionarios[cont].e_mail;
            cout << "\nFone: " << funcionarios[cont].fone;
        }
    }
}

void exibir_armario() {
    if(cont_armario == 0) {
        cout << "N�o h� arm�rios cadastrados!\n";
    } else {
        int cont;
        for (cont = 0; cont < cont_armario; cont++){
            cout << "\nN�mero: " << armarios[cont].num_armario;
            cout<< " \nDispon�vel :" << armarios[cont].disponivel;
            cout<< " \nEstado :" << armarios[cont].estado;
        }
    }
}

void exibir_aluno() {
    if(cont_alunos == 0) {
        cout << "N�o h� alunos cadastrados!\n";
    } else {
        int cont;
        for (cont = 0; cont < cont_alunos; cont++){
            cout << "\nMatr�cula: " << alunos[cont].matricula_a;
            cout << "\nNome: " << alunos[cont].nome;
            cout << "\nEmail: " << alunos[cont].e_mail;
            cout << "\nFone: " << alunos[cont].fone;
            cout << "\nTurma: " << alunos[cont].turma;
        }
    }
}

void escolher_curso(){
    cout<<"\nLISTA DE CURSOS CADASTRADOS:";
    exibir_curso();
    cout<<"\nEscolha o COD correspondente:";
    fflush(stdin);
    gets(a_cursos[cont_alunos].cod_curso);
}


void cadastrar_aluno(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE ALUNO---: ";
    cout<<"\nNome:";
    gets(alunos[cont_alunos].nome);
    cout<<"\nMatr�cula: ";
    gets(alunos[cont_alunos].matricula_a);
    strcpy(a_cursos[cont_alunos].matricula,alunos[cont_alunos].matricula_a);
    cout<<"\nTurma:";
    gets(alunos[cont_alunos].turma);
    cout<<"\nFone para contato: ";
    gets(alunos[cont_alunos].fone);
    cout<<"\nE-mail: ";
    gets(alunos[cont_alunos].e_mail);
    cout<<"\nAno de entrada no curso: ";
    cin>>a_cursos[cont_alunos].inicio.ano;
    cout<<"\nAno previsto de t�rmino do curso:";
    cin>>a_cursos[cont_alunos].fim.ano;
    if(cont_curso == 0) {
        printf("\nAinda n�o existem cursos cadastrados, cadastre um novo curso \n");
        cadastrar_curso();
    }
    escolher_curso();
    cout<<"\nAno cursado: ";
    cin >>a_cursos[cont_alunos].ano;
    cout<<"\n\tALUNO CADASTRADO!!";
    cont_alunos++;

}


void armarios_disponiveis() {
    cout << "Arm�rios dispon�veis: \n";
    for(int i = 0; i <= cont_armario; i++) {
        cout << "N�mero: " << armarios[i].num_armario;
        cout << "\nDispon�vel: " << armarios[i].disponivel;
        cout << "\nEstado: " << armarios[i].estado;
    }
}

void exibir_termo_compromisso() {
    //Criando uma vari�vel ponteiro para o arquivo
    FILE *pont_arq;
    char c;
    //Abrindo arquivo para grava��o
    pont_arq = fopen("termo_compromisso.txt", "r");

    //Testando abertura do arquivo
    if(pont_arq == NULL) {
        printf("\n\nErro: O arquivo termo_compromisso.txt n�o pode ser abreto\n");
        exit(1); //Saindo do programa
    }
    //Fa�a
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
        cout << "O que voc� quer fazer? ";
        cout << "\nVer arm�rios dispon�veis [1] \nTermo de compromisso [2] \nVer avisos [3] \nVoltar [4]\n";
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
            cout << "Op��o inv�lida! ";
            system("pause");
            break;
        }
    }
}

void excluir_aluno() {
    char mat[10];
    exibir_aluno();
    cout << "\nQual a matr�cula do aluno que voc� quer excluir? ";
    scanf("%s", mat);
    for(int i = 0; i < cont_alunos; i++) {
        if(strcmp(alunos[i].matricula_a,mat)==0){
            strcpy(alunos[i].matricula_a, "");
            strcpy(alunos[i].nome, "");
            strcpy(alunos[i].e_mail, "");
            strcpy(alunos[i].fone, "");
            strcpy(alunos[i].turma, "");
        }
    }
    cout << "Aluno exclu�do com sucesso!";
    exibir_aluno();
}

void excluir_funcionario() {
    char mat[10];
    exibir_funcionario();
    cout << "\nQual a matr�cula do funcion�rio que voc� quer excluir? ";
    scanf("%s", mat);
    for(int i = 0; i < cont_funcionario; i++) {
        if(strcmp(funcionarios[i].matricula_f,mat)==0){
            strcpy(funcionarios[i].matricula_f, "");
            strcpy(funcionarios[i].nome, "");
            strcpy(funcionarios[i].user, "");
            strcpy(funcionarios[i].senha, "");
            strcpy(funcionarios[i].e_mail, "");
            strcpy(funcionarios[i].fone, "");
        }
    }
    cout << "Funcion�rio exclu�do com sucesso!";
    exibir_funcionario();
}

void menuFuncionario() {
    int opcao;
    while(opcao != 0) {
        system("cls");
        cout << "Bem vindo funcion�rio\n";
        cout << "\nO que voc� quer fazer? ";
        cout << "\nVoltar [0] \nCadastrar aluno [1] \nCadastrar funcion�rio [2]\nCadastrar arm�rio [3] \nCadastrar curso [4]\n";
        cout << "Excluir aluno [5] \nExcluir funcion�rio [6] \nExcluir arm�rio [7] \nExcluir curso [8] ";
        cout << "Editar aluno [9] \nEditar funcion�rio [10] \nEditar arm�rio [11] \nEditar curso [12] \n";
        cout << "Exibir alunos [13] \nExibir funcion�rios [14] \nExibir arm�rios [15] \nExibir cursos [16] \n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 0:
            system("cls");
            cout << "Voltando ao menu principal...\n";
            system("pause");
            break;
        case 1:
            system("cls");
            cadastrar_aluno();
            cout << "\n";
            system("pause");
            break;
        case 2:
            system("cls");
            cadastrar_funcionario();
            cout << "\n";
            system("pause");
            break;
        case 3:
            system("cls");
            cadastrar_armario();
            cout << "\n";
            system("pause");
            break;
        case 4:
            system("cls");
            cadastrar_curso();
            cout << "\n";
            system("pause");
            break;
        case 5:
            system("cls");
            excluir_aluno();
            cout << "\n";
            system("pause");
            break;
        case 6:
            system("cls");
            excluir_funcionario();
            cout << "\n";
            system("pause");
            break;
        case 7:
            system("cls");
            //excluir_armario();
            cout << "\n";
            system("pause");
            break;
        case 8:
            system("cls");
            //excluir_curso();
            cout << "\n";
            system("pause");
            break;
        case 9:
            system("cls");
            //editar_aluno();
            cout << "\n";
            system("pause");
            break;
        case 10:
            system("cls");
            //editar_funcionario();
            cout << "\n";
            system("pause");
            break;
        case 11:
            system("cls");
            //editar_armario();
            cout << "\n";
            system("pause");
            break;
        case 12:
            system("cls");
            //editar_curso();
            cout << "\n";
            system("pause");
            break;
        case 13:
            system("cls");
            exibir_aluno();
            cout << "\n";
            system("pause");
            break;
        case 14:
            system("cls");
            exibir_funcionario();
            cout << "\n";
            system("pause");
            break;
        case 15:
            system("cls");
            exibir_armario();
            cout << "\n";
            system("pause");
            break;
        case 16:
            system("cls");
            exibir_curso();
            cout << "\n";
            system("pause");
            break;
        default:
            cout << "Op��o inv�lida! ";
            break;
        }
    }
}


void menu(){
    int opcao;
    while(opcao != 3) {
        system("cls");
        cout << "\nQuem est� acessando? ";
        cout << "\nAluno [1] \nFuncion�rio [2]\nSair [3] \n";
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
            cout << "Op��o inv�lida! ";
            break;
        }
    }
}

int main() {
    setlocale( LC_ALL, "portuguese" );
    menu();

}
