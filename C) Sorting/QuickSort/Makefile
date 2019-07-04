CXX = gcc

all: quick.x

quick.x: ../aux_functions.c quicksort.c quick_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all