#include <stdio.h>
#include "matrix.h"
#include "matrix_multiplication.h"
#include "timing_lib.h"

matrix* init_matrix(int);
char* test(void(*)(matrix*,matrix*,matrix*,int), int);
void run_test(char*, multiplication_function, int, int);
