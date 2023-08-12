/* *******************************************************************
			Programa: e0306.cpp
		 Proposito: Operadores Condicionais
Ultima Revisao: 23/07/97
******************************************************************* */
void main(){
	int i,j,max1,max2;
	float r,s;

	// A seguinte atribuicao...
	r = (i==j) ? 34.9 : 88.4;

	// e' equivalente a...
	if(i==j){
		s = 34.9;
	}else{
		s = 88.4;
	};

	// Aplicacao simples
	// Para nao escrever...
	if(i > j){
		max1 = i;
	}else{
		max1 = j;
	};

	// pode-se escrever...
	max2 = (i > j) ? i : j;

}
