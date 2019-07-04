// Radix sort
// Test the implementation on a set of instances of the problem and evaluate their execution times

#include "radixsort.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()

#define MAX_VALUE 250


void randomly_fill_array (int* array, size_t n){
	for (size_t i = 0; i < n; i++)
    	array[i] = rand() % (2*MAX_VALUE);
}


// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp

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
  


int main() { 

    printf("\n___RADIX SORT___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array provided as example in the slides:\n\n");

    int array[] = {3475, 2475, 3471, 1733}; 
    int n = 4;
    printf("Unsorted array:\t");
    print_array(array,n);
    RadixSort(array, n);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n");

    printf("On the array provided as example in our reference book (page 171):\n\n");

    int array2[] = {329, 457, 657, 839, 436, 720, 355}; 
    int m = 7;
    printf("Unsorted array:\t");
    print_array(array2,m);
    RadixSort(array2, m);
    printf("Sorted array:\t");
    print_array(array2,m);
    printf("\n\n");


    printf("* Evaluating the execution times on a set of instances *\n\n");

    struct timespec start, end;
    double total;


    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        srand(time(NULL));

        randomly_fill_array(A,n);

        //print_array(A,n);

        clock_gettime (CLOCK_REALTIME, &start);
        
        RadixSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        //print_array(A,n);

        printf ("Execution time: %lf\n\n", total);

        free(A);

    }

    return 0; 
} 
