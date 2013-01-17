#ifndef btree.h
#define btree.h

typedef struct bnode BNode;

typedef BNode* BTree;

BTree newLeaf (int val);

BTree insertIntSearchBTree (BTree t, int val);

void dumpIntBTree (BTree t);

void printIntBTreePreorderVisit (BTree t);

void printIntBTreeInorderVisit (BTree t);

void printIntBTreePostorderVisit (BTree t);

int heightBTree (BTree t);

BTree searchIntBTree (BTree t, int val);

typedef BNode* AVLTree;

AVLTree clockwiseRotation (AVLTree t);

AVLTree counterClockwiseRotation (AVLTree t);

AVLTree insertAVLTree (AVLTree t, int val);

#endif
