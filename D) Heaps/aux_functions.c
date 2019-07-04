#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 50

void randomly_fill_array (int* array, size_t n){
    for (size_t i = 0; i < n; i++)
        array[i] = rand() % MAX_VALUE;
}


//  The <time.h> header declares the structure timespec, which has at least the following members:
// time_t  tv_sec    <- seconds
// long    tv_nsec   <- nanoseconds (10)



double exec_time (const struct timespec start, const struct timespec end){
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1E9;
}

