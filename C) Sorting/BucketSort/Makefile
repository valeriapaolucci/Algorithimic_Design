CXX = gcc

all: bucket.x

bucket.x: bucketsort.c quicksort_float.c bucket_main.c
	$(CXX) $(OPT) $^ -o $@ 

clean:
	@rm *.x

.PHONY: clean all