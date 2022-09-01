#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/stack.h"

int main() {
  IntStack stack = NULL;

  printf("Pushing values from 0 to 9 to the stack:\n");
  for (int i = 0; i < 10; i++) {
    pushIntStack(&stack, i);
  }
  printIntList(stack);
  printf("\n");

  printf("Stack is empty: %d\n", isEmptyIntStack(stack));

  IntPtr top = topIntStack(stack);
  printf("Top: %d\n", *top);
  free(top);

  for (int i = 0; i < 10; i++) {
    IntPtr popped_value = popIntStack(&stack);
    printf("Pop: %d\n", *popped_value);
    free(popped_value);
  }

  printf("Stack is empty: %d\n", isEmptyIntStack(stack));
}