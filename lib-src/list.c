#include <stdlib.h>
#include <stdio.h>
#include "../include/list.h"

IntList createIntList(int val) {
	IntList new = (IntList) malloc(sizeof(IntListNode));
	new->val = val;
	new->next = NULL;
	return new;
}

IntList insertIntListHead(IntList list, int val) {
	IntList new = createIntList(val);
	new->next = list;
	return new;
}

IntList insertIntListTail(IntList list, int val) {
	IntList new = createIntList(val);
	if (!list) {
		return new;
	}
	IntList temp = list;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = new;
	return list;
}

IntList removeIntListByVal(IntList list, int val) {
	if (!list)
		return NULL;
	if (list->val == val) {
		IntList temp = list;
		list = list->next;
		free(temp);
		return list;
	}
	IntList prec = list;
	IntList curr = list->next;
	while (curr) {
		if (curr->val == val) {
			prec->next = curr->next;
			free(curr);
			curr = NULL;
		}
		else {
			prec = curr;
			curr = curr->next;
		}
	}
	return list;
}

IntList removeIntListByIndex(IntList list, int index) {
	if (!list) {
		return NULL;
	}
	if (index == 0) {
		IntList temp = list;
		list = list->next;
		free(temp);
		return list;
	}
	int counter = 1;
	IntList prec = list;
	IntList curr = list->next;
	while (curr && counter < index) {
		prec = curr;
		curr = curr->next;
		counter++;
	}
	if (curr) {
		prec->next = curr->next;
		free(curr);
	}
	return list;	
}

void printIntList(IntList list) {
	printf("[");
	while (list){
		printf("%d", list->val);
		if (list->next) {
			printf(", ");
		}
		list = list->next;
	}
	printf("]");
}

IntList searchIntList(IntList list, int val) {
	while (list) {
		if (list->val == val) {
			return list;
		}
		list = list->next;
	}
	return list;
}

int getListLength(IntList list) {
	int count = 0;
	while (list) {
		count++;
		list = list->next;
	}
	return count;
}

void freeList(IntList list) {
	if (!list) {
		return;
	}
	freeList(list->next);
	free(list);
}
