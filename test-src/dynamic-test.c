#include <stdio.h>
#include <string.h>
#include "../include/dynamic.h"

int main() {
	char a[100], b[100];
	int *m = NULL, *a_int = NULL, *weight = NULL, *values = NULL;
	int i, j, res, dim_a, dim_b, choice, dim, s, capacity;
	
	while(1) {
		printf("0 -> Exit.\n");
		printf("1 -> LCS.\n");
		printf("2 -> Partition.\n");
		printf("3 -> KnapSack.\n");
		printf("4 -> EditDistance.\n");
		printf("What do you want to do? (0, 1, 2, 3, 4) ");
		scanf("%d", &choice);
		
		switch (choice) {			
			case 1:		
				printf("Insert first string for LCS: ");
				scanf("%s", a);
				getchar();
				printf("Insert second string for LCS: ");
				scanf("%s", b);
				
				dim_a = strlen(a) + 1;
				dim_b = strlen(b) + 1;
				
				res = LCS(a, b, &m);
				
				for (i = 0; i < dim_a; i++) {
					for (j = 0; j < dim_b; j++)
						printf("%d ", m[i * dim_b + j]);
					printf("\n");
				}
				
				printf("The longest common sequence is %d chars long.\n", res);
				break;
			
			case 2:
				printf("How many values do you want to store? ");
				scanf("%d", &dim);
				
				a_int = (int*) malloc(sizeof(int) * dim);
				printf("Insert values:\n");
				for (i = 0; i < dim; i++) {
					scanf("%d", &a_int[i]);
				}
				for (i = 0, s = 0; i < dim; i++)
					s += a_int[i];
				s /= 2;
				
				res = Partition(a_int, dim, &m);
				
				for (i = 0; i < dim + 1; i++) {
					for (j = 0; j < s + 1; j++)
						printf("%d ", m[i * (s + 1) + j]);
					printf("\n");
				}
				
				printf("%d\n", res);
				break;
				
			case 3:
				printf("How many elements do you want to add? ");
				scanf("%d", &dim);
				
				weight = (int*) malloc(sizeof(int) * dim);
				values = (int*) malloc(sizeof(int) * dim);
				
				printf("Insert %d couples for weight and value.\n", dim);
				for (i = 0; i < dim; i++) {
					printf("Couple %d: ", i + 1);
					scanf("%d", &weight[i]);
					scanf("%d", &values[i]);
				}
				printf("Which is the capacity? ");
				scanf("%d", &capacity);
				
				res = Knapsack(values, weight, dim, capacity, &m);
				
				for (i = 0; i < dim + 1; i++) {
					for (j = 0; j < capacity + 1; j++)
						printf("%d ", m[i * (capacity + 1) + j]);
					printf("\n");
				}
				break;
			
			case 4:
				printf("Insert first string for EditDistance: ");
				scanf("%s", a);
				getchar();
				printf("Insert second string for EditDistance: ");
				scanf("%s", b);
				
				dim_a = strlen(a) + 1;
				dim_b = strlen(b) + 1;
				
				res = EditDistance(a, b, &m);
				
				for (i = 0; i < dim_b; i++) {
					for (j = 0; j < dim_a; j++)
						printf("%d ", m[i * dim_a + j]);
					printf("\n");
				}
				
				printf("Edit distance between %s and %s is %d chars long.\n", a, b, res);
				break;
				
			
			default:
				return 0;
		}
	}
}
