#include <stdio.h>
#include <string.h>
#include "../include/array.h"
#include "../include/dynamic.h"

int main() {
	char* lcs_test_strings[] = {
    "abdghjiop",
    "zmbdjiply", // LCS from previous 5 (bdjip)
    "zxcvbnm", 	 // LCS from first 1 (b)
		"zsqw",			 // LCS from first 0
	};

	for (int i = 1; i < 4; i++) {
		printf("LCS(\"%s\", \"%s\") = %d\n",
					 lcs_test_strings[0],
				   lcs_test_strings[i],
				   LongestCommonSequence(lcs_test_strings[0], lcs_test_strings[i]));
	}

	int partition_test_array[5] = {1, 3, 5, 7, 2}; 
	printf("\nPartition({1, 3, 5, 7, 2}) = %d\n", 
				 Partition(partition_test_array, 5));
	partition_test_array[4] = 9; 
	printf("Partition({1, 3, 5, 7, 9}) = %d\n", 
				 Partition(partition_test_array, 5));
	partition_test_array[0] = 6; 
	printf("Partition({6, 3, 5, 7, 9}) = %d\n", 
				 Partition(partition_test_array, 5));

	int knapsack_values[5] = {2, 4, 7, 1, 5};
	int knapsack_weights[5] = {1, 3, 5, 1, 5};
	printf("\nKnapsack Problem:\n");
	printf("Values -> ");
	printIntArray(knapsack_values, 5);
	printf("\n");
	printf("Weights -> ");
	printIntArray(knapsack_weights, 5);
	printf("\n");
	for (int i = 0; i < 11; i++) {
		int knapsack_result = Knapsack(knapsack_values,
																	 knapsack_weights,
																	 5, 
																	 i);
		printf("Capacity %d: %d\n", i, knapsack_result);																	 
	}

	char* edit_distance_test_strings[] = {
    "abba",
    "adda", // EditDistance 2
    "abba", // EditDistance 0
		"zsqwp",	// EditDistance 5
	};

	printf("\n");
	for (int i = 1; i < 4; i++) {
		printf("EditDistance(\"%s\", \"%s\") = %d\n",
					 edit_distance_test_strings[0],
				   edit_distance_test_strings[i],
				   EditDistance(edit_distance_test_strings[0],
					 						  edit_distance_test_strings[i]));
	}
}
