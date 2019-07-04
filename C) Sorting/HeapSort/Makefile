CXX = gcc

all: heap.x

heap.x: ../aux_functions.c maxheap.c heapsort.c heap_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all