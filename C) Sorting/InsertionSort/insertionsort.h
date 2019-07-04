#ifndef __INSERTION_SORT__

// Insertion sort

// If the first fragment of the array is already sorted, we can "enlarge" it by inserting next element,
// by swapping it and the previous one in the array, until the previous one (if exists) is greater than it


#include <stdio.h>


void swap (int* a, int* b);

void InsertionSort(int* A, size_t n);


#endif //__INSERTION_SORT__
