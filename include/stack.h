#ifndef stack_lib
#define stack_lib

#include "list.h"

typedef IntListNode* IntStack;

typedef int* IntPtr;

extern void pushIntStack(IntStack* stack, int val);

extern IntPtr popIntStack(IntStack* stack);

extern int isEmptyIntStack(IntStack stack);

extern IntPtr topIntStack(IntStack stack);

#endif
