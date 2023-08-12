//Nome do programa: HistEscR2017.cpp
#include <iostream>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>

using namespace std;

//definição da estrutura de um registro
typedef struct {
    char	  disciplina[30], aluno[50], situacao;
    float     notaBim1, notaBim2, notaBim3, notaBim4, mediaFinal;
    int	      ano, faltas;
} HistoricoEscolar;

int main()
{
    HistoricoEscolar ficha2017008; 	//declaração da variável do tipo HistoricoEscolar
    
    setlocale(LC_ALL, "Portuguese");
    //_tsetlocale(LC_ALL, _T("portuguese"));
    system("cls");   //clrscr();
    //Entrada dos dados da ficha
    cout << "\nInforme os dados da ficha do aluno";
    cout << "\nDisciplina: ";
    gets(ficha2017008.disciplina);
    cout << "\nAluno: ";
    gets(ficha2017008.aluno);
    cout << "\nNotas Bimestrais: ";
    cout << "\n  -> Primeira: ";
    cin >> ficha2017008.notaBim1;
    cout << "\n  -> Segunda: ";
    cin >> ficha2017008.notaBim2;
    cout << "\n  -> Terceira: ";
    cin >> ficha2017008.notaBim3;
    cout << "\n  -> Quarta: ";
    cin >> ficha2017008.notaBim4;
    cout << "\nNumero de Faltas: ";
    cin >> ficha2017008.faltas;
    cout << "\nAno: ";
    cin >> ficha2017008.ano;

    //Processamento da media e da situação do aluno na disciplina
    ficha2017008.mediaFinal=(ficha2017008.notaBim1 +ficha2017008.notaBim2+ficha2017008.notaBim3+ficha2017008.notaBim4)/4;
    if(ficha2017008.mediaFinal>=5)
        ficha2017008.situacao ='A';
    else
        ficha2017008.situacao ='R';

    //Saida dos dados da ficha
    cout << "\n*************  HISTORICO ESCOLAR *************\n";    
    cout << "\nDisciplina: " <<   ficha2017008.disciplina;
    cout << "\nAluno: " <<   ficha2017008.aluno;
    cout << "\n -----  Notas Bimestrais  -----";
    printf("\nPrimeira: \t %2.1f", ficha2017008.notaBim1);
    printf("\nSegunda:  \t %2.1f", ficha2017008.notaBim2);
    printf("\nTerceira: \t %2.1f", ficha2017008.notaBim3);
    printf("\nQuarta:   \t %2.1f", ficha2017008.notaBim4);
    printf("\nMedia Final: \t %2.1f", ficha2017008.mediaFinal);
    if(ficha2017008.situacao=='A')
        cout << "\nSituacao: Aprovado";
    else
        cout << "\nSituacao: Reprovado";
    cout << "\nNumero de Faltas: " << ficha2017008.faltas;
    cout << "\nAno: " << ficha2017008.ano << "\n";

    cout << "\n\n";
    system("pause");
    return 0;
}
