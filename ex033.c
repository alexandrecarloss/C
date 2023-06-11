#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
 /*Objetivo:
Implementar o controle de comandas de um estabelecimento comercial.*/
//Declaração de variáveis
float valor_uni, qnt, soma_total, percent, valor_pago, troco, desconto;
int opcao = 0, opc_desc = 0;

//Declaração de funções
void menu() {
    printf("\tCOMANDA\n");
    printf("1 - Cadastrar comanda \n2 - Fechar comanda \n3 - Realizar desconto \n4 - Fazer pagamento \n5 - Cancelar comanda \n6 - Cancelar item da comanda \n7 - Sair do sistema\n");
    scanf("%i", &opcao);
}
void caso1() {
    printf("Informe o valor do produto R$");
    scanf("%f", &valor_uni);
    printf("Informe a quantidade: ");
    scanf("%f", &qnt);
    soma_total += valor_uni * qnt;
}

void caso2() {
    printf("A soma total é R$%.2f\n", soma_total);
    getch();
}

void caso3() {
    caso2();
    percent = 0;
    while(percent > 100 || percent < 1) {
        printf("Informe o valor percentual (entre 1 e 100): ");
        scanf("%f", &percent);
        if ((percent > 100) || (percent < 0)) {
            printf("Percentual inválido\n");
        }
    }
    soma_total = soma_total - (soma_total * (percent / 100));
}

void caso4() {
    caso2();
    valor_pago = 0;
    while(valor_pago < soma_total) {
        printf("\nValor pago R$");
        scanf("%f", &valor_pago);
        if(valor_pago < soma_total) {
            printf("Valor pago menor que o total");
        } else {
            troco = valor_pago - soma_total;
            printf("\nO troco é R$%.2f\n", troco);
            soma_total = 0;
        }
    }
    getch();
}

void caso5() {
    printf("Comanda cancelada");
    soma_total = 0;
    getch();
}

void caso6() {
    caso2();
    desconto = 0;
    while((desconto <= 0) || (desconto > soma_total)) {
        printf("Informe o valor do produto a ser descontado R$");
        scanf("%f", &valor_uni);
        printf("Informe a quantidade: ");
        scanf("%f", &qnt);
        desconto = (valor_uni * qnt);
        if ((desconto < 0) || (desconto > soma_total)) {
            printf("Desconto inválido!\n");
        }
    }
    soma_total = soma_total - desconto;
}

void caso7() {
    printf("Encerrando o programa...");
    getch();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    while(opcao != 7) {
        menu();
        switch(opcao) {
            case 1:
                caso1();
                break;
            case 2:
                caso2();
                break;
            case 3:
                caso3();
                break;
            case 4:
                caso4();
                break;
            case 5:
                caso5();
                break;
            case 6:
                caso6();
                break;
            case 7:
                caso7();
                break;
            default:
                printf("Opção inválida ");
                getch();
                break;
        }
        system("cls");
    }
    return 0;
}
