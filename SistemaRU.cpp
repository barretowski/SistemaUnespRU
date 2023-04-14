
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio2.h>
#include<time.h>
#include<string.h>
#include "TadAlunos.h"

/*char menu()
{
	system("cls");	
	printf("\n[A] Contador de alunos");
	printf("\n[B] Registrar total de alunos");
	printf("\n[C] Consultar quantidade de alunos");
	printf("\n[D] Relatorio");
	return toupper(getch());
	279

}*/
int main()
{
	FILE *ptr;
	int media=0, total=0,cont=0, mes;
	Dados D;
	char op;
	do
	{
		system("cls");
		op=FormularioMenu();
		switch(op)
		{
			case 'A':
				contador();
				break;
			case 'B':
				registro(ptr,D);
				break;
			case 'C':
				consultar(D,ptr);
				break;
			case 'D':
				alterar(ptr,D);
				break;
			case 'E':
				relatorio(ptr,D,media,total,cont, mes);
				break;	
			case 'F': 
				dados(media,total,cont,mes);
				break;
			case 'X': 
				ajuda();
				break;
		}
	}while(op);
}  
