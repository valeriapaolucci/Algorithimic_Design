# Matrix Multiplication: Homework

We are required to improve the implementation of the provided Strassen’s algorithm by **reducing the memory allocations**, and to test the effects on the execution time.

We can observe that, to compute each matrix P, at most **two** S matrices at a time are needed, therefore there's no need to allocate 10 of them; by allocating just 2 S matrices (see *strassen_improved1.c*), we can achieve a reduction in the execution time with respect to the original Strassen's algorithm (*strassen.c*).

Moreover, we can observe that no more than **four** P matrices at a time are involved in the computation for each of the C blocks, therefore we can allocate just 4 of them instead of 7; combining this strategy with the previous one (*strassen_improved2.c*), a slight additional reduction in the execution time is obtained.

The provided *main.c* file has been integrated so that *strassen_test.x* displays the execution time for each of the four algorithms considered (the naive matrix multiplication, the original Strassen's algorithm, the first improved version and the second one), thus allowing for comparisons; this is done for different matrix sizes, ranging from n=1 to n=2048.

As we can see from the output, the previous considerations hold when the matrix size is **large enough** (i.e. starting from n=64).

An example of the results obtained is shown in the *Strassen.png* file (the table contains the execution times in seconds).



A Makefile is provided; the optimization level is set at -O4, as required in the assignment.

