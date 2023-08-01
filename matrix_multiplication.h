#include"matrix.h"

void set_blocksize(int);
void i_j_k_matrix(matrix*, matrix*, matrix*, int);
void j_k_i_matrix(matrix*, matrix*, matrix*, int);
void k_i_j_matrix(matrix*, matrix*, matrix*, int);
void b_i_j_k_matrix(matrix*, matrix*, matrix*, int);
void b_j_k_i_matrix(matrix*, matrix*, matrix*, int);
void b_k_i_j_matrix(matrix*, matrix*, matrix*, int);