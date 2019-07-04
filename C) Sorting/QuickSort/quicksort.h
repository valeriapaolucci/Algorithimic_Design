#ifndef __QUICK_SORT__

// Quick sort

// Select one element of the array A: the pivot
// Partition A in: subarray S of the elements smaller or equal to the pivot, the pivot, subarray G of the elements greater than the pivot
//Repeat on the subarrays having more than one element


#include <stdio.h>


// Utility function to swap two elements 
void swap (int* a, int* b);

size_t Partition (int* A, int i, int j, int p);

// Quick sort with the leftmost element chosen as pivot
void QuickSort (int* A, int l, int r);

// Quick sort with the central element chosen as pivot
void QuickSort_middle (int* A, int l, int r);


#endif //__QUICKSORT__
