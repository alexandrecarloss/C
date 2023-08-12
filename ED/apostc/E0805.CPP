/****************************************************************************
			Programa: e0805.cpp
		 Proposito: Passagem por referencia.
Ultima Revisao: 05/11/97
****************************************************************************/
#include <ctype.h>
#include <conio.h>
#include <stdio.h>

// ********************
// 1 programa principal
// ********************
void main(){
	void analiza(char,int*,int*,int*,int*,int*);
	char letra;  // letra digitada
	int vog = 0; // numero de vogais
	int con = 0; // numero de consoantes
	int dig = 0; // numero de digitos
	int esp = 0; // numero de espacos
	int out = 0; // numero de outros caracteres

	clrscr();
	puts("Digite uma frase:");

// *********************
// 1.1 Leitura e analize
// *********************
	do{
		letra = getche();
		analiza(letra,&vog,&con,&dig,&esp,&out);   // passagem de enderecos
	}while(letra != '\r');

// *************
// 1.2 Relatorio
// *************
	printf("\n\nVogais:     %2d",vog); // impresao de resultados
	printf("\nConsoantes: %2d",con);
	printf("\nNumeros:    %2d",dig);
	printf("\nEspacos:    %2d",esp);
	printf("\nOutros:     %2d",out);
	puts("\n\nPressione alguma tecla para continuar...");
	getch();

}

// ******************
// 2 Rotina analiza()
// ******************
void analiza(char l,int *pv,int *pc,int *pd,int *pe,int *po){
//                      À>      À>      À>      À>      À> ponteiros
	l = toupper(l);
	if(l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U'){
		(*pv)++;   // contando vogais
	}else if(l >= 'A' && l <= 'Z'){
		(*pc)++;   // contando consoantes
	}else if(l >= '0' && l <= '9'){
		(*pd)++;   // contando digitos
	}else if(l == ' '){
		(*pe)++;   // contando espacos
	}else{
		(*po)++;   // contando outros sinais
	}
}

