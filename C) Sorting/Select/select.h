#ifndef __SELECT__
#define __SELECT__

#include <stdio.h>


size_t SelectPivot (int* A, size_t l, size_t r);

size_t EvenPartition (int* A, int i, int j, int p);

int Select (int* A, size_t i, size_t l, size_t r);


#endif //__SELECT__
