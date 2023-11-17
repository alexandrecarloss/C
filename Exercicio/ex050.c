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
    // Ler Posição do Início
    printf("Digite as coordenadas do Início.\n\nDigite a Linha: ");
    scanf("%d", &Linha_Inicio);
    printf("\nDigite a Coluna: ");
    scanf("%d", &Coluna_Inicio);

    // Ler Posição do Fim
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

    //Gerando obstáculos aletórios
    for (i = 0; i < Obstaculos; i++) {
        Aleatorio1 = rand() % Linhas;
        Aleatorio2 = rand() % Colunas;
        Linhas_Obstaculos[i] = Aleatorio1;
        Colunas_Obstaculos[i] = Aleatorio2;
    }
}

void PreencherTabuleiro(int Tabuleiro[Linhas][Colunas]) {
    int i, j, k;

    //A matriz será preenchida com valores numéricos inteiros para facilitar as comparações
    //0 representa uma posição vazia
    //-1 representa um obstáculo

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

    //No momento da impressão os valores numéricos são subtituídos por caracteres para facilitar a visualização
    //0 é substituío por _
    //-1 é substituído por X
    // Os valores numéricos acima de 0 se mantém pois são referentes aos passos dados
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
    //verificar se o próximo passo previsto é possível
    //Ou seja, se está dentro dos limites da matriz e se é um espaço vazio, ou seja, não representa um obstáculo ou um espaço já visitado anteriormente
    if (i >= 0 && i < Linhas && j >= 0 && j < Colunas && Tabuleiro[i][j] == 0) {
        return 1;
    }
    return 0;
}

int EncontrarCaminho(int i, int j, int passo) {
    //testa se já chegou ao fim
    if (i == Linha_Fim && j == Coluna_Fim) {
        return 1;
    }
    //caso o movimento seja possível o passo será contabilizado
    if (VerificarMovimento(i, j)) {
        Tabuleiro[i][j] = passo;

        //As próximas linhas utilizam da recursividade para testar repetidamente as possibilidades de movimento e incrmentar

        //Este primeiro passo verifica se é possível ir para a direita
        if (EncontrarCaminho(i, j + 1, passo + 1)) {
            return 1;
        }
        //verifica se é possível ir para baixo
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

    printf("\n\n\nO Tabuleiro de Jogo recebeu a seguinte configuração inicial:\n\n");

    ImprimirTabuleiro(Tabuleiro);

    if (EncontrarCaminho(Linha_Inicio, Coluna_Inicio, Passo)) {
        printf("\n\nTabuleiro Resolvido: \n");
        //Caso a função EncontrarCaminho retorne 1 significa que um caminho foi encontrado e o tabuleiro é impresso com os passos
        ImprimirTabuleiro(Tabuleiro);
    } else {
        //Caso retorne 0 significa que não foi possível encontrar um caminho.
        printf("\nNão foi possível encontrar um caminho.\n");
    }

    return 0;
}
