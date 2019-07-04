#include <stdio.h>
#include <stdlib.h>


void swap (float* a, float *b){
	
    float tmp = *a;
	*a = *b;
	*b = tmp;

}


size_t Partition (float* A, int i, int j, int p){

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


void QuickSort (float* A, int l, int r){       // the leftmost element is chosen as pivot

    while (l<r){

        int p = Partition (A, l, r, l);        // p is the partitioning index
        QuickSort (A, l, p-1);
        l = p+1;                               // QuickSort (A, p+1, r);

    }

}