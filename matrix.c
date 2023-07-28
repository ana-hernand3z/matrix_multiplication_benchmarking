#include "matrix.h"

matrix* create_matrix(int n){
    matrix* A = malloc(n * sizeof(matrix));
    if(A == NULL) return NULL;
    for(int i = 0; i < n; i++)
        A[i] = malloc(n * sizeof(double));
    
    return A;
}

void fill_matrix(matrix *A, int n){
    double k = 0.0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++, k++){
            A[i][j] = k;
        }
    }
}

void free_matrix(matrix *A, int n){
    for(int i = 0; i < n; i++){
        free(A[i]);
        A[i] = NULL;
    }
    free(A);
    A = NULL;
}