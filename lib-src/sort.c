#include <stdlib.h>
#include <time.h>
#include "../include/heap.h"

void swapInt (int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int isIntArraySorted(int* numbers, int length) {
	for (int i = 0; i < length - 1; i++) {
		if (numbers[i] > numbers[i+1]) {
			return 0;
		}
	}
	return 1;
}

void intArrayInsertionSort(int* numbers, int length) {
	for (int i = 0; i < length; i++) {
		int j = i;
		while (j > 0 && numbers[j-1] > numbers[j]) {
			swapInt(&numbers[j-1], &numbers[j]);
			j--;
		}
	}
}

void intArraySelectionSort(int* numbers, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++){
			if (numbers[j] < numbers[i]){
				swapInt(&numbers[j], &numbers[i]);
			}
		}
	}
}

void intArrayMergeSort(int* numbers, int left, int right) {
	if (left >= right) {
		return;
	}
	int center = (left + right) / 2;
	intArrayMergeSort(numbers, left, center);
	intArrayMergeSort(numbers, center + 1, right);
	int joined_tmp[right];
	int left_index = left;
	int right_index = center + 1;
	int joined_index = 0;
	while (left_index <= center && right_index <= right) {
		if (numbers[left_index] <= numbers[right_index]) {
			joined_tmp[joined_index] = numbers[left_index];
			left_index++;
		}
		else {
			joined_tmp[joined_index] = numbers[right_index];
			right_index++;
		}
		joined_index++;
	}
	while (left_index <= center) {
		joined_tmp[joined_index] = numbers[left_index];
		left_index++;
		joined_index++;
	} 
	while (right_index <= right) {
		joined_tmp[joined_index] = numbers[right_index];
		right_index++;
		joined_index++;
	} 
	for (int i = left; i <= right; i++) {
		numbers[i] = joined_tmp[i-left];
	}
}

int sortAroundPivot(int *numbers, int left, int pivot, int right) {
	if (pivot < right) {
		swapInt(&numbers[pivot], &numbers[right]);
	}
	pivot = right;
	right--;
	while (left <= right) {
		while (left <= right && numbers[left] <= numbers[pivot]) {
			left++;
		}
		while (right >= left && numbers[right] >= numbers[pivot]) {
			right--;
		}
		if (left < right) {
			swapInt(&numbers[left], &numbers[right]);
		}
	}
	if (left < pivot) {
		swapInt(&numbers[left], &numbers[pivot]);
	}
	return left;
}

void intArrayQuickSort(int* numbers, int left, int right) {
	if (left >= right) {
		return;
	}
	srand(time(NULL));
	int pivot = rand() % (right - left + 1) + left;
	int pivot_position = sortAroundPivot(numbers, left, pivot, right);
	intArrayQuickSort(numbers, left, pivot_position - 1);
	intArrayQuickSort(numbers, pivot_position + 1, right);
}