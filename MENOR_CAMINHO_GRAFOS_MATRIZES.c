#include<stdio.h>
#include<stdlib.h> //comando SYSTEM
#include<locale.h>

int qtd = 0; //tamanho do grafo que será usado em varias funções
int matriz[100][100]; //alocar dinamicamente

int Menu(){
	
	system("cls");
	
	printf("\n=========== >>> MENU CONTROLE <<< ===========\n ");
	printf("\n=====>    1: INICIALIZAR MATRIZ        <===== ");
	printf("\n=====>    2: IMPRIMIR MATRIZ           <===== ");
	printf("\n=====>    3: INSERIR VALOR NA MATRIZ   <===== ");
	printf("\n=====>    4: MENOR CAMINHO             <===== ");
	printf("\n=====>    5: SAIR DO PROGRAMA          <=====\n ");
	printf("\n=============================================\n\n ");
	
	int resp = 0;
    printf("DIGITE A OPÇÃO: "); scanf("%i", &resp);

    return(resp);
}

void resetarMatriz(){
	for (int linha = 1; linha <= qtd; linha++)
		for (int coluna = 1; coluna <= qtd; coluna++)
			matriz[linha][coluna] = 0; 
}

void imprimirMatriz(){
	
	printf("\n");
	for (int linha = 1; linha <= qtd; linha++){
		printf("%i = ", linha);
		for (int coluna = 1; coluna <= qtd; coluna++){
			printf(" %i ", matriz[linha][coluna]);
			if (coluna == qtd)
			printf("\n"); 
		}
	}
	printf("\n\n");
	system("pause");
}

void inserirValor(int val, int lin, int col){
	matriz[lin][col] = val;
	printf("\nO VALOR %i FOI GRAVADO NA MATRIZ [%i, %i]!\n\n", val, lin, col);
	system("pause");
}
int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");
	
	int resp, val, lin, col =0;
	char respSN;
	
	do {
		resp = Menu();
		
		if (resp == 1){ //inicializar Matriz na memória
			
    	printf("\nINFORME QUANTAS CIDADES: "); scanf("%i", &qtd);
    	resetarMatriz(); //limpando as arestas com valor 0
    	printf("\nMATRIZ INICIALIZADA COM %i CIDADES\n\n", qtd);
		system("pause");
		}
		else if (resp == 2){//visualizar a Matriz
			imprimirMatriz();
		}
		else if (resp == 3){//inserir valores na Matriz
			
			while (true){
				printf("\nINFORME A ARESTA (DISTÂNCIA EM KM)...: "); scanf("%i", &val);	
				if (val < 1) // Com um "&"(and) e "|"(or) apenas, se um falhar não testa o outro.
					printf("\nATENÇÃO! DISTÂNCIA TEM QUE SER MAIOR QUE 0.\n\n");
				else break;
			}	
					
			do {	//REGRAS DE NEGÓCIO: OBTENDO E TRATANDO DADOS
				
				while (true){
					printf("INFORME A LINHA DE 1 ATÉ %i....: ", qtd); scanf("%i", &lin);	
					if ((lin <=0) | (lin > qtd)) // Com um "&"(and) e "|"(or) apenas, se um falhar não testa o outro.
						printf("\nATENÇÃO! LINHA INFORMADA FORA DA MATRIZ.\n\n", qtd);
					else break;
				}
				while (true){
					printf("INFORME A COLUNA DE 1 ATÉ %i...: ", qtd); scanf("%i", &col);	
					if ((col <=0) | (col > qtd)) // Com um "&"(and) e "|"(or) apenas, se um falhar não testa o outro.
						printf("\nATENÇÃO! COLUNA INFORMADA FORA DA MATRIZ.\n\n", qtd);
					else break;
				}		
				if (lin == col)
					printf("\nATENÇÃO! LINHA E COLUNA NÃO PODEM TER VALORES IGUAIS.\n\n");
				//system("pause");
				
				if (matriz[lin][col] > 0){
				
					printf("\nMATRIZ [%i][%i] CONTEM O VALOR %i\n", lin, col, matriz[lin][col]);
				
					do { // TRABALHAR DAQUI
						printf("\nDESEJA SOBRESCREVER?: S/N"); scanf("%c", &respSN); // *repetindo duas vezes
					
					} while ((respSN != 'S' | respSN != 's') & (respSN != 'N'| respSN != 'n'));	// *loop infinito
					
					if (respSN == 'S' | respSN == 's'){
						inserirValor(val, lin, col);
						lin, col = 0;
					}						
				}else { 
					inserirValor(val, lin, col);
					lin, col = 0;
				}
			}while ((lin == col) | (lin > qtd) | (col > qtd)); // Com um "&"(and) e "|"(or) apenas, se um falhar não testa os outros. 
		}		
	} while (resp != 5 );
	
	printf("\nPROGRAMA ENCERRADO!\n");
	
    return 0;
}
