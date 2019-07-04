#ifndef __DIJHEAP__
#define __DIJHEAP__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int label;
  int d;
  struct Node *pred;
} Node;


typedef struct Graph {
  Node* V;
  int size;
  int** adj_matrix;       // Adjacency matrix representation
} Graph;


typedef struct BinHeap {    // heap-based representation of the queue
  Node** H;                         
  size_t size;
} BinHeap;


int is_empty(BinHeap *h);

void heapify (BinHeap* h, size_t i);

BinHeap build_Queue(Graph* graph);

void update_distance(BinHeap *h, Node *v, int w);

Node* extract_min(BinHeap *h);


int get_weight(Graph* g, Node* from, Node* to);

Node* set_source(Graph* g, int id);

int num_adj_nodes(Graph* g, Node* u);

Node** adj_nodes(Graph* g, Node* u);

void Init_sssp(Graph* g);

void relax(BinHeap* q, Node* u, Node* v, int w);

void Dijkstra(Graph* g, int start_id);

void print_sssp(Graph* g);


#endif // __DIJARRAY__