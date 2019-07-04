// Quick sort

// Select one element of the array A: the pivot
// Partition A in: subarray S of the elements smaller or equal to the pivot, the pivot, subarray G of the elements greater than the pivot
// Repeat on the subarrays having more than one element

#include <stdio.h>


// Utility function to swap two elements 
void swap (int* a, int* b){
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 


size_t Partition (int* A, int i, int j, int p){

    swap(&A[i], &A[p]);

    p = i;
    i = i+1;

    while (i<=j){
        if(A[i]>A[p]){
            swap(&A[i], &A[j]);
            j = j-1;
        }
        else i = i+1;
    }

    swap(&A[p], &A[j]);

    return j;

}


void QuickSort (int* A, int l, int r){       // the leftmost element is chosen as pivot

    while (l<r){

        int p = Partition (A, l, r, l);      // p is the partitioning index
        QuickSort (A, l, p-1);
        l = p+1;                             // QuickSort (A, p+1, r);

    }

}


/* Without rewriting the last recursion call

void QuickSort (int* A, int l, int r){       // the leftmost element is chosen as pivot

    if (l<r){

        int p = Partition (A, l, r, l);      // p is the partitioning index
        QuickSort (A, l, p-1);
        QuickSort (A, p+1, r);

    }

}

*/

void QuickSort_middle (int* A, int l, int r){       // the central element is chosen as pivot

    while (l<r){

        int p = Partition (A, l, r, (l+r)/2);       // p is the partitioning index
        QuickSort (A, l, p-1);
        l = p+1;                                    // QuickSort (A, p+1, r);

    }

}

/*

int main (){ 
    int A[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10; 
    QuickSort_middle(A, 0, n-1); 
    printf("Sorted array: \n"); 
    print_array(A, n); 
    return 0; 
} 

*/
