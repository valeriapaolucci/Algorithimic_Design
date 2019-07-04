#ifndef __DIJARRAY__
#define __DIJARRAY__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int label;
  int d;
  int position;
  struct Node *pred;
} Node;

typedef struct Queue{
  Node** A;
  size_t size;
} Queue;

typedef struct Graph {
 
    Node* V;
    int size;
    int** adj_matrix;

} Graph;


int is_empty(Queue* queue);

Queue build_Queue(Graph* graph);

Node* extract_min (Queue* queue);

int get_weight(Graph* graph, Node* a, Node* b);

Node* set_source(Graph* graph, int label);

int num_adj_nodes(Graph* graph, Node* u);

Node** adj_nodes(Graph* graph, Node* u, int num);

void Init_sssp(Graph* graph);

void relax(Queue* queue, Node* u, Node* v, int w);

void Dijkstra (Graph* graph, int source);

void print_sssp(Graph* graph);


#endif // __DIJARRAY__
