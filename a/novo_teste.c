#include <stdio.h>
#include <locale.h>



int idade(){

    int ano_nascimento=0;
    int ano_atual=2023;
    int idade=0;
    printf("Digite seu ano de nascimento \n");
    scanf("%d", &ano_nascimento);


    idade = ano_atual - ano_nascimento;

    printf("A sua idade é: %d", idade);

    printf("\n*********************************************************\n");

    printf("\n*********************************************************\n");
    return 0;
}

int quadrado(){
    int comprimento, largura;

    printf("Digite o comprimento, e largura \n");
    scanf("%d %d", &comprimento, &largura);
    int perimetro = 2*comprimento + 2*largura;

    printf("O perimetro deste retangulo é: %d \n",perimetro);
    printf("\n*********************************************************\n");

    printf("\n*********************************************************\n");
    return 0;

}

int peso(){
    float valor_peso;
    float kilos;

    printf("Digite o valor do Kilo\n");
    scanf("%f", &valor_peso);
    printf("Agora digite a qtd, em kilos \n");

    scanf("%f", &kilos);

    float preco = valor_peso*kilos;

    printf("O valor em reais é: %.2f R$",preco);

    printf("\n*********************************************************\n");

    printf("\n*********************************************************\n");
    return 0;
}

int comparar(){
    float peso1, peso2,peso_kilo1,peso_kilo2,preco1, preco2;

    printf("Digite o peso em gramas, do primeiro produto \n");
    scanf("%f", &peso1);
    printf("Digite o valor em reais do primeiro produto \n");
    scanf("%f",&preco1);
    printf("Digite o peso em gramas, do segundo produto \n");
    scanf("%f", &peso2);
    printf("Digite o valor em reais do segundo produto \n");
    scanf("%f",&preco2);
    peso_kilo1 = preco1/peso1;
    peso_kilo2 = preco2/peso2;
    if(peso_kilo1<peso_kilo2){
        printf("O peso por kilo é %.2f R$ para primeiro, do segundo é: %.2f R$, portanto é mais vantajoso o primeiro produto\n",peso_kilo1*100,peso_kilo2*100);

    }else if(peso_kilo1 == peso_kilo2){
        printf("O peso por kilo é %.2f R$ para os dois, portanto não há diferença\n",peso_kilo1*100);

    }else{
        printf("O peso por kilo é %.2f R$ para o primeiro, do segundo é: %.2f R$, portanto é mais vantajoso o segundo produto\n",peso_kilo1*100,peso_kilo2*100);
    }

    printf("\n*********************************************************\n");

    printf("\n*********************************************************\n");

}


void main(){
    setlocale(LC_ALL, "Portuguese");
    char atividade[4];
    while(1){

            printf("Digite o numero da atividade 1-4, ou digite 'sair' para parar o programa\n");
            scanf("%s",&atividade);

            if(atividade[0] == '1' ){
                idade();
            }
            else if(atividade[0] == '2' ){
                quadrado();
            }
            else if(atividade[0] == '3'){
                peso();
            }
            else if(atividade[0] == '4'){
                comparar();
            }
            else {
                    break;
            }


    }


}
