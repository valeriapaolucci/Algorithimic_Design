CXX = gcc

all: counting.x

counting.x: countingsort.c counting_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all