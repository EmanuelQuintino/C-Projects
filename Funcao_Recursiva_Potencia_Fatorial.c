//Potência e fatorial com recursividade

#include<stdio.h>
#include<stdlib.h>

int potencia(int b, int e)
{
	if(e == 1)
		return b;
	else
		return(b * potencia(b, (e - 1)));//recursivo chama a se proprio em escalada	
}

float fatorial(float x)
{	
	if(x==1)
		return x;
	else
		return x *= fatorial(x - 1);
}
		

int main()
{
	int base, exp, i;
	double result = 1;
	
	printf("Numero: ");
	scanf("%i", &base);
	
	printf("exponencial: ");
	scanf("%i", &exp);
	
	for(i=exp; i>=1; i--) //iterativo
	{
		result *= base; 
	}
	
	printf("\nA potenciacao ITERATIVA de %i elevado a %i foi de: %.0f", base, exp, result); //iterativo
	printf("\nA potenciacao RECURSIVA de %i elevado a %i foi de: %i", base, exp, potencia(base, exp)); // recursivo	
	printf("\nO fatorial RECURSIVO de %i eh: %.0f", base, fatorial(base)); // recursivo	
	
	return 0;
}
