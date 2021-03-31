#include <iostream>
#include <pthread.h>
#include "bubblesort.h"
#include "sort.cpp"
void* threadfb(void* thread_data)
{
	bubblesort();
	return mass;
	free(mass);
}