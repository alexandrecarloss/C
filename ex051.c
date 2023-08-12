#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define MAXLINHA 6
#define MAXCOLUNA 6


int matriz[MAXLINHA][MAXCOLUNA], matrizCoordenada[MAXLINHA][MAXCOLUNA], linha, coluna, linhaobs[MAXLINHA], colunaobs[MAXCOLUNA], i, qntPos, linhaPos[MAXLINHA * MAXCOLUNA], colunaPos[MAXLINHA * MAXCOLUNA], perdeu = 0;

void geraMatriz(){
    //Vai gerar a matriz com todas as coordenadas valendo 0
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            matriz[linha][coluna] = 0;
            matrizCoordenada[linha][coluna] = 0;
        }
    }
}

void geraObstaculos() {
    srand(time(NULL));
    int obs, cont = 1;
    //Gera dois vetores com as coordenadas de linha e coluna das bombas
    for(i = 0; i < MAXLINHA; i++){
         linhaobs[i] = rand() % MAXLINHA;
         colunaobs[i] = rand() % MAXCOLUNA;
    }

    //Verifica se há coordenadas iguais, se sim, sorteia novas coordenadas
    for(i = 0; i < MAXLINHA - 1; i++){
         if((linhaobs[i] == linhaobs[i + cont]) && (colunaobs[i] == colunaobs[i + cont])) {
            linhaobs[i] = rand() % MAXLINHA;
            colunaobs[i] = rand() % MAXCOLUNA;
         }
         cont++;
    }
    /*
    printf("Coordenadas dos obstáculos: \n");
    for(i = 0; i < MAXLINHA; i++){
        printf("Linha %d coluna %d\n", linhaobs[i], colunaobs[i]);
    }
    */
    //Adiciona 1 nas coordenadas da matriz que correspondem as das bombas
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            obs = 0;
            for(i = 0; i < MAXLINHA; i++){
                if((linha == linhaobs[i]) && (coluna == colunaobs[i])) {
                    obs = 1;
                }
            }
            if(obs == 0) {
                    matriz[linha][coluna] = 0;
            } else {
                matriz[linha][coluna] = -1;
            }
        }
    }
}

void exibeMatriz() {
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            if(matriz[linha][coluna] == -1){
                printf("* ");
            } else {
                printf("%d ", matriz[linha][coluna]);
            }

        }
        printf("\n");
    }
    printf("\n");
}

void ocultaMatriz() {
    //Compara a matrizCoordenada que recebe 1 nas coordenadas dadas pelo usuário e exibe o número correspondente na matriz
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
        //printf("linha = %d coluna = %d linhaPos = %d colunaPos = %d ", linha, coluna, linhaPos[linha], colunaPos[coluna]);
            if(matrizCoordenada[linha][coluna] == 1) {
                if(matriz[linha][coluna] == -1){
                    printf("* ");
                } else {
                    printf("%d ", matriz[linha][coluna]);
                }
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void calculaBombas() {
    int bombadireita, bombaembaixo, bombaencima, bombaesquerda, bombasupesq, bombasupdir, bombainfesq, bombainfdir;
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            bombadireita = 0;
            bombaembaixo = 0;
            bombaencima = 0;
            bombaesquerda = 0;
            bombasupesq = 0;
            bombasupdir = 0;
            bombainfesq = 0;
            bombainfdir = 0;

            //int direita = 0, esquerda = 0, cima = 0, baixo = 0;

            for(i = 0; i < MAXLINHA; i++){
                if(matriz[linha][coluna] != -1) {
                    if((linha == linhaobs[i]) && ((coluna + 1) == colunaobs[i])) {
                        bombadireita = 1;
                        //printf("Bomba a direita de [%d][%d]\n", linha, coluna);
                    }
                    if(((linha + 1) == linhaobs[i]) && (coluna == colunaobs[i])) {
                        bombaembaixo = 1;
                        //printf("Bomba abaixo de [%d][%d]\n", linha, coluna);
                    }
                    if((linha == linhaobs[i]) && ((coluna - 1) == colunaobs[i])) {
                        bombaesquerda = 1;
                        //printf("Bomba a esquerda de [%d][%d]\n", linha, coluna);
                    }
                    if(((linha - 1) == linhaobs[i]) && (coluna == colunaobs[i])) {
                        bombaencima = 1;
                        //printf("Bomba acima de [%d][%d]\n", linha, coluna);
                    }

                    //Diagonais
                    if(((linha - 1) == linhaobs[i]) && ((coluna - 1) == colunaobs[i])) {
                        bombasupesq = 1;
                        //printf("Bomba superior esquerda de [%d][%d]\n", linha, coluna);
                    }
                    if(((linha - 1) == linhaobs[i]) && ((coluna + 1) == colunaobs[i])) {
                        bombasupdir = 1;
                        //printf("Bomba superior direita de [%d][%d]\n", linha, coluna);
                    }
                    if(((linha + 1) == linhaobs[i]) && ((coluna - 1) == colunaobs[i])) {
                        bombainfesq = 1;
                       //printf("Bomba inferior esquerda de [%d][%d]\n", linha, coluna);
                    }
                    if(((linha + 1) == linhaobs[i]) && ((coluna + 1) == colunaobs[i])) {
                        bombainfdir = 1;
                        //printf("Bomba inferior direita de [%d][%d]\n", linha, coluna);
                    }
                }
            }
            if(matriz[linha][coluna] != -1) {
                matriz[linha][coluna] = bombadireita + bombaembaixo + bombaencima + bombaesquerda + bombasupesq + bombasupdir + bombainfesq + bombainfdir;
            }
        }
    }
}

void recebeCoordenadas(int indice) {
    //Coleta de coordenadas da posição que deve mostrar
    printf("Qual a linha da coordenada? \n[linha] ");
    scanf("%i", &linhaPos[indice]);
    printf("Qual a coluna da coordenada? \n[coluna] ");
    scanf("%i", &colunaPos[indice]);
    printf("Matriz [%d][%d]\n", linhaPos[indice], colunaPos[indice]);
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            if((linha == linhaPos[indice]) && (coluna == colunaPos[indice])) {
                matrizCoordenada[linha][coluna] = 1;
                if(matriz[linha][coluna] == -1){
                    system("cls");
                    printf("\n\n\t\tPerdeu!\n\n");
                    perdeu = 1;
                }
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    geraMatriz();
    geraObstaculos();
    //printf("Matriz com obstáculos sendo *: \n");
    //exibeMatriz();
    calculaBombas();
    ocultaMatriz();
    qntPos = 0;
    while(qntPos < (MAXCOLUNA * MAXLINHA)) {
        recebeCoordenadas(qntPos);
        if(perdeu == 1) {
            break;
        }
        qntPos++;
        ocultaMatriz();
    }

    exibeMatriz();
    return 0;
}
