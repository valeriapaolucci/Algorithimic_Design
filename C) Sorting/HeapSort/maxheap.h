#ifndef __MAX_HEAP__

#include <limits.h>   // INT_MIN
#include <stdio.h>
#include <stdlib.h>


typedef struct BinHeap {
  int* H;
  size_t size;
} BinHeap;

size_t left (size_t i);

size_t right (size_t i);

size_t get_root ();

size_t parent (size_t i);

int is_root (size_t i);

int is_valid_node (BinHeap* h, size_t i);

// Finding the maximum
int heap_maximum (BinHeap* h);

void heap_swap (BinHeap* h, size_t v, size_t w);

// Restoring the heap property: heapify
void heapify (BinHeap* h, size_t i);

// Removing the maximum
void remove_maximum (BinHeap* h);

// Building a binary heap
BinHeap build_heap (int* A, size_t n);

// Increasing a node's key
void heap_increase_key (BinHeap* h, size_t i, int new_value);

// Inserting a new value
void heap_insert (BinHeap* h, int value);

void heap_print (BinHeap* h);


#endif //__MAX_HEAP__