#include <iostream> //BIBLIOTECAS UTILIZADAS
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#define  TAMCURSOS 10//CONSTANTES UTILIZADAS
#define  TAMALUNOS 10
#define  TAMARMARIOS 51
#define  TAMFUNCIONARIOS 5
#define  TAMRESERVAS 50
#define TAMPKEY 10
#define TAMUSER 30
#define TAMSENHA 30

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
 CursorPosition.X = x; // Locates column
 CursorPosition.Y = y; // Locates Row
 SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

//Novas vari�veis solicitadas

typedef struct {
   int dia, mes, ano;
} Data;

typedef struct {
   int horario, minuto;
} Hora;

typedef struct {
   char	nome[60], COD[TAMPKEY];
} Curso;

typedef struct {
   char	nome[60], matricula_a[TAMPKEY],e_mail[60], turma[20],fone[15];
   int ano_aluno;
}Aluno;

typedef struct {
   char	nome[60], matricula_f[TAMPKEY],e_mail[60], senha[TAMSENHA],fone[15], user[TAMUSER];
}Funcionario;

typedef struct {
   char	cod_curso[TAMPKEY], matricula[TAMPKEY], nome_curso[TAMPKEY];
   int ano;
   Data inicio, fim;
}Aluno_Curso;

typedef struct {
   char	estado[100],disponivel[4];
   int num_armario, ano_aluno_armario;
} Armario;

typedef struct {
   char	mat_aluno[TAMPKEY], mat_funcionario[TAMPKEY];
   int numero_armario, ano_aluno_reserva, cod_reserva;
} Reserva;

//variaveis globais utilizadas

Funcionario funcionarios[TAMFUNCIONARIOS];
Armario armarios[TAMARMARIOS];
Reserva reservas[TAMRESERVAS];
Curso cursos[TAMCURSOS];
Aluno_Curso a_cursos[TAMALUNOS];
Aluno alunos[TAMALUNOS];
int cont_funcionario, cont_armario, cont_reserva, cont_curso, cont_aluno,cont_exibe=1, na;
char func_atual[TAMPKEY], user_atual[TAMUSER];
//Fun��es

void ler_reserva_arquivo() {
	FILE *pont_arq;
	int cont = 0;
	pont_arq = fopen("reserva.txt", "r");
	if(pont_arq){
		while(fscanf(pont_arq, "%d%s%s%d%d", &reservas[cont].cod_reserva, reservas[cont].mat_aluno, reservas[cont].mat_funcionario, &reservas[cont].numero_armario, &reservas[cont].ano_aluno_reserva) != EOF) {
			cont++;
			cont_reserva++;
		}
		fclose(pont_arq);
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
}

void gravar_reserva_arquivo() {
	FILE *pont_arq;
	int i;
	pont_arq = fopen("reserva.txt", "a");
	if(pont_arq) {
		for(int pos = 0; pos < cont_reserva; pos++) {
			fprintf(pont_arq, "%d \n", reservas[pos].cod_reserva);
			fprintf(pont_arq, "%s \n", reservas[pos].mat_aluno);
			fprintf(pont_arq, "%s \n", reservas[pos].mat_funcionario);
			fprintf(pont_arq, "%d \n", reservas[pos].numero_armario);
			fprintf(pont_arq, "%d \n", reservas[pos].ano_aluno_reserva);
		}
		fclose(pont_arq);
	} else {
		printf("\nERRO ao abrir arquivo!\n");
	}
}

void ler_alunoCurso_arquivo() {
	FILE *pont_arq;
	int i, cont = 0;
	pont_arq = fopen("alunoCurso.txt", "r");
	if(pont_arq){
		while(fscanf(pont_arq, "%s%s%d%d%d", a_cursos[cont].matricula, a_cursos[cont].cod_curso, &a_cursos[cont].inicio.ano, &a_cursos[cont].fim.ano, &a_cursos[cont].ano) != EOF) {
			cont++;
		}
		fclose(pont_arq);
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
}

void gravar_alunoCurso_arquivo() {
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	int i;
	pont_arq = fopen("alunoCurso.txt", "w");
	if(pont_arq) {
		for(int pos = 0; pos < cont_aluno; pos++) {
			fprintf(pont_arq, "%s \n", a_cursos[pos].matricula);
			fprintf(pont_arq, "%s \n", a_cursos[pos].cod_curso);
			fprintf(pont_arq, "%d \n", a_cursos[pos].inicio.ano);
			fprintf(pont_arq, "%d \n", a_cursos[pos].fim.ano);
			fprintf(pont_arq, "%d \n", a_cursos[pos].ano);
		}
		fclose(pont_arq);
	} else {
		printf("\nERRO ao abrir arquivo!\n");
	}
}

void ler_aluno_arquivo() {
	FILE *pont_arq;
	int i, cont = 0;
	pont_arq = fopen("aluno.txt", "r");
	if(pont_arq){
		 //printf("\nDados lidos do arquivo aluno.txt:\n");
		while(fscanf(pont_arq, "%s%s%s%s%s", alunos[cont].matricula_a, alunos[cont].nome, alunos[cont].e_mail, alunos[cont].turma, alunos[cont].fone) != EOF) {
			for(i = 0; i <= strlen(alunos[cont].nome); i++) {
				if(alunos[cont].nome[i] == '_') {
					alunos[cont].nome[i] = ' ';
				}
			}
			cont++;
			cont_aluno++;
		}
		fclose(pont_arq);
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
}

void gravar_aluno_arquivo() {
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	int i;
	pont_arq = fopen("aluno.txt", "w");
	if(pont_arq) {
		for(int pos = 0; pos < cont_aluno; pos++) {
			for(i = 0; i < strlen(alunos[pos].nome); i++) {
				if(alunos[pos].nome[i] == ' ') {
					alunos[pos].nome[i] = '_';
				}
			}
			fprintf(pont_arq, "%s \n", alunos[pos].matricula_a);
			fprintf(pont_arq, "%s \n", alunos[pos].nome);
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
		while(fscanf(pont_arq, "%s%s%s%s%s%s", funcionarios[cont].matricula_f, funcionarios[cont].nome, funcionarios[cont].e_mail, funcionarios[cont].senha, funcionarios[cont].fone, funcionarios[cont].user) != EOF) {
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
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	int i;
	pont_arq = fopen("funcionario.txt", "w");
	if(pont_arq) {
		for(int pos = 0; pos < cont_funcionario; pos++) {
			for(i = 0; i <= strlen(funcionarios[pos].nome); i++) {
				if(funcionarios[pos].nome[i] == ' ') {
					funcionarios[pos].nome[i] = '_';
				}
			}
			fprintf(pont_arq, "%s \n", funcionarios[pos].matricula_f);
			fprintf(pont_arq, "%s \n", funcionarios[pos].nome);
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
		while(fscanf(pont_arq, "%i%s%s", &armarios[cont].num_armario, armarios[cont].estado, armarios[cont].disponivel) != EOF) {
			cont_armario++;
			cont++;
		}
		fclose(pont_arq);
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
}

void gravar_armario_arquivo() {
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	int i;
	pont_arq = fopen("armario.txt", "w");
	if(pont_arq) {
		for(int pos = 0; pos < cont_armario; pos++) {
			fprintf(pont_arq, "%d \n", armarios[pos].num_armario);
			fprintf(pont_arq, "%s \n", armarios[pos].estado);
			fprintf(pont_arq, "%s \n", armarios[pos].disponivel);
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
		while(fscanf(pont_arq, "%s%s", cursos[cont].COD, cursos[cont].nome) != EOF) {
			for(i = 0; i <= strlen(cursos[cont].nome); i++) {
				if(cursos[cont].nome[i] == '_') {
					cursos[cont].nome[i] = ' ';
				}
			}
			cont_curso++;
			cont++;
		}
		fclose(pont_arq);
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
}

void gravar_curso_arquivo() {
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	int i;
	pont_arq = fopen("curso.txt", "w");
	if(pont_arq) {
		for(int pos = 0; pos < cont_curso; pos++){
			for(i = 0; i < strlen(cursos[pos].nome); i++) {
				if(cursos[pos].nome[i] == ' ') {
					cursos[pos].nome[i] = '_';
				}
			}
			fprintf(pont_arq, "%s \n", cursos[pos].COD);
			fprintf(pont_arq, "%s \n", cursos[pos].nome);
		}
		fclose(pont_arq);
	} else {
		printf("\nERRO ao abrir arquivo!\n");
	}
}

void cadastrar_curso(){
			gotoxy(80,2);
			cout<<">Menu principal";
			gotoxy(80,3);
			cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Cadastrar";
	cout<<"\n\t---CADASTRO DE CURSO---";
	int sair = 0;
	char pkey[TAMPKEY];
	while(sair != 1) {
		cout<<"\nC�digo: ";
		scanf(" %[^\n]", pkey);
		for(int contador = 0; contador <= cont_curso; contador++){
			if(strcmp(cursos[contador].COD, pkey)!=0){
				if(contador == cont_curso) {
				   strcpy(cursos[contador].COD, pkey);
				}
				sair = 1;
			} else {
				cout << "C�digo j� existe!";
				sair = 0;
				break;
			}
		}
	}
	cout<<"\nNome: ";
	scanf(" %[^\n]",cursos[cont_curso].nome);
	cout<<"\n\tCURSO CADASTRADO!!";
	cont_curso++;
}

void cadastrar_armario(){
int cont;
 for(cont=1;cont<=TAMARMARIOS;cont++){
	armarios[cont].num_armario=cont;
	strcpy(armarios[cont].disponivel, "Sim");
	strcpy(armarios[cont].estado, "Bom");
	armarios[cont_armario].ano_aluno_armario=0;
	cont_armario++;
 }
}

void cadastrar_funcionario(){
	cout<<"\t---CADASTRO DE FUNCION�RIO---:";
	int sair = 0;
	char pkey[TAMPKEY];
	while(sair != 1) {
		cout<<"\nMatr�cula: ";
		scanf(" %[^\n]", pkey);
		for(int contador = 0; contador <= cont_funcionario; contador++){
			if(strcmp(funcionarios[contador].matricula_f, pkey)!=0){
				if(contador == cont_funcionario) {
				   strcpy(funcionarios[contador].matricula_f, pkey);
				}
				sair = 1;
			} else {
				cout << "Matr�cula j� existe!";
				sair = 0;
				break;
			}
		}
	}
	cout<<"\nNome: ";
	scanf(" %[^\n]",funcionarios[cont_funcionario].nome);
	cout<<"\nE-mail: ";
	scanf(" %[^\n]",funcionarios[cont_funcionario].e_mail);
	cout<<"\nFone: ";
	scanf(" %[^\n]",funcionarios[cont_funcionario].fone);
	char user[TAMUSER];
	sair = 0;
	while(sair != 1) {
		cout<<"\nUsu�rio: ";
		scanf(" %[^\n]", user);
		for(int contador = 0; contador <= cont_funcionario; contador++){
			if(strcmp(funcionarios[contador].user, user)!=0){
				if(contador == cont_funcionario) {
				   strcpy(funcionarios[contador].user, user);
				}
				sair = 1;
			} else {
				cout << "Usu�rio j� existe!";
				sair = 0;
				break;
			}
		}
	}
	cout<<"\nSenha de acesso \tOBS:(Lembre-se da senha informada!)\t(Max:30 caracteres)\n";
	scanf(" %[^\n]",funcionarios[cont_funcionario].senha);
	cout<<"\n\tFUNCION�RIO CADASTRADO!!";
	cont_funcionario++;

}

int pergunta(){
	int op;
	 while(op != 7){
			gotoxy(80,1);
			cout<<"Diret�rio:";
			gotoxy(80,2);
			cout<<">Menu principal";
			gotoxy(80,3);
			cout<<">>Menu Funcion�rio\n\n";
		cout<<"\n1-Funcion�rio\n2-Aluno\n3-Arm�rio\n4-Curso\n5-Voltar\n:";
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
					cout<<"Op��o inv�lida, tente novamente!\n:";
					break;
			}
	}
}

int buscar(int opcao) {
	int arm_busc, contador, para = 0, codInt;
	char matricula_a_busc[TAMPKEY], matricula_f_busc[TAMPKEY], cod_busc[TAMPKEY];
	while(para != 1) {
		switch(opcao){
			case 1:
				cout<<"\n\tInforme a matr�cula  do funcion�rio\n: ";
				scanf(" %[^\n]",matricula_f_busc);
				for(contador = 0; contador <= cont_funcionario; contador++){
					if(strcmp(funcionarios[contador].matricula_f, matricula_f_busc)==0){
						return contador;
					}
				}
				break;
			case 2:
				 cout<<"\n\tInforme a Matr�cula do aluno\n: ";
				 scanf(" %[^\n]",matricula_a_busc);
				 for(contador = 0; contador < cont_aluno; contador++){
					if(strcmp(alunos[contador].matricula_a,matricula_a_busc)==0){
						return contador;
					}
				}
				break;
			case 3:
				 cout<<"\n\tInforme o n�mero do arm�rio\n: ";
				cin>>arm_busc;
				for(contador = 0; contador < cont_armario; contador++){
					if(armarios[contador].num_armario==arm_busc){
						return contador;
					}
				}
				break;
			case 4:
				 cout<<"\n\tInforme o Cod do curso\n: ";
				 scanf(" %[^\n]",cod_busc);
				 for(contador = 0;contador < cont_curso; contador++){
					if(strcmp(cursos[contador].COD,cod_busc)==0){
						return contador;
					}
				}
			break;
			case 5:
				 cout<<"\n\tInforme o c�digo da reserva\n: ";
				 cin>> codInt;
				 for(contador = 0;contador < cont_reserva; contador++){
					if(reservas[contador].cod_reserva == codInt){
						return contador;
					}
				}
			break;
			case 6:
				 cout<<"\n\tInforme a matr�cula do aluno\n: ";
				 scanf(" %[^\n]",cod_busc);
				 for(contador = 0;contador < cont_aluno; contador++){
					if(strcmp(a_cursos[contador].matricula, cod_busc)==0){
						return contador;
					}
				}
			break;
		}
	}
}

void exibir_curso(int pos){
	int a=4;
	gotoxy(5,a+cont_exibe);
	cout<< "|" << cursos[pos].COD;
	gotoxy(19,a+cont_exibe);
	cout << "|" << cursos[pos].nome;
	gotoxy(32,a+cont_exibe);
	cout<<"|";
	gotoxy(5,a+cont_exibe+1);
	cout<<"----------------------------";
	cont_exibe=cont_exibe+2;
}

void exibir_funcionario(int pos) {
	int a=4;
	gotoxy(5,cont_exibe+a);
	cout<< "| " << funcionarios[pos].matricula_f;
	gotoxy(33,cont_exibe+a);
	cout << "| " << funcionarios[pos].nome;
	gotoxy(60,cont_exibe+a);
	cout << "| "<< funcionarios[pos].e_mail;
	gotoxy(80,cont_exibe+a);
	cout << "| "<< funcionarios[pos].fone;
	gotoxy(95,a+cont_exibe);
	cout<<"|";
	gotoxy(5,cont_exibe+a+1);
	cout<<"-------------------------------------------------------------------------------------------";
	cont_exibe=cont_exibe+2;
}

void exibir_reserva(int pos) {
	int a=4;
	gotoxy(5,cont_exibe+a);
	cout<< "| " << reservas[pos].cod_reserva;
	gotoxy(15,cont_exibe+a);
	cout << "| " << reservas[pos].mat_aluno;
	gotoxy(35,cont_exibe+a);
	cout << "| "<< reservas[pos].mat_funcionario;
	gotoxy(60,cont_exibe+a);
	cout << "| "<< reservas[pos].numero_armario;
	gotoxy(75,cont_exibe+a);
	cout << "| "<< reservas[pos].ano_aluno_reserva;
	gotoxy(95, cont_exibe+a);
	cout<<"|";
	gotoxy(5,cont_exibe+a+1);
	cout<<"-------------------------------------------------------------------------------------------";
	cont_exibe=cont_exibe+2;
}

void exibir_armario(int pos) {
	int a=4;
	gotoxy(5,a+cont_exibe);
	cout << "| " << armarios[pos].num_armario;
	gotoxy(15,a+cont_exibe);
	cout<< "| " << armarios[pos].disponivel;
	gotoxy(35,a+cont_exibe);
	cout<< "| " << armarios[pos].estado;
	gotoxy(47,a+cont_exibe);
	cout<<"|";
	gotoxy(5,a+cont_exibe+1);
	cout<<"-------------------------------------------";
	cont_exibe=cont_exibe+2;
}

void exibir_aluno(int pos) {
	int a=4;
	gotoxy(5,a+cont_exibe);
	cout << "| " << alunos[pos].matricula_a;
	gotoxy(33,a+cont_exibe);
	cout << "| " << alunos[pos].nome;
	gotoxy(63,a+cont_exibe);
	cout << "| " << alunos[pos].e_mail;
	gotoxy(75,a+cont_exibe);
	cout << "| " << alunos[pos].fone;
	gotoxy(90,a+cont_exibe);
	cout << "| " << alunos[pos].turma;
	gotoxy(100,a+cont_exibe);
	cout<<"|";
	gotoxy(5,a+cont_exibe+1);
	cout<<"------------------------------------------------------------------------------------------------";
	cont_exibe=cont_exibe+2;
}

void exibir_alunoCurso(int pos) {
	int a=4;
	gotoxy(5,a+cont_exibe);
	cout << "| " << a_cursos[pos].matricula;
	gotoxy(25,a+cont_exibe);
	cout << "| " << a_cursos[pos].cod_curso;
	gotoxy(40,a+cont_exibe);
	cout << "| " << a_cursos[pos].inicio.ano;
	gotoxy(60,a+cont_exibe);
	cout << "| " << a_cursos[pos].fim.ano;
	gotoxy(80,a+cont_exibe);
	cout << "| " << a_cursos[pos].ano;
	gotoxy(95,a+cont_exibe);
	cout<<"|";
	gotoxy(5,a+cont_exibe+1);
	cout<<"-------------------------------------------------------------------------------------------";
	cont_exibe=cont_exibe+2;
}

void cabecalho_curso(){
	cout<<"Lista dos Curso(s)";
	gotoxy(5,2);
	cout<<"----------------------------";
	gotoxy(5,3);
	cout<<"| COD";
	gotoxy(19,3);
	cout<<"| Nome";
	gotoxy(32,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"----------------------------";
}

void cabecalho_reserva() {
	cout<<"Lista de Reserva(s)";
	gotoxy(5,2);
	cout<<"-------------------------------------------------------------------------------------------";
	gotoxy(5,3);
	cout<<"| C�digo";
	gotoxy(15,3);
	cout<<"| Matr�cula aluno";
	gotoxy(35,3);
	cout<<"| Matr�cula funcion�rio";
	gotoxy(60,3);
	cout<<"| N� arm�rio";
	gotoxy(75,3);
	cout<<"| Ano aluno";
	gotoxy(95,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"-------------------------------------------------------------------------------------------";
}

void cabecalho_aluno(){
	cout<<"Lista dos Aluno(s)";
	gotoxy(5,2);
	cout<<"------------------------------------------------------------------------------------------------";
	gotoxy(5,3);
	cout<<"| Matr�cula";
	gotoxy(33,3);
	cout<<"| Nome";
	gotoxy(63,3);
	cout<<"| E-mail";
	gotoxy(75,3);
	cout<<"| Fone";
	gotoxy(90,3);
	cout<<"| Turma";
	gotoxy(100,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"------------------------------------------------------------------------------------------------";
}

void cabecalho_funcionario(){
	cout<<"Lista dos Funcion�rio(s)";
	gotoxy(5,2);
	cout<<"-------------------------------------------------------------------------------------------";
	gotoxy(5,3);
	cout<<"| Matr�cula";
	gotoxy(33,3);
	cout<<"| Nome";
	gotoxy(60,3);
	cout<<"| E-mail";
	gotoxy(80,3);
	cout<<"| Fone";
	gotoxy(95,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"-------------------------------------------------------------------------------------------";
}

void cabecalho_alunoCurso(){
	cout<<"Lista de aluno-curso(s)";
	gotoxy(5,2);
	cout<<"-------------------------------------------------------------------------------------------";
	gotoxy(5,3);
	cout<<"| Matr�cula aluno";
	gotoxy(25,3);
	cout<<"| COD curso";
	gotoxy(40,3);
	cout<<"| Data de inicio";
	gotoxy(60,3);
	cout<<"| Data de Fim";
	gotoxy(80,3);
	cout<<"| ano";
	gotoxy(95,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"-------------------------------------------------------------------------------------------";
}

void cabecalho_armario(){
	cout<<"Lista dos Arm�rio(s)";
	gotoxy(5,2);
	cout<<"-------------------------------------------";
	gotoxy(5,3);
	cout<<"| N�mero";
	gotoxy(15,3);
	cout<<"| Disponibilidade";
	gotoxy(35,3);
	cout<<"| Situa��o";
	gotoxy(47,3);
	cout<<"|";
	gotoxy(5,4);
	cout<<"-------------------------------------------";
}

void exibir(int escolha){
	int op=escolha, tipo=0, contador, i, pos;
	while(escolha!=7){
	switch(escolha){
	system("cls");
	case 1:
		cont_exibe=1;
		while(tipo<1 || tipo>2){
			cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			cin>>tipo;
		}
		if(tipo==1){
				system("cls");
				cabecalho_funcionario();
			for(contador=0;contador<cont_funcionario;contador++){
				exibir_funcionario(contador);
				}
			}if(tipo==2) {
					pos = buscar(op);
					system("cls");
					cabecalho_funcionario();
					exibir_funcionario(pos);
				}
		break;
	case 2:
		cont_exibe=1;
		while(tipo<1 || tipo>2){
			cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			cin>>tipo;
		}
		if(tipo==1){
			system("cls");
			cabecalho_aluno();
			for(contador=0;contador<cont_aluno;contador++){
				exibir_aluno(contador);
			}
			}
			if(tipo==2){
					pos = buscar(op);
					system("cls");
					cabecalho_aluno();
					exibir_aluno(pos);
				}
		break;
	case 3:
		cont_exibe=1;
		 while(tipo<1 || tipo>2){
			  cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			  cin>>tipo;
		}
		if(tipo==1){
			system("cls");
			cabecalho_armario();
			for(contador=1;contador<cont_armario;contador++){
				exibir_armario(contador);
			}
			}else{
				pos = buscar(op);
				system("cls");
				cabecalho_armario();
				exibir_armario(pos);
			}
		break;
	case 4:
		cont_exibe=1;
		while(tipo<1 || tipo>2){
			cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			cin>>tipo;
		}
		if(tipo==1){
			system("cls");
			cabecalho_curso();
			for(contador=0;contador<cont_curso;contador++){
				exibir_curso(contador);
			}
			}else{
				if(cont_curso == 0) {
					cout << "N�o existem cursos cadastrados!";
				} else {
					pos = buscar(op);
					system("cls");
					cabecalho_curso();
					exibir_curso(pos);
				}
			}
			break;
		case 5:
		cont_exibe=1;
		while(tipo<1 || tipo>2){
			cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			cin>>tipo;
		}
		if(tipo==1){
			system("cls");
			cabecalho_reserva();
			for(contador=0;contador<cont_reserva;contador++){
				exibir_reserva(contador);
			}
			}else{
				if(cont_reserva == 0) {
					cout << "N�o existem cursos cadastrados!";
				} else {
					pos = buscar(op);
					system("cls");
					cabecalho_reserva();
					exibir_reserva(pos);
				}
			}
			break;
		case 6:
		cont_exibe=1;
		while(tipo<1 || tipo>2){
			cout<<"Como deseja exibir?\n\n1-TUDO\n2-SEPARADAMENTE\n:";
			cin>>tipo;
		}
		if(tipo==1){
			system("cls");
			cabecalho_alunoCurso();
			for(contador=0;contador<cont_aluno;contador++){
				exibir_alunoCurso(contador);
			}
			}else{
				if(cont_aluno == 0) {
					cout << "N�o existem cursos cadastrados!";
				} else {
					pos = buscar(op);
					system("cls");
					cabecalho_alunoCurso();
					exibir_alunoCurso(pos);
				}
			}
			break;
			default:
				break;
		}
		break;
	}
 }

void escolher_curso(){
	int contador, sair=0;
	char COD[TAMPKEY];

	while(sair != 1) {
	gotoxy(80,2);
	cout<<">Menu principal";
	gotoxy(80,3);
	cout<<">>Menu Funcion�rio\n";
	gotoxy(80,4);
	cout<<">>>Cadastrar";
	gotoxy(80,5);
	cout<<">>>>Aluno";
	gotoxy(80,6);
	cout<<">>>>>Escolhendo o curso";
	gotoxy(2,1);
	cont_exibe = 1;
	cabecalho_curso();
	for(contador=0;contador<cont_curso;contador++){
		exibir_curso(contador);
	}
	cout << "\nEscolha o Cod\n:";
		scanf(" %[^\n]", COD);
		for(contador=0;contador<=cont_curso; contador++){
			if(strcmp(COD,cursos[contador].COD)==0){
				   strcpy(a_cursos[cont_aluno].nome_curso,cursos[contador].nome);
				   strcpy(a_cursos[cont_aluno].cod_curso,COD);
				sair = 1;
				break;
			}if(contador==cont_curso) {
				cout << "Matr�cula n�o existe!";
				sair = 0;
				break;
			}
		}
	}
}

void reservar_armario(char pkey[TAMPKEY]){
	reservas[cont_reserva].cod_reserva = cont_reserva+1;
	strcpy(reservas[cont_reserva].mat_funcionario,func_atual);
	int contador;
	for(int contador = 0; contador < cont_aluno; contador++){
		if(strcmp(alunos[contador].matricula_a, pkey)==0){
				strcpy(reservas[cont_reserva].mat_aluno,pkey);
				reservas[cont_reserva].ano_aluno_reserva=alunos[contador].ano_aluno;
				armarios[na].ano_aluno_armario=alunos[contador].ano_aluno;
		}
	}
	reservas[cont_reserva].numero_armario = cont_reserva+1;
	na=reservas[cont_reserva].numero_armario;
	strcpy( armarios[na].disponivel, "n�o");
	printf("\nArm�rio reservado!\nO c�digo de reserva � : %d\n",reservas[cont_reserva].cod_reserva);
	cont_reserva++;
	na++;
}

void cadastrar_aluno(){
	cout<<"\t---CADASTRO DE ALUNO---: ";
	int sair = 0, contador, op=0;
	char pkey[TAMPKEY];
	while(sair != 1) {
		cout<<"\nMatr�cula: ";
		scanf(" %[^\n]", pkey);
		for(contador = 0; contador <= cont_aluno; contador++){
			if(strcmp(alunos[contador].matricula_a, pkey)!=0){
				if(contador == cont_aluno) {
				   strcpy(alunos[contador].matricula_a, pkey);
				}
				sair = 1;
			} else {
				cout << "Matr�cula j� existe!";
				sair = 0;
				break;
			}
		}
	}
	cout<<"\nNome:";
	scanf(" %[^\n]",alunos[cont_aluno].nome);
	strcpy(a_cursos[cont_aluno].matricula,alunos[cont_aluno].matricula_a);
	cout<<"\nTurma:";
	scanf(" %[^\n]",alunos[cont_aluno].turma);
	cout<<"\nFone para contato: ";
	scanf(" %[^\n]",alunos[cont_aluno].fone);
	cout<<"\nE-mail: ";
	scanf(" %[^\n]",alunos[cont_aluno].e_mail);
	if(cont_curso == 0) {
		system("cls");
		gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Menu Funcion�rio\n";
		gotoxy(80,4);
		cout<<">>>Cadastrar";
		gotoxy(80,5);
		cout<<">>>>Aluno";
		gotoxy(80,6);
		cout<<">>>>>Cadastrando primeiro curso";
		gotoxy(2,2);
		printf("\nAinda n�o existem cursos cadastrados, cadastre um novo curso \n");
		cadastrar_curso();
	}
	system("cls");
	escolher_curso();
	cout<<"\nS�rie cursada: ";
	cin >>alunos[cont_aluno].ano_aluno;
	a_cursos[cont_aluno].ano = alunos[cont_aluno].ano_aluno;
	cout<<"\nAno de in�cio do curso: ";
	cin >>a_cursos[cont_aluno].inicio.ano;
	cout<<"\nAno de fim do curso: ";
	cin >>a_cursos[cont_aluno].fim.ano;
	cout<<"\n\tALUNO CADASTRADO!!\n";
	cont_aluno++;
	if(cont_reserva == TAMRESERVAS){
		cout << "Arm�rios lotados!!";
	} else {
	    while(op<1 || op>2){
        cout << "Cadastrar arm�rio automaticamente?\n";
        cout << "Sim[1]\nN�o[2]\n:";
        cin>>op;
	    }
        if(op==1){
		reservar_armario(pkey);
        }
	}
}

void cadastrar(int op_c){
	while(op_c!=5){
	switch(op_c){
	case 1:
		system("cls");
		  gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Menu Funcion�rio";
		gotoxy(80,4);
		cout<<">>>Cadastrar\n";
		gotoxy(5,2);
		cadastrar_funcionario();
	break;
	case 2:
		system("cls");
		  gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Menu Funcion�rio";
		gotoxy(80,4);
		cout<<">>>Cadastrar\n";
		gotoxy(5,2);
		cadastrar_aluno();
		break;
	case 3:
		system("cls");
	   cout<<"Arm�rios Cadastrados automaticamente";
		break;
	case 4:
		system("cls");
		  gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Menu Funcion�rio";
		gotoxy(80,4);
		cout<<">>>Cadastrar";
		gotoxy(5,2);
		cadastrar_curso();
	break;
	default:
		break;
	}
	break;
  }
}

void armarios_disponiveis() {
	int compara, contador;
			gotoxy(80,2);
			cout<<">Menu principal";
			gotoxy(80,3);
			cout<<">>Menu Aluno";
			 gotoxy(80,4);
			 cout<<">>>Arm�rios dispon�veis";
			 gotoxy(1,2);
	cout<<"Informe o ano letivo: ";
	cin>>compara;
	system("cls");
	cabecalho_armario();
for(contador=0;contador<cont_armario;contador++){
	if((armarios[contador].ano_aluno_armario==0) || (armarios[contador].ano_aluno_armario<compara)){
		exibir_armario(contador);
	}
}
	cout<<"\n";
}

void exibir_termo_compromisso() {
	//Criando uma vari�vel ponteiro para o arquivo
	FILE *pont_arq;
	char c;
	//Abrindo arquivo para grava��o
	pont_arq = fopen("termo_compromisso.txt", "r");

	//Testando abertura do arquivo
	if(pont_arq == NULL) {
		printf("\n\nErro: O arquivo termo_compromisso.txt n�o pode ser aberto\n");
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
	while(opcao != 3) {
		system("cls");
			gotoxy(80,2);
			cout<<">Menu principal";
			gotoxy(80,3);
			cout<<">>Menu Aluno";
		cout << "\nBem vindo, Aluno\n";
		cout << "O que voc� quer fazer? ";
		cout << "\nVer arm�rios dispon�veis [1] \nTermo de compromisso [2] \nVoltar [3]\n";
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
			system("pause");
			break;
		default:
			cout << "Op��o inv�lida! ";
			system("pause");
			system("cls");
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
	cout << "Arm�rio exclu�do com sucesso!\n";
	system("pause");
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
	cout << "Curso exclu�do com sucesso!\n";
	system("pause");
	cont_curso--;
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
	cout << "Aluno exclu�do com sucesso!\n";
	system("pause");
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
	cout << "Funcion�rio exclu�do com sucesso!\n";
	system("pause");
	cont_funcionario--;
}

void excluir_reserva(int pos){
    int i;
	for(int i = pos; i <= cont_reserva; i++) {
			if(i==TAMRESERVAS){
			strcpy(reservas[i].mat_aluno, "");
			strcpy(reservas[i].mat_funcionario, "");
			reservas[i].ano_aluno_reserva=0;
			reservas[i].cod_reserva=0;
			reservas[i].numero_armario=0;
			}else{
			reservas[i]=reservas[i+1];
			}
	}
	cout << "Reserva exclu�do com sucesso!\n";
	system("pause");
	cont_reserva--;
}

void excluir(){
	int op;
	do{
    system("cls");
    gotoxy(80,1);
    cout<<"Diret�rio:";
    gotoxy(80,2);
    cout<<">Menu principal";
    gotoxy(80,3);
    cout<<">>Menu Funcion�rio";
    gotoxy(80,4);
    cout<<">>>Excluir\n";
    gotoxy(5,2);
    cout<<"O que quer excluir?\n";
    cout<<"1-Funcion�rio\n2-Aluno\n3-Arm�rio\n4-Curso\n5-Reserva\n6-Sair\n:";
    cin>>op;
	switch(op){
	case 1:
		excluir_funcionario(buscar(1));
		break;
	case 2:
		if(cont_aluno == 0) {
			cout << "N�o existem alunos cadastrados!\n";
			system("pause");
			break;
		}
		excluir_aluno(buscar(2));
		break;
	case 3:
		excluir_armario(buscar(3));
		break;
	case 4:
		if(cont_curso == 0) {
			cout << "N�o existem cursos cadastrados!\n";
			system("pause");
			break;
		}
		excluir_curso(buscar(4));
    break;
    case 5:
        if(cont_reserva == 0) {
			cout << "N�o existem reservas cadastradas!\n";
			system("pause");
			break;
		}
        excluir_reserva(buscar(5));
    break;
    default:
    break;
	}
  }while(op!=6);
}

void alterarFuncionario(int pos){
            int i, op;
            do{
            system("cls");
            gotoxy(80,2);
            cout<<">Menu principal";
            gotoxy(80,3);
            cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Alterar funcion�rio\n";
			gotoxy(80,5);
			cout<<">>>Escolhendo o campo\n";
			gotoxy(5,2);
                printf("\nQual campo?\n\t1 - Nome\n\t2 - E-mail\n\t3 - Telefone\n\t4 - USER\n\t5 - Senha\n\t6 - Sair\n\t");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        system("cls");
                        cout<<"\nNovo nome: ";
                        scanf(" %[^\n]",funcionarios[pos].nome);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 2:
                        system("cls");
                        cout<<"\nNovo e-mail: ";
                        scanf(" %[^\n]",funcionarios[pos].e_mail);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 3:
                      system("cls");
                        cout<<"\nNovo telefone: ";
                        scanf(" %[^\n]",funcionarios[pos].fone);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 4:
                        system("cls");
                        cout<<"\nNovo USER :";
                        scanf(" %[^\n]",funcionarios[pos].user);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                      case 5:
                        system("cls");
                        cout<<"\nNova senha:";
                        scanf(" %[^\n]",funcionarios[pos].senha);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 6:
                    break;
                    default:
                        printf("\n\tOp��o inv�lida!\n\t");
  }
 }while(op != 6);
}

void alterarAluno(int pos){
            int i, op;
            do{
            system("cls");
            gotoxy(80,2);
            cout<<">Menu principal";
            gotoxy(80,3);
            cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Alterar aluno\n";
			gotoxy(80,5);
			cout<<">>>Escolhendo o campo\n";
			gotoxy(5,2);
                printf("\nQual campo?\n\t1 - Nome\n\t2 - E-mail\n\t3 - Telefone\n\t4- S�rie cursada\n\t5- Sair\n\t");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        system("cls");
                        cout<<"\nNovo nome: ";
                        scanf(" %[^\n]",alunos[pos].nome);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 2:
                        cout<<"\nNovo e-mail: ";
                        scanf(" %[^\n]",alunos[pos].e_mail);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 3:
                        cout<<"\nNovo telefone: ";
                        scanf(" %[^\n]",alunos[pos].fone);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 4:
                        cout<<"\nNovo s�rie:";
                        cin>>alunos[pos].ano_aluno;
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                      case 5:
                     break;
                    default:
                        printf("\n\tOp��o inv�lida!\n\t");
  }
 }while(op != 5);
}

void alterarArmario(int pos){
            int i, op;
            do{
            system("cls");
            gotoxy(80,2);
            cout<<">Menu principal";
            gotoxy(80,3);
            cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Alterar arm�rio\n";
			gotoxy(80,5);
			cout<<">>>Escolhendo o campo\n";
			gotoxy(5,2);
                printf("\nQual campo?\n\t1 -Disponiblidade\n\t2 -Estado\n\t3- Sair\n\t");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        system("cls");
                        cout<<"\nNova disponibilidade: ";
                        scanf(" %[^\n]",armarios[pos].disponivel);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 2:
                        cout<<"\nNovo estado: ";
                        scanf(" %[^\n]",armarios[pos].estado);
                        printf("\n\tDado atualizado!\n\t");
                        system("pause");
                    break;
                    case 3:
                    break;
                    default:
                        printf("\n\tOp��o inv�lida!\n\t");
  }
 }while(op != 3);

}

void alterarCurso(int pos){
            system("cls");
            gotoxy(80,2);
            cout<<">Menu principal";
            gotoxy(80,3);
            cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Alterar Curso\n";
			gotoxy(2,3);
			cout<<"Novo nome:";
            scanf(" %[^\n]",cursos[pos].nome);
            printf("\n\tNova informa��o cadastrada!\n\t");
            system("pause");
}

void alterarCursoAluno(int pos){
    int cont;
    char COD[TAMPKEY];
    system("cls");
    cabecalho_curso();
    for(cont=0;cont<cont_curso;cont++){
        exibir_curso(cont);
    }
    cout << "\nEscolha o Cod\n:";
		scanf(" %[^\n]", COD);
		for(cont=0;cont<=cont_curso; cont++){
			if(strcmp(COD,cursos[cont].COD)==0){
				   strcpy(a_cursos[pos].nome_curso,cursos[cont].nome);
				   strcpy(a_cursos[pos].cod_curso,COD);
				   cout<<"\nDado atualizado\n";
				   system("pause");
				break;
			}if(cont==cont_curso) {
				cout << "Matr�cula n�o existe!";
				break;
			}
		}
}

void menuAlterar(){
                int op;
                do{
            system("cls");
            gotoxy(80,2);
            cout<<">Menu principal";
            gotoxy(80,3);
            cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Alterar\n";
			gotoxy(5,2);
                    printf("\nO que quer alterar?\n\t1 - Funcion�rio\n\t2 - Aluno\n\t3 - Arm�rio\n\t4 - Curso\n\t5 - Curso do aluno\n\t6 - Sair\n\t");
                    scanf("%d", &op);
                    switch(op){
                        case 1:
                             alterarFuncionario(buscar(1));
                        break;
                        case 2:
                            if(cont_aluno!=0){
                            alterarAluno(buscar(2));
                            }else{
                                cout<<"N�o existem alunos cadastrados\n";
                                 system("pause");
                            }
                        break;
                        case 3:
                          alterarArmario(buscar(3));
                        break;
                        case 4:
                             if(cont_curso!=0){
                            alterarCurso(buscar(4));
                            }else{
                                cout<<"N�o existem cursos cadastrados\n";
                                system("pause");
                            }
                        break;
                        case 5:
                            if(cont_curso==0){
                                cout<<"N�o existem cursos cadastrados\n";
                                system("pause");
                            }else{
                             if(cont_curso>1){
                             alterarCursoAluno(buscar(6));
                             }
                            }
                            if(cont_curso==1){
                                cout<<"S� existe um curso cadastrado\n";
                                system("pause");
                            }
                        break;
                        case 6:
                        break;
                        default:
                             printf("\n\tOp��o Inv�lida!\n\t");
                    }
                }while(op!= 6);
}

void imprimir_aluno_arquivo(){
	int i;
	FILE* arquivo =fopen("relatorioAluno.txt","w");
	fprintf(arquivo,"Relat�rio de Alunos cadastrados:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|Matricula\t\t|");
	fprintf(arquivo,"Nome\t\t|");
	fprintf(arquivo,"Email\t\t|");
	fprintf(arquivo, "Telefone\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_aluno; i++) {
		fprintf(arquivo,"|%s\t\t|", alunos[i].matricula_a);
		fprintf(arquivo,"%s\t\t|", alunos[i].nome);
		fprintf(arquivo,"%s\t\t|", alunos[i].e_mail);
		fprintf(arquivo,"%s\t\t|\n", alunos[i].fone);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}
	fprintf(arquivo, "\n");
	fclose(arquivo);
}

void imprimir_funcionario_Arquivo(){

	int i;
	FILE* arquivo =fopen("relatorioFuncion�rio.txt","w");
	fprintf(arquivo,"Relat�rio de Funcion�rios cadastrados:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|Matricula\t\t|");
	fprintf(arquivo,"Nome\t\t|");
	fprintf(arquivo,"Email\t\t|");
	fprintf(arquivo, "Telefone\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_funcionario; i++) {
		fprintf(arquivo,"|%s\t\t|", funcionarios[i].matricula_f);
		fprintf(arquivo,"%s\t\t|", funcionarios[i].nome);
		fprintf(arquivo,"%s\t\t|", funcionarios[i].e_mail);
		fprintf(arquivo,"%s\t\t|\n", funcionarios[i].fone);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}
	fprintf(arquivo, "\n");
	fclose(arquivo);
}
void imprimir_curso_arquivo(){

	int i;
	FILE* arquivo =fopen("relatorioCurso.txt","w");
	fprintf(arquivo,"Relat�rio de Cursos cadastrados:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|C�digo\t\t|");
	fprintf(arquivo,"Nome\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_aluno; i++) {
		fprintf(arquivo,"|%s\t\t|", cursos[i].COD);
		fprintf(arquivo,"%s\t\t|\n", cursos[i].nome);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}
	fprintf(arquivo, "\n");
	fclose(arquivo);
}
void imprimir_aluno_curso_arquivo(){

	int i;
	FILE* arquivo =fopen("relatorioAlunoCurso.txt","w");
	fprintf(arquivo,"Relat�rio de Alunos cadastrados em seus respectivos cursos:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|Matricula do Aluno\t\t|");
	fprintf(arquivo,"Nome\t\t|");
	fprintf(arquivo,"C�digo do curso\t\t|");
	fprintf(arquivo, "Nome do Curso\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_aluno; i++) {
		fprintf(arquivo,"|%s\t\t|", a_cursos[i].matricula);
		fprintf(arquivo,"%s\t\t|", alunos[i].nome);
		fprintf(arquivo,"%s\t\t|", a_cursos[i].cod_curso);
		fprintf(arquivo,"%s\t\t|\n", a_cursos[i].nome_curso);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}
	fprintf(arquivo, "\n");
	fclose(arquivo);
}
void imprimir_reserva_arquivo(){
	int i;
	FILE* arquivo =fopen("relatorioReserva.txt","w");
	fprintf(arquivo,"Relat�rio de Reservas realizadas:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|Cod Reserva\t\t|");
	fprintf(arquivo,"Matr�cula do funcion�rio\t\t|");
	fprintf(arquivo,"Matr�cula do Aluno\t\t|");
	fprintf(arquivo, "N�mero do arm�rio\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_reserva; i++) {
		fprintf(arquivo,"|%d\t\t|",reservas[i].cod_reserva);
		fprintf(arquivo,"%s\t\t|", reservas[i].mat_funcionario);
		fprintf(arquivo,"%s\t\t|", reservas[i].mat_aluno);
		fprintf(arquivo,"%d\t\t|\n", reservas[i].numero_armario);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}

	fprintf(arquivo, "\n");
	fclose(arquivo);
}

void imprimir_armario_arquivo(){
	int i;
	FILE* arquivo =fopen("relatorioArm�rio.txt","w");
	fprintf(arquivo,"Relat�rio de arm�rios cadastrados:\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "|N�mero\t\t|");
	fprintf(arquivo,"Disponibilidade\t\t|");
	fprintf(arquivo,"Estado\t\t|\n");
	fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < cont_armario; i++) {
		fprintf(arquivo,"|%d\t\t|", armarios[i].num_armario);
		fprintf(arquivo,"%s\t\t|", armarios[i].disponivel);
		fprintf(arquivo,"%s\t\t|\n", armarios[i].estado);
		fprintf(arquivo, "---------------------------------------------------------------------------------------------------\n");
	}
	fprintf(arquivo, "\n");
	fclose(arquivo);
}

void menuFuncionario() {
	int opcao=1, exibe=0;
		while(opcao != 0) {
		system("cls");
		gotoxy(80,1);
        cout<<"Diret�rio:";
        gotoxy(80,2);
        cout<<">Menu principal";
        gotoxy(80,3);
        cout<<">>Menu Funcion�rio\n";
		cout << "Bem vindo, "<<user_atual<<"\n";
		cout << "\nO que voc� quer fazer? ";
		cout << "\nVoltar [0] \nCadastrar[1]\nExcluir [2]\nAlterar[3]\nExibir[4]\nReservar arm�rio[5]\n:";
	   scanf("%d", &opcao);
		switch(opcao) {
		case 0:
			system("cls");
			cout << "Voltando ao menu principal...\n";
			system("pause");
			break;
		case 1:
			system("cls");
			gotoxy(80,4);
			cout<<">>>Cadastrar\n";
			gotoxy(5,2);
			cout<<"O que quer cadastrar?\n";
			cadastrar(pergunta());
			cout << "\n";
			system("pause");
			break;
		case 2:
        excluir();
			cout<<"\n";
			system("pause");
			break;
		case 3:
			menuAlterar();
			system("pause");
			break;
		case 4:
			while(exibe<1 || exibe>7){
			system("cls");
			gotoxy(80,1);
			cout<<"Diret�rio:";
				gotoxy(80,2);
			cout<<">Menu principal";
			gotoxy(80,3);
			cout<<">>Menu Funcion�rio";
			gotoxy(80,4);
			cout<<">>>Exibir";
			gotoxy(2,2);
			cout<<"O que quer exibir?\n";
			cout<<"\n1-Funcion�rio\n2-Aluno\n3-Arm�rio\n4-Curso\n5-Reservas\n6-Aluno-cursos\n7-Voltar\n:";
			cin>>exibe;
			}
			exibir(exibe);
			cout << "\n";
			system("pause");
            exibe=0;
        break;
        case 5:
            if(cont_aluno!=0){
            reservar_armario(alunos[buscar(2)].matricula_a);
            system("pause");
            }else{
                cout<<"\nN�o existem alunos cadastrados\n";
                 system("pause");
            }
        break;
		default:
			cout << "Op��o inv�lida!\n\n";
			system("pause");
			break;
		}
	}

}

void login() {
	char usuario[TAMUSER], senha[TAMSENHA];
	int sair = 0;
		gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Login de Funcion�rio";
		cout<<"\nUsu�rio: ";
		scanf(" %[^\n]", usuario);
		for(int contador = 0; contador <= cont_funcionario; contador++) {
			if(strcmp(funcionarios[contador].user, usuario)==0){
		while(sair<3) {
			system("cls");
		gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(80,3);
		cout<<">>Login de Funcion�rio";
		cout<<"\nUsu�rio : "<<usuario;
		cout<<"\nSenha: ";
		scanf(" %[^\n]", senha);
				if(strcmp(funcionarios[contador].senha, senha)==0) {
					strcpy(func_atual, funcionarios[contador].matricula_f);
					strcpy(user_atual, funcionarios[contador].user);
					menuFuncionario();
					break;
				} else {
					cout << "Senha inv�lida\n";
					sair++;
				}
				if(sair==3){
					cout<<"M�ximo de tentativas gastos\n";
					system("pause");
				}
			}
			break;
			}if(contador==cont_funcionario){
				cout << "Usu�rio n�o encontrado\n";
				system("pause");
				sair = 0;
			}
		}
}

void menu(){
	int opcao;
	while(opcao != 3) {
		system("cls");
		gotoxy(80,1);
		cout<<"Diret�rio:";
		gotoxy(80,2);
		cout<<">Menu principal";
		gotoxy(1,1);
		cout << "\nQuem est� acessando? ";
		cout << "\nAluno [1] \nFuncion�rio [2]\nSair [3]\n:";
	   scanf("%d", &opcao);
	   //getchar();
		switch(opcao) {
		case 1:
			system("cls");
			menuAluno();
			break;
		case 2:
			system("cls");
			if(cont_funcionario==0){
	gotoxy(80,2);
	cout<<">Menu principal";
	gotoxy(80,3);
	cout<<">>Cadastrando primeiro funcion�rio";
	gotoxy(2,2);
				cout<<"N�o existe Funcion�rio cadastrado!\n";
				cadastrar_funcionario();
			}
			system("cls");
			login();
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
	cout << "Lendo dados dos arquivos aguarde...";
	ler_funcionario_arquivo();
	ler_aluno_arquivo();
	ler_armario_arquivo();
	ler_curso_arquivo();
	ler_reserva_arquivo();
	ler_alunoCurso_arquivo();
	if(cont_armario==0){
	 cadastrar_armario();
	}
	menu();
	gravar_aluno_arquivo();
	gravar_armario_arquivo();
	gravar_curso_arquivo();
	gravar_funcionario_arquivo();
	gravar_reserva_arquivo();
	gravar_alunoCurso_arquivo();
	imprimir_aluno_arquivo();
	imprimir_aluno_curso_arquivo();
	imprimir_armario_arquivo();
	imprimir_curso_arquivo();
	imprimir_funcionario_Arquivo();
	imprimir_reserva_arquivo();
}
