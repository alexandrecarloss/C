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

																							���� Variavel
	Janela de Inspecao ��>��������� Inspecting Num �������Ŀ
										���>�8F90:FFF2                       �
				Endereco ����	�>�float                   3.14159 �<��� Valor
		(Segmento:Bloco)	�	����������������������������������
											Tipo de Variavel
*/