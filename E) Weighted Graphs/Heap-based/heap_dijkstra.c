#include <limits.h>     //INT_MAX
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
  int** adj_matrix;          // Adjacency matrix representation of the graph
} Graph;


typedef struct BinHeap {    // Heap-based representation of the queue
  Node** H;                         
  size_t size;
} BinHeap;


size_t left (size_t i){
  return (2*i)+1;
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

Node* heap_minimum (BinHeap* h){
  return h->H[0];
}

void heap_swap (BinHeap* h, size_t v, size_t w){
  Node* tmp = h->H[v];
  h->H[v] = h->H[w];
  h->H[w] = tmp;
}


void heapify (BinHeap* h, size_t i){

  size_t m = i, comp = m;
  int condition = 1;

  while (condition) {
    
    size_t l = left(m);
    size_t r = right(m);
    size_t arr[2] = {l, r};

    for (size_t j = 0; j <= 1; j++){
      if (is_valid_node(h, arr[j]) && h->H[arr[j]]->d < h->H[m]->d){
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


int is_empty (BinHeap* queue){
    return queue->size == 0;
}


Node* extract_min (BinHeap* queue){
    
    Node* min = queue->H[get_root()];
    
    queue->H[get_root()] = queue->H[queue->size-1];
    queue->size = queue->size-1;
    heapify (queue, get_root());

    return min;
}


BinHeap build_Queue (Graph* graph){

    BinHeap queue;
    queue.size = graph->size;
    queue.H = (Node**)malloc(sizeof(Node*) * graph->size);

    for (size_t i=0; i<(graph->size); i++){
        queue.H[i] = &(graph->V[i]);
    }

    for (int i = parent(queue.size-1); i>=0; i--){            // restoring heap property
        heapify (&queue, i);
    }

    return queue;

}


void update_distance (BinHeap* queue, Node* v, int new_distance){
    
    int i = v->label;

    queue->H[i]->d = new_distance;

    while (!(is_root(i) || queue->H[parent(i)] <= queue->H[i])){
        heap_swap(queue, i, parent(i));
        i = parent(i);
    }
        
}


Node* set_source (Graph* graph, int label){

  for (int i=0; i<(graph->size); i++)
      if (i == label){
          Node* source = &(graph->V[i]);
          return source;
      }
}


int get_weight (Graph* graph, Node* a, Node* b){
    
    int i = a->label;
    int j = b->label;

    return graph->adj_matrix[i][j];

}


void Init_sssp (Graph* graph){

    for(int i=0; i<(graph->size); i++){

        Node* v = &(graph->V[i]);

        v->label = i;
        v->d = INT_MAX;
        v->pred = NULL;

    }

}


int num_adj_nodes (Graph* graph, Node* u){
    
    int num = 0;
    
    for (int i=0; i<(graph->size); i++){

        Node* v = &(graph->V[i]);
        int cond1 = (i != u->label);
        int cond2 = get_weight(graph,u,v) < INT_MAX;
        
        if (cond1 && cond2)
            num++;

    }
        
    return num;
}


Node** adj_nodes (Graph* graph, Node* u, int n){

    Node** Adj = (Node**)malloc(sizeof(Node*) * n);
    
    int k = 0;
    
    for (int i=0; i<(graph->size); i++){

        Node* v = &(graph->V[i]);
        int cond1 = (i != u->label);
        int cond2 = get_weight(graph,u,v) < INT_MAX;
        
        if (cond1 && cond2){
            Adj[k] = v;
            k++;
        }
    }
         
    return Adj;
}


void relax (BinHeap* queue, Node* u, Node* v, int w){
    
    if (u->d+w < v->d){
        update_distance (queue, v, u->d+w);
        v->pred = u;
    }
}


void Dijkstra (Graph* graph, int label){
    
    Init_sssp (graph);
    
    Node* source = set_source(graph, label);
    source->d = 0;

    BinHeap Q = build_Queue (graph);
   
    while (!is_empty(&Q)){

        Node* u = extract_min(&Q);
        int num = num_adj_nodes(graph, u);
        Node** Adj_u = adj_nodes(graph, u, num);
        
        for (size_t i=0; i<num; i++){
            relax(&Q, u, Adj_u[i], get_weight(graph, u, Adj_u[i]));
        }
        
        free(Adj_u);
    
    }
    
    free(Q.H);

}


void print_sssp(Graph* graph){   

    for(size_t i=0; i<(graph->size); i++){

        Node v = graph->V[i];
        
        printf("\nNode %d:\n", v.label);
        
        if((v.d)!=INT_MAX)
            printf("d=%d\n", v.d);
        else
            printf("d=/\n");

        if((v.pred)!=NULL)
            printf("pred=%d", v.pred->label);
        else
            printf("no pred");
        
        printf("\n");
    }
    
    printf("\n");
}