//4. Programa que verifica o tamanho de uma string, concatena uma string e executa um
//comando de sistema (terminal).

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str1[] = "Como programador se cumprimenta? ";
	char str2[] = "E ai, tudo compilando?";
	
	printf("str1 tem %i caracteres.", strlen(str1));
	printf("\nstr2 tem %i caracteres.", strlen(str2));
	
	printf("\n\n%s\n\n", strcat(str1, str2));
	
	system("pause");
	
	return 0;
}
