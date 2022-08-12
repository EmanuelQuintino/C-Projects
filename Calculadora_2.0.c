#include <stdio.h>
#include <stdlib.h>

int main()
{
	char opc;
	float vet[2];
	
 	vet[0] = vet[1] = vet[2] = 0;
	 
	//vet[0] = resultado da operação
	//vet[1] = número 1
	//vet[2] = número 2
	
	do
	{		
		system("cls");
		
		printf("\n>>>>>>>>>>  CALCULADORA 2.0  <<<<<<<<<<\n");
	
		printf("\n(1)SOMAR\n(2)SUBTRAIR\n(3)MULTIPLICAR\n(4)DIVIDIR\n(0)SAIR\n\n");
		
		printf("Digite a opcao: ");
		
		//opc = getchar();
		scanf("%c", &opc);	
		
		if(opc >= '1' && opc <= '4')
		{
			printf("\nNumero 1: ");
			scanf("%f", &vet[1]);
			
			printf("Numero 2: ");
			scanf("%f", &vet[2]);
			
			if(opc == '1')
			{
				printf("\nA soma de %0.2f e %0.2f = %0.2f\n\n", vet[1], vet[2], vet[1] + vet[2]);
				system("pause");
			}	
			else if(opc == '2')
			{
				printf("\nA subtracao de %0.2f e %0.2f = %0.2f\n\n", vet[1], vet[2], vet[1] - vet[2]);
				system("pause");
			}
			else if(opc == '3')
			{
				printf("\nA multiplicacao de %0.2f e %0.2f = %0.2f\n\n", vet[1], vet[2], vet[1] * vet[2]);
				system("pause");
			}
			else if(opc == '4')
			{
				printf("\nA divisao de %0.2f e %0.2f = %0.2f\n\n", vet[1], vet[2], vet[1] / vet[2]);
				system("pause");
			}
		}
		else	
		{
			printf("\nDigite um comando valido entre 0 e 4...\n\n");
			system("pause");
		}
	
	}
	while(opc != '0');
	
	printf("\nPrograma finalizado...\n");
		
	return 0;	
}
