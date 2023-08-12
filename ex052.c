#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Aula 178 estrutura do campo minado
/*
    CELULA
    eBomba 0 ou 1
    estaAberta 0 ou 1
    vizinhos 0 a 4
*/
//Variáveis globais
typedef struct {
    int eBomba;
    int estaAberta;
    int vizinhos;
} Celula;
Celula jogo[10][10];
int l, c, tam = 10;

//Procedimento para inicializar a matriz jogo
void inicializarJogo() {
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
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

/* Função que retorna a quantidade de bombas na vizinhança de 1c
    n - Quantidade de bombas
*/
int quantBombasVizinhas(int l, int c) {
    /*
    l - 1 e c == cima
    l + 1 e c == baixo
    l e c + 1 == direita
    l e c - 1 == esquerda
    l - 1 e c - 1 == diagonal superior esquerda
    l - 1 e c + 1 == diagonal superior direita
    l + 1 e c - 1 == diagonal inferior esquerda
    l + 1 e c + 1 == diagonal inferior direita
    */
    int quantidade = 0;
    if(coordenadaEhValida(l - 1, c) && jogo[l - 1][c].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l + 1, c) && jogo[l + 1][c].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l , c + 1) && jogo[l][c + 1].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l, c - 1) && jogo[l][c - 1].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l - 1, c - 1) && jogo[l - 1][c - 1].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l - 1, c + 1) && jogo[l - 1][c + 1].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l + 1, c - 1) && jogo[l + 1][c - 1].eBomba) {
        quantidade++;
    }
    if(coordenadaEhValida(l + 1, c + 1) && jogo[l + 1][c + 1].eBomba) {
        quantidade++;
    }
    return quantidade;
}

//Procedimento para contar as bombas vizinhas
void contarBombas() {
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].vizinhos = quantBombasVizinhas(l, c);
        }
    }
}

//Procedimento para imprimir o jogo
void imprimir() {
    printf("\n\n\t    ");
    for(l = 0; l < tam; l++) {
        printf(" %d  ", l); //Indices das colunas
    }
    printf("\n\t   -----------------------------------------\n");
    for(l = 0; l < tam; l++) {
            printf("\t%d  |", l); // Indices das linhas
        for(c = 0; c < tam; c++) {
            if(jogo[l][c].estaAberta) {
                if(jogo[l][c].eBomba) {
                    printf(" * ");
                } else {
                    printf(" %d ", jogo[l][c].vizinhos);
                }
            } else {
                printf("   ");
            }
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}

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
            */
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

//Procedimento jogar que faz a leitura das coordenadas
void jogar() {
    setlocale(LC_ALL, "Portuguese");
    int linha, coluna;
    do {
        imprimir();
        do {
            printf("Digite as coordenadas de linha e coluna ");
            scanf("%d%d", &linha, &coluna);
            if((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].estaAberta == 1)) {
                printf("Coordenada inválida ou já aberta!\n");
            }
        } while((coordenadaEhValida(linha, coluna) == 0) || (jogo[linha][coluna].estaAberta == 1));
        abrirCelula(linha, coluna);
    } while((ganhou() != 0) && (jogo[linha][coluna].eBomba == 0));
    if(jogo[linha][coluna].eBomba == 1) {
        printf("\n\tQue pena! você perdeu!!!");
        imprimir();
    } else {
        printf("\n\tPARABÉNS! VOCÊ GANHOU!!!");
        imprimir();
    }
}
int main() {
    int opcao;
    do {
        inicializarJogo();
        sortearBombas(10);
        contarBombas();
        printf("\n\t\t\tCAMPO MINADO\n");
        jogar();
        printf("\n Digite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    } while(opcao == 1);
    return 0;
}
