#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "list.h"

#define PRIME 426389

typedef struct intOpenHashTable {
	int *table;
	int *free;
	int *deleted;
	int a;
	int b;
	int size;
	int full;
} IntOpenHashTable;

IntOpenHashTable newIntOpenHashTable (int n) {
	IntOpenHashTable hash;
	int i;
	srand(time(NULL));
	hash.size = 2 * n;
	hash.table = (int*) malloc(sizeof(int) * hash.size);
	hash.free = (int*) malloc(sizeof(int) * hash.size);
	for (i = 0; i < hash.size; i++)
		hash.free[i] = 0;
	hash.deleted = (int*) malloc(sizeof(int) * hash.size);
	for (i = 0; i < hash.size; i++)
		hash.deleted[i] = 0;
	hash.a = rand() % 10000;
	hash.b = rand() % 10000;
	hash.full = 0;
	return hash;
}

int getOpenHash (IntOpenHashTable hash, int val) {
	return ((hash.a * val + hash.b) % PRIME) % hash.size;
}

void insertIntOpenHashTable (IntOpenHashTable *hash, int val) {
	int val_hash = getOpenHash(*hash, val);
	while (hash->free[val_hash] == 1 && hash->table[val_hash] != val)
		val_hash = (val_hash + 1) % hash->size;
	if (hash->table[val_hash] != val) {
		hash->table[val_hash] = val;
		hash->deleted[val_hash] = 0;
		hash->free[val_hash] = 1;
		hash->full++;
	}
}

void removeIntOpenHashTable (IntOpenHashTable *hash, int val) {
	int val_hash = getOpenHash(*hash, val);
	while ((hash->free[val_hash] == 1 || hash->deleted[val_hash] == 1) && hash->table[val_hash] != val)
		val_hash = (val_hash + 1) % hash->size;
	if (hash->table[val_hash] == val) {
		hash->free[val_hash] = 0;
		hash->deleted[val_hash] = 1;
		hash->full++;
	}
}

int searchIntOpenHashTable (IntOpenHashTable hash, int val) {
	int val_hash = getOpenHash(hash, val);
	while ((hash.free[val_hash] == 1 || hash.deleted[val_hash] == 1) && hash.table[val_hash] != val)
		val_hash = (val_hash + 1) % hash.size;
	if (hash.table[val_hash] == val)
		return 1;
	else
		return 0;
}

void dumpIntOpenHashTable (IntOpenHashTable hash, char *name) {
	int i;
	printf("%s {\n", name);
	for (i = 0; i < hash.size; i++)
		if (hash.free[i] != 0 && hash.deleted[i] != 1)
			printf("\t%d\t=>\t%d\n", i, hash.table[i]);
		else
			printf("\t%d\t=>\tNULL\n", i);
	printf("}\n");
}

typedef struct intChainingHashTable {
	IntList *table;
	int size;
	int a;
	int b;
} IntChainingHashTable;

IntChainingHashTable newIntChainingHashTable (int n) {
	int i;
	IntChainingHashTable new;
	new.size = n * 2;
	new.table = (IntList*) malloc(sizeof(IntList) * new.size);
	for (i = 0; i < 2 * n; i++)
		new.table[i] = NULL;
	srand(time(NULL));
	new.a = rand() % 10000;
	new.b = rand() % 10000;
	return new;
}

int getChainingHash (IntChainingHashTable hash, int val) {
	return ((hash.a * val + hash.b) % PRIME) % hash.size;
}

void insertIntChainingHashTable (IntChainingHashTable *hash, int val) {
	int hash_val = getChainingHash(*hash, val);
	IntList l = hash->table[hash_val];
	while (l != NULL && l->next != NULL && l->info != val)
		l = l->next;
	if (l == NULL)
		hash->table[hash_val] = insertIntListTail(hash->table[hash_val], val);
	else if (l->info != val)
		l = insertIntListTail(hash->table[hash_val], val);
}

void removeIntChainingHashTable (IntChainingHashTable *hash, int val) {
	int hash_val = getChainingHash(*hash, val);
	hash->table[hash_val] = removeIntList(hash->table[hash_val], val);
}

int searchIntChainingHashTable (IntChainingHashTable hash, int val) {
	int hash_val = getChainingHash(hash, val);
	IntList = searchIntList(hash.table[hash_val], n);
	if (IntList)
		return 1;
	else
		return 0;
}

void dumpIntChainingHashTable (IntChainingHashTable hash, char *name) {
	int i;
	printf("%s {\n", name);
	for (i = 0; i < hash.size; i++) {
		printf("\t%d\t=>\t", i);
		printIntList(hash.table[i]);
	}
	printf("}\n");
}
