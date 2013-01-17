#ifndef heap
#define heap

typedef struct intMinHeap IntMinHeap;

IntMinHeap newIntMinHeap (int dim);

int emptyHeap (IntMinHeap h);

int firstHeap (IntMinHeap h);

void reorganizeIntMinHeap (IntMinHeap *h, int index);

void enqueueIntMinHeap (IntMinHeap *h, int val);

void dequeIntMinHeap (IntMinHeap *h, int *i);

IntMinHeap arrayToIntMinHeap (int *a, int dim);

#endif
