#include <stdio.h>
#include <string.h>
#include "../include/dynamic.h"

int main() {
	char* lcs_test_strings[] = {
    "abdghjiop",
    "zmbdjiply", // LCS from previous 5 (bdjip)
    "zxcvbnm", 	 // LCS from first 1 (b)
		"zsqw",			 // LCS from first 0
	};

	for (int i = 1; i < 4; i ++) {
		printf("LCS(\"%s\", \"%s\") = %d\n",
					 lcs_test_strings[0],
				   lcs_test_strings[i],
				  LongestCommonSequence(lcs_test_strings[0], lcs_test_strings[i]));
	}

	int partition_test_array[5] = {1, 3, 5, 7, 2}; 
	printf("Partition({1, 3, 5, 7, 2}) = %d\n", 
				 Partition(partition_test_array, 5));
	partition_test_array[4] = 9; 
	printf("Partition({1, 3, 5, 7, 9}) = %d\n", 
				 Partition(partition_test_array, 5));
	partition_test_array[0] = 6; 
	printf("Partition({6, 3, 5, 7, 9}) = %d\n", 
				 Partition(partition_test_array, 5));
}
