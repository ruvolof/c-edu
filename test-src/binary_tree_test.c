#include <stdio.h>
#include "../include/binary_tree.h"

int main () { 
	IntBinaryTree root = NULL;
	int values[7] = {1,2,3,4,5,6,7};

	for (int i = 0; i < 7; i++) {
		root = insertIntSearchBinaryTree(root, values[i]);
	}

	printIntBinaryTreePreorderVisit(root);
	printf("\n");
	printIntBinaryTreeInorderVisit(root);
	printf("\n");
	printIntBinaryTreePostorderVisit(root);
	printf("\n");
	printf("Height: %d\n", getBinaryTreeHeight(root));

	IntAVLTree avl_root = NULL;
	for (int i = 0; i < 7; i++) {
		avl_root = insertIntAVLTree(avl_root, values[i]);
	}

	printIntBinaryTreePreorderVisit(avl_root);
	printf("\n");
	printIntBinaryTreeInorderVisit(avl_root);
	printf("\n");
	printIntBinaryTreePostorderVisit(avl_root);
	printf("\n");
	printf("AVL Height: %d\n", getBinaryTreeHeight(avl_root));

	for (int i = 1; i < 9; i++) {
		IntBinaryTree exists = searchIntBinaryTree(avl_root, i);
		if (exists) {
			printf("%d found.", i);
		}
		else {
			printf("%d not found.", i);
		}
		printf("\n");
	}

	freeBinaryTree(root);
	freeBinaryTree(avl_root);
	
	return 0;
}
