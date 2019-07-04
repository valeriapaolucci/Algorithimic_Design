// Bucket sort
// Test the implementation on a set of instances of the problem and evaluate their execution times

#include "bucketsort.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()


void randomly_fill_array (float* array, size_t n){
	for (size_t i = 0; i < n; i++)
    	array[i] = ((float)rand()/(float)RAND_MAX);
}


// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp

//  The <time.h> header declares the structure timespec, which has at least the following members:
// time_t  tv_sec    <- seconds
// long    tv_nsec   <- nanoseconds (10)
double exec_time (const struct timespec start, const struct timespec end){
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1E9;
}


void print_array (float* A, size_t size){ 
    size_t i; 
    for (i=0; i < size; i++){
        printf("%f ", A[i]); 
    }
    printf("\n"); 
} 


int main() { 

    printf("\n___BUCKET SORT___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the array provided as example in the slides:\n\n");

    float array[] = {0.23, 0.60, 0.20, 0.73, 0.97, 0.34, 0.01, 0.50, 0.78, 0.44};
    float n = 10;
    printf("Unsorted array:\t");
    print_array(array,n);
    BucketSort(array,n);
    printf("Sorted array:\t");
    print_array(array,n);
    printf("\n");

    printf("On the array provided as example in our reference book (page 175):\n\n");

    float array2[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}; 
    float m = 10;
    printf("Unsorted array:\t");
    print_array(array2,m);
    BucketSort(array2,m);
    printf("Sorted array:\t");
    print_array(array2,m);
    printf("\n\n");


    printf("* Evaluating the execution times on a set of instances *\n\n");

    struct timespec start, end;
    double total;


    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the array: %ld\t\t", n);

        float* A = (float*)malloc(sizeof(int)*n);

        srand(time(NULL));

        randomly_fill_array(A,n);

	    //print_array(A,n);

        clock_gettime (CLOCK_REALTIME, &start);
        
        BucketSort(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

	    //print_array(A,n);

        free(A);

    }

    return 0; 
} 
