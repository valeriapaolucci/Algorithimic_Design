// Heaps
// Test the implementation on a set of instances of the problem and evaluate the execution time

#include "aux_functions.h"
#include "minheap.h"
#include <math.h>       // pow()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // timespec, clock_gettime()


// The <time.h> header contains the clock_gettime() function: int clock_gettime (clockid_t clock_id, struct timespec *tp)
// It gets the current time of the clock specified by clock_id (e.g. realtime), and puts it into the buffer pointed to by tp.


int main() { 

    printf("\n___HEAPS___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the Min-heap provided as example in the slides:\n\n");

    size_t n = 6;
	int array[] = {1, 2, 4, 7, 6, 5};

    printf("Let's build the heap...\n\n");
   
    BinHeap heap1 = build_heap (array, n);

    heap_print(&heap1);

    printf("Let's decrease the key 6 to 0...\n\n");

    heap_decrease_key(&heap1, 4, 0);

    heap_print(&heap1);

    printf("Let's insert a new value (3)...\n\n");

    heap_insert(&heap1, 3);

    heap_print(&heap1);

    printf("Let's remove the minimum...\n\n");
  
    remove_minimum(&heap1);
  
    heap_print(&heap1);

    printf("\n");
    

    printf("With the values <28, 22, 0, 102, 68, 70, 93, 66, 109>:\n\n");

    size_t m = 9;
	int array2[] = {28, 22, 0, 102, 68, 70, 93, 66, 109};

    printf("Let's build the heap...\n\n");
   
    BinHeap heap2 = build_heap (array2, m);

    heap_print(&heap2);

    printf("Let's remove the minimum...\n\n");
  
    remove_minimum(&heap2);
  
    heap_print(&heap2);

    printf("Let's try to decrease the key 70 to 80...\n\n");

    heap_decrease_key(&heap2, 5, 80);

    heap_print(&heap2);

    printf("Let's insert a new value (40)...\n\n");

    heap_insert(&heap2, 40);

    heap_print(&heap2);

    printf("\n");

    printf("* Evaluating the execution time on a set of instances (build_heap) *\n\n");

    struct timespec start, end;
    double total;


    for (size_t n=pow(2,8); n<=pow(2,16); n*=2){

        printf ("Size of the heap: %ld\t\t", n);

        int* A = (int*)malloc(sizeof(int)*n);

        srand(time(NULL));

        randomly_fill_array(A,n);

        clock_gettime (CLOCK_REALTIME, &start);
        
        BinHeap myheap = build_heap(A, n);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

        // heap_print(&myheap);

        free(A);

    }

    return 0; 
} 
