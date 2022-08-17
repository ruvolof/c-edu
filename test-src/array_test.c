#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"


int main() {
  int test_array[5] = {1, 2, 3, 4, 5};
  int* array_copy;

  printIntArray(test_array, 5);
  printf("\n");
  printIntArrayReverse(test_array, 5);
  printf("\n");
  array_copy = copyIntArray(test_array, 5);
  printIntArray(array_copy, 5);
  printf("\n");
  free(array_copy);

  int width = 6;
  int height = 5;
  int** matrix = makeIntMatrix(width, height);
  printIntMatrix(matrix, width, height);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      matrix[i][j] = 1;
    }
  }
  printIntMatrix(matrix, width, height);
}