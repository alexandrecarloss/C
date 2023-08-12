#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define MAXLINHA 6
#define MAXCOLUNA 6


int matriz[MAXLINHA][MAXCOLUNA], linha, coluna, linhaobs[MAXLINHA], colunaobs[MAXCOLUNA], i, linhaper[MAXLINHA * MAXCOLUNA], colunaper[MAXLINHA * MAXCOLUNA];

void geraMatriz(){
    for(linha = 0; linha < MAXLINHA; linha++){
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {
            matriz[linha][coluna] = 0;
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

    printf("Coordenadas dos obstáculos: \n");
    for(i = 0; i < MAXLINHA; i++){
        printf("Linha %d coluna %d\n", linhaobs[i], colunaobs[i]);
    }

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
            printf("%d \t", matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
}

void chegarLocal() {
    int linhaSai, colunaSai, linhaChe, colunaChe, cont = 0, direita, esquerda, cima, baixo;
    //Coleta de coordenadas de saida e chegada
    printf("De onde você quer sair? \n[linha] ");
    scanf("%i", &linhaSai);
    printf("[coluna] ");
    scanf("%i", &colunaSai);
    printf("Aonde você quer chegar? \n[linha] ");
    scanf("%i", &linhaChe);
    printf("[coluna] ");
    scanf("%i", &colunaChe);
    printf("\nSaindo de [%d][%d] para [%d][%d] \n", linhaSai, colunaSai, linhaChe, colunaChe);

    int bombadireita, bombaembaixo, bombaencima, bombaesquerda, quebralinha, fim=0;
    for(linha = 0; linha < MAXLINHA; linha++){
        quebralinha = 0;
        for(coluna = 0; coluna < MAXCOLUNA; coluna++) {

            bombadireita = 0;
            bombaembaixo = 0;
            bombaencima = 0;
            bombaesquerda = 0;

            direita = 0;
            esquerda = 0;
            cima = 0;
            baixo = 0;

            //linhaper[linha] = linha;
            //colunaper[coluna] = coluna;

            for(i = 0; i < MAXLINHA; i++){
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
                //Percurso


                if(linha == 0) {
                    //Não pode subir
                    cima = -1;
                }
                if(coluna == 0){
                    //Não pode esquerda
                    esquerda = -1;
                }
                if(coluna == MAXCOLUNA - 1) {
                    //não pode direita
                    direita = -1;
                }
                if(linha == MAXLINHA - 1) {
                    //Não pode descer
                    baixo = -1;
                }


            }
            if(linhaChe > linhaSai) {
                //Objetivo abaixo
                if((bombaembaixo == 0) && (baixo == 0)) {
                    //Pode descer
                }
            }
            //Alimenta os vetores colunaper e linhaper com os valores de linha e coluna do percurso
            if(matriz[linha][coluna] == -1) {
                quebralinha = 1;
            } else {
                if((colunaChe > colunaSai) && (linha >= linhaSai) && (coluna >= colunaSai)) {
                    //Objetivo a direita
                    if((bombadireita == 0) && (direita == 0)) {
                        //Pode direita
                        colunaper[cont] = coluna;
                        linhaper[cont] = linha;
                        matriz[linha][coluna] = cont;
                        cont++;
                        //printf("Atual [%d][%d] mov direita [%d][%d]\n", linha, coluna, linha, coluna+1);
                    } else {
                        colunaper[cont] = coluna;
                        linhaper[cont] = linha;
                        matriz[linha][coluna] = cont;
                        cont++;
                        //Não pode direita
                        quebralinha = 1;
                    }
                }
            }

            /*
            if(linhaChe < linhaSai) {
                //Objetivo acima
                if((bombaencima == 0) && (cima == 0)) {
                    //Pode subir
                }
            }
            if(colunaChe < colunaSai) {
                //Objetivo a esquerda
                if((bombaesquerda == 0) && (esquerda == 0)) {
                    //Pode esquerda
                }
            }
            */

            /*
            if(bombaembaixo == 1) {
                col = coluna[];
                break;
            }
            */
            //Encerra os doi laços e finaliza
               if((linha == linhaChe) && (coluna == colunaChe)) {
                    printf("Chegou em [%d][%d]\n", linhaChe, colunaChe);
                    colunaper[cont] = coluna;
                    linhaper[cont] = linha;
                    matriz[linha][coluna] = cont;
                    cont++;
                    fim = 1;
                    break;
               }
               //Encerra o laço de coluna e pula para próxima linha
                if(quebralinha == 1) {
                    break;
                }


        }
        if((linhaChe == linha) && (fim != 1)) {
            printf("Não consegui chegar ao objetivo chefe \n");
            break;
        }
        if(fim == 1) {
            break;
        }
    }

    //printf("inicio [%d] [%d]", linhaper[0], colunaper[0]);
    /*
    for(i = 0; i < (MAXLINHA * MAXCOLUNA); i++) {
        //printf("\ncaminho [%d][%d]", linhaper[i], colunaper[i]);
    }
    */

    //Peercurso de movimentos
    /*
    for(i = 0; i < cont; i++) {
        printf(" cont = %d matriz[%d][%d]\n", i, linhaper[i], colunaper[i]);
    }
    */
}



int main() {
    setlocale(LC_ALL, "Portuguese");
    geraMatriz();
    geraObstaculos();
    printf("\nMatriz com obstáculos sendo -1: \n");
    exibeMatriz();
    chegarLocal();
    exibeMatriz();
    return 0;
}
