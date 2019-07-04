// Heap sort
// Test the implementation on a set of instances of the problem and evaluate their execution times

#include "../aux_functions.h"
#include "heapsort.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()

// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp


int main() { 

    printf("\n___HEAP SORT___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array provided as example in the slides:\n\n");

    int array[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    printf("Unsorted array:\t");
    print_array(array,n);
    HeapSort(array,n);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n");

    printf("On the array provided as example in our reference book (page 137):\n\n");

    int array2[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1}; 
    int m = 10;
    printf("Unsorted array:\t");
    print_array(array2,m);
    HeapSort(array2,m);
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
        
        HeapSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

	//print_array(A,n);

        free(A);

    }

    return 0; 
} 
