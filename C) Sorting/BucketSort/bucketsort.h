#ifndef __BUCKET_SORT__

#include <stdio.h>

typedef struct Node{
    float data;
    struct Node* next;
} Node;

typedef struct Bucket{
    size_t size;
    Node* head;
} Bucket;

Node* get_node (Bucket* bucket, size_t k);

void append (Bucket* bucket, float value);

void BucketSort(float* A, size_t n);


#endif //__BUCKET_SORT__
