#include <stdlib.h>
#include "../include/sort.h"

typedef struct intMinHeap {
	int *array;
	int size;
} IntMinHeap;

IntMinHeap newIntMinHeap (int dim) {
	IntMinHeap new;
	new.array = (int*) malloc(sizeof(int)*dim);
	new.size = 0;
	return new;
}

int emptyHeap (IntMinHeap h) {
	if (h.size == 0)
		return 1;
	else
		return 0;
}

int firstHeap (IntMinHeap h) {
	if(!emptyHeap(h))
		return h.array[0];
}

int findFather (int index) {
	return (index - 1) / 2;
}

int findLeftChild (int index) {
	return index * 2 + 1;
}

int findRightChild (int index) {
	return index * 2 + 2;
}

int minFatherChilds (IntMinHeap h, int index) {
	int leftchild = findLeftChild(index);
	int rightchild = findRightChild(index);
	if (rightchild >= h.size)
		rightchild = leftchild;
	if (h.array[index] > h.array[leftchild])
		index = leftchild;
	if (h.array[index] > h.array[rightchild])
		index = rightchild;
	return index;
}

void reorganizeIntMinHeap (IntMinHeap *h, int index) {
	int father, leftchild, child;
	father = findFather(index);
	while (index > 0 && h->array[index] < h->array[father]) {
		swapInt(&h->array[index], &h->array[father]);
		index = father;
		father = findFather(index);
	}
	leftchild = findLeftChild(index);
	while (leftchild < h->size && index != minFatherChilds(*h, index)) {
		child = minFatherChilds(*h, index);
		swapInt(&h->array[index], &h->array[child]);
		index = child;
		leftchild = findLeftChild(index);
	}
}

void enqueueIntMinHeap (IntMinHeap *h, int val) {
	h->array[h->size] = val;
	h->size++;
	reorganizeIntMinHeap(h, h->size - 1);
}

void dequeIntMinHeap (IntMinHeap *h, int *i) {
	if (emptyHeap(*h))
		return;
	else {
		*i = firstHeap(*h);
		h->array[0] = h->array[h->size - 1];
		h->size--;
		reorganizeIntMinHeap(h, 0);
	}
}

IntMinHeap arrayToIntMinHeap (int *a, int dim) {
	IntMinHeap new = newIntMinHeap(dim);
	int i;
	for (i = 0; i < dim; i++)
		enqueueIntMinHeap(&new, a[i]);
	return new;
}
