#include <stdlib.h>
#include <stdio.h>

typedef struct bnode {
	int info;
	struct bnode* left;
	struct bnode* right;
} BNode;

typedef BNode* BTree;

/* This functions creates a new leaf */
BTree newLeaf (int val) {
	BTree new = (BTree) malloc(sizeof(BNode));
	new->info = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

BTree insertIntSearchBTree (BTree t, int val) {
	BTree new = newLeaf(val);
	if (t == NULL)
		return new;
	else {
		BTree parent;
		BTree current = t;
		while (current != NULL) {
			parent = current;
			if (current->info >= val)
				current = current->left;
			else
				current = current->right;
		}
		if (parent->info >= val)
			parent->left = new;
		else
			parent->right = new;
		return t;
	}
}

void dumpIntBTree (BTree t) {
	if (t == NULL) {
		printf("Void");
	}
	else{
		printf("Node(%d, ", t->info);
		printIntBTree(t->left);
		printf(", ");
		printIntBTree(t->right);
		printf(")");
	}
}

void printIntBTreePreorderVisit (BTree t) {
	if (t != NULL) {
		printIntBTreePreorderVisit(t->left);
		printf("%d ", t->info);
		printIntBTreePreorderVisit(t->right);
	}
}

void printIntBTreeInorderVisit (BTree t) {
	if (t != NULL) {
		printf("%d ", t->info);
		printIntBTreeInorderVisit(t->left);
		printIntBTreeInorderVisit(t->right);
	}
}

void printIntBTreePostorderVisit (BTree t) {
	if (t != NULL) {
		printIntBTreePostorderVisit(t->left);
		printIntBTreePostorderVisit(t->right);
		printf("%d ", t->info);
	}
}

int heightBTree (BTree t) {
	if (t == NULL) {
		return 0;
	}
	else {
		int leftheight = 1 + heightBTree(t->left);
		int rightheight = 1 + heightBTree(t->right);	
		int height = leftheight > rightheight ? leftheight : rightheight;
		return height;
	}
}

BTree searchIntBTree (BTree t, int val){
    while (t != NULL){
        if (t->info == val)
            return t;
        else if (t->info >= val)
            t = t->left;
        else
            t = t->right;
    }
    return t;
}

/* Here we're going to introduce the AVL binary tree.
 * The name comes from the authors Adel'son-Velsky and Landis.
 * This is a special binary search tree that grant to be height
 * no more than log n, where n is the number of leaf.
 */
 
/* Note: it uses the same structure for normal BTree */

typedef BNode* AVLTree;

AVLTree clockwiseRotation (AVLTree t) {
	AVLTree temp = t->left;
	t->left = temp->right;
	temp->right = t;
	return temp;
}
 
AVLTree counterClockwiseRotation (AVLTree t) {
	AVLTree temp = t->right;
	t->right = temp->left;
	temp->left = t;
	return temp;
}
 
AVLTree insertAVLTree (AVLTree t, int val) {
	AVLTree new = (AVLTree) newLeaf(val);
	if (t == NULL)
		return new;
	else if (t->info >= val) {
		t->left = insertAVLTree (t->left, val);
		if (heightBTree(t->left) - heightBTree(t->right) == 2) {
			if (t->left->info < val)
				t->left = counterClockwiseRotation(t->left);
			t = clockwiseRotation(t);
		}
	}
	else if (t->info < val) {
		t->right = insertAVLTree(t->right, val);
		if (heightBTree(t->right) - heightBTree(t->left) == 2){
			if (t->right->info > val)
				t->right = clockwiseRotation(t->right);
			t = counterClockwiseRotation(t);
		}
	}
	return t;
}
 
