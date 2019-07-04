// Select algorithm

#include "../QuickSort/quicksort.h"
#include <stdio.h>


size_t SelectPivot (int* A, size_t l, size_t r){
	
    if (r-l<5) {                                                    
		QuickSort(A,l,r);
		return (l+r)/2;
	}	

	int num_chunks = (r-l)/5 + 1;                                   // number of chunks

	for (size_t i=0; i<num_chunks; i++){                            // sorting each chunk
		
        size_t first = 5*i + l;                                     // first element of the chunk
        size_t last;                                                // last element of the chunk
        if (5*i + l + 4 > r){                                       // we are dealing with the last (incomplete) chunk
            last = r;
        }
        else last = 5*i + l + 4;                                 
        
        QuickSort(A, first, last);
        
    }

	for (size_t i=0; i<num_chunks; i++){                             // compute the median of each chunk
        
        size_t chunkmedian;
        if (5*i + l + 2 > r){                                       // we are dealing with the last (incomplete) chunk
            chunkmedian = r;
        }
        else chunkmedian = 5*i + l + 2;
        
        swap(&A[l+i], &A[chunkmedian]);                   
    }                              
		
	int median = SelectPivot (A, l, l + num_chunks);                   // recursively compute the median of the chunk medians

	return median;
}

// Another implementation of the partition is required in order to deal with possible repeated values in A:
// the previous implementation (see QuickSort.c) put all the values equal to the pivot in the S subarray, thus
// leading to an unbalanced partition; here, we want to distribute those values evenly among the two subarrays

size_t EvenPartition (int* A, int i, int j, int p){

    swap(&A[i], &A[p]);

    p = i;
    i = i+1;

    int G = 1;                              // G "subarray of greater values"

    while (i<=j){

        if(A[i]>A[p]){
            swap(&A[i], &A[j]);
            j = j-1;
        }

        else if (A[i]==A[p]){
            if (G) {
                swap(&A[i], &A[j]);
                j = j-1;
                G = 0;
            }
            else {
                i = i+1;
                G = 1;
            }
        }

        else i = i+1;

    }

    swap(&A[p], &A[j]);

    return j;

}



int Select (int* A, size_t i, size_t l, size_t r){
    
    size_t j = SelectPivot (A, l, r);
    size_t k = EvenPartition (A, l, r, j);  // size_t k = Partition (A, l, r, j);

    if (i==k){
        return A[k];
    }

    if (i<k){
        return Select(A, i, l, k-1);        // search in S
    }
    
    //else
    return Select (A, i, k+1, r);           // search in G

}




/*
int main (){ 
    int A[] = {13, 5, 7, 2, -4, 4, 1, 11, 6, 0}; 
    int n = 10;
    size_t i = 4;
    Select(A, i, 0, n-1); 
    printf("The %ld-th element in the sorted array is: %d\n", i+1, Select(A, i, 0, n-1));
    QuickSort(A, 0, n-1);
    print_array(A, n);
    
    return 0; 
}
*/


