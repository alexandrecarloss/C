/****************************************************************************
			Programa: e0801.cpp
		 Proposito: Verifica  endereco de variavel.
Ultima Revisao: 05/11/97
****************************************************************************/

// execute este programa passo a passo (Run / Step Over)

void main(){
	float Num = 3.14159; // <--- EXECUTE esta instrucao, mas...
}                      // <--- NAO saia do programa!

/*
 - ABRA a janela de INSPECAO DE VARIAVEL: Debug/Inspect
 - COLOQUE (Num) como parametro e veja que a seguinte janela aparece:

																							ÚÄÄÄ Variavel
	Janela de Inspecao ÄÄ>ÚÄÄÄÄÄÄÄÄ Inspecting Num ÄÄÄÄÄÄÄÄ¿
										ÚÄÄ>³8F90:FFF2                       ³
				Endereco ÄÄÄÙ	Ú>³float                   3.14159 ³<ÄÄÄ Valor
		(Segmento:Bloco)	³	ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
											Tipo de Variavel
*/