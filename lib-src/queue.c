#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/queue.h"

void pushIntQueue(IntQueue* queue, int val) {
	IntList new = insertIntListTail(*queue, val);
	*queue = new;
}

IntPtr popIntQueue(IntQueue* queue) {
	if (!queue) {
		return NULL;
	}
	IntPtr res = (IntPtr) malloc(sizeof(int));
	*res = (*queue)->val;
	*queue = removeIntListByIndex(*queue, 0);
	return res;
}

int isEmptyQueue(IntQueue queue) {
	return queue == NULL;
}
