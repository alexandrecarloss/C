#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define Linhas 6
#define Colunas 7
#define Obstaculos 5

int Linha_Inicio = 0, Linha_Fim = 0, Coluna_Inicio = 0, Coluna_Fim = 0, Passo = 0;
int Linhas_Obstaculos[Obstaculos], Colunas_Obstaculos[Obstaculos];
int Tabuleiro[Linhas][Colunas];

void LerValoresInciais() {
    // Ler Posi��o do In�cio
    printf("Digite as coordenadas do In�cio.\n\nDigite a Linha: ");
    scanf("%d", &Linha_Inicio);
    printf("\nDigite a Coluna: ");
    scanf("%d", &Coluna_Inicio);

    // Ler Posi��o do Fim
    printf("\n\nDigite as coordenadas do Fim.\n\nDigite a Linha: ");
    scanf("%d", &Linha_Fim);
    printf("\nDigite a Coluna: ");
    scanf("%d", &Coluna_Fim);
}

void GerarObstaculos() {
    int i;
    int Aleatorio1, Aleatorio2;
    //Configurando a semente do RAND
    srand(time(NULL));

    //Gerando obst�culos alet�rios
    for (i = 0; i < Obstaculos; i++) {
        Aleatorio1 = rand() % Linhas;
        Aleatorio2 = rand() % Colunas;
        Linhas_Obstaculos[i] = Aleatorio1;
        Colunas_Obstaculos[i] = Aleatorio2;
    }
}

void PreencherTabuleiro(int Tabuleiro[Linhas][Colunas]) {
    int i, j, k;

    //A matriz ser� preenchida com valores num�ricos inteiros para facilitar as compara��es
    //0 representa uma posi��o vazia
    //-1 representa um obst�culo

    for (i = 0; i < Linhas; i++) {
        for (j = 0; j < Colunas; j++) {
            int obstaculo = 0;
            for (k = 0; k < Obstaculos; k++) {
                if (i == Linhas_Obstaculos[k] && j == Colunas_Obstaculos[k]) {
                    obstaculo = 1;
                    break;
                }
            }
            if (obstaculo) {
                Tabuleiro[i][j] = -1;
            } else {
                Tabuleiro[i][j] = 0;
            }
        }
    }
}

void ImprimirTabuleiro(int Tabuleiro[Linhas][Colunas]) {
    int i, j;

    //No momento da impress�o os valores num�ricos s�o subtitu�dos por caracteres para facilitar a visualiza��o
    //0 � substitu�o por _
    //-1 � substitu�do por X
    // Os valores num�ricos acima de 0 se mant�m pois s�o referentes aos passos dados
    for (i = 0; i < Linhas; i++) {
        for (j = 0; j < Colunas; j++) {
            if (i == Linha_Inicio && j == Coluna_Inicio) {
                printf("I\t");
            } else if (i == Linha_Fim && j == Coluna_Fim) {
                printf("F\t");
            } else if (Tabuleiro[i][j] == -1) {
                printf("X\t");
            } else if (Tabuleiro[i][j] == 0) {
                printf("_\t");
            } else {
                printf("%d\t", Tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

int VerificarMovimento(int i, int j) {
    //verificar se o pr�ximo passo previsto � poss�vel
    //Ou seja, se est� dentro dos limites da matriz e se � um espa�o vazio, ou seja, n�o representa um obst�culo ou um espa�o j� visitado anteriormente
    if (i >= 0 && i < Linhas && j >= 0 && j < Colunas && Tabuleiro[i][j] == 0) {
        return 1;
    }
    return 0;
}

int EncontrarCaminho(int i, int j, int passo) {
    //testa se j� chegou ao fim
    if (i == Linha_Fim && j == Coluna_Fim) {
        return 1;
    }
    //caso o movimento seja poss�vel o passo ser� contabilizado
    if (VerificarMovimento(i, j)) {
        Tabuleiro[i][j] = passo;

        //As pr�ximas linhas utilizam da recursividade para testar repetidamente as possibilidades de movimento e incrmentar

        //Este primeiro passo verifica se � poss�vel ir para a direita
        if (EncontrarCaminho(i, j + 1, passo + 1)) {
            return 1;
        }
        //verifica se � poss�vel ir para baixo
        if (EncontrarCaminho(i + 1, j, passo + 1)) {
            return 1;
        }
        //verifica o movimento a esquerda
        if (EncontrarCaminho(i, j - 1, passo + 1)) {
            return 1;
        }

        //verifica o movimento para cima
        if (EncontrarCaminho(i - 1, j, passo + 1)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    LerValoresInciais();

    GerarObstaculos();

    PreencherTabuleiro(Tabuleiro);

    printf("\n\n\nO Tabuleiro de Jogo recebeu a seguinte configura��o inicial:\n\n");

    ImprimirTabuleiro(Tabuleiro);

    if (EncontrarCaminho(Linha_Inicio, Coluna_Inicio, Passo)) {
        printf("\n\nTabuleiro Resolvido: \n");
        //Caso a fun��o EncontrarCaminho retorne 1 significa que um caminho foi encontrado e o tabuleiro � impresso com os passos
        ImprimirTabuleiro(Tabuleiro);
    } else {
        //Caso retorne 0 significa que n�o foi poss�vel encontrar um caminho.
        printf("\nN�o foi poss�vel encontrar um caminho.\n");
    }

    return 0;
}
