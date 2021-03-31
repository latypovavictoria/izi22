#include <iostream>
#include <pthread.h>
#include <malloc.h>
#include "sort.h"
void* threadf(void* thread_data)
{
	int potok;
	potok= m++;
	int left = potok * (N / NUM);
	int right = (potok + 1) * (N / NUM) - 1;
	int midd = left + (right - left) / 2;
	if (left < right) {
		sort(left, midd);
		sort(midd + 1, right);
		merge(left, midd, right);
	}
	return mass;
	free(mass);
}