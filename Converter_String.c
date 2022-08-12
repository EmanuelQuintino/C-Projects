#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x = 5;
	char y[] = "2";
	
	printf("%i\n", x);
	printf("%s\n", y);
	
	float z = atoi(y);
	printf("%f", z);
	
	//char k = atoi(x);
	//printf("%c", k);
	
	return 0;
}
