#include <iostream>
#include <stdio.h>
#include <new>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

struct Fruta {
     char nome[40], descricao[500];
     struct Fruta *pProx;
     int relevancia;
} frutas, *pAux_fruta, *pLer_fruta, *pProx_fruta, *pbuscarFruta, *pAux_fruta_temp, *pAnt_fruta, *tempFruta = new Fruta;

struct Dicionario {
     char inicial;
     int rand;
     struct Dicionario *pProx;
     struct Dicionario *pAnt;
     Fruta inicio_fruta;
} inicio_dicio, *pAux_dicio, *pSal, *pAnt_dicio, *pbuscarLetra, dicio_temp;

//************************Vari�veis globais
char palavra[40], letra,elemento[40], descricao_fruta[500];
int cont_linha = 2, cont_fruta;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
 CursorPosition.X = x; // Locates column
 CursorPosition.Y = y; // Locates Row
 SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

/****************** FUNCAO VERIFICAR NODO ******************/
int inicial_existe(char let){//verifica��o da inicial para inserir
    pAux_dicio = &inicio_dicio;
    while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(let))){
        pAnt_dicio = pAux_dicio;
        pAux_dicio = pAux_dicio->pProx;
    }
    if(toupper(pAux_dicio->inicial) == toupper(let)) { //Inicial existe
        return 1;
    } else {
        return 0;
    }
}

/****************** FUNCAO CONTADOR DE OCORR�NCIA ******************/
int existe(char *str1, char *str2, int id) { //Passa a string que pode conter a substring, a substring e a posi��o em que come�a a verifica��o
    int i, j = 0;
    for(i = id; i < strlen(str1); i++){ //Percorre a string da posi��o id at� o final
        if(str1[i] == str2[j]) //Se a letra atual � igual a letra da sobstring j++
            j++;
        else //Sen�o � uma palavra diferente e j = 0
            j = 0;
        if(j == strlen(str2)) //retorna a posi��o em que termina a substring na string
            return i;
    }
    return -1; //N�o encontrou substring na string
}

/****************** FUNCAO SALVAR ******************/
void gravar(){
    FILE *pont_arq;
    pont_arq = fopen("dicionario.txt", "w");
    if(pont_arq) {
        if(inicio_dicio.pProx != NULL) {
            pSal = inicio_dicio.pProx; /* aponta para o inicio do dicionario */
             while(pSal){
                 pAux_fruta = pSal->inicio_fruta.pProx;/* aponta para o inicio da lista de frutas */
                 while(pAux_fruta) {
                    fprintf(pont_arq, "%s\n", pAux_fruta->nome);
                    fprintf(pont_arq, "%s\n", pAux_fruta->descricao);
                    pAux_fruta = pAux_fruta->pProx; //Passa para a pr�xima fruta
             }
            pSal = pSal->pProx; //Passa para a pr�xima letra
        }
        fclose(pont_arq);
    }
  } else {
        cout << "Erro ao gravar arquivo!";
        system("pause");
    }
  pAux_dicio = NULL;
  pAux_fruta = NULL;
}

/****************** FUNCAO LER ******************/
void ler(){
    char lido[500];
    int etapa=0;
    FILE *pont_arq;
    pont_arq = fopen("dicionario.txt", "r");
    if(pont_arq) {
      pAux_dicio = &inicio_dicio;
      while(!feof(pont_arq)) {
          if(fgets(lido, 500, pont_arq)) {
            lido[strlen(lido)-1] = '\0';
            switch(etapa) {
            case 0:
                pAux_dicio = &inicio_dicio;
                while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(lido[0]))){
                    pAnt_dicio = pAux_dicio;
                    pAux_dicio = pAux_dicio->pProx;
                }
                if(toupper(pAux_dicio->inicial) != toupper(lido[0])) { //Inicial n�o existe
                    pAux_dicio->pProx = new Dicionario;
                    pAux_dicio = pAux_dicio->pProx;
                    pAux_dicio->pProx = NULL;
                    pAux_dicio->inicial = lido[0];
                    pLer_fruta = &pAux_dicio->inicio_fruta;
                    pLer_fruta->pProx = new Fruta;
                    pAux_fruta = pLer_fruta->pProx;
                    strcpy(pAux_fruta->nome, lido);
                }
                else if(toupper(pAux_dicio->inicial) == toupper(lido[0])) { //Inicial existe
                    pAux_fruta = &pAux_dicio->inicio_fruta;
                    while(pAux_fruta->pProx){
                        pAux_fruta = pAux_fruta->pProx;
                    }
                    pAux_fruta->pProx = new Fruta;
                    pAux_fruta = pAux_fruta->pProx;
                    strcpy(pAux_fruta->nome, lido);
                    pAux_fruta->pProx = NULL;
                }
                cont_fruta++;
            break;
            case 1:
                strcpy(pAux_fruta->descricao, lido);
                etapa = -1;
                break;
            }
            etapa++;
          }
      }
    }
    else{
     cout << "Sem dados no arquivo\n";
     system("pause");
    }

}//fun��o onde devemos ordenar a partir do arquivo;


/****************** FUNCAO INSERIR ******************/
void inserir_fruta(){
    pAux_dicio = &inicio_dicio;
    //Verifica inicial
    gotoxy(0, 1);
    cout << "Informe a fruta que deseja inserir: ";
    gotoxy(0, 2);
    cout << "Descri��o da fruta: ";
    gotoxy(37, 1);
    fflush(stdin);
    gets(palavra);

    while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(palavra[0]))){
        pAnt_dicio = pAux_dicio;
        pAux_dicio = pAux_dicio->pProx;
    }
    if(pAux_dicio->inicial != palavra[0]) { //Inicial n�o encontrada
        pAux_dicio->pProx = new Dicionario; //Cria novo nodo para essa inicial
        pAux_dicio = pAux_dicio->pProx;
        pAux_dicio->inicial = palavra[0];
        pAux_dicio->pProx = NULL; //Faz o pr�ximo item(�ltimo) apontar para nulo(necess�rio)
    }
    //Validar palavra
    pAux_fruta = &pAux_dicio->inicio_fruta;
    while((pAux_fruta->pProx) && (strcmp(pAux_fruta->nome, palavra) != 0)) {
        pAux_fruta = pAux_fruta->pProx;
    }
    if(strcmp(pAux_fruta->nome, palavra) == 0) { //Palavra j� inserida
        cout << "Fruta j� inserida!";
    } else { //Cria espa�o para nova fruta
        pAux_fruta->pProx = new Fruta;
        pAux_fruta = pAux_fruta->pProx;
        strcpy(pAux_fruta->nome, palavra);
        gotoxy(21, 2);
        fflush(stdin);
        gets(pAux_fruta->descricao);
        cont_fruta++;
    }
    gravar();
    pAux_dicio = NULL;
    pAux_fruta = NULL;
}

/****************** FUNCAO BUSCAR ******************/
Fruta* buscar(){
    cout<<"Informe a fruta\n:";
    fflush(stdin);
    gets(elemento);
    pAux_dicio=&inicio_dicio;
    if(pAux_dicio->pProx!=NULL){
        pbuscarLetra=pAux_dicio->pProx;
        while(pbuscarLetra){
           if(toupper(elemento[0])==toupper(pbuscarLetra->inicial)){
               pbuscarFruta=&pbuscarLetra->inicio_fruta;
               while(pbuscarFruta->pProx){
                    pbuscarFruta=pbuscarFruta->pProx;
                    if(strcmp(elemento, pbuscarFruta->nome)==0){
                        return pbuscarFruta;
                    }
               }
           }
           pbuscarLetra=pbuscarLetra->pProx ;
        }
    } else {
        cout<<"\nN�o existe fruta cadastrada na lista!\n";
    }
}

void excluir_inicial_parametro(Dicionario letra) {
    if(pbuscarLetra->pProx) { //N�o � o �ltimo da lista
        if(pAnt_dicio != pbuscarLetra) { //Tem anterior
            pAnt_dicio->pProx = pbuscarLetra->pProx;
            delete pbuscarLetra;
            pbuscarLetra = pAnt_dicio->pProx;
            pbuscarLetra->pAnt = pAnt_dicio;
        } else { //N�o tem anterior
            inicio_dicio.pProx = pbuscarLetra->pProx;
            pbuscarLetra = inicio_dicio.pProx;
            delete pAnt_dicio;
            pbuscarLetra->pAnt = &inicio_dicio;
        }
    } else { //� o �ltimo da lista
        if(inicio_dicio.pProx != pbuscarLetra) { // Tem anterior
            pAnt_dicio->pProx = NULL;
            pbuscarLetra = pAnt_dicio;
        } else { //N�o tem anterior
            pbuscarLetra = &inicio_dicio;
            pbuscarLetra->pProx = NULL;
        }
    }
}

/****************** FUNCAO EXCLUIR INICIAL ******************/
void excluir_inicial(){
    pbuscarLetra = &inicio_dicio;
    cont_linha = 1;
    cout << "Inicial: ";
    cin >> letra;
    while((pbuscarLetra->pProx) && (toupper(pbuscarLetra->inicial) != toupper(letra))){
        pAnt_dicio = pbuscarLetra;
        pbuscarLetra = pbuscarLetra->pProx;
    }
    if(toupper(pbuscarLetra->inicial) != toupper(letra)) { //Inicial n�o encontrada
        cout << "Essa inicial n�o existe!";
        system("pause");
    } else { //Inicial encontrada
        if(pbuscarLetra->pProx) { //N�o � o �ltimo da lista
            if(pAnt_dicio != pbuscarLetra) { //Tem anterior
                pAnt_dicio->pProx = pbuscarLetra->pProx;
                delete pbuscarLetra;
                pbuscarLetra = pAnt_dicio->pProx;
                pbuscarLetra->pAnt = pAnt_dicio;
            } else { //N�o tem anterior
                inicio_dicio.pProx = pbuscarLetra->pProx;
                pbuscarLetra = inicio_dicio.pProx;
                delete pAnt_dicio;
                pbuscarLetra->pAnt = &inicio_dicio;
            }
        } else { //� o �ltimo da lista
            if(inicio_dicio.pProx != pbuscarLetra) { // Tem anterior
                pAnt_dicio->pProx = NULL;
                pbuscarLetra = pAnt_dicio;
            } else { //N�o tem anterior
                pbuscarLetra = &inicio_dicio;
                pbuscarLetra->pProx = NULL;
            }
        }
        cout << "Inicial " << letra << " exclu�da com sucesso!";
        gravar();
    }
}



/****************** FUNCAO CABE�ALHO DE EXIBIR ******************/
void cabecalhoExibir() {
    cout<<"                       *******************FRUTAS DO DICION�RIO*********************";
    gotoxy(0, cont_linha);
    cout << "----------------------------------------------------------------------------------------------------------------";
    gotoxy(0, cont_linha+1);
    cout << "|Nome ";
    gotoxy(50, cont_linha+1);
    cout << "| Descri��o ";
    gotoxy(111, cont_linha+1);
    cout << "|";
    gotoxy(0, cont_linha+2);
    cout << "----------------------------------------------------------------------------------------------------------------";
    cont_linha=cont_linha+2;
}

void cabecalhoExibirReferecia() {
    cout<<"                         *******************BUSCAR POR RELEV�NCIA*********************\n";
    cout << "----------------------------------------------------------------------------------------------------------------";
    gotoxy(0, cont_linha+1);
    cout << "|Qtd ";
    gotoxy(6, cont_linha+1);
    cout << "|Nome ";
    gotoxy(50, cont_linha+1);
    cout << "| Descri��o";
    gotoxy(111, cont_linha+1);
    cout<<"|";
    gotoxy(0, cont_linha+2);
    cout << "----------------------------------------------------------------------------------------------------------------";
    cont_linha=cont_linha+2;
}

/****************** FUNCAO EXIBIR FRUTA ******************/
void exibir_fruta(Fruta *exibir, int qnt = 0){
    int cont=0;
    cont_linha++;
    if(qnt != 0) {
        gotoxy(0, cont_linha);
        cout << "|" << pAux_fruta->relevancia;
        gotoxy(6, cont_linha);
        cout << "|" << exibir->nome;
    } else {
        gotoxy(0, cont_linha);
        cout << "|" << exibir->nome;
    }
    gotoxy(111, cont_linha);
    cout << "|";
    gotoxy(50, cont_linha);
    cout << "|";
    for(cont = 0; cont < strlen(exibir->descricao); cont++) {
        cout << exibir->descricao[cont];
        if((cont % 59 == 0) && (cont > 0)) {
            cont_linha++;
            if(qnt != 0) {
                gotoxy(6, cont_linha);
                cout << "|";
            }
            gotoxy(111, cont_linha);
            cout << "|";
            gotoxy(0, cont_linha);
            cout << "|";
            gotoxy(50, cont_linha);
            cout << "|";
            gotoxy(51, cont_linha);
        }
    }
    cont_linha++;
    gotoxy(0, cont_linha);
    cout << "----------------------------------------------------------------------------------------------------------------";
}

/****************** FUNCAO EXIBIR INICIAL ******************/
 void exibir_inicial(){ //todas palavras de tal letra
    pAux_dicio = &inicio_dicio;
    cont_linha = 1;
    cout << "Inicial: ";
    cin >> letra;
    while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(letra))){
        pAux_dicio = pAux_dicio->pProx;
    }
    if(toupper(pAux_dicio->inicial) != toupper(letra)) { //Inicial n�o encontrada
        cout << "Essa inicial n�o existe!";
        system("pause");
    } else {
        cabecalhoExibir();
        pAux_fruta = &pAux_dicio->inicio_fruta;
        while(pAux_fruta->pProx) {
            pAux_fruta = pAux_fruta->pProx;
            exibir_fruta(pAux_fruta);
        }
        cout << "\n";
    }
 }

/****************** FUNCAO LISTAR TODAS AS FRUTAS ******************/
void listar_tudo(Dicionario exibir){
    cont_linha = 1;
    if(exibir.pProx) {
        cabecalhoExibir();
        pAux_dicio = &exibir;
        while(pAux_dicio->pProx) {
            pAux_dicio = pAux_dicio->pProx;
            pAux_fruta = &pAux_dicio->inicio_fruta;
            while(pAux_fruta->pProx) {
                pAux_fruta = pAux_fruta->pProx;
                exibir_fruta(pAux_fruta);
            }
        }
        cout << "\n";
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
}

/****************** FUNCAO EXCLUIR FRUTA ******************/
void excluir_fruta(){
    if(inicio_dicio.pProx){
        char elemento[40];
        int encontrou;
        cout<<"Informe a fruta\n:";
        fflush(stdin);
        gets(elemento);
        pAux_dicio=&inicio_dicio;
        if(pAux_dicio->pProx!=NULL){
            pbuscarLetra=pAux_dicio->pProx;
            while(pbuscarLetra){
                pAnt_dicio = pbuscarLetra;
               if(toupper(elemento[0])==toupper(pbuscarLetra->inicial)){
                   pbuscarFruta=&pbuscarLetra->inicio_fruta;
                   while(pbuscarFruta->pProx){
                        pAnt_fruta = pbuscarFruta; //Anterior recebe atual
                        pbuscarFruta=pbuscarFruta->pProx; //Atual recebe pr�ximo
                        if(strcmp(elemento, pbuscarFruta->nome)==0){
                            //Fruta encontrada
                            encontrou = 1;
                            pAnt_fruta->pProx = pbuscarFruta->pProx;
                            cout << "Fruta " << pbuscarFruta->nome << " exclu�da com sucesso!";
                            delete pbuscarFruta;
                            cont_fruta--;
                        }
                   }
                   if(pbuscarLetra->inicio_fruta.pProx == NULL){ //nodo ficou sem frutas
                        if(pbuscarLetra->pProx) { //N�o � o �ltimo da lista
                            if(pAnt_dicio != pbuscarLetra) { //Tem anterior
                                pAnt_dicio->pProx = pbuscarLetra->pProx;
                                delete pbuscarLetra;
                                pbuscarLetra = pAnt_dicio->pProx;
                                pbuscarLetra->pAnt = pAnt_dicio;
                            } else { //N�o tem anterior
                                inicio_dicio.pProx = pbuscarLetra->pProx;
                                pbuscarLetra = inicio_dicio.pProx;
                                delete pAnt_dicio;
                                pbuscarLetra->pAnt = &inicio_dicio;
                            }
                        } else { //� o �ltimo da lista
                            if(inicio_dicio.pProx != pbuscarLetra) { // Tem anterior
                                pAnt_dicio->pProx = NULL;
                                pbuscarLetra = pAnt_dicio;
                            } else { //N�o tem anterior
                                pbuscarLetra = &inicio_dicio;
                                pbuscarLetra->pProx = NULL;
                            }
                        }
                   }
               }
               pbuscarLetra=pbuscarLetra->pProx;
            }
            if(encontrou != 1) {
                cout << "Fruta " << elemento << " n�o encontrada!\n";
                system("pause");
            }
        } else {
            cout<<"\nN�o existe fruta cadastrada na lista!\n";
        }
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
    pAux_dicio = NULL;
    pAux_fruta = NULL;
    gravar();
}

/****************** FUNCAO LISTAR REMISSO ******************/
void listar_remisso(){//exibir como t� no arquivo
    listar_tudo(inicio_dicio);
}


/****************** FUNCAO MENU EXCLUIR ******************/
void menu_excluir(){
    int op=1;
    do{
       system("cls");
       cout<<"\t\tO QUE DESEJA FAZER?\n";
       cout<<"SAIR-0\nEXCLUIR FRUTA-1\nEXCLUIR INICIAL-2\n:";
       cin>>op;
       switch(op){
       case 0:

       break;
       case 1:
           system("cls");
           excluir_fruta();
           system("pause");
       break;
       case 2:
           system("cls");
           excluir_inicial();
           system("pause");
       break;
       default:
        cout<<"\nOp��o inv�lida, tente novamente!\n";
        system("pause");
       break;
       }
    }while(op!=0);
}

/****************** FUNCAO MENU EXIBIR ******************/
void menu_exibir(){
    if(inicio_dicio.pProx){
        int op=1;
        do{
           system("cls");
           cout<<"\t\tComo deseja exibir?\n";
           cout<<"Voltar-0\nExibir remisso-1\nExibir letra-2\n:";
           cin>>op;
           switch(op){
           case 0:
           break;
           case 1:
               system("cls");
               listar_remisso();
               system("pause");
           break;
           case 2:
               system("cls");
               exibir_inicial();
               system("pause");
           break;
           default:
            cout<<"\nOp��o inv�lida, tente novamente!\n";
            system("pause");
           break;
           }
        }while(op!=0);
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
}

int compara_string(char nome1[40], char nome2[40]) {
    int tamanho_nome, primeiro = 0;
    if(strlen(nome1) > strlen(nome2)) {
        tamanho_nome = strlen(nome2);
    } else {
        tamanho_nome = strlen(nome1);
    }
    for(int i = 0; i < tamanho_nome; i++){
        if(toupper(nome1[i]) < toupper(nome2[i])) {
            //cout << "\nnome " << nome1 << " � menor em " << nome1[i] << " que " << nome2 << " na posicao " << nome2[i];
            primeiro = 1;
            break;
        } else if(toupper(nome1[i]) > toupper(nome2[i])){
            //cout << "\nnome " << nome1 << " � maior em " << nome1[i] << " que " << nome2 << " na posicao " << nome2[i];
            primeiro = 0;
            break;
        }
    }
    if(primeiro == 1) {
        return 1; //Primeira string � menor
    } else {
        return 0;
    }
}

/****************** FUNCAO ORDENAR ALFAB�TICO ******************/
void ordenar_alfabetico() { //Ordena��o por compara��o
    //##########Precisa criar uma lista auxiliar e usar ela para ordenar
    pAux_dicio = inicio_dicio.pProx;
    Dicionario *pAux_Temp_Dicio;
    pAux_Temp_Dicio = &dicio_temp;
    while(pAux_dicio) { //Percorre os nodos do dicionario
        pAux_Temp_Dicio->pProx = new Dicionario;//Cria novo nodo para dicionario temporario
        pAux_Temp_Dicio = pAux_Temp_Dicio->pProx; //Ponteiro temporario aponta para novo nodo
        pAux_fruta_temp = &pAux_Temp_Dicio->inicio_fruta; //Ponteira auxiliar temp para fruta aponta para o inicio de frutas
        pAux_Temp_Dicio->pProx = NULL;
        pAux_Temp_Dicio->inicial = pAux_dicio->inicial; //Copia a inicial da original para temporario
        pAux_fruta = pAux_dicio->inicio_fruta.pProx;//Aponta para o primeiro da lista de frutas com inicial igual
        while(pAux_fruta){ //Percorre as frutas de um nodo original
            pAux_fruta_temp->pProx = new Fruta; //Cria novo nodo para fruta no dicionario temporario
            pAux_fruta_temp = pAux_fruta_temp->pProx;
            strcpy(pAux_fruta_temp->nome, pAux_fruta->nome); //Copia o nome para a temporaria
            strcpy(pAux_fruta_temp->descricao, pAux_fruta->descricao); //Copia a descri��o para a tempor�ria
            pAux_fruta_temp->pProx = NULL;
            pAux_fruta = pAux_fruta->pProx;
        }
        pAux_dicio = pAux_dicio->pProx;
    }
    //Ordenar lista tempor�ria principal
    pAnt_dicio = dicio_temp.pProx;
    Dicionario *temporario = new Dicionario; //Necess�rio reservar local de mem�ria
    while(pAnt_dicio->pProx){
        pAux_dicio = pAnt_dicio->pProx;
        while(pAux_dicio){
            //cout << "\ncomparando " << pAnt_dicio->inicial << " e " << pAux_dicio->inicial << " ";

            if(pAnt_dicio->inicial > pAux_dicio->inicial){
                //cout << "\n" << pAnt_dicio->inicial << " E maior que " << pAux_dicio->inicial;
                //cout << "\ntrocar " << pAnt_dicio->inicial << " e " << pAux_dicio->inicial << " ";
                temporario->inicial = pAnt_dicio->inicial;
                temporario->inicio_fruta = pAnt_dicio->inicio_fruta;

                pAnt_dicio->inicial = pAux_dicio->inicial;
                pAnt_dicio->inicio_fruta = pAux_dicio->inicio_fruta;

                pAux_dicio->inicial = temporario->inicial;
                pAux_dicio->inicio_fruta = temporario->inicio_fruta;
            }

            pAux_dicio = pAux_dicio->pProx;
        }
        //cout << "\nproximo";
        pAnt_dicio = pAnt_dicio->pProx;
    }

    //Ordenando as sub-listas
    pAux_dicio = dicio_temp.pProx;
    int comp;
    while(pAux_dicio){
        pAux_fruta = pAux_dicio->inicio_fruta.pProx;
        while(pAux_fruta->pProx){
            pProx_fruta = pAux_fruta->pProx;
            while(pProx_fruta) {
                //cout << " comparando " << pAux_fruta->nome << " e " << pProx_fruta->nome << "\n";
                comp = compara_string(pAux_fruta->nome, pProx_fruta->nome);
                if(comp == 1) {
                    //cout << "\n" << pAux_fruta->nome << " menor que " << pProx_fruta->nome << "\n";
                } else {
                    //cout << pAux_fruta->nome << " maior que " << pProx_fruta->nome << "\n";
                    strcpy(tempFruta->nome, pAux_fruta->nome);
                    strcpy(tempFruta->descricao, pAux_fruta->descricao);

                    strcpy(pAux_fruta->nome, pProx_fruta->nome);
                    strcpy(pAux_fruta->descricao, pProx_fruta->descricao);

                    strcpy(pProx_fruta->nome, tempFruta->nome);
                    strcpy(pProx_fruta->descricao, tempFruta->descricao);
                }
                pProx_fruta = pProx_fruta->pProx;
            }
            pAux_fruta = pAux_fruta->pProx;
        }
        pAux_dicio = pAux_dicio->pProx;
    }
    //Exibindo lista tempor�ria
    listar_tudo(dicio_temp);
}

/****************** FUNCAO MENU ORDENAR ******************/
void menu_ordenar(){//escolhe como ser�o ordenadas as palavras(alfab�tica, cria��o e randomica);
    if(inicio_dicio.pProx){
        int op = -1;
        do {
            system("cls");
            cout << "SAIR [0]\nOrdenar por: \nALFAB�TICA [1] \nCRIA��O [2]\n:";
            cin >> op;
            switch(op) {
            case 0:
            break;
            case 1:
                system("cls");
                ordenar_alfabetico();
                system("pause");
            break;
            case 2:
                system("cls");
                listar_remisso();
                system("pause");
            break;
            default:
                cout<<"\nOp��o inv�lida, tente novamente!\n";
                system("pause");
            break;
            }
        } while(op != 0);
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
}

/****************** FUNCAO ORDENAR POR RELEV�NCIA ******************/
void ordenar_relevancia(){
    //Ordenando as sub-listas
    pAux_dicio = dicio_temp.pProx;
    while(pAux_dicio){
        pAux_fruta = pAux_dicio->inicio_fruta.pProx;
        while(pAux_fruta->pProx){
            pProx_fruta = pAux_fruta->pProx;
            while(pProx_fruta) {
                //cout << " comparando " << pAux_fruta->nome << " e " << pProx_fruta->nome << "\n";
                if(pAux_fruta->relevancia < pProx_fruta->relevancia) {
                    //cout << pAux_fruta->nome << " menor que " << pProx_fruta->nome << "\n";
                    strcpy(tempFruta->nome, pAux_fruta->nome);
                    strcpy(tempFruta->descricao, pAux_fruta->descricao);
                    tempFruta->relevancia = pAux_fruta->relevancia;

                    strcpy(pAux_fruta->nome, pProx_fruta->nome);
                    strcpy(pAux_fruta->descricao, pProx_fruta->descricao);
                    pAux_fruta->relevancia = pProx_fruta->relevancia;

                    strcpy(pProx_fruta->nome, tempFruta->nome);
                    strcpy(pProx_fruta->descricao, tempFruta->descricao);
                    pProx_fruta->relevancia = tempFruta->relevancia;
                }
                pProx_fruta = pProx_fruta->pProx;
            }
            pAux_fruta = pAux_fruta->pProx;
        }
        pAux_dicio = pAux_dicio->pProx;
    }
}

/****************** FUNCAO PESQUISAR POR RELEV�NCIA ******************/
void buscar_relevancia() {
    if(inicio_dicio.pProx != NULL) {
        Fruta *pPesq_fruta;
        Dicionario *pPesq_dicio, *pAux_Temp_Dicio;
        dicio_temp.pProx = NULL;
        char pesquisa[40];
        int indice = 0, quantidade = 0;
        cout<<"Informe o que quer pesquisar (mais de uma letra)\n:";
        fflush(stdin);
        gets(pesquisa);
        if(strlen(pesquisa) > 1) {
            pPesq_dicio = &inicio_dicio;
            while(pPesq_dicio->pProx) {
                pPesq_dicio = pPesq_dicio->pProx;
                pPesq_fruta = &pPesq_dicio->inicio_fruta;
                while(pPesq_fruta->pProx) {
                    pPesq_fruta = pPesq_fruta->pProx;
                    //Verifica se a pesquisa esta na descri��o
                    //cout << "Verificando " << pPesq_fruta->nome << "\n";
                    indice = 0;
                    quantidade = 0;
                    do{
                        indice = existe(pPesq_fruta->descricao, pesquisa, indice);
                        if(indice != -1) {
                            quantidade++;
                            //Adicionar em lista tempor�ria
                            //cout << quantidade << " quantidade em " << pPesq_fruta->nome << "\n";
                            pAux_dicio = &dicio_temp;
                            if(dicio_temp.pProx == NULL) {
                                //cout << "nova inicial primeira";
                                pAux_dicio->pProx = new Dicionario; //Cria novo nodo para essa inicial
                                pAux_dicio = pAux_dicio->pProx;
                                pAux_dicio->inicial = pesquisa[0];
                                pAux_dicio->pProx = NULL; //Faz o pr�ximo item(�ltimo) apontar para nulo(necess�rio)
                            } else {
                                while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(pesquisa[0]))){
                                    pAnt_dicio = pAux_dicio;
                                    pAux_dicio = pAux_dicio->pProx;
                                }
                                if(toupper(pAux_dicio->inicial) != toupper(pesquisa[0])) { //Inicial n�o encontrada
                                    pAux_dicio->pProx = new Dicionario; //Cria novo nodo para essa inicial
                                    pAux_dicio = pAux_dicio->pProx;
                                    pAux_dicio->inicial = pesquisa[0];
                                    //cout << "inicial: " << pAux_dicio->inicial;
                                    pAux_dicio->pProx = NULL; //Faz o pr�ximo item(�ltimo) apontar para nulo(necess�rio)
                                }
                            }

                            //Validar palavra
                            pAux_fruta = &pAux_dicio->inicio_fruta;
                            while((pAux_fruta->pProx) && (strcmp(pAux_fruta->nome, pPesq_fruta->nome) != 0)) {
                                pAux_fruta = pAux_fruta->pProx;
                            }
                             //Cria espa�o para nova fruta
                             if(strcmp(pAux_fruta->nome, pPesq_fruta->nome) != 0) {
                                pAux_fruta->pProx = new Fruta;
                                pAux_fruta = pAux_fruta->pProx;
                                pAux_fruta->pProx = NULL;
                                strcpy(pAux_fruta->nome, pPesq_fruta->nome);
                                strcpy(pAux_fruta->descricao, pPesq_fruta->descricao);
                                pAux_fruta->relevancia = 1;
                             } else {
                                 //cout << "incrementa";
                                 pAux_fruta->relevancia++;
                             }
                        }
                    } while(indice != -1);
                }
            }
            //Ordenar por relev�ncia
            ordenar_relevancia();
            //Exibir por relev�ncia
            system("cls");
            cont_linha = 1;
            if(dicio_temp.pProx) {
                cabecalhoExibirReferecia();
                pAux_dicio = &dicio_temp;
                while(pAux_dicio->pProx) {
                    pAux_dicio = pAux_dicio->pProx;
                    pAux_fruta = &pAux_dicio->inicio_fruta;
                    while(pAux_fruta->pProx) {
                        pAux_fruta = pAux_fruta->pProx;
                        exibir_fruta(pAux_fruta, 1);
                    }
                }
            }
                cout << "\n";
        }
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
}

/****************** FUNCAO MENU PESQUISAR ******************/
void menu_pesquisar(){
    int op=1;
    do{
       system("cls");
       cout<<"\t\tO QUE DESEJA FAZER?\n";
       cout<<"SAIR-0\nPESQUISAR FRUTA-1\nPESQUISAR POR RELEV�NCIA-2\n:";
       cin>>op;
       switch(op){
       case 0:
       break;
       case 1:
           system("cls");
           pLer_fruta = buscar();
           if(pLer_fruta!= NULL){
               system("cls");
               cont_linha = 1;
               cabecalhoExibir();
               exibir_fruta(pLer_fruta);
               cout << "\n";
               system("pause");
           }else{
             printf("Essa fruta n�o foi adicionado(a) ao dicion�rio\n");
             system("pause");
           }
       break;
       case 2:
           system("cls");
           buscar_relevancia();
           system("pause");
       break;
       default:
            cout<<"\nOp��o inv�lida, tente novamente!\n";
            system("pause");
       break;
       }
    }while(op!=0);
}

/****************** FUNCAO EXCLUIR COM PAR�METRO ******************/
void excluir_fruta_parametro(char fruta[40]) {
    int encontrou;
    if(inicio_dicio.pProx){
        strcpy(elemento, fruta);
        pAux_dicio=&inicio_dicio;
        if(pAux_dicio->pProx!=NULL){
            pbuscarLetra=pAux_dicio->pProx;
            while(pbuscarLetra){
                pAnt_dicio = pbuscarLetra;
               if(toupper(elemento[0])==toupper(pbuscarLetra->inicial)){
                   pbuscarFruta=&pbuscarLetra->inicio_fruta;
                   while(pbuscarFruta->pProx){
                        pAnt_fruta = pbuscarFruta; //Anterior recebe atual
                        pbuscarFruta=pbuscarFruta->pProx; //Atual recebe pr�ximo
                        if(strcmp(elemento, pbuscarFruta->nome)==0){
                            //Fruta encontrada
                            encontrou = 1;
                            pAnt_fruta->pProx = pbuscarFruta->pProx;
                            delete pbuscarFruta;
                        }
                   }
                   if(pbuscarLetra->inicio_fruta.pProx == NULL){
                        if(pbuscarLetra->pProx) { //N�o � o �ltimo da lista
                            if(pAnt_dicio != pbuscarLetra) { //Tem anterior
                                pAnt_dicio->pProx = pbuscarLetra->pProx;
                                delete pbuscarLetra;
                                pbuscarLetra = pAnt_dicio->pProx;
                                pbuscarLetra->pAnt = pAnt_dicio;
                            } else { //N�o tem anterior
                                inicio_dicio.pProx = pbuscarLetra->pProx;
                                pbuscarLetra = inicio_dicio.pProx;
                                delete pAnt_dicio;
                                pbuscarLetra->pAnt = &inicio_dicio;
                            }
                        } else { //� o �ltimo da lista
                            if(inicio_dicio.pProx != pbuscarLetra) { // Tem anterior
                                pAnt_dicio->pProx = NULL;
                                pbuscarLetra = pAnt_dicio;
                            } else { //N�o tem anterior
                                pbuscarLetra = &inicio_dicio;
                                pbuscarLetra->pProx = NULL;
                            }
                        }
                   }
               }
               pbuscarLetra=pbuscarLetra->pProx;
            }
            if(encontrou != 1) {
                cout << "Fruta " << elemento << " n�o encontrada!\n";
                system("pause");
            }
        } else {
            cout<<"\nN�o existe fruta cadastrada na lista!\n";
        }
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
    pAux_dicio = NULL;
    pAux_fruta = NULL;
    gravar();
}

/****************** FUNCAO ALTERAR DESCRI��O ******************/
void alterar(Fruta *achada){
    if(inicio_dicio.pProx){
        pAux_fruta = achada;
        fflush(stdin);
        cont_linha = 3;
        cabecalhoExibir();
        exibir_fruta(pAux_fruta);
        cout<<"\nNova descri��o\n:";
        gets(pAux_fruta->descricao);
        gravar();
    } else {
        cout << "N�o existem registros de frutas!\n";
    }
}

/****************** FUNCAO ALTERAR FRUTA ******************/
void alterar_fruta() {
    tempFruta = buscar(); //Fruta que deve ser alterada
    if(tempFruta != NULL) { //Se encontrou no dicionario
        system("cls");
        cont_linha = 1;
        cabecalhoExibir();
        exibir_fruta(tempFruta);
        cont_linha++;
        gotoxy(0, cont_linha);
        cout << "Informe o novo nome da fruta: ";
        gotoxy(0, cont_linha+1);
        cout << "Nova escri��o da fruta: ";
        gotoxy(30, cont_linha);
        fflush(stdin);
        gets(palavra);
        gotoxy(24, cont_linha+1);
        fflush(stdin);
        gets(descricao_fruta);
        if(palavra[0] != tempFruta->nome[0]){
            //Subistituir
            pAux_dicio = &inicio_dicio;
            //Verifica inicial
            while((pAux_dicio->pProx) && (toupper(pAux_dicio->inicial) != toupper(palavra[0]))){
                pAnt_dicio = pAux_dicio;
                pAux_dicio = pAux_dicio->pProx;
            }
            if(pAux_dicio->inicial != palavra[0]) { //Inicial n�o encontrada
                pAux_dicio->pProx = new Dicionario; //Cria novo nodo para essa inicial
                pAux_dicio = pAux_dicio->pProx;
                pAux_dicio->inicial = palavra[0];
                pAux_dicio->pProx = NULL; //Faz o pr�ximo item(�ltimo) apontar para nulo(necess�rio)
            }
            //Validar palavra
            pAux_fruta = &pAux_dicio->inicio_fruta;
            while((pAux_fruta->pProx) && (strcmp(pAux_fruta->nome, palavra) != 0)) {
                pAux_fruta = pAux_fruta->pProx;
            }
            if(strcmp(pAux_fruta->nome, palavra) == 0) { //Palavra j� inserida
                cout << "Fruta j� inserida!";
            } else { //Cria espa�o para nova fruta
                pAux_fruta->pProx = new Fruta; //Cria novo espa�o para substituir fruta antiga
                pAux_fruta = pAux_fruta->pProx;
                strcpy(pAux_fruta->nome, palavra);
                strcpy(pAux_fruta->descricao, descricao_fruta);
                //Excluir fruta alterada
                excluir_fruta_parametro(tempFruta->nome);
            }
            pAux_dicio = NULL;
            pAux_fruta = NULL;
        } else{ //Palavra continua no mesmo nodo e s� � modificada
            strcpy(tempFruta->nome, palavra);
            strcpy(tempFruta->descricao, descricao_fruta);
        }
        gravar();
    } else {
        cout << "Fruta n�o encontrada!\n";
    }
}

/****************** FUNCAO MENU ALTERAR ******************/
void menu_alterar() {
    int op=1;
    do{
       system("cls");
       cout<<"\t\tO QUE DESEJA FAZER?\n";
       cout<<"SAIR-0\nALTERAR DESCRI�AO-1\nALTERAR NOME E DESCRI��O-2\n:";
       cin>>op;
       switch(op){
       case 0:
       break;
       case 1:
           system("cls");
           tempFruta = NULL;
           tempFruta = buscar();
           if(tempFruta != NULL) {
                alterar(tempFruta);
            } else {
                cout << "Fruta n�o encontrada!\n";
            }
           system("pause");
       break;
       case 2:
           system("cls");
            alterar_fruta();
           system("pause");
       break;
       default:
        cout<<"\nOp��o inv�lida, tente novamente!\n";
        system("pause");
       break;
    }
    }while(op!=0);
}

/****************** FUNCAO MENU PRINCIPAL ******************/
void menu(){
    int op=1;
    do{
       system("cls");
       cout<<"\t\tO QUE DESEJA FAZER?\n";
       cout<<"SAIR-0\nINSERIR FRUTA(S)-1\nEXIBIR DICION�RIO-2\nEXCLUIR FRUTA(S)-3\nALTERAR FRUTA(S)-4\nORDENAR DICION�RIO-5\nPESQUISAR-6\n:";
       cin>>op;
       switch(op){
       case 0:
           system("cls");
           cout<<"TCHAU";
       break;
       case 1:
           system("cls");
           inserir_fruta();
           system("pause");
       break;
       case 2:
           system("cls");
           menu_exibir();
           system("pause");
       break;
       case 3:
           system("cls");
           menu_excluir();
           system("pause");
       break;
       case 4:
           system("cls");
           menu_alterar();
           system("pause");
       break;
       case 5:
           system("cls");
           menu_ordenar();
           system("pause");
       break;
       case 6:
           system("cls");
           menu_pesquisar();
           system("pause");
       break;
       default:
        cout<<"\nOp��o inv�lida, tente novamente!\n";
        system("pause");
       break;
       }
    }while(op!=0);
}

/****************** FUNCAO PRINCIPAL ******************/
int main() {
    setlocale(LC_ALL, "Portuguese");
    ler();
    menu();
}
