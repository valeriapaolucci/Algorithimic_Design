CXX = gcc

all: select.x

select.x: ../QuickSort/quicksort.c ../aux_functions.c select.c select_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all