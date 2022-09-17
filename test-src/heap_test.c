#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.h"

int main () {
	IntMinHeap* heap = newIntMinHeap(50);

	printf("Adding numbers from 9 to 0.\n");
	for (int i = 9; i >= 0; i--) {
		pushIntMinHeap(heap, i);
		assert(*(topIntMinHeap(heap)) == i);
	}
	assert(!isEmptyHeap(heap));

	printf("Popping all numbers from heap.\n");
	for (int i = 0; i < 10; i++) {
		IntPtr val = popIntMinHeap(heap);
		assert(*val == i);
		free(val);
	}
	assert(isEmptyHeap(heap));

	printf("Checking sorting on random numbers.\n");
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		pushIntMinHeap(heap, rand() % 1000);
	}
	assert(heap->size == 50);
	int last = -1;
	for (int i = 0; i < 50; i++) {
		IntPtr val = popIntMinHeap(heap);
		assert(last <= *val);
		last = *val;
		free(val);
	}
	assert(isEmptyHeap(heap));
	freeMinHeap(heap);

	printf("Testing intArrayToIntMinHeap.\n");
	int numbers[50];
	for (int i = 0; i < 50; i++) {
		numbers[i] = rand() % 1000;
	}
	IntMinHeap* heapFromArray = intArrayToIntMinHeap(numbers, 50);
	assert(heapFromArray->size == 50);
	last = -1;
	for (int i = 0; i < 50; i++) {
		IntPtr val = popIntMinHeap(heapFromArray);
		assert(last <= *val);
		last = *val;
		free(val);
	}
	assert(isEmptyHeap(heapFromArray));
	freeMinHeap(heapFromArray);

	return 0;
}
