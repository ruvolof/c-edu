#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sort.h"
#include "../include/array.h"

int main () {
	int *a = NULL, *temp = NULL, n, i;
	
	printf("How many elements do you want store in the array? ");
	scanf("%d", &n);
	
	a = (int*) malloc(sizeof(int)*n);
	
	printf("Insert elements:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("This is your array:\n");
	printIntArray(a, n);
	
	cloneIntArray(&temp, a, n);
		
	printf("This is the temporary array that we're going to order:\n");
	printIntArray(temp, n);
	
	IntArraySelSort(temp, n);
	printf("This is the array ordered with selection sort:\n");
	printIntArray(temp, n);
	free(temp);
	
	cloneIntArray(&temp, a, n);
	
	IntArrayInsSort(temp, n);
	printf("This is the array ordered with insertion sort:\n");
	printIntArray(temp, n);
	free(temp);
	
	cloneIntArray(&temp, a, n);
	
	intArrayMergeSort(temp, 0, n - 1);
	printf("This is the array ordered with mergesort:\n");
	printIntArray(temp, n);
	free(temp);
	
	cloneIntArray(&temp, a, n);
	
	/* Initialising srandom for pivot calculation */
	srand(time(NULL));
	intArrayQuickSort(temp, 0, n - 1);
	printf("This is the array ordered with quicksort:\n");
	printIntArray(temp, n);
	free(temp);
	
	cloneIntArray(&temp, a, n);
	
	intArrayHeapSort(&temp, n);
	printf("This is the array ordered with heapsort:\n");
	printIntArrayReverse(temp, n);
	free(temp);
	
	return 0;
}
