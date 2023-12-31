/* Prof.: Sergio Augusto C. Bezerra
   Programa MODULADO "LS_INS02_dev.CPP" para exemplificar uma lista simplesmente encadeada
*/

#include <stdio.h>
#include <new>    //<alloc.h>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y);
/****************** VARIAVEIS GLOBAIS ******************/

   char professor[50],disciplina[50],turma[10];
   int opcao;
   char resp;
   int linha,col, matTemp;

   struct Aluno {
     int matricula;   /* numeros de 1 a no maximo 40 */
     char nome[50];
     float notas[3];  /* valores das notas */
     struct Aluno *pProx; /* ponteiro para o proximo aluno */
   };

   Aluno inicio, *pAux, *pAnt, *pProx, *pSal, *pLer;

/****************** FUNCAO SALVAR ******************/
void gravarAluno(){
    FILE *pont_arq;
    pont_arq = fopen("aluno.txt", "w");
    if(pont_arq) {
        if(inicio.pProx != NULL){
            pSal = inicio.pProx; /* aponta para o inicio da lista */
             while(pSal){
                fprintf(pont_arq, "%d\n", pSal->matricula);
                fprintf(pont_arq, "%s\n",  pSal->nome);
                //cout << pSal->nome << "Gravado";
                fprintf(pont_arq, "%.2f\n",  pSal->notas[0]);
                fprintf(pont_arq, "%.2f\n",  pSal->notas[1]);
                fprintf(pont_arq, "%.2f\n",  pSal->notas[2]);
                pSal = pSal->pProx;
             }
        }
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao gravar arquivo!";
        system("pause");
    }
}

/****************** FUNCAO LER ******************/
void lerAluno(){
    FILE *pont_arq;
    pont_arq = fopen("aluno.txt", "r");
    int contarq = 0;
    char lido[500];
    if(pont_arq) {
        pAux = &inicio;
        while(!feof(pont_arq)) {
            if(fgets(lido, 500, pont_arq)) {
                //cout << lido;
                switch(contarq) {
                case 0:
                    pAux->pProx = new Aluno;
                    pAux = pAux->pProx;
                    pAux->matricula = atoi(lido);
                    break;
                case 1:
                    char aux[50];
                    strcpy(pAux->nome, lido);
                    pAux->nome[strlen(pAux->nome)-1] = '\0';
                    //cout << pAux->nome << "Lido";
                    break;
                case 2:
                    pAux->notas[0] = atof(lido);
                    break;
                case 3:
                    pAux->notas[1] = atof(lido);
                    break;
                case 4:
                    pAux->notas[2] = atof(lido);
                    contarq = -1;
                    break;
                }
                contarq++;
            }
        }
        pAux->pProx = NULL;
        //system("pause");
        fclose(pont_arq);
    }
    else {
        cout << "Erro ao ler arquivo!";
        system("pause");
    }
}

/****************** FUNCAO CABECALHO ******************/
void cabecalho(){
   system("cls");
   gotoXY(3,5);
   cout << "PROGRAMA PARA GERENCIAR A MATRICULA, O NOME E AS NOTAS";
   gotoXY(3,7);
   cout << "DE UM ALUNO USANDO UMA LISTA SIMPLESMENTE ENCADEADA\n";
}

/****************** FUNCAO MENU ******************/
void menu(){
   col=15;
   gotoXY(col,10);
   cout << "*************** Menu ****************";
   gotoXY(col,11);
   cout << "*      Exibir.............[1]       *";
   gotoXY(col,12);
   cout << "*      Inserir............[2]       *";
   gotoXY(col,13);
   cout << "*      Remover............[3]       *";
   gotoXY(col,14);
   cout << "*      Inserir em Ordem...[4]       *";
   gotoXY(col,15);
   cout << "*      Retifica��o........[5]       *";
   gotoXY(col,16);
   cout << "*      Sair...............[0]       *";
   gotoXY(col,17);
   cout << "*      Digite a opcao:              *";
   gotoXY(col,18);
   cout << "*************************************";
   gotoXY(42,17);
   cin >> opcao;
}

/******************** FUNCAO DIARIO *******************/
void diario(){
   gotoXY(3,9);
   cout << "PREENCHER OS DADOS DO CABECALHO DO DIARIO";
   gotoXY(3,11);
   cout << "Professor: ";
   gets(professor);
   gotoXY(3,13);
   cout << "Disciplina: ";
   gets(disciplina);
   gotoXY(3,15);
   cout << "Turma: ";
   gets(turma);

}

/********************* FUNCAO BUSCAR MATRICULA *******************/
Aluno* buscar() {
    //Se encontrar retorna o ponteiro para estrutura da matr�cula equivalente, sen�o, retorna uma estrutura null
    do{
        resp = '0';
        if(inicio.pProx == NULL) {
            gotoXY(4,4);
            cout << "ATENCAO: Alunos inexistentes! ";
            system("pause");
        } else {
            gotoXY(3,1);
            cout << "*  Matricula:                                                       *";
            gotoXY(3,2);
            cout << "*********************************************************************";
            gotoXY(17,1);
            cin >> matTemp;
            pAux = &inicio;
            while(pAux->matricula!=matTemp && pAux->pProx!=NULL){
                pAnt=pAux;
                pAux = pAux->pProx;
            }
        }
        if(pAux->matricula==matTemp){
            return pAux;
        } else {
        gotoXY(3,6);
        cout << "Matricula inexistente";
        system("pause");
      }
        gotoXY(3,7);
        cout << "Continuar buscando matricula? Sim[S] Nao[outra tecla]---->";
        cin >> resp;
        resp = toupper(resp);
        system("cls");
    }while (resp == 'S');
    pAux = NULL;
    return pAux;
}

/********************* FUNCAO VALIDAR MATRICULA *******************/
int validarMat(int mat) {
    pLer = &inicio;
    while(pLer->matricula!=mat && pLer->pProx!=NULL){
        pAnt=pLer;
        pLer = pLer->pProx;
    }
    if(pLer->matricula==mat){
        return 0;
    } else {
        return 1;
    }
}

/********************* FUNCAO EXIBIR CABE�ALHO *******************/
void cabecalhoExibir() {
    gotoXY(1,5);
    cout << "********************************  DIARIO *********************************";
    gotoXY(1,7);
    cout << "Professor: " << professor;
    gotoXY(1,8);
    cout << "Disciplina: " << disciplina;
    gotoXY(1,9);
    cout << "Turma: " << turma;
    cout << "\n---------------------------------------------------------------------------";
    gotoXY(1,linha);
    cout << "Matricula";
    gotoXY(15,linha);
    cout << "Nome";
    gotoXY(50,linha);
    cout << "Nota1";
    gotoXY(60,linha);
    cout << "Nota2";
    gotoXY(70,linha);
    cout << "Media";
    linha=13;
    cout << "\n---------------------------------------------------------------------------";
}

/********************* FUNCAO EXIBIR DADO *******************/
void dadoExibir(Aluno *aluno) {
    gotoXY(1,linha);
    cout << pAux->matricula;
    gotoXY(15,linha);
    cout << pAux->nome;
    gotoXY(50,linha);
    cout <<  pAux->notas[0];
    gotoXY(60,linha);
    cout << pAux->notas[1];
    gotoXY(70,linha);
    cout << pAux->notas[2];
}

/********************* FUNCAO EXIBIR *******************/
void exibir() {
  if(inicio.pProx != NULL){
    resp = '0';
    system("cls");
    gotoXY(0,0);
    cout << "********************************  EXIBIR *********************************\n";
    gotoXY(3,1);
    cout << "Como deseja exibir?  Apenas um[1] Tudo[outra tecla] ";
    cin >> resp;
    linha=11;
    if(resp == '1') {
        system("cls");
        gotoXY(0,0);
        cout << "********************************  EXIBIR *********************************\n";
        Aluno *aluno = buscar();
        if(aluno != NULL){
            cabecalhoExibir();
            dadoExibir(aluno);
            cout << "\n---------------------------------------------------------------------------\n";
        }

        system("pause");
    } else {
         pAux = inicio.pProx; /* aponta para o inicio da lista */
         system("cls");
         cabecalhoExibir();
         while(pAux){
           dadoExibir(pAux);
           pAux = pAux->pProx;
           linha++;
         }
         cout << "\n---------------------------------------------------------------------------\n";
         system("pause");
    }
  }
  else{
    gotoXY(15,18);
    cout << "ATENCAO: Alunos inexistentes! ";
	system("pause");
  }
}

/********************* FUNCAO ATUALIZAR *******************/
void atualizar() {
    if(inicio.pProx != NULL){
    int op;
    system("cls");
    cout << "********************************  RETIFICA��O *********************************\n";
     Aluno *aluno = buscar();
    if(aluno != NULL){
        system("cls");
        cout << "Qual campo deseja retificar \nMatricula[1] \nNome[2] \nNota 1[3] \nNota 2[4]\n";
        cin >> op;
        cout << "\n---------------------------------------------------------------------------\n";
        switch(op){
        case 1:
            system("cls");
            gotoXY(1,2);
            cout << "*  Matricula:                                                       *";
            gotoXY(20,2);
            cin >> matTemp;
            if(validarMat(matTemp)){
                aluno->matricula = matTemp;
            } else {
                cout << "Matr�cula j� existe!";
                system("pause");
            }
            break;
        case 2:
            system("cls");
            gotoXY(1,2);
            printf("*  Nome do Aluno:                                                   *");
            gotoXY(20,2);
            fflush(stdin);
            gets(aluno->nome);
            break;
        case 3:
            system("cls");
            gotoXY(1,2);
            cout << "*  Nota1:                                                           *";
            gotoXY(20,2);
            cin >> aluno->notas[0];
            aluno->notas[2] = (aluno->notas[0] + aluno->notas[1])/2;
            break;
        case 4:
            system("cls");
            gotoXY(1,2);
            cout << "*  Nota2:                                                           *";
            gotoXY(20,2);
            cin >> aluno->notas[1];
            aluno->notas[2] = (aluno->notas[0] + aluno->notas[1])/2;
            break;
        default:
            cout << "Op��o inv�lida!";
            break;
        }
    }
    gravarAluno();
    system("pause");
    } else{
    gotoXY(15,18);
    cout << "ATENCAO: Alunos inexistentes! ";
	system("pause");
  }
}

/********************* FUNCAO INSERIR CABE�ALHO *******************/
void inserirCabecalho() {
    cout << "************************* CADASTRO DE ALUNO *************************";
    gotoXY(1,2);
    cout << "*  Matricula:                                                       *";
    gotoXY(1,3);
    printf("*  Nome do Aluno:                                                   *");
    gotoXY(1,4);
    cout << "*  Nota1:                                                           *";
    gotoXY(1,5);
    cout << "*  Nota2:                                                           *";
    cout << "\n*********************************************************************";
}

/********************* FUNCAO INSERIR *******************/
void inserir(){
   resp = '0';
   pAux = &inicio; /* aponta para o inicio da lista */
   while(pAux->pProx)
     pAux = pAux->pProx;
   do{
     system("cls");

     inserirCabecalho();
     while(true){
        system("cls");
        inserirCabecalho();
        gotoXY(20,2);
        cin >> matTemp;
        if(validarMat(matTemp)){
            pAux->pProx = new Aluno;
            pAux = pAux->pProx;
            pAux->matricula = matTemp;
            break;
        } else {
            cout << "Matr�cula j� existe!";
            system("pause");
        }
     }
     gotoXY(20,3);
     fflush(stdin);
	 gets(pAux->nome);
     gotoXY(20,4);
     cin >> pAux->notas[0];
     gotoXY(20,5);
     cin >> pAux->notas[1];
     pAux->notas[2] = (pAux->notas[0] + pAux->notas[1])/2;
     pAux->pProx = NULL;
     gravarAluno();
     cout << "\nContinuar inserindo dados? Sim[S] Nao[outra tecla]---->";
     cin >> resp;
     resp = toupper(resp);
   }while (resp == 'S');
}

/********************* FUNCAO REMOVER *******************/
void remover(){
  if(inicio.pProx != NULL){
  do{
  resp = '0';
  system("cls");
  cout << "************************** REMOVER ALUNO ****************************";
  gotoXY(1,2);
  cout << "*  Matricula:                                                       *";
  gotoXY(1,3);
  cout << "*********************************************************************";
  gotoXY(15,2);
  cin >> matTemp;
  pAux = &inicio;
  while(pAux->matricula!=matTemp && pAux->pProx!=NULL){
    pAnt=pAux;
    pAux = pAux->pProx;
  }
  if(pAux->matricula==matTemp){
    gotoXY(3,5);
    cout << "ATENCAO: Remover " << pAux->nome << "? Sim[S] Nao[outra tecla]---->";
    cin >> resp;
    resp = toupper(resp);
    if(resp=='S'){
      pAnt->pProx = pAux->pProx;
      pAux->pProx = NULL;
      pAnt = NULL;
      delete pAux;
    }
    gravarAluno();
  }
  else{
    gotoXY(20,2);
    cout << "Matricula inexistente";
    system("pause");
    pAnt = NULL;
    pAux = NULL;
  }
   gotoXY(3,6);
   cout << "Continuar removendo dados? Sim[S] Nao[outra tecla]---->";
   cin >> resp;
   resp = toupper(resp);
 }while (resp == 'S');
 } else{
    gotoXY(15,18);
    cout << "ATENCAO: Alunos inexistentes! ";
	system("pause");
 }
}

/********************* FUNCAO INSERIR EM ORDEM *******************/
void inserirOrdem(){
   Aluno *pMenor,*pMaior;
   do{
     pMaior = &inicio; /* aponta para o inicio da lista */
     pMenor = pMaior;
     system("cls");
     pAux = new Aluno; //Novo espa�o que vai receber os dados
     inserirCabecalho();
     gotoXY(20,2);
     while(true){
        system("cls");
        inserirCabecalho();
        gotoXY(20,2);
        cin >> matTemp;
        if(validarMat(matTemp)){
            pAux->pProx = new Aluno;
            pAux = pAux->pProx;
            pAux->matricula = matTemp;
            break;
        } else {
            cout << "Matr�cula j� existe!";
            system("pause");
        }
     }
     gotoXY(20,3);
     fflush(stdin);
     gets(pAux->nome);
     gotoXY(20,4);
     cin >> pAux->notas[0];
     gotoXY(20,5);
     cin >> pAux->notas[1];
     pAux->notas[2] = (pAux->notas[0] + pAux->notas[1])/2;
     pAux->pProx = NULL;
     if(pMaior->pProx == NULL) { //pMaior � o final da lista
       pMaior->pProx = pAux; //pProximo de pMaior vai receber pAux que � o que recebeu os dados
       pAux->pProx = NULL; //pProximo de pAux vai ser null
     }
     else{
        pMaior = pMaior->pProx;
        while(pAux->matricula > pMaior->matricula && pMaior->pProx!=NULL){
          pMenor = pMaior;
          pMaior = pMaior->pProx;
        }
        if(pAux->matricula>pMaior->matricula && pMaior->pProx==NULL){
          pMaior->pProx=pAux;
          pAux->pProx = NULL;
        }
        else{
          pMenor->pProx = pAux;
          pAux->pProx = pMaior;
        }
     }
     gravarAluno();
     cout << "\nContinuar inserindo dados? Sim[S] Nao[outra tecla]---->";
     cin >> resp;
     resp = toupper(resp);
   }while (resp == 'S');
}

void gotoXY(int x, int y){
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}


/****************** FUNCAO PRINCIPAL ******************/
int main(){
   setlocale(LC_ALL, "Portuguese");
   int cont_tela=1;
   inicio.pProx = NULL; /* lista vazia */
   lerAluno();
   cabecalho();
   diario();
   cont_tela++;
 do{
   if (cont_tela > 1){
     cabecalho();
     menu();
   }
   switch(opcao){
     case 0:
	    break;
     case 1:
	    exibir();
	    break;
     case 2:
	   inserir();
	   break;
     case 3:
	  remover();
	   break;
     case 4:
	   inserirOrdem();
	   break;
     case 5:
        atualizar();
        break;
     default:
	   gotoXY(15,18);
       cout << "ATENCAO: Opcao Invalida! ";
	   system("pause");
     }
 }while (opcao != 0);
 return 0;
}


