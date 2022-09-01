#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/stack.h"

void pushIntStack(IntStack* stack, int val) {
	IntStack new = insertIntListHead(*stack, val);
	*stack = new;
}

IntPtr popIntStack(IntStack* stack) {
	if (!stack) {
		return NULL;
	}
	IntPtr res = (IntPtr) malloc(sizeof(int));
	*res = (*stack)->val;
	*stack = removeIntListByIndex(*stack, 0);
	return res;
}

int isEmptyIntStack(IntStack stack) {
	return stack == NULL;
}

IntPtr topIntStack(IntStack stack) {
	if (!stack) {
		return NULL;
	}
	IntPtr res = (IntPtr) malloc(sizeof(int));
	*res = stack->val;
	return res;
}