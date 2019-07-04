# Chain Matrix Multiplication: Homework

We are required to implement the iterative dynamic-programming algorithm to solve the chain matrix multiplication problem.

•
*matrixchain.c* contains an implementation that follows the pseudocode described in the slides, in order to find out the optimal parenthesization that minimizes the number of scalar products for the chain multiplication; *chain_main.c* tests the implementation.
The files *Chain1.png* and *Chain2.png* contain a picture of the output obtained (i.e. the printing of the matrices m and s).
A Makefile is provided.


•
The folder CMM contains the implementation seen during the lessons.
In particular, for different input sizes, we can compare the execution time required to perform the chain matrix multiplication by:
- the naive solution;
- the optimal solution, which follows the optimal parenthesization obtained.
We can observe that the execution times are comparable for input sizes ranging from 1 to 4; starting from 5, instead, the optimal solution clearly outperforms the naive one.
A Makefile is provided.
