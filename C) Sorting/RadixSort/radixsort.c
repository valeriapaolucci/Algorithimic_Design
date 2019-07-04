// Radix sort

// An array A of d-digit values can be sorted digit-by-digit

// For each digit i, from the rightmost down to the leftmost,
// use a stable algorithm and sort A according the digit i



#include <stdio.h>
#include <stdlib.h>     // malloc, calloc


  
// Get the maximum value in A; this is needed in order to know number of digits
int getmax (int* A, size_t n){ 

    int max = A[0];

    for (size_t i = 1; i < n; i++){

        if (A[i] > max) 
            max = A[i];

    }        

    return max; 
} 


// Counting sort of A according to exp
void CountingSortExp (int* A, size_t n, int exp){ 
    
    int* B;
    int* C;
    
    B = (int*)malloc(sizeof(int)*n);         // B is uninitialized
    C = (int*)calloc(10, sizeof(int));       // C is 0-initialized
  

    for (size_t i=0; i<n; i++){
        C[(A[i]/exp)%10]++; 
    }
  
    for (size_t i=1; i<10; i++){
        C[i] += C[i - 1]; 
    }
  
    for (int i=(n-1); i>=0; i--){ 
        B[C[(A[i]/exp)%10]-1] = A[i]; 
        C[(A[i]/exp)%10]--; 
    }
  
    for (size_t i=0; i < n; i++){
        A[i] = B[i];
    }

    free(B);
    free(C);

} 
  



// For every digit, we use CountingSortExp
// Digits are represented by exp: exp is 10^i, where i is the current digit number 
void RadixSort (int* A, size_t n) {

    int max = getmax(A, n); 
  
    for (int exp=1; (max/exp)>0; exp*=10){

        CountingSortExp(A, n, exp); 
        
    }

} 


/*
int main (){ 
    int A[] = {3475, 2475, 3471, 1733}; 
    int n = 4; 
    RadixSort(A, n); 
    printf("Sorted array: \n"); 
    print_array(A, n); 
    return 0; 
}
*/