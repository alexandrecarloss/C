#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>

using namespace std;
struct alimentos {
    char nome[50];
    int numero;
    alimentos *pProx;
} *paux, inicio_alimentos;


void recebe_alimentos() {
    int continua = 1, num = 0;
    paux = &inicio_alimentos;
    while(continua != 0) {
        num++;
        paux->pProx = new(alimentos);
        paux = paux->pProx;
        cout << "Insira um alimento: ";
        gets(paux->nome);
        paux->numero = num;
        cout << "Continuar Sim[1] Não[0]: ";
        cin >> continua;
        getchar();
        paux->pProx = NULL;
        system("cls");
    }
}

void exibe_alimentos() {
    paux = &inicio_alimentos;
    cout << "Num | Nome";
    while(paux->pProx) {
        paux = paux->pProx;
        cout << "\n";
        cout << paux->numero << " | " << paux->nome;
    }

}

void escolhe_alimento() {
    int opcao, id = 0;
    cout << "\nQual alimento gerou reação alergica? ";
    cin >> opcao;
     paux = &inicio_alimentos;
    while(paux->pProx) {
        id++;
        paux = paux->pProx;
        if(id == opcao) {
            cout << "Você pode ter alergia a: " << paux->nome;
        }
    }


}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    cout << "Você sentiu reação alergica hoje? Sim[1] Não[0]";
    cin >> op;
    getchar();
    if(op == 1) {
        recebe_alimentos();
        exibe_alimentos();
        escolhe_alimento();
    } else {
        cout << "Programa finalizado";
    }
    return 0;
}
