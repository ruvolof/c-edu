#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/array.h"
#include "../include/dynamic.h"

int LongestCommonSequence(char *a, char *b) {
	int len_a = strlen(a) + 1;
	int len_b = strlen(b) + 1;
	int results[len_a][len_b];
	for (int i = 0; i < len_a; i++) {
		for (int j = 0; j < len_b; j++) {
			results[i][j] = 0;
		}
	}
	for (int i = 1; i < len_a; i++) {
		for (int j = 1; j < len_b; j++) {
			if (strncmp(&a[i-1], &b[j-1], 1) == 0) {
				results[i][j] = results[i-1][j-1] + 1;
			}
			else if (results[i][j-1] > results[i-1][j]) {
				results[i][j] = results[i][j-1];
			}
			else {
				results[i][j] = results[i-1][j];
			}
		}
	}
	return results[len_a-1][len_b-1];
}

int Partition(int* nums, int length) {
	int array_sum = 0;
	for(int i = 0; i < length; i++)
		array_sum += nums[i];
	if (array_sum % 2 != 0) {
		return 0;
	}
	int target_sum = array_sum / 2;
	int results[target_sum+1][length+1];
	for (int i = 0; i < target_sum + 1; i++) {
		for (int j = 0; j < length + 1; j++) {
			if (i == 0) {
				results[i][j] = 1;
			}
			else {
				results[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < target_sum + 1; i++) {
		for (int j = 1; j < length + 1; j++) {
			int current = nums[j-1];
			if (i >= current && results[i-current][j-1]) {
				results[i][j] = 1;
			}
			else {
				results[i][j] = results[i][j-1];
			}
		}
	}
	return results[target_sum][length];
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
