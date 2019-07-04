#ifndef __MATRIX_CHAIN__

#include <limits.h>     //INT_MAX
#include <stdio.h>


void MatrixChainAux (int* P, int** m, size_t** s, size_t i, size_t j);

void MatrixChain (size_t n, int* P, int** m, size_t** s);

void print_m (int** m, size_t n);

void print_s (size_t** s, size_t n);


#endif // __MATRIX_CHAIN__

