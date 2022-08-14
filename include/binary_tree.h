#ifndef binarytree
#define binarytree

typedef struct IntBinaryTreeNode {
	int val;
	struct IntBinaryTreeNode* left;
	struct IntBinaryTreeNode* right;
} IntBinaryTreeNode;

typedef IntBinaryTreeNode* IntBinaryTree;
typedef IntBinaryTreeNode* IntAVLTree;

extern IntBinaryTree newLeaf(int val);

extern void freeBinaryTree(IntBinaryTreeNode* root);

extern IntBinaryTree insertIntSearchBinaryTree(IntBinaryTree root, int val);

extern void dumpIntBinaryTree(IntBinaryTree root);

extern void printIntBinaryTreePreorderVisit(IntBinaryTree root);

extern void printIntBinaryTreeInorderVisit(IntBinaryTree root);

extern void printIntBinaryTreePostorderVisit(IntBinaryTree root);

extern int getBinaryTreeHeight(IntBinaryTree root);

extern IntBinaryTree searchIntBinaryTree (IntBinaryTree root, int val);

extern IntAVLTree insertIntAVLTree (IntAVLTree root, int val);

#endif
