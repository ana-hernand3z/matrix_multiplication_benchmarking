#include "matrix_multiplication.h"

void i_j_k_matrix(matrix *A, matrix *B, matrix *C, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void j_k_i_matrix(matrix *A, matrix *B, matrix *C, int n){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            double r = B[k][j];
            for (int i = 0; i < n; i++) C[i][j] += r * A[i][k];
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

void b_i_j_k_matrix(matrix *A, matrix *B, matrix *C, int n){
    int block = BLOCKSIZE;
    for(int i = 0; i < n; i+=block){
        for(int j = 0; j < n; j += block){
            for(int k = 0; k < n; k += block){
                for(int ii = i; ii < i+block && ii < n; ii++){
                    for(int ij = j; ij < j+block && ij < n; ij++){
                        for(int ik = k; ik < k+block && ik < n; ik++){
                            C[ii][ij] += A[ii][ik] * B[ik][ij];
                        }
                    }
                }
            }
        }
    }
}

void b_j_k_i_matrix(matrix *A, matrix *B, matrix *C, int n){
    int block = 20;
    for(int j = 0; j < n; j+=block){
        for(int k = 0; k < n; k += block){
            for(int i= 0; i < n; i += block){
                for(int ij = j; ij < j+block && ij < n; ij++){
                        for(int ik = k; ik < k+block && ik < n; ik++){
                            double r = B[ik][ij];
                            for(int ii = i; ii < i+block && ii < n; ii++){
                                C[ii][ij] += A[ii][ik] * r;
                        }
                    }
                }
            }
        }
    }
}

void b_k_i_j_matrix(matrix *A, matrix *B, matrix *C, int n){
    int block = 20;
    for(int k = 0; k < n; k+=block){
        for(int i = 0; i < n; i += block){
            for(int j= 0; j < n; j += block){
                for(int ik = k; ik < k+block && ik < n; ik++){
                    for(int ii = i; ii < i+block && ii < n; ii++){
                        double r = A[ii][ik];
                        for(int ij = j; ij < j+block && ij < n; ij++){
                                C[ii][ij] += r * B[ik][ij];
                        }
                    }
                }
            }
        }
    }
}