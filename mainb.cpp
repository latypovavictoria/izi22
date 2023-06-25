#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <malloc.h>
#include "threadfb.h"
#include "bubblesort.h"
#include "sort.h"
int main(){
	for (int i = 0; i < N; i++){
		mass[i] = 0+rand() % N;
	}
	printf("\n");
	pthread_t threadb;
	pthread_create(&threadb,NULL,threadfb,(void*)NULL);
	pthread_join(threadb,NULL);
	printf("Однопоточная сортировка:\n");
	for(int i=0;i<N;i++){
		printf("%d ",mass[i]);
	}
	free(mass);
}