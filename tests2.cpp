#include "gtest/gtest.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "sort.h"
#include "thread.h"
#include "bubblesort.h"
#include "threadfb.h"
void randomizem(){
	for (int i = 0; i < N; i++){
		mass[i] = 0+rand() % N;
	}
}
void print(){
	randomizem();
	pthread_t *thread;
	thread=(pthread_t*)malloc(sizeof(pthread_t)*NUM);
	for (int i = 0; i < NUM; i++){
		pthread_create(&thread[i], NULL, threadf,(void*)NULL);
	}
	for (int i = 0; i < 4; i++){
		pthread_join(thread[i], NULL);
	}
	merge(0, (N / 2 - 1) / 2, N / 2 - 1);
	merge(N / 2, N/2 + (N-1-N/2)/2, N - 1);
	merge(0, (N - 1)/2, N - 1);
	
}
void printb(){
	randomizem();
	printf("\n");
	pthread_t threadb;
	pthread_create(&threadb,NULL,threadfb,(void*)NULL);
	pthread_join(threadb,NULL);
}
int compare(){
	randomizem();
	int i,j;
	pthread_t *thread;
	thread=(pthread_t*)malloc(sizeof(pthread_t)*NUM);
	for (i = 0; i < NUM; i++){
		pthread_create(&thread[i], NULL, threadf,(void*)NULL);
	}
	for (i = 0; i < NUM; i++){
		pthread_join(thread[i], NULL);
	}
	merge(0, (N / 2 - 1) / 2, N / 2 - 1);
	merge(N / 2, N/2 + (N-1-N/2)/2, N - 1);
	merge(0, (N - 1)/2, N - 1);
	pthread_t threadb;
	pthread_create(&threadb,NULL,threadfb,(void*)NULL);
	pthread_join(threadb,NULL);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(mass[i]==mass[j]){
				return 1;
			}
			else
				return 0;
		}
	}
}
TEST(compare_one,compare_two){
	ASSERT_EQ(compare(),1);
}
int main(int argc,char** argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
	free(mass);
}