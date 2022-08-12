#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    int qtd = 0;
    printf("INFORME QUANTAS CIDADES: "); scanf("%i", &qtd);

    printf("VOCÊ DIGITOU %i cidades", qtd);


    return 0;
}