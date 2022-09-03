#include <assert.h>
#include <stdio.h>
#include "../include/hash.h"

int main () {
	IntOpenHashSet* open_set = newIntOpenHashSet(50);
	IntChainingHashSet* chain_set = newIntChainingHashSet(50);

	printf("Adding even number from 0 to 20 to the set:\n");
	for (int i = 0; i < 11; i++) {
		addIntOpenHashSet(open_set, i * 2);
		addIntChainingHashSet(chain_set, i * 2);
	}
	dumpIntOpenHashSet(open_set);
	printf("\n");
	dumpIntChainingHashSet(chain_set);

	printf("\nVerifying numbers in set: ");
	for (int i = 0; i < 21; i++) {
		if (i % 2 == 0) {
			assert(searchIntOpenHashSet(open_set, i));
			assert(searchIntChainingHashSet(chain_set, i));
		}
		else {
			assert(!searchIntOpenHashSet(open_set, i));
			assert(!searchIntChainingHashSet(chain_set, i));
		}
	}
	printf("OK.\n");

	printf("Removing numbers less than 10:\n");
	for (int i = 0; i < 10; i++) {
		removeIntOpenHashSet(open_set, i);
		removeIntChainingHashSet(chain_set, i);
	}
	dumpIntOpenHashSet(open_set);
	printf("\n");
	dumpIntChainingHashSet(chain_set);

	printf("\nVerifying numbers in set: ");
	for (int i = 0; i < 21; i++) {
		if (i >= 10 && i % 2 == 0) {
			assert(searchIntOpenHashSet(open_set, i));
			assert(searchIntChainingHashSet(chain_set, i));
		}
		else {
			assert(!searchIntOpenHashSet(open_set, i));
			assert(!searchIntChainingHashSet(chain_set, i));
		}
	}
	printf("OK.\n");

	printf("Re-adding even number from 0 to 10 to the set:\n");
	for (int i = 0; i < 5; i++) {
		addIntOpenHashSet(open_set, i * 2);
		addIntChainingHashSet(chain_set, i * 2);
	}
	dumpIntOpenHashSet(open_set);
	printf("\n");
	dumpIntChainingHashSet(chain_set);

	printf("\nVerifying numbers in set: ");
	for (int i = 0; i < 21; i++) {
		if (i % 2 == 0) {
			assert(searchIntOpenHashSet(open_set, i));
			assert(searchIntChainingHashSet(chain_set, i));
		}
		else {
			assert(!searchIntOpenHashSet(open_set, i));
			assert(!searchIntChainingHashSet(chain_set, i));
		}
	}
	printf("OK.\n");

	freeOpenHashSet(open_set);
	freeChainingHashSet(chain_set);

	return 0;
}
