CXX = gcc

all: chain_mm.x

chain_mm.x: matrix.c chain_mm.c main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all