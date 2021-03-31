#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <malloc.h>
#include "thread.h"
#include "sort.h"
int main()
{
	for (int i = 0; i < N; i++){
		mass[i] = 0+rand() % N;
	}
	pthread_t *thread;
	thread=(pthread_t*)malloc(sizeof(pthread_t)*NUM);
	for (int i = 0; i < NUM; i++){
		pthread_create(&thread[i], NULL, threadf,(void*)NULL);
	}
	for (int i = 0; i < NUM; i++){
		pthread_join(thread[i], NULL);
	}
	merge(0, (N / 2 - 1) / 2, N / 2 - 1);
	merge(N / 2, N/2 + (N-1-N/2)/2, N - 1);
	merge(0, (N - 1)/2, N - 1);
	printf("Многопоточная сортировка:\n");
	for (int i = 0; i < N; i++){
		printf("%d ",mass[i]);
	}
	free(thread);
	free(mass);
}