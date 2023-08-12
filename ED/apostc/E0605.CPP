/****************************************************************************
Programa: e0605.cpp
Proposito: Uso de varias funcoes de usuario.
Ultima Revisao: 29/09/97
****************************************************************************/

// **********************************
// 1 inclusao de bibliotecas padrao C
// **********************************
#include <dos.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// **************
// 2 rotina bip()
// **************
void bip(int tipo){
	int i;               // contador de iteracao
	switch (tipo){       // seleciona tipo de som...
	case 0:              // giro da roleta
		sound(100);
		delay(5);
		break;
	case 1:              // parada da roleta
		sound(200);
		delay(100);
		break;
	case 2:              // moedas caindo
			sound(3000);
			delay(20);
	}
	nosound();
}

// ****************
// 3 rotina pinta()
// ****************
void pinta(int figura,int status, int linha, int coluna){
	switch (figura){           // seleciona figura...
	case 1:                    // happy face
		if(status == 0){         // se roleta girando...
			textcolor(LIGHTGRAY);     // cor normal
		}else{
			textcolor(YELLOW+BLINK);  // cor da figura
		}
		gotoxy(coluna,linha++);   // posiciona cursor
		cprintf("  ÛÛÛÛÛ  ");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°Û°Û°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°Û°°°Û°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°ÛÛÛ°°Û");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("  ÛÛÛÛÛ  ");
		break;
	case 2:   // copa
		if(status == 0){         // se roleta girando...
			textcolor(LIGHTGRAY);  // cor normal
		}else{
			textcolor(RED);        // cor da figura
		}
		gotoxy(coluna,linha++);   // posiciona cursor
		cprintf(" ÛÛÛ ÛÛÛ ");
		gotoxy(coluna,linha++);
		cprintf("Û°°°Û°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf("   Û°Û   ");
		gotoxy(coluna,linha++);
		cprintf("    Û    ");
		break;
	case 3:   // ouro
		if(status == 0){         // se roleta girando...
			textcolor(LIGHTGRAY);  // cor normal
		}else{
			textcolor(BLUE);        // cor da figura
		}
		gotoxy(coluna,linha++);   // posiciona cursor
		cprintf("    Û    ");
		gotoxy(coluna,linha++);
		cprintf("   Û°Û   ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf("   Û°Û   ");
		gotoxy(coluna,linha++);
		cprintf("    Û    ");
		break;
	case 4:   // espada
		if(status == 0){         // se roleta girando...
			textcolor(LIGHTGRAY);  // cor normal
		}else{
			textcolor(GREEN);        // cor da figura
		}
		gotoxy(coluna,linha++);
		cprintf("    Û    ");
		gotoxy(coluna,linha++);
		cprintf("   Û°Û   ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf(" Û°°°°°Û ");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°ÛÛÛ°°Û");
		gotoxy(coluna,linha++);
		cprintf(" ÛÛ Û ÛÛ ");
		gotoxy(coluna,linha++);
		cprintf("    Û    ");
		break;
	case 5:   // pau
		if(status == 0){         // se roleta girando...
			textcolor(LIGHTGRAY);  // cor normal
		}else{
			textcolor(CYAN);        // cor da figura
		}
		gotoxy(coluna,linha++);
		cprintf("   ÛÛÛ   ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf("  Û°°°Û  ");
		gotoxy(coluna,linha++);
		cprintf("   Û°Û   ");
		gotoxy(coluna,linha++);
		cprintf(" ÛÛ°°°ÛÛ ");
		gotoxy(coluna,linha++);
		cprintf("Û°°°°°°°Û");
		gotoxy(coluna,linha++);
		cprintf("Û°°ÛÛÛ°°Û");
		gotoxy(coluna,linha++);
		cprintf(" ÛÛ Û ÛÛ ");
		gotoxy(coluna,linha++);
		cprintf("    Û    ");
	};
	textcolor(LIGHTGRAY);   // cor padrao
};

// *******************
// 4 rotina imprimec()
// *******************
void imprimec(int linha,char* texto){
	int col,tam;
	textcolor(WHITE);      // cor de letra
	textbackground(BLUE);  // cor de fundo
	gotoxy(1,linha);       // posiciona o cursor
	clreol();              // limpa linha(imprime fundo)
	tam = strlen(texto);   // calcula o tamanho do texto
	col = 40 - tam / 2;    // calcula a coluna de inicio
	gotoxy(col,linha);     // posiciona o cursor
	cprintf("%s",texto);   // imprime o texto
	textcolor(LIGHTGRAY);  // cor de letra original
	textbackground(BLACK); // cor de fundo original
};

// *****************
// 5 rotina regras()
// *****************
void regras(){
	clrscr();
	imprimec(1,"J a c k p o t !");
	imprimec(10,"Regras:");
	imprimec(11,"- Pressione [enter] para rodar a roleta.                   ");
	imprimec(12,"- Pressione [esc] para sair.                               ");
	imprimec(13,"- Quanto maior o numero de CARAS FELIZES, maior seu premio!");
	getch();
	clrscr();
}

// ****************
// 6 Rotina Saida()
// ****************
void saida(void){
	imprimec(12,"Vencedores nao usam drogas!");
	delay(2000);
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	clrscr();
}

// *****************
// 7 rotina roleta()
// *****************
void roleta(int naipe1,int naipe2,int naipe3,int naipe4,int naipe5){
	int volta1=2,volta2=4,volta3=8,volta4=16,volta5=32,tempo=25;
	do{
		if(volta1 > 1){
			pinta(random(4)+2,0,5,6);
			bip(0);
			volta1--;
		}else if(volta1 == 1){
			pinta(naipe1,1,5,6);
			bip(1);
			volta1--;
		}
		delay(tempo);

		if(volta2 > 1){
			pinta(random(4)+2,0,5,21);
			bip(0);
			volta2--;
		}else if(volta2 == 1){
			pinta(naipe2,1,5,21);
			bip(1);
			volta2--;
		}
		delay(tempo);

		if(volta3 > 1){
			pinta(random(4)+2,0,5,36);
			bip(0);
			volta3--;
		}else if(volta3 == 1){
			pinta(naipe3,1,5,36);
			bip(1);
			volta3--;
		}
		delay(tempo);

		if(volta4 > 1){
			pinta(random(4)+2,0,5,51);
			bip(0);
			volta4--;
		}else if(volta4 == 1){
			pinta(naipe4,1,5,51);
			bip(1);
			volta4--;
		}
		delay(tempo);

		if(volta5 > 1){
			pinta(random(4)+2,0,5,66);
			bip(0);
			volta5--;
		}else if(volta5 == 1){
			pinta(naipe5,1,5,66);
			bip(1);
			volta5--;
		}
		delay(tempo);

	}while(volta5 > 0);
}

// *******************
// 8 rotina abertura()
// *******************
void abertura(){
	imprimec(1,"J a c k P o t !");                  // titulo
	roleta(1,1,1,1,1);                              // caras felizes
	imprimec(25,"T e n t e   s u a   S o r t e !"); // rodape
	getch();                                        // aguarda
}

// *****************
// 9 rotina simnao()
// *****************
int simnao(){
	int tecla,resp;
	do{
		tecla = getch();   // leitura do teclado
		switch (tecla){
		case 13:   // pressionou [enter]?
			resp = 1;
			break;
		case 27:   // pressionou [esc]?
			resp = 0;
			break;
		default:   // pressionou qq outra coisa?
			printf("\a");
		};
	}while(tecla != 13 && tecla != 27);   // nao sai enquanto tecla != [enter] ou [esc]
	return(resp);
};

// ****************
// 10 rotina sorte()
// ****************
int sorte(int f1,int f2,int f3,int f4,int f5){
	int lucro,cont = 0;
	if(f1 == 1){cont++;};
	if(f2 == 1){cont++;};
	if(f3 == 1){cont++;};
	if(f4 == 1){cont++;};
	if(f5 == 1){cont++;};
	switch (cont) {
	case 0:
		lucro = 0;
		break;
	case 1:
		lucro = 1;
		break;
	case 2:
		lucro = 5;
		break;
	case 3:
		lucro = 20;
		break;
	case 4:
		lucro = 50;
		break;
	case 5:
		lucro = 250;
	};
	return(lucro);
};

// ********************
// 11 rotina plim_plim()
// ********************
int plim_plim(int total,int lucro){
	do{
		if(lucro > 0){
			lucro--;
			total++;
			bip(2);
			delay(50+random(100));
		};
		gotoxy(1,25);
		clreol();
		printf("Dinheiro: $ %d",total);
	}while(lucro > 0);
	textcolor(7);
	textbackground(0);
	return(total);
};
// ********************
// 12 programa principal
// ********************
void main(){
	int fig1,fig2,fig3,fig4,fig5;     // figuras geradas na roleta
	int lucro = 0;                    // valor recebido na roleta
	int moedas = 10;                  // dinheiro disponivel
	randomize();                      // inicializa gerador aleatorio
	regras();                         // anuncia regras
	abertura();                       // abertura do programa
	do{                                         // joga...
		fig1 = random(5)+1;                       // gera figuras da roleta
		fig2 = random(5)+1;
		fig3 = random(5)+1;
		fig4 = random(5)+1;
		fig5 = random(5)+1;
		roleta(fig1,fig2,fig3,fig4,fig5);         // gira a roleta
		lucro =  sorte(fig1,fig2,fig3,fig4,fig5); // calcula ganho na roleta
		moedas = plim_plim((moedas-2),lucro);         // despeja moedas
	}while(simnao() && moedas);                 // ... enquanto desejar e tiver moedas
	if(moedas <= 0){                            // se nao tem mais moedas...
		imprimec(25,"Sinto muito, mas seu dinheiro acabou!");
		getch();                                    // aguarda
	}
	saida();                                    // termina
}
// * * * *  f i m   d o   p r o g r a m a   p r i n c p a l ! * * * *
