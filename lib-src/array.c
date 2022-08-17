#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

void printIntArray(int* int_array, int length) {
	printf("[");
	for (int i = 0; i < length - 1; i++) {
		printf("%d, ", int_array[i]);
	}
	printf("%d]", int_array[length - 1]);
}

void printIntArrayReverse(int* int_array, int length) {
	printf("[");
	for (int i = length - 1; i > 0; i--) {
		printf("%d, ", int_array[i]);
	}
	printf("%d]", int_array[0]);
} 

int* copyIntArray(int* int_array, int length) {
	int *array_copy;
	array_copy = malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		array_copy[i] = int_array[i];
	}
	return array_copy;
}

int** makeIntMatrix(int width, int height) {
	int** matrix = (int**) malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * width);
		for (int j = 0; j < width; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void printIntMatrix(int** matrix, int width, int height) {
	for (int i = 0; i < height; i++) {
		printIntArray(matrix[i], width);
		printf("\n");
	}
}

void freeMatrix(int** matrix, int height) {
	for (int i = 0; i < height; i++) {
		free(matrix[i]);
	}
}
