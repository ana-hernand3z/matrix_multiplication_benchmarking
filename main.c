#include "test_lib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// exe.name max
int main(int argc, char *argv[]) {
    if(argc < 0){
        printf("Expected arguments");
        return -1;
    }
    int  max = atoi(argv[1]);
    
    run_test("i_j_k.csv", i_j_k_matrix, 1, max);
    run_test("j_k_i.csv", j_k_i_matrix, 1, max);
    run_test("k_i_j.csv", k_i_j_matrix, 1, max);
    run_test("b_i_j_k.csv", b_i_j_k_matrix, 1, max);
    run_test("b_j_k_i.csv", b_j_k_i_matrix, 1, max);
    run_test("b_k_i_j.csv", b_k_i_j_matrix, 1, max);

}
