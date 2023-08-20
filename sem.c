
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

int *prod_rate,* cons_rate;
int prod_rate_size,cons_rate_size;
void *producer(void * arg);
void *consumer(void * arg);
sem_t empty,full,mutex;
int buffer_fill;
int main()
{
	int buffer;
	srand(time(0));
	printf("enter the buffer size: ");
	scanf("%d",&buffer);
	sem_init(&empty,1,buffer);
	sem_init(&full,1,0);
	sem_init(&mutex,1,1);
	printf("enter the number of production sessions: ");
	scanf("%d",&prod_rate_size);
	printf("enter rates: ");
	prod_rate=malloc(prod_rate_size*sizeof(int));
	for(int i=0;i<prod_rate_size;i++)
	{
		scanf("%d",&prod_rate[i]);
	}
	printf("enter the number of consumption sessions: ");
	scanf("%d",&cons_rate_size);
	cons_rate=malloc(cons_rate_size*sizeof(int));
	printf("enter the rates: ");
	for(int i=0;i<cons_rate_size;i++)
	{
		scanf("%d",&cons_rate[i]);
	}
	pthread_t prod_thread,cons_thread;
	pthread_create(&prod_thread,NULL,producer,NULL);
	pthread_create(&cons_thread,NULL,consumer,NULL);
	pthread_join(prod_thread,NULL);
	pthread_join(cons_thread,NULL);
	printf("completed\n");
	sem_destroy(&full);
	sem_destroy(&empty);
	sem_destroy(&mutex);
	free(prod_rate);
	free(cons_rate);
	return(0);
}

void * producer(void * arg)
{
	for(int i=0;i<prod_rate_size;i++)
	{
		for(int j=0;j<prod_rate[i];j++)
		
			sem_wait(&empty);
			sem_wait(&mutex);
			buffer_fill+=prod_rate[i];
			printf("produced %d total space filled :%d \n",prod_rate[i],buffer_fill);
			sem_post(&mutex);
			for(int j=0;j<prod_rate[i];j++)
			{
				sem_post(&full);
			}
			usleep(1000*(rand()%1000));
		
	}
}

void * consumer(void * arg)
{
	for(int i=0;i<cons_rate_size;i++)
	{
		for(int j=0;j<cons_rate[i];j++)
		
			sem_wait(&full);
			sem_wait(&mutex);
			buffer_fill-=cons_rate[i];
			printf("consumer %d total space filled :%d \n",cons_rate[i],buffer_fill);
			sem_post(&mutex);
			for(int j=0;j<cons_rate[i];j++)
			{
				sem_post(&empty);
			}
			usleep(1000*(rand()%1000));
		
	}
}

