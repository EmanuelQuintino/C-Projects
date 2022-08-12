#include<stdio.h>
#include<stdlib.h>

void porValor(int v1, int v2) //recebe parâmetro por valor
{
	int aux = v1;
	v1 = v2;
	v2 = aux;
}

void porReferencia(int *v1, int *v2) //recebe parâmetro por referência
{
	int aux = *v1;
	*v1 = *v2;
	*v2 = aux;
}

int main()
{
	int num1, num2;
	
	printf("\nInforme o numero 1: ");
	scanf("%i", &num1);
	
	printf("Informe o numero 2: ");
	scanf("%d", &num2);
	
	printf("\n>>> Por Valor <<<");
	porValor(num1, num2); //envia parâmetro por valor
	printf("\nNum1: %i\n", num1);
	printf("Num2: %d", num2);
	
	printf("\n\n>>> Por Referencia <<<");
	porReferencia(&num1, &num2); //envia parâmetro por referência
	printf("\nNum1: %i\n", num1);
	printf("Num2: %d", num2);
		
	return 0;
}
