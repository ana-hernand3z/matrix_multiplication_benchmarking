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
    char max = argv[1];
    if(!isdigit(max)){
        printf("Expected number argument");
        return -1;
    }
    
    int size = atoi(max);
    run_test("i_j_k.csv", i_j_k_matrix, 0, size);
    run_test("j_k_i.csv", j_k_i_matrix, 0, size);
    run_test("k_i_j.csv", k_i_j_matrix, 0, size);

}