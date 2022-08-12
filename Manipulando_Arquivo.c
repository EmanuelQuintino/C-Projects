//1. Programa que abre um arquivo, lê algumas coisas, fecha o arquivo e escreve algo na tela.

#include<stdio.h>
//#include<stdlib.h>

int main(){
	
	FILE *arq;
	
	arq = fopen("arq.txt", "w");
	
	if(arq == NULL){
		printf("Arquivo nao encontrado.");
	}
	else{
		printf("Arquivo aberto.");
	}
	
	fwrite("testando arq.txt", sizeof(char), 16, arq);// texto ou variável; sizeof() retorna tamanho do tipo (bytes)
													  //16 tamannho do arquivo; ponteiro do arquivo (FILE *arq)	
	
	fclose(arq); //se retornar 0 fecha e salva com sucesso.
	
	return 0;
}
