#include "matrixchain.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\n___CHAIN MATRIX MULTIPLICATION___\n\n");

    printf("* Testing the correctness of the implementation *\n\n");
    printf("On the matrices provided as example in the slides:\n");
    printf("A_1 (3×5), A_2 (5×10), A_3 (10×2) and A_4 (2×3)\n\n\n");

    size_t n = 4;                       // number of matrices
    int P[5] = {3, 5, 10, 2, 3};        // vector containing the dimensions of the matrices
    

    // Allocating the matrix m
    int** m = (int**)malloc(sizeof(int*) * n);
    for (size_t i=0; i<n; i++){
        m[i] = (int*)malloc(sizeof(int) * n);
    }

    // Allocating the matrix s
    size_t** s = (size_t**)malloc(sizeof(size_t*) * n);
    for (size_t i=0; i<n; i++){
        s[i] = (size_t*)malloc(sizeof(size_t) * n);
    }

    MatrixChain(n, P, m, s);

    print_m (m, n);
    print_s (s, n);
    
    // Deallocating the matrix m
    for (size_t i=0; i<n; i++){
        free(m[i]);
    }
    free(m);

    // Deallocating the matrix s
    for (size_t i=0; i<n; i++){
        free(s[i]);
    }
    free(s);
    
    ////////////////////////////

    printf("On the matrices provided as example in our reference book (page 357):\n");
    printf("A_1 (30×35), A_2 (35×15), A_3 (15×5), A_4 (5×10), A_5 (10x20) and A_6 (20x25)\n\n\n");

    size_t n2 = 6;                               // number of matrices
    int P2[7] = {30, 35, 15, 5, 10, 20, 25};     // vector containing the dimensions of the matrices
    

    // Allocating the matrix m
    int** m2 = (int**)malloc(sizeof(int*) * n2);
    for (size_t i=0; i<n2; i++){
        m2[i] = (int*)malloc(sizeof(int) * n2);
    }

    // Allocating the matrix s
    size_t** s2 = (size_t**)malloc(sizeof(size_t*) * n2);
    for (size_t i=0; i<n2; i++){
        s2[i] = (size_t*)malloc(sizeof(size_t) * n2);
    }

    MatrixChain(n2, P2, m2, s2);

    print_m (m2, n2);
    print_s (s2, n2);
    
    // Deallocating the matrix m
    for (size_t i=0; i<n2; i++){
        free(m2[i]);
    }
    free(m2);

    // Deallocating the matrix s
    for (size_t i=0; i<n2; i++){
        free(s2[i]);
    }
    free(s2);

}