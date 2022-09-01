#ifndef queue_lib
#define queue_lib

#include "../include/list.h"
#include "../include/stack.h"

typedef IntListNode* IntQueue;

extern void pushIntQueue(IntQueue* queue, int val);

extern IntPtr popIntQueue(IntQueue* queue);

extern int isEmptyQueue(IntQueue queue);

#endif
