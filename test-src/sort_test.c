#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sort.h"

#define ARRAY_LENGTH 100000

int main () {
	srand(time(NULL));
	
	int numbers[ARRAY_LENGTH];
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		numbers[i] = rand() % ARRAY_LENGTH * 100;
	}
	assert(!isIntArraySorted(numbers, ARRAY_LENGTH));
	time_t start = time(NULL);
	intArrayInsertionSort(numbers, ARRAY_LENGTH);
	time_t end = time(NULL);
	assert(isIntArraySorted(numbers, ARRAY_LENGTH));
	printf("Insertion Sort: OK. Time: %lds\n", end - start);

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		numbers[i] = rand() % ARRAY_LENGTH * 100;
	}
	assert(!isIntArraySorted(numbers, ARRAY_LENGTH));
	start = time(NULL);
	intArraySelectionSort(numbers, ARRAY_LENGTH);
	end = time(NULL);
	assert(isIntArraySorted(numbers, ARRAY_LENGTH));
	printf("Selection Sort: OK. Time: %lds\n", end - start);

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		numbers[i] = rand() % ARRAY_LENGTH * 100;
	}
	assert(!isIntArraySorted(numbers, ARRAY_LENGTH));
	start = time(NULL);
	intArrayMergeSort(numbers, 0, ARRAY_LENGTH - 1);
	end = time(NULL);
	assert(isIntArraySorted(numbers, ARRAY_LENGTH));
	printf("Merge Sort: OK. Time: %lds\n", end - start);

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		numbers[i] = rand() % ARRAY_LENGTH * 100;
	}
	assert(!isIntArraySorted(numbers, ARRAY_LENGTH));
	start = time(NULL);
	intArrayQuickSort(numbers, 0, ARRAY_LENGTH - 1);
	end = time(NULL);
	assert(isIntArraySorted(numbers, ARRAY_LENGTH));
	printf("Quick Sort: OK. Time: %lds\n", end - start);
}
