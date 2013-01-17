#ifndef list
#define list

typedef struct elementIntList ElementIntList;

typedef ElementIntList* IntList;

IntList createIntList (int val);

IntList insertIntListHead (IntList l, int val);

IntList insertIntListTail (IntList l, int val);

IntList removeIntListByVal (IntList l, int val);

IntList removeIntListByPosition (IntList l, int pos, IntList *ret);

void printIntList (IntList l);

IntList searchIntList (IntList l, int val);

int lengthList (IntList l);

#endif
