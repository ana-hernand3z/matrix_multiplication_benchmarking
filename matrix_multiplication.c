#include "matrix_multiplication.h"

void i_j_k_matrix(matrix *A, matrix *B, matrix *C, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double sum = 0.0;
            for (int k = 0; k < n; k++) sum += A[i][j] * B[k][j];
            C[i][j] = sum;
        }
    }
}

void j_k_i_matrix(matrix *A, matrix *B, matrix *C, int n){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            double r = B[k][j];
            for (int i = 0; i < n; i++) C[i][j] += r * A[i][j];
        }
    }
}

void k_i_j_matrix(matrix *A, matrix *B, matrix *C, int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            double r = A[i][k];
            for (int j = 0; j < n; j++) C[i][j] += r * B[k][j];
        }
    }
}