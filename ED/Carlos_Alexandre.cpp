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
   char	  nome[60], COD[6];
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

//vari�veis globais utilizadas
Funcionario funcionarios[TAMFUNCIONARIOS];
Armario armarios[TAMARMARIOS];
Reserva reservas[TAMRESERVAS];
Curso cursos[TAMCURSOS];
Aluno_Curso a_cursos[TAMALUNOS];
Aluno alunos[TAMALUNOS];
int cont_funcionario, cont_armario, cont_reserva, cont_curso, cont_alunos;

//Fun��es

void cadastrar_curso(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE CURSO---:";
    cout<<"\nNome:";
    gets(cursos[cont_curso].nome);
    cout<<"\nC�digo:";
    gets(cursos[cont_curso].COD);
    cout<<"\n\tCURSO CADASTRADO!!";
}

void cadastrar_armario(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE ARM�RIO---:";
    cout<<"\nEstado:";
    gets(armarios[cont_armario].estado);
    cout<<"\nDispon�vel?";
    gets(armarios[cont_armario].disponivel);
    cout<<"\nN�mero:";
    cin>>armarios[cont_armario].num_armario;
    cout<<"\n\tARM�RIO CADASTRADO!!";
}

void cadastrar_funcionario(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE FUNCION�RIO---:";
    cout<<"\nNome:";
    gets(funcionarios[cont_funcionario].nome);
    cout<<"\nMatr�cula:";
    gets(funcionarios[cont_funcionario].matricula_f);
    cout<<"\nUsu�rio:";
    gets(funcionarios[cont_funcionario].user);
    cout<<"\nE-mail:";
    gets(funcionarios[cont_funcionario].e_mail);
    cout<<"\nFone:";
    gets(funcionarios[cont_funcionario].fone);
    cout<<"\nSenha de acesso \tOBS:(Lembre-se da senha informada!)\t(Max:30 caracteres)\n";
    gets(funcionarios[cont_funcionario].senha);
    cout<<"\n\tFUNCION�RIO CADASTRADO!!";
}

void exibir_curso(){
    for(int i = 0; i <= cont_curso; i++) {
        cout << "\nCursos cadastrados: ";
        cout<<"\nNome: " << cursos[i].nome;
        cout<<"\nC�digo: " << cursos[i].COD;
    }

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

void escolher_curso(){
    cout<<"LISTA DE CURSOS CADASTRADOS: ";
    exibir_curso();
    cout<<"\nEscolha o COD correspondente: ";
    fflush(stdin);
    gets(a_cursos[cont_alunos].cod_curso);
}


void cadastrar_aluno(){
    fflush(stdin);
    cout<<"\t---CADASTRO DE ALUNO---:";
    cout<<"\nNome: ";
    gets(alunos[cont_alunos].nome);
    cout<<"\nMatr�cula: ";
    gets(alunos[cont_alunos].matricula_a);
    strcpy(a_cursos[cont_alunos].matricula, alunos[cont_alunos].matricula_a);
    cout<<"\nTurma: ";
    gets(alunos[cont_alunos].turma);
    cout<<"\nFone para contato: ";
    gets(alunos[cont_alunos].fone);
    cout<<"\nE-mail: ";
    gets(alunos[cont_alunos].e_mail);
    cout<<"\nAno de entrada no curso: ";
    cin >> a_cursos[cont_alunos].inicio.ano;
    cout<<"\nAno previsto de t�rmino do curso: ";
    cin >> a_cursos[cont_alunos].fim.ano;
    escolher_curso();
    cout<<"\nAno cursado";
    cin>>a_cursos[cont_alunos].ano;
    cout<<"\n\tALUNO CADASTRADO!!";
}

void armarios_disponiveis() {
    cout << "Arm�rios dispon�veis: \n";
    for(int i = 0; i <= cont_armario; i++) {
        cout << "N�mero: " << armarios[i].num_armario;
        cout << "\nDispon�vel: " << armarios[i].disponivel;
        cout << "\nEstado: " << armarios[i].estado;
    }
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
            break;
        case 2:
            system("cls");
            //termoCompromisso();
            break;
        case 3:
            system("cls");
            //verAvisos();
            break;
        case 4:
            system("cls");
            break;
        default:
            cout << "Op��o inv�lida! ";
            break;
        }
    }
}

void menuFuncionario() {
    int opcao;
    while(opcao != 9) {
        system("cls");
        cout << "Bem vindo funcion�rio\n";
        cout << "\nO que voc� quer fazer? ";
        cout << "\nCadastrar aluno [1] \nCadastrar funcion�rio [2]\nCadastrar arm�rio [3] \nCadastrar curso [4]\n";
        cout << "Excluir aluno [5] \nExcluir funcion�rio [6] \nExcluir arm�rio [7] \nExcluir curso [8] \nVoltar [9]\n";
       scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            cadastrar_aluno();
            break;
        case 2:
            cadastrar_funcionario();
            break;
        case 3:
            cadastrar_armario();
            break;
        case 4:
            cadastrar_curso();
            break;
        case 5:
            //excluir_aluno();
            break;
        case 6:
            //excluir_funcionario();
            break;
        case 7:
            //excluir_armario();
            break;
        case 8:
            //excluir_curso();
            break;
        case 9:
            cout << "Voltando ao menu principal...";
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

            menuAluno();
            break;
        case 2:
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





using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << "Hello world!" << endl;
    menu();
    return 0;
}