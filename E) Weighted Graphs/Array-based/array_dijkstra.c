#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int label;
    int d;                    
    struct Node* pred;
} Node;


typedef struct Graph {
    Node* V;
    int size;
    int** adj_matrix;       // Adjacency matrix representation
} Graph;


typedef struct Queue {
    Node** A;               // Array-based queue
    size_t size;
} Queue;


int is_empty (Queue* queue){
    return queue->size == 0;
}


Queue build_Queue (Graph* graph) {

    Queue queue;
    queue.size = graph->size;
    queue.A = (Node**)malloc(sizeof(Node*) * graph->size);
    
    for (size_t i=0; i<(graph->size); i++){             // all the nodes are in the queue at the beginning of the computation
        queue.A[i] = &(graph->V[i]);
    }
    
    return queue;
}


Node* extract_min (Queue* queue){

    int min = queue->A[0]->d;
    size_t idx = 0;

    for (size_t i=1; i<(queue->size); i++) {

        if (queue->A[i]->d < min) {
            min = queue->A[i]->d;
            idx = i;
        }
    }

    Node* tmp = queue->A[idx];
    queue->A[idx] = queue->A[queue->size-1];
    queue->A[queue->size-1] = tmp;

    queue->size = queue->size-1;

    return tmp;
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


void Init_sssp (Graph* graph){

    for(int i=0; i<(graph->size); i++){

        Node* v = &(graph->V[i]);

        v->label = i;
        v->d = INT_MAX;
        v->pred = NULL;

    }

}


void relax (Queue* queue, Node* u, Node* v, int w) {

    if ( u->d + w < v->d ) {
        
        v->d = u->d + w;                // UPDATE_DISTANCE
        
        v->pred = u;
    }

}


void Dijkstra (Graph* graph, int label){
    
    Init_sssp (graph);
    
    Node* source = set_source(graph, label);
    source->d = 0;

    Queue Q = build_Queue (graph);
   
    while (!is_empty(&Q)){
        Node* u = extract_min(&Q);
        int num = num_adj_nodes(graph, u);
        Node** Adj_u = adj_nodes(graph, u, num);
        for (size_t i=0; i<num; i++){
            relax(&Q, u, Adj_u[i], get_weight(graph, u, Adj_u[i]));
        }
        free(Adj_u);
    }
    
    free(Q.A);

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