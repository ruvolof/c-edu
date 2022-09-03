#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../include/hash.h"
#include "../include/list.h"

#define PRIME 426389

IntOpenHashSet* newIntOpenHashSet(int size) {
	IntOpenHashSet* set = (IntOpenHashSet*)malloc(sizeof(IntOpenHashSet));
	set->size = 2 * size;
	set->values = (int*) malloc(sizeof(int) * set->size);
	set->is_free = (int*) malloc(sizeof(int) * set->size);
	for (int i = 0; i < set->size; i++) {
		set->is_free[i] = 1;
		set->values[i] = 0;
	}
	srand(time(NULL));
	set->param_mul = rand() % 10000;
	set->param_add = rand() % 10000;
	set->count = 0;
	return set;
}

void freeOpenHashSet(IntOpenHashSet* set) {
	free(set->values);
	free(set->is_free);
	free(set);
}

int computeHash(int param_mul, int param_add, int hash_size, int val) {
	return ((param_mul * val + param_add) % PRIME) % hash_size;
}

void addIntOpenHashSet(IntOpenHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	while (!(set->is_free[val_hash]) && set->values[val_hash] != val) {
		val_hash = (val_hash + 1) % set->size;
	}
	if (set->is_free[val_hash]) {
		set->values[val_hash] = val;
		set->is_free[val_hash] = 0;
		set->count++;
	}
}

void removeIntOpenHashSet(IntOpenHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	while (!(set->is_free[val_hash]) && set->values[val_hash] != val) {
		val_hash = (val_hash + 1) % set->size;
	}
	if (set->values[val_hash] == val) {
		set->is_free[val_hash] = 1;
		set->count--;
	}
}

int searchIntOpenHashSet(IntOpenHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	while (!(set->is_free[val_hash])) {
		if (set->values[val_hash] == val) {
			return 1;
		}
		val_hash = (val_hash + 1) % set->size;
	}
	return 0;
}

void dumpIntOpenHashSet(IntOpenHashSet* set) {
	int last = set->size - 1;
	while (set->is_free[last]) {
		last--;
	}
	printf("{");
	for (int i = 0; i < set->size; i++) {
		if (!(set->is_free[i])) {
			printf("%d", set->values[i]);
			if (i != last) {
				printf(", ");
			}
		}
	}
	printf("}");
}

IntChainingHashSet* newIntChainingHashSet(int size) {
	IntChainingHashSet* set = (IntChainingHashSet*)malloc(sizeof(IntChainingHashSet));
	set->size = size * 2;
	set->lists = (IntList*)malloc(sizeof(IntList) * set->size);
	for (int i = 0; i < set->size; i++) {
		set->lists[i] = NULL;
	}
	srand(time(NULL));
	set->param_mul = rand() % 10000;
	set->param_add = rand() % 10000;
	return set;
}

void freeChainingHashSet(IntChainingHashSet* set) {
	for (int i = 0; i < set->size; i++) {
		if (set->lists[i]) {
			free(set->lists[i]);
		}
	}
	free(set);
}

void addIntChainingHashSet(IntChainingHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	if (!searchIntList(set->lists[val_hash], val)) {
		set->lists[val_hash] = insertIntListHead(set->lists[val_hash], val);
	}
}

void removeIntChainingHashSet(IntChainingHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	set->lists[val_hash] = removeIntListByVal(set->lists[val_hash], val);
}

int searchIntChainingHashSet(IntChainingHashSet* set, int val) {
	int val_hash = computeHash(set->param_mul,
														 set->param_add,
														 set->size,
														 val);
	return searchIntList(set->lists[val_hash], val) != NULL;
}

void dumpIntChainingHashSet(IntChainingHashSet* set) {
	int last = set->size - 1;
	while (!(set->lists[last])) {
		last--;
	}
	printf("{");
	for (int i = 0; i < set->size; i++) {
		if (set->lists[i]) {
			printIntList(set->lists[i]);
			if (i != last) {
				printf(", ");
			}
		}
	}
	printf("}");
}
