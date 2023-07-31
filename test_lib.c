#include "test_lib.h"
#include <string.h>

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
    snprintf(ret, 256, "%d, %f\n", n, timing/((double)n*n*n));

    free_matrix(A, n);
    free_matrix(C, n);
    return ret;
}

void run_test(char* name, multiplication_function f, int start, int end){
    FILE *t = fopen(name, "w");
    int loading_bar_size = 100;
    if(!t){
        printf("(-) Could not open file\n");
        return;
    }
    char *loading_bar = malloc(loading_bar_size + 1);
    char a = '-',  b = '=';

    printf("Creating %s\n", name);
    memset(loading_bar, a, loading_bar_size);
    loading_bar[loading_bar_size] = '\0';

    printf("\r0.00\%\t%s", loading_bar);

    float progress = 0;
    for(int i = start; i < end; i++){
	loading_bar[(int)(progress * loading_bar_size)] = b;
        fprintf(t, "%s", test(f, i));
	progress = ((double)(i+1.0))/(double)end;
        printf("\033[1;31m\r%.2f\%\t%s\033[0m", progress * 100., loading_bar);
	fflush(stdout);
    }
    puts("");
    fclose(t);
    free(loading_bar);
}
