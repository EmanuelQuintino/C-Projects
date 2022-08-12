//3. Programa que aloca uma certa memória, gera números aleatórios e ordena uma lista.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void *x,const void *y) //conversao para const void
{
	if(*(int*)x == *(int*)y) // "casting" convertendo tipo
		return 0;
	
	else
		if(*(int*)x > *(int*)y)
			return 1;
		else
			return -1;
}

int main()
{	
	int i, *vet, qtd;

	printf("Insira a quantidade de elementos no vetor: ");
	scanf("%i", &qtd);
	
	vet = (int*) malloc(qtd * sizeof(int)); //retorna um ponteiro void; converter usando "casting" (int*).
	
	if(vet == NULL)
	{
		printf("\nNao alocado!\n\n");
		exit(1);
	}
	else
		printf("\nAlocado com sucesso!\n\n");
	
	srand(time(NULL)); //recebe total de segundos desde 1 janeiro 1970. 
	
	for(i=0; i<qtd; i++)
	{
		vet[i] = rand() % 100; // Usa "semente" 1 como padrão e precisa da srand(time(NULL)) para mudar.
		printf("Numero %i: %i\n", i + 1, vet[i]);
	}

	qsort(vet, qtd, sizeof(int), compare); //Usa vetor, qtd elementos, tamanho do tipo, função de comparação.
	
	printf("\n");
	
	for(i=0; i<qtd; i++)
		printf("Numero %i: %i\n", i + 1, vet[i]);
		
	//printf("\n%i\n", sizeof(i));
	//printf("%i\n", sizeof(vet));
	//printf("%i", qtd);
	
	free(vet);
	
	return 0;
}
