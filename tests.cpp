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
	for (int i = 0; i < NUM; i++){
		pthread_join(thread[i], NULL);
	}
	merge(0, (N / 2 - 1) / 2, N / 2 - 1);
	merge(N / 2, N/2 + (N-1-N/2)/2, N - 1);
	merge(0, (N - 1)/2, N - 1);
	
}
int test(){
	print();
	for(int i=0;i<N;i++){
		if(mass[i]<=mass[i+1])
			return 1;
	else 
		return 0;
	}
}
void printb(){
	randomizem();
	printf("\n");
	pthread_t threadb;
	pthread_create(&threadb,NULL,threadfb,(void*)NULL);
	pthread_join(threadb,NULL);
}
int test2(){
	printb();
	for(int i=0;i<N;i++){
		if(mass[i]<=mass[i+1])
			return 1;
	else 
		return 0;
	}
}
int proc(){
	int count=sysconf(_SC_NPROCESSORS_ONLN);
	return count;
}
TEST(sort_in, sort_out){
	ASSERT_EQ(test(),1);
}
TEST(proc_real,proc_br){
	ASSERT_EQ(proc(),NUM);
}
TEST(bsort_in, bsort_out){
	ASSERT_EQ(test2(),1);
}
int main(int argc,char** argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
	free(mass);
}