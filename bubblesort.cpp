#include <iostream>
#include <malloc.h>
#include "sort.h"
void bubblesort(){
  for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                int temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}