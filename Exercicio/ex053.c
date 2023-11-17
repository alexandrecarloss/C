#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAXLINHA 5
#define MAXCOLUNA 5

/*
    CELULA
    eBomba 0 ou 1
    passo e, d, c, b
    vizinhos 0 a 8
*/

//Variáveis globais
typedef struct {
    int eBomba;
    int direita;
    int esquerda;
    int cima;
    int baixo;
    int percurso;
    char inicio;
    char fim;
} Celula;
Celula jogo[MAXLINHA][MAXCOLUNA];
int l, c, tam = MAXLINHA, sai[2], chega[2];

//Procedimento para inicializar a matriz jogo
void inicializarJogo() {
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].eBomba = 0;
            jogo[l][c].percurso = 0;
        }
    }
}

//Procedimento para sortear n bombas
void sortearBombas(int n) {
    int i;
    srand(time(NULL));
    for(i = 1; i <= n; i++) {
        l = rand() % tam;
        c = rand() % tam;
        if(jogo[l][c].eBomba == 0) {
           jogo[l][c].eBomba = 1;
        } else {
            i--;
        }
    }
}

/*
    Função que diz se um par de coordenadas é valido ou não
    1 - é válido
    0 - não é válido
*/
int coordenadaEhValida(int l, int c) {
    if((l >= 0) && (l < tam) && (c >= 0) && (c < tam)) {
        return 1;
    } else {
        return 0;
    }
}

//Função que verifica as quatro posições ao redor e se puder ir recebem 1, senão recebem 0
void qualDirecaoPodeIr(int l, int c) {
    /*
    l - 1 e c == cima
    l + 1 e c == baixo
    l e c + 1 == direita
    l e c - 1 == esquerda
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].baixo = 0;
            jogo[l][c].cima = 0;
            jogo[l][c].direita = 0;
            jogo[l][c].esquerda = 0;
        }
    }
    */

    if(coordenadaEhValida(l - 1, c) && jogo[l - 1][c].eBomba == 0) {
        //Pode subir
        jogo[l][c].cima = 1;
    }
    if(coordenadaEhValida(l + 1, c) && jogo[l + 1][c].eBomba == 0) {
        //Pode descer
        jogo[l][c].baixo = 1;
    }
    if(coordenadaEhValida(l , c + 1) && jogo[l][c + 1].eBomba == 0) {
        //Pode direita
        jogo[l][c].direita = 1;
    }
    if(coordenadaEhValida(l, c - 1) && jogo[l][c - 1].eBomba == 0) {
        //Pode esquerda
        jogo[l][c].esquerda = 1;
    }
}
//Procedimento para finalizar o jogo
void finaliza() {
    printf("Não consegui completar chefe fim em %d %d", l, c);
}

//Procedimento para resolver labirinto
void resolverLabirinto() {
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            qualDirecaoPodeIr(l, c);
        }
    }

    int cont = 0, quebralinha = 0, fim = 0;
    //if((sai[0] <= chega[0]) && (sai[1] <= chega[1])) {
        //Objetivo embaixo e a direita
        for(l = 0; l < tam; l++) {
            quebralinha = 0;
            for(c = 0; c < tam; c++) {
                if ((jogo[l][c].direita == 0) && (jogo[l][c].inicio == 1)) {
                    //Não pode ir para direita a partir do início
                    quebralinha = 1;
                    printf("inicio queimado na direita %d %d\n", l, c);
                } else if((jogo[l][c].baixo == 0) && (jogo[l][c].direita == 0)) {
                     //Não pode ir para baixo e também não pode descer
                     finaliza();
                     fim =  1;
                     quebralinha = 1;
                }else if ((jogo[l][c].direita) && (jogo[l][c].inicio == 0) && (jogo[l][c].eBomba == 0) && (l >= sai[0])) {
                    //Pode direita, não é inicio, não é bomba e à partir da linha de saída
                    cont++;
                    jogo[l][c].percurso = cont;
                    printf("direita %d %d\n", l, c);
                } else if((jogo[l][c].baixo) && (jogo[l][c].inicio == 0) && (jogo[l][c].eBomba == 0) && (l >= sai[0])) {
                    //Pode baixo, não é inicio, não é bomba e à partir da linha de saída
                    cont++;
                    jogo[l][c].percurso = cont;
                    printf("baixo %d %d\n", l, c);
                    quebralinha = 1;
                }
                /*
                if((l >= sai[0]) && (c >= sai[0])) {
                    //A partir da saida
                    if((l <= chega[0]) && (c <= chega[1])) {
                        //Ate a chegada
                        if((jogo[l][c].direita) && (jogo[l][c].eBomba == 0)) {
                            //Pode direita
                            printf("linha = %d coluna = %d\n", l, c);
                            cont++;
                            jogo[l][c].percurso = cont;
                        }
                    }
                }
                */
                if(quebralinha) {
                    break;
                }
            }
            if(fim) {
                break;
            }
        }
/*
        printf("cont %d",cont);
    } else{
        printf("fora");
    }
*/
}

//Procedimento para imprimir o jogo
void imprimir() {
    printf("\n\n\t    ");
    for(l = 0; l < tam; l++) {
        printf(" %d  ", l); //Indices das colunas
    }
    printf("\n\t   --------------------\n");
    for(l = 0; l < tam; l++) {
        printf("\t%d  |", l); // Indices das linhas
        for(c = 0; c < tam; c++) {

            if(jogo[l][c].eBomba) {
                printf(" * ");
            } else if(jogo[l][c].inicio){
                printf(" I ");
            } else if(jogo[l][c].fim) {
                printf(" F ");
            } else {
                printf(" %d ", jogo[l][c].percurso);
            }
            printf("|");
        }
        printf("\n\t   --------------------\n");
    }
}

//Procedimento para receber início e fim
void recebeCoordenadasInicioFim() {
    setlocale(LC_ALL, "Portuguese");
    int linha, coluna;
    do {
        printf("Digite as coordenadas de linha e coluna inicio: ");
        scanf("%d%d", &linha, &coluna);
        if((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].eBomba == 1)) {
            printf("Coordenada inválida!\n");
        } else {
            jogo[linha][coluna].inicio = "I";
            sai[0] = linha;
            sai[1] = coluna;
        }
    } while((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].eBomba == 1));
    do {
        printf("Digite as coordenadas de linha e coluna fim: ");
        scanf("%d%d", &linha, &coluna);
        if((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].eBomba == 1)) {
            printf("Coordenada inválida!\n");
        } else {
            jogo[linha][coluna].fim = "F";
            chega[0] = linha;
            chega[1] = coluna;
        }
    } while((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].eBomba == 1));
}

/*
//Procedimento para abrir a célula digitada pelo usuário
void abrirCelula(int l, int c) {
    if((coordenadaEhValida(l, c) == 1) && (jogo[l][c].estaAberta == 0)) {
        jogo[l][c].estaAberta = 1;
        if(jogo[l][c].vizinhos == 0) {
            /*
            l - 1 e c == cima
            l + 1 e c == baixo
            l e c + 1 == direita
            l e c - 1 == esquerda
            l - 1 e c - 1 == diagonal superior esquerda
            l - 1 e c + 1 == diagonal superior direita
            l + 1 e c - 1 == diagonal inferior esquerda
            l + 1 e c + 1 == diagonal inferior direita

            //Procedimento utiliza recursividade para abrir automaticamente as células ao redor
            abrirCelula(l - 1, c);
            abrirCelula(l + 1, c);
            abrirCelula(l, c + 1);
            abrirCelula(l, c - 1);
            abrirCelula(l - 1, c - 1);
            abrirCelula(l - 1, c + 1);
            abrirCelula(l + 1, c - 1);
            abrirCelula(l + 1, c + 1);
        }
    }
}

/*Função para verificar vitória
    n - ganhou
    0 - não ganhou ainda
*/

/*
int ganhou() {
    int quantidade = 0;
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            if((jogo[l][c].estaAberta == 0) && (jogo[l][c].eBomba == 0)) {
                quantidade++;
            }
        }
    }
    return quantidade;
}

*/
int main() {
    inicializarJogo();
    sortearBombas(MAXLINHA);
    //contarBombas();
    printf("\n\t\tCAMPO MINADO\n");
    imprimir();
    recebeCoordenadasInicioFim();
    resolverLabirinto();
    imprimir();
    return 0;
}
