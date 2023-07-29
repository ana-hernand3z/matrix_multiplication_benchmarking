COMPILER = gcc
PREREQUISITES = matrix_multiplication.o matrix.o timing.o
FLAGS = -g -Ilib -c
main: test_lib.o
	$(COMPILER) $(PREREQUISITES) test_lib.o -o test
test_lib.o: $(PREREQUISITES) test_lib.c
	$(COMPILER) $(FLAGS) $(PREREQUISITES) test_lib.c
matrix_multiplication.o: matrix.o matrix_multiplication.h matrix_multiplication.c
	$(COMPILER) $(FLAGS) matrix.o matrix_multiplication.c
timing.o: matrix.o timing.h timing.c 
	$(COMPILER) $(FLAGS) timing.c matrix.o
matrix.o: matrix.h matrix.c 
	$(COMPILER) $(FLAGS) matrix.c

clean:
	rm -f test
	rm -f test_lib.o
	rm -f matrix_multiplication.o
	rm -f matrix.o
	rm -f timing.o