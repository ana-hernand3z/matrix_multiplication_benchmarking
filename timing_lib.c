#include "timing_lib.h"

float time_function(multiplication_function f, matrix *A, matrix *B, matrix *C, int n){
    clock_t t;
    t = clock();
    f(A, B, C, n);
    t = clock() - t;
    return ((float)t);
}
