#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main() {
  IntQueue queue = NULL;

  printf("Pushing values from 0 to 9 to the queue:\n");
  for (int i = 0; i < 10; i++) {
    pushIntQueue(&queue, i);
  }
  printIntList(queue);
  printf("\n");

  printf("Queue is empty: %d\n", isEmptyQueue(queue));

  for (int i = 0; i < 10; i++) {
    IntPtr popped_value = popIntQueue(&queue);
    printf("Pop: %d\n", *popped_value);
    free(popped_value);
  }

  printf("Queue is empty: %d\n", isEmptyQueue(queue));
}