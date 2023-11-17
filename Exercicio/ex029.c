#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>


//Declaração de funções

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Objetivo:
    Implementar o controle de comandas de um estabelecimento comercial.*/

    //Declaração de variáveis
    float valor_uni, qnt, soma_total, percent, valor_pago, troco, desconto;
    int opcao = 0, opc_desc = 0;

    while(opcao != 7) {
        printf("\tCOMANDA\n");
        printf("1 - Cadastrar comanda \n2 - Fechar comanda \n3 - Realizar desconto \n4 - Fazer pagamento \n5 - Cancelar comanda \n6 - Cancelar item da comanda \n7 - Sair do sistema\n");
        scanf("%i", &opcao);
        switch(opcao) {
            case 1:
                printf("Informe o valor do produto R$");
                scanf("%f", &valor_uni);
                printf("Informe a quantidade: ");
                scanf("%f", &qnt);
                soma_total += valor_uni * qnt;
                break;
            case 2:
                printf("A soma total é R$%.2f\n", soma_total);
                system("pause");
                break;
            case 3:
                while(percent > 100 || percent < 1) {
                    printf("Informe o valor percentual (entre 1 e 100): ");
                    scanf("%f", &percent);
                    if ((percent > 100) || (percent < 0)) {
                        printf("Percentual inválido\n");
                    }
                }
                soma_total = soma_total - (soma_total * (percent / 100));
                break;
            case 4:
                printf("Valor total = R$%.2f", soma_total);
                valor_pago = 0;
                while(valor_pago < soma_total) {
                    printf("\nValor pago R$");
                    scanf("%f", &valor_pago);
                    if(valor_pago < soma_total) {
                        printf("\nValor pago menor que o total");
                    } else {
                        troco = valor_pago - soma_total;
                        printf("\nO troco é R$%.2f\n", troco);
                        soma_total = 0;
                    }
                }
                getch();
                break;
            case 5:
                soma_total = 0;
                break;
            case 6:
                printf("Valor total = R$%.2f", soma_total);
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
                break;
            case 7:
                printf("Encerrnado programa...");
                break;
            default:
                printf("Opção inválida ");
                system("pause");
                break;
        }
        system("cls");
    }
    return 0;
}
