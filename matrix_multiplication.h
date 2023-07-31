#include"matrix.h"
#define BLOCKSIZE 20
void i_j_k_matrix(matrix*, matrix*, matrix*, int);
void j_k_i_matrix(matrix*, matrix*, matrix*, int);
void k_i_j_matrix(matrix*, matrix*, matrix*, int);
void b_i_j_k_matrix(matrix*, matrix*, matrix*, int);
void b_j_k_i_matrix(matrix*, matrix*, matrix*, int);
void b_k_i_j_matrix(matrix*, matrix*, matrix*, int);