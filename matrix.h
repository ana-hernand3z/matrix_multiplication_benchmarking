#include <stdlib.h>

typedef double* matrix;
typedef void(*multiplication_function)(matrix*, matrix*, matrix*, int);

matrix *create_matrix(int);
void fill_matrix(matrix*, int);
void free_matrix(matrix*, int);
