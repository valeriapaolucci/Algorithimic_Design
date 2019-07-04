CXX = gcc
OPT = -O4

all: strassen_test.x

strassen_test.x: matrix.c strassen.c strassen_improved1.c strassen_improved2.c main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all