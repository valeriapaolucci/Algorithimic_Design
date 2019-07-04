#ifndef __AUXFUNC__
#define __AUXFUNC__


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 250


void randomly_fill_array(int* array, size_t n);


//  The <time.h> header declares the structure timespec, which has at least the following members:
// time_t  tv_sec    <- seconds
// long    tv_nsec   <- nanoseconds (10)
double exec_time (const struct timespec start, const struct timespec end);

void print_array (int* A, size_t size);


#endif //__AUXFUNC__
