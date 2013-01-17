#ifndef dynamic
#define dynamic

int LCS (char *a, char *b, int **mat);

int Partition (int *a, int dim, int **mat);

int Knapsack (int *values, int *weight, int dim, int capacity, int **mat);

int EditDistance (char *a, char *b, int **mat);

#endif
