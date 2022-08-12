//Funcionamento do CAIXA de Supermercado 
//N clientes receberá a quantidade e o preço dos produtos com total da compra, valor pago e o troco.
//Mostrar faturamento, quantidade de clientes e o gasto médio por cliente.

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	int qtd_client, qtd_prod, i =0;
	float *faturamento, preco, total_compra, pagamento =0;
	char resp;
	
	faturamento = (float*) malloc(qtd_client * sizeof(int)); //retorna um ponteiro void; converter usando "casting" (float*).
	
	if(faturamento == NULL)
	{
		printf("\nNao alocado!\n\n");
		exit(1);
	}
	else
		printf("\nAlocado com sucesso!\n\n");
	
	system("pause");
	system("cls");
	printf(">>>>>>>>>>>> CAIXA SUPERMERCADO <<<<<<<<<<<<<<\n\n");
	printf("==============================\n");
	printf("ADICIONAR CLIENTE? S/N: ");
	scanf("%c", &resp);
	
	while (true)
	{
		if (resp == 'S' || resp == 's')
		{		
			printf("==============================\n\n");
			printf("QUANTOS PRODUTOS?: ");
			scanf("%i", &qtd_prod);
			printf("\n");
			
			total_compra = 0;
			for (i=1; i<=qtd_prod; i++)
			{
				printf("O preco do %i produto: ", i);
				scanf("%f", &preco);
				total_compra += preco;			
			}
		
			printf("\nO total da compra dos %i produtos foi: %.2f R$",qtd_prod, total_compra);
			printf("\nTroco para quanto?: "); scanf("%f", &pagamento);
			printf("\nO troco para %.2f R$ foi de: %.2f R$\n\n", pagamento, pagamento - total_compra);
			
			qtd_client++;
			faturamento[qtd_client] = total_compra;
			faturamento[0] += total_compra; 
			
			system("pause");
			system("cls");
			printf(">>>>>>>>>>>> CAIXA SUPERMERCADO <<<<<<<<<<<<<<\n\n");
			printf("==============================\n");
			printf("ADICIONAR NOVO CLIENTE? S/N: ");
			fflush(stdin);
			scanf("%c", &resp);
		}
		else if (resp == 'N' || resp == 'n')
			break;
	
		else
		{
			printf("\n\nDigite um comando válido!\n\n");
			system("pause");
			
			system("cls");
			printf(">>>>>>>>>>>> CAIXA SUPERMERCADO <<<<<<<<<<<<<<\n\n");
			printf("==============================\n");
			fflush(stdin);
			printf("ADICIONAR NOVO CLIENTE? S/N: "); scanf("%c", &resp);
		}
	}
	 
	printf("\nCaixa encerrado!\n");
	printf("\nO Faturamento de: %.2f R$", faturamento[0]);
	printf("\nA quantidade de clientes de: %i", qtd_client);
	printf("\nCom gasto média de: %.2f R$ / por cliente\n\n", faturamento[0] / qtd_client);
	
	do
	{
		system("pause");
		system("cls");	
		printf(">>>>>>>>>>>> CAIXA SUPERMERCADO <<<<<<<<<<<<<<\n\n");
		printf("==============================\n");
		
		fflush(stdin);
		printf("\nDeseja ver a compra de algum cliente? S/N: ");
		scanf("%c", &resp);	
	
		if (resp == 'S' || resp == 's')
		{
			printf("\nQual número?: ");
			scanf("%i", &i); //variável i está em desuso
			
			printf("\nO cliente %i comprou %.2f R$\n\n", i, faturamento[i]);	
		}
	}
	while(resp == 'S' || resp == 's');
	
	system("cls");	
	
	free(faturamento);
	
	printf("\nPrograma encerrado!\n");
	
	return 0;
}
