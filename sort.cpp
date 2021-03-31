#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <malloc.h>
#include "sort.h"
int *mass=(int*)malloc(sizeof(int)*N);
int m = 0;
void merge(int left, int midd, int right)
{
	int* mass1 = (int*)malloc(sizeof(int)*(midd - left + 1));
	int* mass2 = (int*)malloc(sizeof(int)*(right - midd));
	int i, j;
	for (i = 0; i < midd - left + 1; i++){
		mass1[i] = mass[i + left];
	}
	for (i = 0; i < right - midd; i++){
		mass2[i] = mass[i + midd + 1];
	}
	i = j = 0;
	int k=left;
	while (i < (midd - left + 1) && j < (right - midd)) {
		if (mass1[i] <= mass2[j]){
			mass[k++] = mass1[i++];
		}
		else
			mass[k++] = mass2[j++];
	}
	while (i <(midd - left + 1)) {
		mass[k++] = mass1[i++];
	}
	while (j < (right-midd)) {
		mass[k++] = mass2[j++];
	}
	free(mass1);
	free(mass2);
}
void sort(int left, int right)
{
	int midd = left + (right - left) / 2;
	if (left < right) {
		sort(left, midd);
		sort(midd + 1, right);
		merge(left, midd, right);
	}
}