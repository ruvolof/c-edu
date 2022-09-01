#include <stdio.h>
#include "../include/array.h"
#include "../include/list.h"

int main() {
	IntList list = NULL;

	printf("Adding 0-9 to tail:\n");
	for (int i = 0; i < 10; i++) {
		list = insertIntListTail(list, i);
	}
	printIntList(list);
	printf("\n");

	printf("Adding 10-14 to head:\n");
	for (int i = 10; i < 15; i++) {
		list = insertIntListHead(list, i);
	}
	printIntList(list);
	printf("\n");

	printf("List length: %d\n", getListLength(list));

	printf("Remove first element (14) by value:\n");
	list = removeIntListByVal(list, 14);
	printIntList(list);
	printf("\n");

	printf("Remove first element by position:\n");
	list = removeIntListByIndex(list, 0);
	printIntList(list);
	printf("\n");
	
	printf("Remove element 6 by value:\n");
	list = removeIntListByVal(list, 6);
	printIntList(list);
	printf("\n");

	printf("Remove element at index 6:\n");
	list = removeIntListByIndex(list, 6);
	printIntList(list);
	printf("\n");

	printf("Looking for numbers from 0 to 14:\n");
	int results[15];
	for (int i = 0; i < 15; i++) {
		IntList found = searchIntList(list, i);
		if (found) {
			results[i] = 1;
		}
		else {
			results[i] = 0;
		}
	}
	printIntArray(results, 15);
	printf("\n");

	return 0;
}
