// Insertion sort

// If the first fragment of the array is already sorted, we can "enlarge" it by inserting next element,
// by swapping it and the previous one in the array, until the previous one (if exists) is greater than it


#include <stdio.h>


// Utility function to swap two elements 
void swap (int* a, int* b){
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 


void InsertionSort(int* A, size_t n){

    for (size_t i=1; i<n; i++){
        
        size_t j = i;
        
        while (j>0 && A[j]<A[j-1]){
            swap(&A[j-1], &A[j]);
            j = j-1;
        }
    
    }

}


/* Another implementation

void InsertionSort(int* A, size_t n){
    
    for (size_t i=1; i<n; i++){
        
        int key = A[i];
        int j = i-1;
        
        while (j>=0 && A[j]>key){
            A[j+1]=A[j];
            j = j-1;
        }

        A[j+1] = key;

    }
    
}

*/
  


/*

int main() { 

    int A[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    
    InsertionSort(A, n); 

    print_array(A, n);
  
    return 0; 
}

*/
