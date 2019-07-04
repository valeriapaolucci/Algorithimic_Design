#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_dijkstra.h"


double exec_time (const struct timespec start, const struct timespec end){
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1E9;
}

void randomly_fill_matrix(int** A, const size_t A_rows, const size_t A_cols){
   for (size_t i=0; i< A_rows; i++) {
     for (size_t j=0; j< A_cols; j++) {
   	   A[i][j]=rand()%5 +1;
     }
   }
}

void print_adjmatrix(int** adjmatrix, size_t n){

    printf("Adjacency matrix:\n");

    for(size_t i=0; i<n; i++){

        for(size_t j=0; j<n; j++){
            
            if(adjmatrix[i][j]==INT_MAX)
                printf("-\t");
            else 
                printf("%d\t", adjmatrix[i][j]);
        }
        printf("\n");
    }

}     
        

int main(){

    printf("___DIJKSTRA___\n"); 
    printf("Array-based solution\n\n"); 
    printf("* Testing the correcteness of the implementation *\n\n");
    printf("Graph taken from the slide <<Representing graphs>>\n\n");
    
    size_t size = 4;
    int** adj_matrix = (int**) malloc(sizeof(int*)*size);
    for (size_t i=0; i<size; i++) {
     adj_matrix[i]=(int*)malloc(sizeof(int)*size);
    }

    for(int i=0; i<size; i++){
        for (int j=0; j<size; j++)
            adj_matrix[i][j]=INT_MAX;
    }

    adj_matrix[0][1] = 4;
    adj_matrix[0][3] = 6;
    adj_matrix[1][1] = 1;
    adj_matrix[1][3] = 3;
    adj_matrix[3][1] = 5;

    Graph graph;
    graph.size = size;
    graph.adj_matrix = adj_matrix;
    graph.V = (Node*) malloc(sizeof(Node)*size);

    Dijkstra(&graph, 0);
    print_sssp(&graph);
    print_adjmatrix(adj_matrix,size);

    printf("\n\n");
    
    for (size_t i=0; i<size; i++)
        free(adj_matrix[i]);
    free(adj_matrix);
    
    free(graph.V);

    /////////////////////////////////////////////////////////////////////////////////////////

    printf("* Evaluating the execution times on a set of instances *\n\n");

    struct timespec start, end;
    double total;

    for (size_t n=5; n<=25; n+=5){

        printf ("Size of the graph: %ld\n\n", n);

        int** adj_matrix2 = (int**) malloc(sizeof(int*)*n);
        for (size_t i=0; i<n; i++) {
            adj_matrix2[i]=(int*)malloc(sizeof(int)*n);
        }

        randomly_fill_matrix(adj_matrix2, n, n);
        
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int condition = rand()%(n-i);
                if (!condition || i==j)
                adj_matrix2[i][j]=INT_MAX;
            }
        }

        Graph graph2;
        graph2.size = n;
        graph2.adj_matrix = adj_matrix2;
        graph2.V = (Node*) malloc(sizeof(Node)*n);

        clock_gettime (CLOCK_REALTIME, &start);
        
        Dijkstra(&graph2, 0);
        
        clock_gettime (CLOCK_REALTIME, &end);

        total = exec_time (start, end);

        printf ("Execution time: %lf\n\n", total);

        if (n==5){
        print_sssp(&graph2);
        print_adjmatrix(adj_matrix2,n);
        }

        printf("\n\n");
        
        for (size_t i=0; i<n; i++)
            free(adj_matrix2[i]);
        free(adj_matrix2);
        
        free(graph2.V);

        }

    return 0;
}
