// Select algorithm
// Test the implementation on a set of instances of the problem and evaluate their execution times

#include "../aux_functions.h"
#include "../QuickSort/quicksort.h"
#include "select.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()


// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp


int main() { 

    printf("\n___SELECT ALGORITHM___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array <13, 5, 7, 2, -4, 4, 1, 11, 6, 0>:\n\n");

    int array[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    printf("Unsorted array:\t");
    print_array(array,n);
    printf("\n");
    size_t i = 4;
    printf("The element #%ld in the sorted array is: %d\n\n", i+1, Select(array, i, 0, n-1));
    printf("Let's check...\n\n");
    QuickSort(array, 0, n-1);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n\n");

    printf("On the array <2, 8, 7, 1, 3, 5, 6, 4>:\n\n");

    int array2[] = {2, 8, 7, 1, 3, 5, 6, 4}; 
    int m = 8;
    printf("Unsorted array:\t");
    print_array(array2,m);
    printf("\n");
    size_t j = 7;
    printf("The element #%ld in the sorted array is: %d\n\n", j+1, Select(array2, j, 0, m-1));
    printf("Let's check...\n\n");
    QuickSort(array2, 0, m-1);
    printf("Sorted array:\t");
    print_array(array2,m);
    printf("\n\n");


    printf("* Evaluating the execution times on a set of instances *\n\n");

    struct timespec start, end;
    double total;


    for (size_t n=pow(2,3); n<=pow(2,8); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        srand(time(NULL));

        randomly_fill_array(A,n);

        clock_gettime (CLOCK_REALTIME, &start);

        size_t i = n/2+2;
        
        Select(A, i, 0, n-1);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n", total);

        printf("The element #%ld in the sorted array is: %d\n", i+1, Select(A, i, 0, n-1));

	printf("Let's check...\n");
 
        QuickSort(A, 0, n-1);
   
        print_array(A, n);

	printf("\n");

        free(A);    

    }

    return 0; 
} 
