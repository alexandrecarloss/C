#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct Fila{
    int dados;
    struct Fila *prox;
} inicio_fila, *pAux;

int tamanho_arquivo, qtd_pacote, tam_pacote;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
 CursorPosition.X = x; // Locates column
 CursorPosition.Y = y; // Locates Row
 SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

Fila* ultimo_fila(Fila *ultimo) {
    pAux = ultimo;
    while(pAux->prox) {
        pAux = pAux->prox;
    }
    return pAux;
}

void inserir_dado(Fila *recebe, int dado) {
    Fila *novo = new Fila;
    pAux = recebe;
    if(novo) {
        novo->dados = dado;
        novo->prox = NULL; //Vai ficar no fim da lista
        while(pAux->prox){ //Percorre at� o �ltimo
            pAux = pAux->prox;
        }
        cout << "dado " << dado;
        pAux->prox = novo; //insere no final da fila
    } else {
        cout << "\nErro ao alocar mem�ria";
    }
}

void exibir_fila(Fila *exibir) {
    if(!exibir->prox){
        cout << "\nFila vazia";
    }
    while(exibir->prox) {
        cout << "\nDado exibe: " << exibir->prox->dados;
        exibir = exibir->prox;
    }
}

Fila* remover_fila(Fila *remover) {
    if(remover->prox) {
        pAux = remover;
        Fila *removido = pAux->prox;
        pAux->prox = pAux->prox->prox;
        //cout << "\nRemovido " << removido->dados;
        return removido;
    }
    return NULL;
}

Fila* primeiro_fila(Fila *primeiro) {
    if(primeiro->prox) {
        cout << "\nPrimeiro: " << primeiro->prox->dados;
        return primeiro->prox;
    }
    return NULL;
}

void limpar_fila(Fila *limpar) {
    pAux = limpar;
    while(pAux->prox) {
        remover_fila(pAux);
    }
    cout << "\nFila vazia";
}

int esta_vazia(Fila *vazia) {
    if(vazia->prox) {
        //cout << "nao vazia ";
        return 0;
    } else {
        //cout << "vazia";
        return 1;
    }
}

void recebe_tamanho() {
    cout << "Tamanho do arquivo em kB: ";
    scanf("%d", &tamanho_arquivo);
    cout << "Tamanho do pacote em kB: ";
    scanf("%d", &tam_pacote);
}

void enviar_dado_lista() {
    int cont;
    for(cont = 1; cont <= qtd_pacote; cont++) {
        //Enviar pacote cont
        inserir_dado(&inicio_fila, tam_pacote);
    }
    if(tamanho_arquivo % tam_pacote) {
        inserir_dado(&inicio_fila, tamanho_arquivo % tam_pacote);
    }
}

void envio_pacote(int tamanho) {
    system("cls");
    int cont_linha = 0, cont;
    gotoxy(20, cont_linha);
    cout << "ENVIO DE PACOTE " << tamanho << " Bytes";
    cont_linha++;
    gotoxy(0, cont_linha);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cont_linha = 3;
    gotoxy(0, cont_linha);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cont_linha--;
    gotoxy(85, cont_linha);
    cout << " <<<";
    gotoxy(0, cont_linha);
    cout << ">>>";
    for(cont = 10; cont <= 75; cont++) {
        gotoxy(cont, cont_linha);
        cout << "  ";
        cout << tamanho << "B" << "";

        Sleep(10);
    }

    //system("pause");
    cout << "\n";
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    recebe_tamanho();
    qtd_pacote = tamanho_arquivo / tam_pacote;
    enviar_dado_lista();

    Fila *retirado;
    while(inicio_fila.prox) {
        retirado = remover_fila(&inicio_fila);
        envio_pacote(retirado->dados);
    }

    if(tamanho_arquivo % tam_pacote) {
        //cout << "\nresto " << tamanho_arquivo % tam_pacote;
        qtd_pacote++;
    }
    cout << "\nPacotes enviados: " << qtd_pacote << ". Total enviado: " << tamanho_arquivo << " Bytes";


    return 0;
}
