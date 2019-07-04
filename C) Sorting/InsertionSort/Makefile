CXX = gcc

all: insertion.x

insertion.x: ../aux_functions.c insertionsort.c insertion_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all