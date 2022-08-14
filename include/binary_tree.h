#ifndef binarytree
#define binarytree

typedef struct intBinaryTreeNode IntBinaryTreeNode;

typedef IntBinaryTreeNode* IntBinaryTree;

IntBinaryTree newLeaf(int val);

IntBinaryTree insertIntSearchBinaryTree(IntBinaryTree root, int val);

void dumpIntBinaryTree(IntBinaryTree root);

void printIntBinaryTreePreorderVisit(IntBinaryTree root);

void printIntBinaryTreeInorderVisit(IntBinaryTree root);

void printIntBinaryTreePostorderVisit(IntBinaryTree root);

int getBinaryTreeHeight(IntBinaryTree root);

IntBinaryTree searchIntBinaryTree (IntBinaryTree root, int val);

typedef IntBinaryTreeNode* IntAVLTree;

IntAVLTree clockwiseRotation (IntAVLTree root);

IntAVLTree counterClockwiseRotation (IntAVLTree root);

IntAVLTree insertIntAVLTree (IntAVLTree root, int val);

#endif
