// Bucket sort

// We assume uniform distribution of the array values; in particular, in [0,1)

// Split [0,1) in n buckets;
// Add each value of A to the correct bucket;
// Sort the buckets;
// Reverse the content of buckets in bucket order on A.

#include "quicksort_float.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    float data;
    struct Node* next;
} Node;


typedef struct Bucket{
    size_t size;
    Node* head;
} Bucket;


Node* get_node (Bucket* bucket, size_t k){

    Node* node = bucket->head;
	
    for (size_t i=0; i<k; i++)
        node = node->next;

    return node;

}


void append (Bucket* bucket, float value){

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (bucket->size==0){
        bucket->head = new_node;
    }

    else {
        Node* last = get_node (bucket, bucket->size-1);
        last->next = new_node;
    }

    bucket->size = bucket->size+1;

}


void BucketSort(float* A, size_t n){

	Bucket* B = (Bucket*)malloc(sizeof(Bucket)*n);     // Allocate an array B of empty lists (buckets)
  	for (size_t i=0; i<n; i++){
    	B[i].size = 0;
    	B[i].head = NULL;
 	}
        

  	for (size_t i=0; i<n; i++){                        // now B contains the buckets
		append(&B[(int)(A[i]*n)], A[i]);
    }


  	size_t i = 0;

    for (size_t j=0; j<n; j++){

        for (int v=(B[j].size-1); v>=0; v--){       // for v in B[j]
              
			Node* getnode = get_node(&B[j],v);
			A[i] = getnode->data;                     // reverse the bucket in A
			i = i+1;

        }

        QuickSort(A, i-B[j].size, i-1);             // sort the bucket
      
    }

  	free(B);

}


/*
int main(){
  
  	size_t n = 10;
	float A[10] = {0.23, 0.60, 0.20, 0.73, 0.97, 0.34, 0.01, 0.50, 0.78, 0.44};
	
	print_array(A,n);
	BucketSort(A,n);
	print_array(A,n);
	printf("\n");
    
}
*/