#ifndef array
#define array

extern void printIntArray (int *array, int length);

extern void printIntArrayReverse (int *array, int length);

extern int* copyIntArray(int *array, int length);

extern int** makeIntMatrix(int width, int height);

extern void printIntMatrix(int** matrix, int width, int height);

extern void freeMatrix(int** matrix, int height);

#endif
