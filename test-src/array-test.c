#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"


int main() {
  int test_array[5] = {1, 2, 3, 4, 5};
  int* array_copy;

  printIntArray(test_array, 5);
  printIntArrayReverse(test_array, 5);
  array_copy = copyIntArray(test_array, 5);
  printIntArray(array_copy, 5);
  free(array_copy);
}