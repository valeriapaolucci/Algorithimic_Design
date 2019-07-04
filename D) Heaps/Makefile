CXX = gcc

all: minheap.x

minheap.x: aux_functions.c minheap.c minheap_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all