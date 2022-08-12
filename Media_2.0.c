//informa quantos alunos, recebe notas, faz a média e mostra 
//se um determinado aluno foi aprovado ou não

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Aluno
{	
	char 	nome[40];
	char	situacao[10];
	float	media;
};

int main()
{
	struct  Aluno vetorAluno[100];
	float 	nota[2];
	int 	i, qtdAlunos;
	char 	resp;
	
	printf("\n>>>>>>>>>>> Calculando a Media 2.0 <<<<<<<<<<<<\n");
	printf("\nInforme a quantidade de alunos: ");
	scanf("%i", &qtdAlunos);
	
	for(i = 0; i < qtdAlunos; i++ )
	{
		printf("\nInforme o nome do aluno %i: ", i + 1);
		scanf(" %[^\n]s", &vetorAluno[i].nome); // máscara para pegar o nome inteiro
		
		printf("A sua nota 1: ");
		scanf("%f", &nota[1]);
		
		printf("A sua nota 2: ");
		scanf("%f", &nota[2]);
		
		nota[0] = (nota[1] + nota[2]) / 2; // usa um vetor para economizar memória 
		
		vetorAluno[i].media = nota[0];
		
		if(nota[0] >= 7)
			strcpy(vetorAluno[i].situacao, "APROVADO!");
		else
			strcpy(vetorAluno[i].situacao,"REPROVADO!");
	}
	
	do
	{
		//system("cls");
		
		printf("\nInforme a posicao do registro para visualizar: ");
		scanf("%i", &qtdAlunos); //reutiliza a variável qtdAlunos que não está tendo mais uso
		
		//if para registro de aluno maior que o vetor
		printf("\nO aluno %i: %s\n", qtdAlunos, vetorAluno[qtdAlunos - 1].nome);
		printf("Com media: %.2f\n", vetorAluno[qtdAlunos - 1].media);
		printf("Foi: %s\n", vetorAluno[qtdAlunos - 1].situacao);
		
		printf("\nDeseja ver outro? [S]/[N]?: ");
		scanf("%s", &resp);
	}
	while (resp == 's' || resp == 'S');
	
	printf("\nPrograma finalizado...\n");
	
	return 0;
}
