// Counting sort
// Test the implementation on a set of instances of the problem and evaluate their execution times

#include "countingsort.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()


void randomly_fill_array (int* array, size_t n){
	for (size_t i = 0; i < n; i++)
    	array[i] = rand() % 25;
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

    printf("\n___COUNTING SORT___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array provided as example in the slides:\n\n");

    int array[] = {13, 5, 7, 2, 1, 4, 1, 11, 6, 1}; 
    int n = 10;
    printf("Unsorted array:\t");
    print_array(array,n);
    CountingSort(array,n,14);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n");

    printf("On the array provided as example in our reference book (page 169):\n\n");

    int array2[] = {2, 5, 3, 0, 2, 3, 0, 3}; 
    int m = 8;
    printf("Unsorted array:\t");
    print_array(array2,m);
    CountingSort(array2,m,6);
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
        
        CountingSort(A, n, 25);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

	//print_array(A,n);

        free(A);

    }

    return 0; 
} 
