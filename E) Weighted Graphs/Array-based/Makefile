CXX = gcc

all: array_dijkstra.x

array_dijkstra.x: array_dijkstra.c da_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all