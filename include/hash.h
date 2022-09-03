#ifndef hash_lib
#define hash_lib

#include "../include/list.h"

typedef struct intOpenHashSet {
	int* values;
	int* is_free;
	int param_mul;
	int param_add;
	int size;
	int count;
} IntOpenHashSet;

typedef struct intChainingHashSet {
	IntList* lists;
	int size;
	int param_mul;
	int param_add;
} IntChainingHashSet;

extern IntOpenHashSet* newIntOpenHashSet(int size);

extern void freeOpenHashSet(IntOpenHashSet* set);

extern void addIntOpenHashSet(IntOpenHashSet* set, int val);

extern void removeIntOpenHashSet(IntOpenHashSet* set, int val);

extern int searchIntOpenHashSet(IntOpenHashSet* set, int val);

extern void dumpIntOpenHashSet(IntOpenHashSet* set);

extern IntChainingHashSet* newIntChainingHashSet(int size);

extern void freeChainingHashSet(IntChainingHashSet* set);

extern void addIntChainingHashSet(IntChainingHashSet* set, int val);

extern void removeIntChainingHashSet(IntChainingHashSet* set, int val);

extern int searchIntChainingHashSet(IntChainingHashSet* set, int val);

extern void dumpIntChainingHashSet(IntChainingHashSet* set);

#endif
