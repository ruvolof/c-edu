#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/dynamic.h"

int LCS (char *a, char *b, int **mat) {
	int dim_a = strlen(a) + 1;
	int dim_b = strlen(b) + 1;
	int i, j, *m;

	m = (int*) malloc(sizeof(int) * dim_a * dim_b);
	for (i = 0; i < dim_a * dim_b; i++)
		m[i] = 0;
	for (i = 1; i < dim_a; i++) {
		for (j = 1; j < dim_b; j++) {
			if (strncmp(&a[i-1], &b[j-1], 1) == 0)
				m[i * dim_b + j] = m[(i - 1) * dim_b + (j - 1)] + 1;
			else if (m[i * dim_b + (j - 1)] > m[(i - 1) * dim_b + j])
				m[i * dim_b + j] = m[i * dim_b + (j - 1)];
			else
				m[i * dim_b + j] = m[(i - 1) * dim_b + j];
		}
	}
	*mat = m;
	return m[dim_a * dim_b - 1];
}

int Partition (int *a, int dim, int **mat) {
	int s, i, j, *m;
	for (i = 0, s = 0; i < dim; i++)
		s += a[i];
	s /= 2;
	m = (int*) malloc(sizeof(int) * (dim + 1) * (s + 1));
	for (i = 0; i < (dim + 1) * (s + 1); i++)
		m[i] = 0;
	m[0] = 1;
	for (i = 1; i < dim + 1; i++) {
		for (j = 0; j < s + 1; j++) {
			if (m[(i - 1) * (s + 1) + j])
				m[i * (s + 1) + j] = 1;
			else if (j >= a[i - 1] && m[(i - 1) * (s + 1) + (j - a[i - 1])])
				m[i * (s + 1) + j] = 1;
		}
	}
	printf("\n");
	*mat = m;
	return m[(dim + 1) * (s + 1) - 1];
}

int Knapsack (int *values, int *weight, int dim, int capacity, int **mat) {
	int *m, i, j, val;
	m = (int*) malloc(sizeof(int) * (dim + 1) * (capacity + 1));
	for (i = 0; i < (dim + 1) * (capacity + 1); i++)
		m[i] = 0;
	for (i = 1; i < dim + 1; i++) {
		for (j = 1; j < capacity + 1; j++) {
			m[i * (capacity + 1) + j] = m[(i - 1) * (capacity + 1) + j];
			if (j >= weight[i - 1]) {
				val = m[(i - 1) * (capacity + 1) + (j - weight[i - 1])] + values[i - 1];
				if (val > m[i * (capacity + 1) + j])
					m[i * (capacity + 1) + j] = val;
			}
		}
	}
	*mat = m;
	return m[(dim + 1) * (capacity + 1) - 1];
}

int EditDistance (char *a, char *b, int **mat) {
	int i, j, cost, min;
	int *m = NULL;
	int dim_a = strlen(a) + 1;
	int dim_b = strlen(b) + 1;
	m = (int*) malloc(sizeof(int) * (dim_a + 1) * (dim_b + 1));
	for (i = 0; i < dim_a; i++)
		m[i] = i;
	for (i = 0; i < dim_b; i++)
		m[i * (dim_a)] = i;
	for (i = 1; i < dim_b; i++) 
		for (j = 1; j < dim_a; j++) {
			if (strncmp(&a[i - 1], &b[j - 1], 1) == 0)
				cost = 0;
			else
				cost = 1;
			min = m[(i - 1) * dim_a + j] + 1;
			if (min > m[i * dim_a + (j - 1)] + 1)
				min = m[i * dim_a + (j - 1)] + 1;
			if (min > m[(i - 1) * dim_a + (j - 1)] + cost)
				min = m[(i - 1) * dim_a + (j - 1)] + cost;
			m[i * dim_a + j] = min;
		}
	*mat = m;
	return m[dim_a * dim_b - 1];
}
