#include <stdio.h>

void printIntArray (int *a, int dim) {
	int i;
	printf("[");
	for (i = 0; i < dim - 1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[dim - 1]);
}

void printIntArrayReverse (int *a, int dim) {
	int i;
	printf("[");
	for (i = dim - 1; i > 0; i--)
		printf("%d, ", a[i]);
	printf("%d]\n", a[0] 

void cloneIntArray (int **temp, int *a, int dim) {
	int i, *aux;
	aux = malloc(sizeof(int)*dim);
	for (i = 0; i < dim; i++)
		aux[i] = a[i];
	*temp = aux;
}
