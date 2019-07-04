#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 250


void randomly_fill_array (int* array, size_t n){
	for (size_t i = 0; i < n; i++)
    	array[i] = rand() % (2*MAX_VALUE)-MAX_VALUE;
}

//  The <time.h> header declares the structure timespec, which has at least the following members:
// time_t  tv_sec    <- seconds
// long    tv_nsec   <- nanoseconds (10)

double exec_time (const struct timespec start, const struct timespec end){
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1E9;
}


void print_array (int* A, size_t size){ 
    
    size_t i; 
    
    for (i=0; i < size; i++){

        printf("%d ", A[i]); 

    }
        
    printf("\n"); 
} 
  
