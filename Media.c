//Pega a quantidade de provas, recebe as notas e fala a situação
//se aprovado ou não com media, maior e menor notas.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char 	alunoNome[30];
	int 	indMenor, indMaior;
	int 	i, provasQtd;
	float 	nota[10];
	float 	notaMenor, notaMaior;
	
	nota[0]	= 0; 
	
	do
	{
		system("cls");
		
		printf(">>>>>>>>> Calculando Media <<<<<<<<<\n");
		printf("\nInforme a quantidade de provas entre 1 e 10: ");
		 scanf("%i", &provasQtd);
		
		if(provasQtd < 1 || provasQtd > 10)
		{
			printf("\nAtencao! Entre 1 e 10.\n");
			system("pause");
		}
			
	}
	
	while(1 > provasQtd || provasQtd > 10);
	
	printf("Nome do aluno: ");
	 scanf(" %[^\n]s", &alunoNome);
	
	for(i=1; i<=provasQtd; i++)
	{
		printf("Nota %i: ", i);
		 scanf("%f", &nota[i]);
		
		nota[0] += nota[i];	
	
		if(i==1)
		{
			notaMaior = nota[i];
			indMaior = i;
			
			notaMenor = nota[1];
			indMenor = i;
		}
		
		else if(nota[i] > notaMaior)
		{
			notaMaior = nota[i];
			indMaior = i;
		}
		
		else if(nota[i] < notaMenor)
		{
			notaMenor = nota[i];
			indMenor = i;
		}
	}
	
	printf("\n%s", alunoNome);
	printf("\nMenor nota: %.2f", notaMenor);
	printf("\nMaior nota: %.2f", notaMaior);
	printf("\nSua media : %.2f", nota[0] / provasQtd);
	printf("\nSituacao  : ");
	
	if(nota[0] / provasQtd >= 7)
		printf("APROVADO!");
	
	else
		printf("REPROVADO!");
	
	return(0);
}
