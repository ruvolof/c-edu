#include <stdlib.h>
#include "../include/heap.h"
#include "../include/sort.h"
#include "../include/stack.h"

IntMinHeap* newIntMinHeap(int size) {
	IntMinHeap* heap = (IntMinHeap*)malloc(sizeof(IntMinHeap));
	heap->elements = (int*)malloc(sizeof(int) * size);
	heap->size = 0;
	return heap;
}

void freeMinHeap(IntMinHeap* heap) {
	free(heap->elements);
	free(heap);
}

int isEmptyHeap(IntMinHeap* heap) {
	return !(heap->size);
}

IntPtr topIntMinHeap(IntMinHeap* heap) {
	if (isEmptyHeap(heap)) {
		return NULL;
	}
	return heap->elements;
}

int findFatherByIndex(int index) {
	return (index - 1) / 2;
}

int findLeftChildByIndex(int index) {
	return index * 2 + 1;
}

int findRightChildByIndex(int index) {
	return index * 2 + 2;
}

int getMinFatherChilds(IntMinHeap* heap, int index) {
	int left_child = findLeftChildByIndex(index);
	int right_child = findRightChildByIndex(index);
	if (right_child >= heap->size) {
		right_child = left_child;
	}
	if (heap->elements[index] > heap->elements[left_child]) {
		index = left_child;
	}
	if (heap->elements[index] > heap->elements[right_child]) {
		index = right_child;
	}
	return index;
}

void reorganizeIntMinHeap(IntMinHeap* heap, int index) {
	int father = findFatherByIndex(index);
	while (index > 0 && heap->elements[index] < heap->elements[father]) {
		swapInt(&heap->elements[index], &heap->elements[father]);
		index = father;
		father = findFatherByIndex(index);
	}
	int left_child = findLeftChildByIndex(index);
	while (left_child < heap->size && index != getMinFatherChilds(heap, index)) {
		int min_child = getMinFatherChilds(heap, index);
		swapInt(&heap->elements[index], &heap->elements[min_child]);
		index = min_child;
		left_child = findLeftChildByIndex(index);
	}
}

void pushIntMinHeap(IntMinHeap* heap, int val) {
	heap->elements[heap->size] = val;
	heap->size++;
	reorganizeIntMinHeap(heap, heap->size - 1);
}

IntPtr popIntMinHeap(IntMinHeap* heap) {
	if (isEmptyHeap(heap)) {
		return NULL;
	}
	IntPtr res = (IntPtr)malloc(sizeof(int));
	*res = heap->elements[0];
	heap->elements[0] = heap->elements[heap->size-1];
	heap->size--;
	reorganizeIntMinHeap(heap, 0);
	return res;
}

IntMinHeap* intArrayToIntMinHeap(int* numbers, int size) {
	IntMinHeap* heap = newIntMinHeap(size);
	for (int i = 0; i < size; i++) {
		pushIntMinHeap(heap, numbers[i]);
	}
	return heap;
}
