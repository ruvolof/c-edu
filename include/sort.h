#ifndef sort_lib
#define sort_lib

extern int isIntArraySorted(int* numbers, int length);

extern void intArrayInsertionSort(int* numbers, int length);

extern void intArraySelectionSort(int* numbers, int length);

extern void intArrayMergeSort(int* numbers, int left, int right);

extern void intArrayQuickSort(int* numbers, int left, int right);

#endif
