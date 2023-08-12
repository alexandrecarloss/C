//Nome do programa: HistEsRC2017.cpp
#include <iostream>
#include <tchar.h>

using namespace std;


//definição da estrutura de um registro de conjuntos
typedef struct {
   char	  disciplina[30], aluno[50], situacao;
   float  notas[5];
   int	  ano, faltas;
} HistoricoEscolar;

int main(){

   HistoricoEscolar ficha2017008; 	//declaração da variável do tipo HistoricoEscolar

    setlocale(LC_ALL, "Portuguese");
    system("cls");   //clrscr();

   //Entrada dos dados da ficha
   cout << "\nInforme os dados da ficha do aluno";
   cout << "\nDisciplina: ";
   gets(ficha2017008.disciplina);
   cout << "\nAluno: ";
   gets(ficha2017008.aluno);
   cout << "\nNotas Bimestrais: ";
   cout << "\n  -> Primeira: ";
   cin >> ficha2017008.notas[0];
   cout << "\n  -> Segunda: ";
   cin >> ficha2017008.notas[1];
   cout << "\n  -> Terceira: ";
   cin >> ficha2017008.notas[2];
   cout << "\n  -> Quarta: ";
   cin >> ficha2017008.notas[3];
   cout << "\nNumero de Faltas: ";
   cin >> ficha2017008.faltas;
   cout << "\nAno: ";
   cin >> ficha2017008.ano;

   //Processamento da m‚dia e da situa‡Æo do aluno na disciplina
   ficha2017008.notas[4]=(ficha2017008.notas[0] + ficha2017008.notas[1] + ficha2017008.notas[2] + ficha2017008.notas[3])/4;
   if(ficha2017008.notas[4]>=5)
     ficha2017008.situacao ='A';
   else
     ficha2017008.situacao ='R';

   //Sa¡da dos dados da ficha
   cout << "\n*************  HISTORICO ESCOLAR *************\n";
   cout << "\nDisciplina: " <<   ficha2017008.disciplina;
   cout << "\nAluno:      " <<   ficha2017008.aluno;
   cout << "\n -----  Notas Bimestrais  -----";
   printf("\nPrimeira: \t %2.1f",   ficha2017008.notas[0]);
   printf("\nSegunda:  \t %2.1f",   ficha2017008.notas[1]);
   printf("\nTerceira: \t %2.1f",   ficha2017008.notas[2]);
   printf("\nQuarta:   \t %2.1f",   ficha2017008.notas[3]);
   printf("\nMedia Final: \t %2.1f",ficha2017008.notas[4]);
   if(ficha2017008.situacao=='A')
      cout << "\nSituacao: Aprovado";
   else
      cout << "\nSituacao: Reprovado";
   cout << "\nNumero de Faltas: " << ficha2017008.faltas;
   cout << "\nAno: " << ficha2017008.ano;
   
   cout << "\n\n";
   system("pause");
   return 0;
}
