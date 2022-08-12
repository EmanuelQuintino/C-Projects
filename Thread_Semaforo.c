//2. Programa que cria um thread e usa algum semáforo.

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define QTD 4 //Quantidade de Threads

sem_t semaforo;

void *executar(void *args)
{
	for(int i = 0; i < 5; i++)
	{
		sem_wait(&semaforo);
		
		printf("Executando Thread %i\n", args);	//zona crítica
		sleep(1);
		
		sem_post(&semaforo);
	}
}  

int main()
{
	sem_init(&semaforo, 0 ,1);
	
	pthread_t t[QTD];
	
	for(int i=1; i<=QTD; i++)
	{
		pthread_create(&t[i], NULL, executar, (void*)i); //se return != 0 falha em criar Thread		
	}

	for(int i=1; i<=QTD; i++ )
	{
		pthread_join(t[i], NULL); //se return != 0 falha no Join
	}
	
	sem_destroy(&semaforo);
	
	return 0;
}
