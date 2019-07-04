// Counting sort

// We assume bounded domain for the array values

// Count the occurrences of A’s values and place them in C;
// Sum the values in C and get the number of elements ≤ to C’s indexes;
// Use C to place the elements of A in the correct positions in B.


#include <stdio.h>
#include <stdlib.h>     // malloc, calloc



void CountingSort (int* A, size_t n, size_t k){
    
    int* B;
    int* C;
    
    B = (int*)malloc(sizeof(int)*n);         // B is uninitialized
    C = (int*)calloc(k, sizeof(int));        // C is 0-initialized

    
    for (size_t i=0; i<n; i++){
        C[A[i]] = C[A[i]] + 1;               // C[j] is now the number of j in A
    }

    for (size_t j=1; j<k; j++){
        C[j] = C[j-1] + C[j];                // C[j] is now the number of A's values <= j
    }

    for (int i=(n-1); i>=0; i--){            // Backward placing is for stability
        B[C[A[i]]-1] = A[i];           
        C[A[i]] = C[A[i]] - 1;
    }

    for(size_t i=0; i<n; i++){
        A[i] = B[i];                         // CountingSort is not in-place
    }

    free(B);
    free(C);

}

  
/*
int main (){ 
    int A[] = {13, 5, 7, 2, 1, 4, 1, 11, 6, 1}; 
    int n = 10; 
    CountingSort(A, n, 14);                             // 14 possible values in [0,13]
    printf("Sorted array: \n"); 
    print_array(A, n); 
    return 0; 
}
*/
