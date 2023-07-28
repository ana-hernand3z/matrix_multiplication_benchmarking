#include "timing_lib.h"

double time_function(multiplication_function f, matrix *A, matrix *B, matrix *C, int n){
    clock_t t;
    t = clock();
    f(A, B, C, n);
    t = clock() - t;
    return ((double)t)/CLOCKS_PER_SEC;
}