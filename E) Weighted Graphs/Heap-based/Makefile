CXX = gcc

all: heap_dijkstra.x

heap_dijkstra.x: heap_dijkstra.c dh_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all