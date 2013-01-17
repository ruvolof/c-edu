#ifndef hash.h
#define hash.h

typedef struct intOpenHashTable IntOpenHashTable;

IntOpenHashTable newIntOpenHashTable (int n);

void insertIntOpenHashTable (IntOpenHashTable *hash, int val);

void removeIntOpenHashTable (IntOpenHashTable *hash, int val)

int searchIntOpenHashTable (IntOpenHashTable hash, int val);

void dumpIntOpenHashTable (IntOpenHashTable hash, char *name);

typedef struct intChainingHashTable IntChainingHashTable;

IntChainingHashTable newIntChainingHashTable (int n);

void insertIntChainingHashTable (IntChainingHashTable *hash, int val);

void removeIntChainingHashTable (IntChainingHashTable *hash, int val);

int searchIntChainingHashTable (IntChainingHashTable hash, int val);

void dumpIntChainingHashTable (IntChainingHashTable hash, char *name);

#endif
