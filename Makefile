COMPILER = gcc
PREREQUISITES = matrix_multiplication.o matrix.o timing_lib.o
FLAGS = -g -Ilib -c

main: test_lib.o $(PREREQUISITES)
	$(COMPILER) -g -Ilib $(PREREQUISITES) test_lib.o main.c -o test

test_lib.o: $(PREREQUISITES) test_lib.c test_lib.h
	$(COMPILER) $(FLAGS) test_lib.c

matrix_multiplication.o: matrix_multiplication.h matrix_multiplication.c
	$(COMPILER) $(FLAGS) matrix_multiplication.c

timing_lib.o: timing_lib.h timing_lib.c 
	$(COMPILER) $(FLAGS) timing_lib.c
	
matrix.o: matrix.h matrix.c 
	$(COMPILER) $(FLAGS) matrix.c

clean:
	rm -f test
	rm -f test_lib.o
	rm -f matrix_multiplication.o
	rm -f matrix.o
	rm -f timing.o
