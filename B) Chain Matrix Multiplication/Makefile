CXX = gcc

all: matrixchain.x

matrixchain.x: matrixchain.c chain_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all