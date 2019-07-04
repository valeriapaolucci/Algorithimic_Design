#ifndef __RADIX_SORT__

// Radix sort

// An array A of d-digit values can be sorted digit-by-digit

// For each digit i, from the rightmost down to the leftmost,
// use a stable algorithm and sort A according the digit i


#include <stdio.h>
#include <stdlib.h>
  
// Get the maximum value in A; this is needed in order to know number of digits
int getmax (int* A, size_t n);

// Counting sort of A according to exp
void CountingSortExp (int* A, size_t n, int exp);

// For every digit, we use CountingSortExp
// Digits are represented by exp: exp is 10^i, where i is the current digit number 
void RadixSort (int* A, size_t n);

#endif //__RADIX_SORT__