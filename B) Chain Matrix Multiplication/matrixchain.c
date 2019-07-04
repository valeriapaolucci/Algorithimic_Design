// Chain matrix multiplication problem

#include <limits.h>     //INT_MAX
#include <stdio.h>


void MatrixChainAux (int* P, int** m, size_t** s, size_t i, size_t j){

    m[i][j] = INT_MAX;

    for (size_t k=i; k<=(j-1); k++){
        
        int q = m[i][k] + m[k+1][j] + P[i]*P[k+1]*P[j+1];           // since our indexes start from 0, P[i] is the number of rows of matrix A_i
                                                                    // and P[i+1] is the number of its columns (instead of P[i-1], P[i] respectively)
        if (q<m[i][j]){
            
            m[i][j] = q;
            s[i][j] = k;
        
        }

    }

}


void MatrixChain (size_t n, int* P, int** m, size_t** s){

    for (size_t i=0; i<n; i++)
        m[i][i] = 0;
    
    for (size_t l=1; l<=(n-1); l++){
        
        for (size_t i=0; i<=(n-l-1); i++){

            size_t j = i + l;
            
            MatrixChainAux (P, m, s, i, j);

        }
            
    }

}


void print_m (int** m, size_t n){
    
    printf("Matrix m:\n\n");

    for (size_t i = 0; i < n; ++i){
    
    	for (size_t j = 0; j < n; ++j){
            
            if (i>j)
            printf(" \t");

            else printf("%d\t", m[i][j]); 

	}

	printf("\n\n");

    }
printf("\n");

}


void print_s (size_t** s, size_t n){
    
    printf("Matrix s:\n\n");

    for (size_t i = 0; i < n; ++i){
    
    	for (size_t j = 0; j < n; ++j){
            
            if (i>=j)
            printf(" \t");

            else printf("%lu\t", s[i][j]+1);                // +1 is needed since our indexes start from 0

	}

	printf("\n\n");

    }

printf("\n");
    
}



