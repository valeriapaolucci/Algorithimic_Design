// Insertion sort
// Test the implementation on a set of instances of the problem and evaluate their execution times.

#include "../aux_functions.h"
#include "insertionsort.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()


// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp.


int main() { 

    printf("\n___INSERTION SORT___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array provided as example in the slides:\n\n");

    int array[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    printf("Unsorted array:\t");
    print_array(array,n);
    InsertionSort(array,n);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n");

    printf("On the array provided as example in our reference book (page 17):\n\n");

    int array2[] = {5, 2, 4, 6, 1, 3}; 
    int m = 6;
    printf("Unsorted array:\t");
    print_array(array2,m);
    InsertionSort(array2,m);
    printf("Sorted array:\t");
    print_array(array2,m);
    printf("\n\n");


    printf("* Evaluating the execution times on a set of instances *\n\n");

    struct timespec start, end;
    double total;

    printf("\n___Average case___\n\n");


    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        srand(time(NULL));

        randomly_fill_array(A,n);

        clock_gettime (CLOCK_REALTIME, &start);
        
        InsertionSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

        free(A);

    }

    printf("\n___Worst case___\n\n");

    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        for (size_t i = 0; i < n; i++){
            A[i] = n-i;
        }     

        clock_gettime (CLOCK_REALTIME, &start);
        
        InsertionSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

        free(A);

    }

    printf("\n___Best case___\n\n");

    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        for (size_t i = 0; i < n; i++){
            A[i] = i;
        }     

        clock_gettime (CLOCK_REALTIME, &start);
        
        InsertionSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

        free(A);

    }

    return 0; 
} 
