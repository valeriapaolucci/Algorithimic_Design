CXX = gcc

all: radix.x

radix.x: radixsort.c radix_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all