// Heap sort

#include "maxheap.h"
#include <stdio.h>


// Utility function to swap two elements 
void swap (int* a, int* b){
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 


void HeapSort(int* A, size_t n){

    BinHeap maxheap = build_heap(A, n);                 // the root is the max

    for (size_t i=n-1; i>=1; i--){
        
        swap (&maxheap.H[0], &maxheap.H[i]);

        maxheap.size = maxheap.size -1;                 // remove the last leaf
        
        heapify (&maxheap, 0);                          // fix the max-heap
    
    }

}


/*

int main() { 

    int A[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    
    HeapSort(A, n);

    print_array(A, n);
  
    return 0; 
}

*/
