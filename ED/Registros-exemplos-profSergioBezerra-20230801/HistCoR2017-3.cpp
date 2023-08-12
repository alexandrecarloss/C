//Nome do programa: HistCoRI.cpp
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

#define  TAMCONJ 100
using namespace std;
//definição da estrutura de um registro de conjuntos de um aluno
typedef struct {
   char	  disciplina[30], situacao;
   float  notas[5];
   int	  faltas;
} HistoricoEscolar;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int i, ano, disciplinaEncontrada, posicaoDisciplina, tamConj = 1;
char aluno[50], nomeDisciplina[30];


void gotoxy(int x, int y){
  CursorPosition.X = x; // Locates column
  CursorPosition.Y = y; // Locates Row
  SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

int menu() {
    int opcao;
    do {
        system("cls");
        cout << "-------------------------------------------------------";
        gotoxy(15, 1);
        cout << "<<  Menu de opcoes  >>";
        cout << "\n1 - Adicionar registro";
        cout << "\n2 - Pesquisar registro";
        cout << "\n3 - Editar registro";
        cout << "\n4 - Excluir registro";
        cout << "\n5 - Sair\n";
        scanf("%i", &opcao);
    } while((opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao != 4) && (opcao != 5));
    system("cls");
    return opcao;
}

void media(HistoricoEscolar *ficha2017) {
    //Processamento da media e da situação dos alunos nas disciplinas
   for(i=0;i<tamConj;i++){
     ficha2017[i].notas[4]=(ficha2017[i].notas[0] + ficha2017[i].notas[1] + ficha2017[i].notas[2] + ficha2017[i].notas[3])/4;
     if(ficha2017[i].notas[4]>=5)
       ficha2017[i].situacao ='A';
     else
       ficha2017[i].situacao ='R';
   }
}

void pesquisarRegistro(HistoricoEscolar ficha2017) {
    //cout << ficha2017.disciplina << "\n" << nomeDisciplina << "\n";
    if(strcmp(ficha2017.disciplina,nomeDisciplina)==0){
        //cout << "\nsim,";
        disciplinaEncontrada = 1;
        posicaoDisciplina = i;
    }
}

void receberDados(HistoricoEscolar *ficha2017) {
    cout << "\nDisciplina: ";
    scanf("%s", &ficha2017->disciplina);
    cout << "\nNotas Bimestrais: ";
    cout << "\n  -> Primeira: ";
    scanf("%f", &ficha2017->notas[0]);
    cout << "\n  -> Segunda: ";
    scanf("%f", &ficha2017->notas[1]);
    cout << "\n  -> Terceira: ";
    scanf("%f", &ficha2017->notas[2]);
    cout << "\n  -> Quarta: ";
    scanf("%f", &ficha2017->notas[3]);
    cout << "\nNumero de Faltas: ";
    scanf("%i", &ficha2017->faltas);
}

void cabecalhoPesquisarRegistro() {
    disciplinaEncontrada = 0;
    cout << "Qual o nome da disciplina que voce deseja?\n";
    scanf("%s", &nomeDisciplina);
}

void cabecalhoExibirDados() {
    system("cls");       //clrscr();
    gotoxy(1,5);
    cout << "***************************  HISTORICO ESCOLAR *****************************";
    gotoxy(5,7);
    cout << "Aluno: " << aluno;
    gotoxy(5,8);
    cout << "Ano:   " << ano;
    gotoxy(1,11);
    cout << "----------------------------------  Notas Bimestrais  -----------------------";
    gotoxy(1,12);
    cout << " Disciplina";
    gotoxy(30,12);
    cout << "1a    2a    3a    4a    Media   Situacao  Faltas";
    gotoxy(1,13);
    cout << "-----------------------------------------------------------------------------";
}

void exibirDados(HistoricoEscolar ficha2017) {
     gotoxy(2,14+i);
     cout << ficha2017.disciplina;
     gotoxy(30,14+i);
     printf("%2.1f",   ficha2017.notas[0]);
     gotoxy(36,14+i);
     printf("%2.1f",   ficha2017.notas[1]);
     gotoxy(42,14+i);
     printf("%2.1f",   ficha2017.notas[2]);
     gotoxy(48,14+i);
     printf("%2.1f",   ficha2017.notas[3]);
     gotoxy(55,14+i);
     printf("%2.1f",   ficha2017.notas[4]);
     gotoxy(62,14+i);
     if(ficha2017.situacao=='A')
       cout << "Aprovado";
     else
       cout << "Reprovado";
     gotoxy(74,14+i);
     cout << ficha2017.faltas;
     cout << "\n";
}

void excluirDados(HistoricoEscolar *ficha2017){
    ficha2017->notas[0] = 0;
    ficha2017->notas[1] = 0;
    ficha2017->notas[2] = 0;
    ficha2017->notas[3] = 0;
    ficha2017->faltas = 0;
}

int main(){
   int opcao;
   //char *aluno = "";
   HistoricoEscolar ficha2017[TAMCONJ]; 	//declaração da variável que é um conj. de registros
   setlocale(LC_ALL, "Portuguese");

   gotoxy(1,5);
   cout << "*********************  Programa: Historico Escolar ***********************";

   //Entrada dos dados da ficha
   fflush(stdin);
   cout << "\nAluno: ";
   gets(aluno);
   //cin >> aluno;
   cout << "\nAno:   ";
   cin >> ano;
   receberDados(&ficha2017[tamConj-1]);
   for(i=0;i<tamConj;i++){
        media(&ficha2017[i]);
   }

   //Saida dos dados da ficha
    cabecalhoExibirDados();
   for(i=0;i<tamConj;i++){
     exibirDados(ficha2017[i]);
   }
   cout << "\n\n";
   system("pause");       //getchar();

    do {
       system("cls");
       opcao = menu();
       switch(opcao) {
        case 1:
            //Criar novo registro
            tamConj++;
            receberDados(&ficha2017[tamConj - 1]);
            break;
        case 2:
            //Pesquisar registro
            cabecalhoPesquisarRegistro();
            for(i=0;i<tamConj;i++) {
                pesquisarRegistro(ficha2017[i]);
            }
            //cout << "\n" << disciplinaEncontrada << posicaoDisciplina;
            if(disciplinaEncontrada) {
                cabecalhoExibirDados();
                exibirDados(ficha2017[posicaoDisciplina]);
            } else {
                cout << "\nDisciplina nao encontrada\n";
            }
            system("pause");
            break;
        case 3:
            //Editar registro
            cabecalhoPesquisarRegistro();
            for(i=0;i<tamConj;i++) {
                pesquisarRegistro(ficha2017[i]);
            }
            if(disciplinaEncontrada) {
                receberDados(&ficha2017[posicaoDisciplina]);
            } else {
                cout << "\nDisciplina nao encontrada\n";
            }
            system("pause");
            break;
        case 4:
            //Excluir registro
            cabecalhoPesquisarRegistro();
            for(i=0;i<tamConj;i++) {
                pesquisarRegistro(ficha2017[i]);
            }
            if(disciplinaEncontrada) {
                excluirDados(&ficha2017[posicaoDisciplina]);
            } else {
                cout << "\nDisciplina nao encontrada\n";
            }
            system("pause");
            break;

        case 5:
            break;
        default:
            cout << "Tente novamente";
            break;
       }
       for(i=0;i<tamConj;i++){
            media(&ficha2017[i]);
        }
       cabecalhoExibirDados();
       for(i=0;i<tamConj;i++){
         exibirDados(ficha2017[i]);
       }
       system("pause");
    } while(opcao != 5);

   return 0;
}

