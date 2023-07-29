#include "test_lib.h"

matrix* init_matrix(int n){
    matrix *A = create_matrix(n);
    fill_matrix(A, n);
    return A;
}

char* test(multiplication_function f, int n){
    matrix *A = init_matrix(n);
    matrix *C = create_matrix(n);
    double timing = time_function(f, A, A, C, n);
    char* ret = malloc(256);
    snprintf(ret, 256, "%d, %f\n", n, timing);
    free_matrix(A, n);
    free_matrix(C, n);
    return ret;
}

void run_test(char* name, multiplication_function f, int start, int end){
    FILE *t = fopen(name, "w");
    if(!t){
        printf("(-) Could not open file\n");
        return;
    }
    char *loading_bar = malloc((end-start)*sizeof(char));
    char a = '-',  b = '=';

    printf("Creating %s\n", name);
    for(int j = start; j < end; j++){
        loading_bar[j] = a;
        printf("\r%s", loading_bar);
    }
    for(int i = start; i < end; i++){
        fprintf(t, "%s", test(f, i));
        loading_bar[i] = b;
        printf("\r%s", loading_bar);
    }
    fclose(t);
}