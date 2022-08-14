#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

void printIntArray(int* int_array, int length) {
	printf("[");
	for (int i = 0; i < length - 1; i++) {
		printf("%d, ", int_array[i]);
	}
	printf("%d]\n", int_array[length - 1]);
}

void printIntArrayReverse(int* int_array, int length) {
	printf("[");
	for (int i = length - 1; i > 0; i--) {
		printf("%d, ", int_array[i]);
	}
	printf("%d]\n", int_array[0]);
} 

int* copyIntArray(int* int_array, int length) {
	int *array_copy;
	array_copy = malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		array_copy[i] = int_array[i];
	}
	return array_copy;
}
