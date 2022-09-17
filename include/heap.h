#ifndef heap_lib
#define heap_lib

#include "../include/stack.h"

typedef struct intMinHeap {
	int* elements;
	int size;
} IntMinHeap;

extern IntMinHeap* newIntMinHeap(int size);

extern void freeMinHeap(IntMinHeap* heap);

extern int isEmptyHeap(IntMinHeap* heap);

extern IntPtr topIntMinHeap(IntMinHeap* heap);

extern void pushIntMinHeap(IntMinHeap* heap, int val);

extern IntPtr popIntMinHeap(IntMinHeap* heap);

extern IntMinHeap* intArrayToIntMinHeap(int* numbers, int size);

#endif
