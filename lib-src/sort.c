/*      sort.h
 * 
 *      Copyright 2012 Francesco Ruvolo <ruvolof@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *       
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *      
 */
 
 
/* INDEX
 * 
 * Subject									Line
 * Needed Libraries							33
 * Swap										46
 * Insertion Sort on Integers				59
 * Selection Sort on Integers				90
 * Merge Sort on Integers					122
 * Quick Sort on Integers					179
 */

/* NEDEED LIBRARIES */

/* We needs stdlib because we are going to use the malloc() function in the Merge Sort
 * algorithm. We need it also in the Quick Sort algortihm, because it needs to random
 * generate a number and so we'll need srand() and rand() from this library. Have a
 * look to 'man malloc' and 'man srand' (rand is there, too).
 * The time library is used bacause the time() functions returns the number of second
 * from epoch (http://en.wikipedia.org/wiki/Unix_time). We'll use this value as seed
 * for srand()
 */ 
#include <stdlib.h>
#include <time.h>
#include "../include/heap.h"

/* SWAP */

/* Sequent algorithm needs (almost all) to swap value between them.
 * This functions accept two pointers to integers and swap the values pointed by these two pointers.
 * Because we're passing argument by address and not by value, the change will have effect
 * globally and not only inside this functions.
 */
void swapInt (int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

/* INSERTION SORT ON INTEGERS */

/* This algorithm will order an array of integers in O(n²) time. But if the array
 * is already ordered or only few elements are misplaced, it will use O(n). So, it's
 * Ω(n) and O(n²).
 * It's very simple. It take an element and check if it's ordered among the previous elements.
 * So, let's say we have the sequent array:
 * 
 * [6, 7, 2, 3]
 * 
 * It starts and takes only the first value: 6 is alone, so it's ordered with itself.
 * It takes the second values and compares it with the first: [6, 7] is still ordered.
 * It takes the third value: finally we have a misplaced element. We'll swap it with the
 * previous one and will check again if it's greater than the preceding one, if it is
 * we'll swap it again, otherwise we'll go the next iteration.
 * Then it will take the next element and will do the same. And so on.
 * It means that at every iteration, we know that the first i elements are ordered, but
 * we don't know if they are in their final place.
 * Note that the array is passed as pointer, so the change will be globally.
 */
void IntArrayInsSort (int *a, int dim) {
	int i, j;
	for (i = 0; i < dim; i++) {
		j = i;
		while (j > 0 && a[j-1] > a[j]) {
			swapInt(&a[j-1], &a[j]);
			j--;
		}
	}
}

/* SELECTION SORT ON INTEGERS */

/* Unlike the Insertion Sort, that has Ω(n) time, this algorithm will always need O(n²).
 * So, it's Θ(n²).
 * At every iteration, the algorithm select which value has to occupy the i position.
 * Let's say we have the sequent array:
 * 
 * [6, 7, 2, 3]
 * 
 * It takes and index fixed on the 0 position and with another one it will scroll the
 * whole array looking for values smaller than the one in position 0. So, it will swap
 * 6 with 2 and then it will do nothing because two is lowest value.
 * Then it will advance the i index to 1 and with the j index it will scroll the rest
 * of the array looking for values smaller than the one in one (7). So, it will swap 7
 * with 6 and then 6 with 3. And so on.
 * At iteration i, the first i elements of the array will be ordered and will be in their
 * final position.
 * We can easily see that also if the array is already ordered, it will check every value
 * bacause it can't know if there are minor values.
 * Note that the array is passed as pointer, so the change will be globally.
 */
void IntArraySelSort (int *a, int dim) {
	int i, j;
	for (i = 0; i < dim-1; i++){
		for (j = i+1; j < dim; j++){
			if (a[j] < a[i]){
				swapInt(&a[j], &a[i]);
			}
		}
	}
}

/* MERGE SORT ON INTEGERS */

/* Merge Sort is a very fast ordering algorithm. It orders an array in O(n*log n) steps.
 * A lot less than Insertion Sort and Selection Sort.
 * It works by dividing the given array in always smaller one, dividing it into two equal
 * (if possible) parts. At the end it will have only couples. At this point, it's easy to
 * determine which is the smaller, so it creates a new array that contains the two elements
 * ordered. Then it join this array with another couples ordered by one the other recursive calls:
 * the two arrays are already ordered, so it's enough to compare the first element of each array
 * to order them.
 * For example:
 * 
 * [2, 6, 7, 3]
 * 
 * It calls the function recursively on [2, 6] and [7, 3]. Then it calls it again on [2] and [6],
 * and then on [7] and [3]. They are all ordered. It compares them two by two: 2 is smaller than 6,
 * so it creates the array [2, 6], and 3 is smaller than 7, so it creates the array [3, 7].
 * Now we have two ordere arrays and we have to join them. 2 is smaller than 3, so the first element
 * of the new array will be 2. 3 is smaller than 6, so the second element will be 3. And so on.
 * This is why we have two function for the merge sort algortihm: one does the 'recursive' job,
 * and the other merges the results of the recursive calling.
 * We are using an extra array to store our temporary result, so this algorithm uses O(n) extra space.
 */
void intArrayMerge (int *a, int left, int center, int right) {
	int *b = (int*) malloc(sizeof(int)*right);
	int i = left;
	int j = center + 1;
	int k = 0;
	while (i <= center && j <= right) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	for (; i <= center; i++, k++)
		b[k] = a[i];
	for (; j <= right; j++, k++)
		b[k] = a[j];
	for (i = left; i <= right; i++)
		a[i] = b[i-left];
}

void intArrayMergeSort (int *a, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		intArrayMergeSort(a, left, center);
		intArrayMergeSort(a, center + 1, right);
		intArrayMerge(a, left, center, right);
	}
}

/* QUICK SORT ON INTEGERS */

/* As the name says, Quick Sort is a very quick sorting algortihm. Although it's not so easy
 * to demonstrate ad it is for Merge Sort. Quick Sort, in fact, requires O(n*log n) on average,
 * but it can require more (i.e. O(n²)) in the case the array is already ordered.
 * This is because it's based on a sorting done around a random element selected among those
 * present in the array.
 * Let's try with an array:
 * 
 * [2, 7, 6, 3, 8, 0]
 * 
 * We have, first, to pick a random element (pivot, from now on). Suppose we pick 3. We switch 
 * 3 with the last element, obtaining the array [2, 7, 6, 0, 8, 3].
 * We'll use two index: the first one will point on the
 * first element, the second one on the second-last. The first index will scroll the array from
 * left to right until it finds an element that is bigger then the pivot: 2 is not,
 * 7 is, so the first index stop on 7. The second index will scroll the array from right
 * to left until it find an element that is smaller than the pivot: 8 is not,
 * 0 is, so the second will stop on 0. Now we switch this two elements, obtaining the array
 * [2, 0, 6, 7, 8, 3]. Now it's again the turn of the first index to go: 0 is lower than the pivot,
 * so the index advance, but 6 is not. The second index will go further until it finds 0. But now,
 * the first index is bigger than the second, so there will be no swap between them. The value
 * in the first index will be swapped with the pivot and we'll have the array: [2, 0, 3, 7, 8, 6].
 * It's easy to note that 3 is already in it's position and that previus values are all lower than it,
 * while sequent are all bigger. Now it's time to call the function recursively on these two
 * subarrays.
 * Like the Merge Sort, we need two different function: one does the recursion, while the other one
 * distribute values. Note that if you want to obtain a different order, you have only to change
 * the distribution function.
 */
int distributePivot (int *a, int left, int pivot, int right) {
	int i = left, j = right - 1;
	if (pivot < right)
		swapInt(&a[pivot], &a[right]);
	while (i <= j) {
		while (i <= j && a[i] <= a[right])
			i++;
		while (j >= i && a[j] >= a[right])
			j--;
		if (i < j)
			swapInt(&a[i], &a[j]);
	}
	if (i < right)
		swapInt(&a[i], &a[right]);
	return i;
}

void intArrayQuickSort (int *a, int left, int right) {
	int pivot;;
	if (left < right) {
		pivot = rand() % (right - left + 1) + left;
		pivot = distributePivot(a, left, pivot, right);
		intArrayQuickSort (a, left, pivot - 1);
		intArrayQuickSort (a, pivot + 1, right);
	}
}

/* HEAP SORT ON INTEGERS */
void intArrayHeapSort (int **a, int dim) {
	int i;
	IntMinHeap h = arrayToIntMinHeap(*a, dim);
	for (i = dim - 1; i > 0; i--) {
		swapInt(&h.array[i], &h.array[0]);
		h.size--;
		reorganizeIntMinHeap(&h, 0);
	}
	*a = h.array;
}
