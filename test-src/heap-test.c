#include <stdio.h>
#include "heap.h"

void printIntArray (int *a, int dim) {
	int i;
	printf("[");
	for (i = 0; i < dim - 1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[dim-1]);
}

int main () {
	IntMinHeap h;
	int n, i, val;
	
	printf("How many value would you like to add to the heap? ");
	scanf("%d", &n);
	
	h = newIntMinHeap(n);
	
	printf("Insert values:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &val);
		enqueueIntMinHeap(&h, val);
	}
	
	printf("This is your heap:\n");
	printIntArray(h.array, h.size);
	
	dequeIntMinHeap(&h, &val);
	printf("Its first value is: %d\n", val);
	
	printf("Now the heap is:\n");
	printIntArray(h.array, h.size);
	
	return 0;
}
