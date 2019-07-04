#ifndef __QUICKSORT_FLOAT__
#define __QUICKSORT_FLOAT__

#include <stdio.h>

void swap (float* a, float* b);

size_t Partition (float* A, int i, int j, int p);

void QuickSort (float* A, int l, int r);


#endif //__QUICKSORT_FLOAT__
