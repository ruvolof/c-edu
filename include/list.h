#ifndef list_lib
#define list_lib

typedef struct intListNode {
	int val;
	struct intListNode* next;
} IntListNode;

typedef IntListNode* IntList;

extern IntList createIntList(int val);

extern IntList insertIntListHead(IntList list, int val);

extern IntList insertIntListTail(IntList list, int val);

extern IntList removeIntListByVal(IntList list, int val);

extern IntList removeIntListByIndex(IntList list, int index);

extern void printIntList(IntList list);

extern IntList searchIntList(IntList list, int val);

extern int getListLength(IntList list);

extern void freeList(IntList list);

#endif
