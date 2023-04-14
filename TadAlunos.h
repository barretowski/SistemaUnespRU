struct Dados
{
	int dia,mes,ano,alunos;
	long data;
};

void Quadro (int CI , int LI ,int CF, int LF, int cortexto , int corfundo)
{
	int i;
	textcolor(cortexto);textbackground(corfundo);
	gotoxy(CI,LI);printf ("%c",201);
	gotoxy(CF,LI);printf ("%c",187);
	gotoxy(CI,LF);printf ("%c",200);
	gotoxy(CF,LF);printf ("%c",188);
	
	for (i=CI+1;i<CF;i++)
	{
		gotoxy (i,LI);printf("%c",205);
		gotoxy (i,LF);printf("%c",205);
	}
	
	for (i=LI+1;i<LF;i++)
	{
		gotoxy (CI,i);printf("%c",186);
		gotoxy (CF,i);printf("%c",186);
	}
	for(CI=0,LI=5;CI!=CF;CI++)
	{
		gotoxy (CI,LI);printf("%c",186);
	}
	for(CI=7,LI=5;LI!=LF;LI++)
	{
		gotoxy (CI,LI);printf("%c",186);
	}
	for(CI=73,LI=5;LI!=LF;LI++)
	{
		gotoxy (CI,LI);printf("%c",186);
	}
	for(CI=0,LI=24;CI!=CF;CI++)
	{
		gotoxy (CI,LI);printf("%c",186);
		//gotoxy (CI,LI-1);printf("%c",186);
	}
	textcolor(15);textbackground(9);
	gotoxy(60,25);printf("Developer: Paulo H.");
	textbackground(0);
		textcolor(11);
	gotoxy(25,3);printf("Restaurante Universitario - UNESP");
		textcolor(15);
	char dateStr [9];
    char timeStr [9];
    _strdate(dateStr);
    gotoxy(65,22);printf("%s", dateStr);
    _strtime( timeStr );
    gotoxy(65,23);printf("%s", timeStr);
	
}
char FormularioMenu (void)
{
	textcolor(15);
	gotoxy(10,7);printf("[A] Contador de alunos");
	gotoxy(10,9);printf("[B] Registrar total de alunos");
	gotoxy(10,11);printf("[C] Consultar quantidade de alunos");
	gotoxy(10,13);printf("[D] Alterar");
	gotoxy(10,15);printf("[E] Relatorio");
	gotoxy(10,17);printf("[F] Dados");
	gotoxy(10,23);printf("[X] Ajuda");
	Quadro(1,1,80,25,9,9);
	return toupper(getch());
}
void limpatela()
{
	for(int i=8; i<73;i++)
	{
		for(int j=6;j<24;j++)
		{
			gotoxy(i,j);printf(" ");
		}
	}
	
}
//270
void contador()
{
	system("cls");	
	Quadro(1,1,80,25,9,9);
	limpatela();
	char i;
	int aux=0,cont=0;
	gotoxy(10,7);printf("Contador de alunos!");
	gotoxy(10,9);printf("[1-Acrescentar]  [2-Decrementar]  [3-Inicializar]  [4-Atribuir]");
	gotoxy(10,15);printf("%d Alunos",cont);
	scanf("\n%d",&i);	
	do
	{
		system("cls");
		Quadro(1,1,80,25,9,9);
			
			if(i==1)
				cont++;
			if(i==2)
				cont--;
				if(i==3)
				{
					gotoxy(10,9);printf("Digite a quantidade: ");
					scanf("%d",&cont);
				}
					if(i==4)
					{
						gotoxy(10,9);printf("Digite a quantidade: ");
						scanf("%d",&aux);
						cont+=aux;
					}
						if(i!=1 && i!=2 && i!=3 && i!=4)
						{
							textcolor(11);
							gotoxy(10,9);printf("\nComando invalido!");
							getch();
							textcolor(15);
						}
					
		gotoxy(10,10);printf("%d Alunos",cont);				
		scanf("\n%d",&i);
			
	}while(i!=0);
}

int busca(FILE*ptr, long dia)
{
	Dados D;
	rewind(ptr);
	
	fread(&D,sizeof(Dados),1,ptr);
	while(!feof(ptr) && D.data!=dia)
		fread(&D,sizeof(Dados),1,ptr);
	
	if(feof(ptr))
		return -1;
	else
		return ftell(ptr)-sizeof(Dados);
		
}
void registro(FILE *ptr, Dados D)
{
	ptr=fopen("Arquivo.dat","ab+");
	limpatela();
	gotoxy(20,7);printf("REGISTRO");
	gotoxy(10,9);printf("Digite o dia: ");
	fflush(stdin);
	scanf("%d",&D.dia);
	if(D.dia>0 && D.dia<32)
	{
		gotoxy(10,10);printf("Digite o mes: ");
		fflush(stdin);
		scanf("%d",&D.mes);
		if(D.mes>0 && D.mes<13)
		{
			gotoxy(10,11);printf("Digite o ano: ");
			fflush(stdin);
			scanf("%d",&D.ano);
			if(D.ano>2018)
			{
				gotoxy(9,13);printf("Digite a quantidade de alunos referente a data: ");
				scanf("%d",&D.alunos);
				D.data=D.dia*100;
				D.data+=D.mes;
				D.data*=10000;
				D.data+=D.ano;
				int b=busca(ptr,D.data);
				if(b==-1)
				{
						fwrite(&D,sizeof(Dados),1,ptr);
					textcolor(10);
					gotoxy(9,22);printf("Registro do dia %d/%d/%d com %d alunos realizado com sucesso!",D.dia,D.mes,D.ano,D.alunos);
				}
				else
				{
						textcolor(12);
						gotoxy(9,22);printf("Data ja registrada!");
				}
			}
			else
			{
				textcolor(12);
				gotoxy(9,22);printf("Ano invalido!");	
			}
			
		}
		else
		{
			textcolor(12);
			gotoxy(9,22);printf("Mes invalido!");
		}
	}
	else
	{
		textcolor(12);
		gotoxy(9,22);printf("Dia invalido!");
	}
	
	textcolor(15);
	getch();
	fclose(ptr);
}

void consultar(Dados D, FILE*ptr)
{
	ptr=fopen("Arquivo.dat","rb");
	int dia,mes,ano;
	long dat,res;
	limpatela();
	gotoxy(20,7);printf("Consultar");
	gotoxy(10,9);printf("Digite a data: ");
	fflush(stdin);
	scanf("%ld",&dat);
	
	res=busca(ptr,dat);
	
	if(res==-1)
	{
		textcolor(12);
		gotoxy(9,22);printf("Data nao encontrada!");
	}	
	else
	{
		limpatela();
		fseek(ptr,res,0);
		fread(&D,sizeof(Dados),1,ptr);;
		gotoxy(10,9);printf("Dia: %d/%d/%d",D.dia,D.mes,D.ano);
		gotoxy(10,10);printf("Total de alunos: %d",D.alunos);
	}
	textcolor(15);
	getch();
	fclose(ptr);
}
void alterar(FILE *ptr, Dados D)
{
	ptr=fopen("Arquivo.dat","rb+");
	int dia,mes,ano;
	long dat,res;
	limpatela();
	gotoxy(20,7);printf("Alterar");
	gotoxy(10,9);printf("Digite a data: ");
	fflush(stdin);
	scanf("%ld",&dat);
	
	res=busca(ptr,dat);
	
	if(res==-1)
	{
		textcolor(12);
		gotoxy(9,22);printf("Data nao encontrada!");
	}	
	else
	{
		limpatela();
		gotoxy(10,9);printf("Digite o dia: ");
		fflush(stdin);
		scanf("%d",&D.dia);
		if(D.dia>0 && D.dia<32)
		{
			gotoxy(10,10);printf("Digite o mes: ");
			fflush(stdin);
			scanf("%d",&D.mes);
			if(D.mes>0 && D.mes<13)
			{
				gotoxy(10,11);printf("Digite o ano: ");
				fflush(stdin);
				scanf("%d",&D.ano);
				if(D.ano>2018)
				{
					gotoxy(9,13);printf("Digite a quantidade de alunos referente a data: ");
					scanf("%d",&D.alunos);
					D.data=D.dia*100;
					D.data+=D.mes;
					D.data*=10000;
					D.data+=D.ano;
					fseek(ptr,res,0);
					fwrite(&D,sizeof(Dados),1,ptr);
					textcolor(10);
					gotoxy(9,22);printf("Registro do dia %d/%d/%d com %d alunos realizado com sucesso!",D.dia,D.mes,D.ano,D.alunos);
				}
				else
				{
					textcolor(12);
					gotoxy(9,22);printf("Ano invalido!");	
				}
				
			}
			else
			{
				textcolor(12);
				gotoxy(9,22);printf("Mes invalido!");
			}
		}
		else
		{	
			textcolor(12);
			gotoxy(9,22);printf("Dia invalido!");
		}		
	}
	textcolor(15);
	getch();
	fclose(ptr);
	
}
void relatorio(FILE*ptr, Dados D, int &media, int &total,int &cont, int &mes)
{
	cont=0,media=0,total=0;
	textcolor(10);
	ptr=fopen("Arquivo.dat","rb");
	rewind(ptr);
	system("cls");
	gotoxy(20,1);printf("Relatorio\n\n");
	printf("\nDigite o mes: ");
	scanf("%d",&mes);
	fread(&D,sizeof(Dados),1,ptr);
	printf("\n----------------------------------------");
	while(!feof(ptr))
	{
		if(D.mes==mes)
		{
			cont++;
			total+=D.alunos;
			printf("\n\tDia: %d/%d/%d",D.dia,D.mes,D.ano);
			printf("\n\tAlunos: %d",D.alunos);
			printf("\n\n----------------------------------------");
		}
		fread(&D,sizeof(Dados),1,ptr);
	}
	if(cont==0)
	printf("\nNenhum registro referente ao mes %d",mes);
	media=total/cont;
	getch();
	fclose(ptr);
}
void dados(int media, int total,int cont, int mes)
{
	system("cls");
	char aux[15];
	if(mes==1)strcpy(aux,"Janeiro");
	if(mes==2)strcpy(aux,"Fevereiro");
	if(mes==3)strcpy(aux,"Marco");
	if(mes==4)strcpy(aux,"Abril");
	if(mes==5)strcpy(aux,"Maio");
	if(mes==6)strcpy(aux,"Junho");
	if(mes==7)strcpy(aux,"Julho");
	if(mes==8)strcpy(aux,"Agosto");
	if(mes==9)strcpy(aux,"Setembro");
	if(mes==10)strcpy(aux,"Outubro");
	if(mes==11)strcpy(aux,"Novembro");
	if(mes==12)strcpy(aux,"Dezembro");
	strupr(aux);
	Quadro(1,1,80,25,9,9);
	textcolor(10);
	gotoxy(20,7);printf("DADOS REFERENTES AO MES DE %s",aux);
		textcolor(15);
	gotoxy(10,9);printf("Dias computados: %d",cont);
	gotoxy(10,11);printf("Media de alunos por dia: %d",media);
	gotoxy(10,13);printf("Total de pratos servidos: %d",total);
	getch();
}
void ajuda()
{
	limpatela();
	gotoxy(20,7);printf("Ajuda");
	getch();
}
