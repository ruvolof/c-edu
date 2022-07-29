#include <stdio.h>
#include <stdlib.h>

void printIntArray(int *array, int length) {
	printf("[");
	for (int i = 0; i < length - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[length - 1]);
}

void printIntArrayReverse(int *array, int length) {
	printf("[");
	for (int i = length - 1; i > 0; i--) {
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[0]);
} 

int* copyIntArray(int *array, int length) {
	int *array_copy;
	array_copy = malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		array_copy[i] = array[i];
	}
	return array_copy;
}
