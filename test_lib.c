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
    char *loading_bar = malloc(100+1);
    char a = '-',  b = '=';

    printf("Creating %s\n", name);
    int j = 0;
    for(; j < 100; j++){
	    loading_bar[j] = a;
    }
    loading_bar[j] = '\0';

    printf("\r0.00\%\t%s", loading_bar);

    float  progress = 0;
    for(int i = start; i < end; i++){
	loading_bar[(int)progress] = b;
        fprintf(t, "%s", test(f, i));
	    progress = ((double)(i+1.0)*100.)/(double)end;
        printf("\r%.2f\%\t%s", progress, loading_bar);
    }
    printf("\n");
    fclose(t);
    free(loading_bar);
}
