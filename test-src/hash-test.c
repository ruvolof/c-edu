#include <stdio.h>
#include "hash.h"

int main () {
	int i, n, val;
	IntOpenHashTable openhash;
	IntChainingHashTable chaininghash;
	
	printf("How many elements do you want to insert in the table? ");
	scanf("%d", &n);
	
	openhash = newIntOpenHashTable(n);
	chaininghash = newIntChainingHashTable(n);
	
	printf("Insert elements:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &val);
		insertIntOpenHashTable(&openhash, val);
		insertIntChainingHashTable(&chaininghash, val);
	}
	
	dumpIntOpenHashTable(openhash, "OPEN\0");
	dumpIntChainingHashTable(chaininghash, "CHAINING\0");
	
	return 0;
}
