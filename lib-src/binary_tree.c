#include <stdlib.h>
#include <stdio.h>

typedef struct IntBinaryTreeNode {
	int val;
	struct IntBinaryTreeNode* left;
	struct IntBinaryTreeNode* right;
} IntBinaryTreeNode;

typedef IntBinaryTreeNode* IntBinaryTree;

IntBinaryTree newLeaf(int val) {
	IntBinaryTree new = (IntBinaryTree) malloc(sizeof(IntBinaryTreeNode));
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

IntBinaryTree insertIntSearchBinaryTree(IntBinaryTree root, int val) {
	IntBinaryTree new = newLeaf(val);
	if (root == NULL) {
		return new;
	}
	else {
		IntBinaryTree parent;
		IntBinaryTree current = root;
		while (current != NULL) {
			parent = current;
			if (current->val >= val) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		if (parent->val >= val) {
			parent->left = new;
		}
		else {
			parent->right = new;
		}
		return root;
	}
}

void dumpIntBinaryTree (IntBinaryTree root) {
	if (root == NULL) {
		printf("Void");
	}
	else{
		printf("Node(%d, ", root->val);
		dumpIntBinaryTree(root->left);
		printf(", ");
		dumpIntBinaryTree(root->right);
		printf(")");
	}
}

void printIntBinaryTreePreorderVisit(IntBinaryTree root) {
	if (root != NULL) {
		printIntBinaryTreePreorderVisit(root->left);
		printf("%d ", root->val);
		printIntBinaryTreePreorderVisit(root->right);
	}
}

void printIntBinaryTreeInorderVisit (IntBinaryTree root) {
	if (root != NULL) {
		printf("%d ", root->val);
		printIntBinaryTreeInorderVisit(root->left);
		printIntBinaryTreeInorderVisit(root->right);
	}
}

void printIntBinaryTreePostorderVisit(IntBinaryTree root) {
	if (root != NULL) {
		printIntBinaryTreePostorderVisit(root->left);
		printIntBinaryTreePostorderVisit(root->right);
		printf("%d ", root->val);
	}
}

int getBinaryTreeHeight (IntBinaryTree root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int left_height = 1 + getBinaryTreeHeight(root->left);
		int right_height = 1 + getBinaryTreeHeight(root->right);
		if (left_height > right_height) {
			return left_height;
		}
		return right_height;
	}
}

IntBinaryTree searchIntBinaryTree (IntBinaryTree root, int val){
    while (root != NULL){
      if (root->val == val)
        return root;
      else if (root->val >= val)
        root = root->left;
      else
        root = root->right;
    }
    return NULL;
}

/* Here we're going to introduce the AVL binary tree.
 * The name comes from the authors Adel'son-Velsky and Landis.
 * This is a special binary search tree that grant to be height
 * no more than log n, where n is the number of leaf.
 */

typedef IntBinaryTreeNode* IntAVLTree;

IntAVLTree clockwiseRotation(IntAVLTree node) {
	IntAVLTree temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}
 
IntAVLTree counterClockwiseRotation(IntAVLTree node) {
	IntAVLTree temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}
 
IntAVLTree insertIntAVLTree(IntAVLTree root, int val) {
	IntAVLTree new = (IntAVLTree) newLeaf(val);
	if (root == NULL) {
		return new;
	}
	else if (root->val >= val) {
		root->left = insertIntAVLTree(root->left, val);
		if (getBinaryTreeHeight(root->left) - getBinaryTreeHeight(root->right) > 1) {
			if (root->left->val < val) {
				root->left = counterClockwiseRotation(root->left);
			}
			root = clockwiseRotation(root);
		}
	}
	else {
		root->right = insertIntAVLTree(root->right, val);
		if (getBinaryTreeHeight(root->right) - getBinaryTreeHeight(root->left) > 1) {
			if (root->right->val > val) {
				root->right = clockwiseRotation(root->right);
			}
			root = counterClockwiseRotation(root);
		}
	}
	return root;
}
 
