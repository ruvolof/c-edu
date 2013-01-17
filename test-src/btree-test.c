#include <stdio.h>
#include "btree.h"

int main () {
	BTree t = NULL;
	AVLTree avl = NULL;
	BTree search = NULL;
	int i, val, n;
	
	printf("How many nodes do you want to add to your tree? ");
	scanf("%d", &n);
	printf("Insert nodes:\n");
	for (i=0; i<n; i++){
		scanf("%d", &val);
		t = insertIntSearchBTree(t, val);
		avl = insertAVLTree(avl, val);
	}
	
	printf("This is your binary search tree:\n");
	printIntBTree(t);
	printf("\n");
	
	printf("Its height is %d.\n", heightBTree(t));
	
	printf("This is the same tree, but create with AVL tree format:\n");
	printIntBTree(avl);
	printf("\n");
	
	printf("Its height is %d. The left branch height height is %d, while the right branch height is %d.\n", heightBTree(avl), heightBTree(avl->left), heightBTree(avl->right));
	
	printf("This is your tree with preordered visit:\n");
	printIntBTreePreorderVisit(t);
	printf("\n");	
	
	printf("This is your tree with postordered visit:\n");
	printIntBTreePostorderVisit(t);
	printf("\n");	
	
	printf("How many searches do you want to perform? ");
	scanf("%d", &n);
	if (n > 0)
		printf("Insert nodes:\n");
	for (i=0; i<n; i++) {
		scanf("%d", &val);
		search = searchIntBTree(t, val);
		if (search) {
			printf("TROVATO\n");
		}
		else {
			printf("ASSENTE\n");
		}
	}
	
	return 0;
}
