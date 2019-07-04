// MAX HEAP

#include <limits.h>   // INT_MIN
#include <stdio.h>
#include <stdlib.h>


typedef struct BinHeap {
  int* H;
  size_t size;
} BinHeap;

size_t left (size_t i){
  return 2*(i+1)-1;
}

size_t right (size_t i){
  return 2*(i+1);
}

size_t get_root (){
  return 0;
}

size_t parent (size_t i){
  return (i-1)/2;
}

int is_root (size_t i){
  return i == 0;
}

int is_valid_node (BinHeap* h, size_t i){
  return h->size > i;
}


// Finding the maximum
int heap_maximum (BinHeap* h){
  return h->H[0];
}


void heap_swap (BinHeap* h, size_t v, size_t w){
  size_t tmp = h->H[v];
  h->H[v] = h->H[w];
  h->H[w] = tmp;
}


// Restoring the heap property: heapify
void heapify (BinHeap* h, size_t i){

  size_t m = i, comp = m;
  int condition = 1;

  while (condition) {
	
	size_t l = left(m);
	size_t r = right(m);
	size_t arr[2] = {l, r};

	for (size_t j = 0; j <= 1; j++){
	  if (is_valid_node(h, arr[j]) && h->H[arr[j]] >= h->H[m]){
		m = arr[j];
	  }
	}
	
	if (comp != m){
	  heap_swap(h, comp, m);
	  comp = m;
	}
	else condition = 0;
  }
}


// Removing the maximum
void remove_maximum (BinHeap* h){
  h->H[get_root()] = h->H[h->size-1];
  h->size = h->size-1;
  heapify (h, get_root());
}


// Building a binary heap
BinHeap build_heap (int* A, size_t n){

  	BinHeap h;
	h.H = A;
	h.size = n;

	for (int i = parent(h.size-1); i>=0; i--){            // restoring heap property
		heapify (&h, i);
	}
	
	return h;

}


// Increasing a node's key
void heap_increase_key (BinHeap* h, size_t i, int new_value){
  
  if (h->H[i] >= new_value){
	printf("%d is not greater than %d\n\n", new_value, h->H[i]);
  }
  
  h->H[i] = new_value;     // else
  
  while (!(is_root(i) || h->H[parent(i)] >= h->H[i])){
	heap_swap(h, i, parent(i));
	i = parent(i);
  }

}


// Inserting a new value
void heap_insert (BinHeap* h, int value){
  h->size = h->size + 1;
  h->H[h->size-1] = INT_MIN;
  heap_increase_key(h, (h->size-1), value);
}


void heap_print (BinHeap* h){

	printf("Binary heap (array-based representation):\n");

  	for (size_t i = 0; i < h->size; i++) {
		printf("%d\t", h->H[i]);
  	}

  	printf("\n\n");

}


/*

int main(){

  int A[6] = {7,6,5,4,2,1};
   
  BinHeap myheap = build_heap (A, 6);

  heap_print(&myheap);
  
  remove_maximum(&myheap);
  
  heap_print(&myheap);

  heap_increase_key(&myheap, 3, 1);

  heap_print(&myheap);

  heap_increase_key(&myheap, 3, 14);

  heap_print(&myheap);

  heap_insert(&myheap, 3);

  heap_print(&myheap);

  return 0;
}

*/
