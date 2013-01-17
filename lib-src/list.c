/*      list.h
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
 
/* INDEX */

/* Subject								Line
 * Needed libraries						35
 * Integer list							44
 * Data structure						46
 * Adding an element					62
 * Removing an element					117
 * Printing								167
 * Searching							185
 * Lenght								206
 */

/* NEEDED LIBRARIES */

/* We need stdlib because we're going to use the malloc and the free function.
 * Have a look to 'man malloc' (free function is there, too).
 * We need stdio for the printf function. Have a look to 'man 3 printf'. 
 */    
#include <stdlib.h>
#include <stdio.h>

/* INTEGER LIST */

/* DATA STRUCTURE */

/* The structure of an integer list is quite simple: an integer that represent
 * the information stored in the element, and a pointer to the same structure.
 * This is why list are really useful when we don't know how many elements
 * will be submitted: a list can be easily extended by allocating new memory for
 * a new element and linking the two elements with the pointer.
 */
typedef struct elementIntList {
	int info;
	struct elementIntList* next;
} ElementIntList;

/* Here we are declaring a list as a pointer to the previous structure */
typedef ElementIntList* IntList;

/* CREATING AN ELEMENT */
IntList createIntList (int val) {
	IntList new = (IntList) malloc(sizeof(IntList));
	new->info = val;
	new->next = NULL;
	return new;
}

/* ADDING AN ELEMENT */

/* ADDING AN ELEMENT TO THE HEAD */

/* The easiest way to add new elements to a list is to add the at the beginning
 * (the head, from now on) of the list. This is because, unlike arrays, we can't
 * access directly to every element of a list and we have to scan them one by one.
 * Adding a new element to the head of the list saves us time. We can always add
 * an element to the head in O(1) time, regardless of the lenght of the list.
 * This functions accept an IntList (remember, is a pointer) and an int value that
 * will be store in the field 'info' of the structure. The functions return a IntList,
 * so you have to use it in an assignment.
 * Here I'm creating the new element. It's important to set to NULL the field 'next',
 * it means that the list ends. 
 * I have to add the element to the head of the list. So, if the IntList passed
 * to the function is empty, it means my list will have only the newly created 
 * element, I'll return 'new' (that is an IntList, so a pointer, again).
 * While, if the IntList isn't NULL, I'll set the field 'next' of the newly created
 * element to point to the old one, and then return again 'new'.
 */
IntList insertIntListHead (IntList l, int val) {
	IntList new = createIntList(val);
	if (l == NULL)
		return new;
	else {
		new->next = l;
		return new;
	}
}

/* ADDING AN ELEMENT TO THE TAIL */

/* Adding an element to the end (the tail, from now on) of the list is a bit
 * different. I have to create the element in the same way, and if the IntList passed
 * is NULL, I have again to return my 'new' pointer.
 * But if the list isn't NULL, I have to scroll its elements until I find a field
 * 'next' that points to NULL. Finally, I can point that field to the new element.
 * This functions has to return a pointer to the head of the list, so in the case that
 * the IntList wasn't empty, I have to return the same pointer passed to this function,
 * that is the head of the list (if it's not, something went wrong).
 * To add an element to the tail of the list, we always use O(n) time.
 */
IntList insertIntListTail (IntList l, int val) {
	IntList new = createIntList(val);
	if (l == NULL)
		return new;
	else {
		IntList temp = l;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return l;
	}
}

/* REMOVING AN ELEMENT */

/* Removing an element is something a bit harder.
 * Imagine that we have this list:
 * 
 * 1 -> 2 -> 3 -> NULL
 * 
 * If we simply delete an element (for example 2), we'll leave an empty space between
 * the others and list will be broken.
 * If we delete an element, we must ensure
 * that no void space remains. So, during ours scroll of the IntList, we have to keep
 * track not only of the current element, but also of the preceding one. Delete an
 * element, now, is as simple as to assign to the field 'next' of the preceding one, the
 * same value of the field 'next' of the current one.
 * Of course, if the element to remove is the head of the list, we have only to point
 * to the second element, and we don't need anything else. If there isn't the
 * element that must be deleted, the list will remain unmodified and we'll return the
 * same pointer that was passed to the list.
 * Note that everytime that we delete an element, we have to free the memory that
 * was allocated for it. Be carefull, once you freed an element, there's no way to
 * recover it.
 * Deleting an element from a list requires O(n), since we don't know where is the 
 * element that must be deleted.
 */
 
/* REMOVING AN ELEMENT BY VAL */
IntList removeIntListByVal (IntList l, int val) {
	if (l == NULL)
		return NULL;
	else if (l->info == val) {
		IntList temp = l;
		l = l->next;
		free(temp);
		return l;
	}
	else {
		IntList prec = l, curr = l->next;
		while (curr != NULL) {
			if (curr->info == val) {
				prec->next = curr->next;
				free(curr);
				return l;
			}
			else {
				prec = curr;
				curr = curr->next;
			}
		}
		return l;
	}
}

/* REMOVING AN ELEMENT BY POSITION */

/* Just a note: the int 'pos' starts from 0. 0 is the head of the list.
 * This function has an extra argument where will be stored the value that was
 * removed from the list.
 * This is useful, for example, when we have to remove
 * the first element in stack list and we need it for our algorithm. Have a look
 * to 'stack.h'.
 */
IntList removeIntListByPosition (IntList l, int pos, IntList *ret) {
	if (l == NULL) {
		*ret = NULL;
		return NULL;
	}
	else if (pos == 0) {
		*ret = l;
		l = l->next;
		(*ret)->next = NULL;
		return l;
	}
	else {
		int counter = 1;
		IntList prec = l;
		IntList curr = l->next;
		while (curr != NULL && counter != pos) {
			prec = curr;
			curr = curr->next;
		}
		if (curr != NULL) {
			*ret = curr;
			prec->next = curr->next;
			(*ret)->next = NULL;
			return l;
		}
		else {
			*ret = NULL;
			return l;
		}
	}
}

/* PRINTING */

/* You can really print your list as you prefer, as long as you scroll the list until
 * your pointer points to NULL. But this is the representation that I think is the best
 * one.
 * A pointer to NULL will be represented by a "NULL" string. A pointer to a structure
 * will be represented by the field 'info' followed by an arrow (->).
 * Note, if the IntList passed points to NULL, the while is never executed and it will
 * print "NULL" and nothing else (as expected).
 */
void printIntList (IntList l) {
	while (l != NULL){
		printf("%d -> ", l->info);
		l = l->next;
	}
	printf("NULL\n");
}

/* SEARCHING */

/* C assumes NULL as false and a pointer to something as true.
 * This function will return a NULL pointer if the elements isn't found, otherwise it
 * will return a pointer to that element. It's easy as returning 0 or 1, but having a
 * pointer we can perform something else to that element (for example we can check how far
 * is from the end using the function lenghtList (explained below).
 * This function will scroll the whole list until the pointer is NULL or it finds an
 * element that has the field 'info' equal to the int val passed to the function.
 * If it doesn't find anything, it means the while has terminated because l was NULL,
 * it will return l.
 */
IntList searchIntList (IntList l, int val) {
	while (l != NULL) {
		if (l->info == val)
			return l;
		l = l->next;
	}
	return l;
}

/* LENGHT */

/* I don't think there's something to explain here, once you have understood all the
 * others functions. This one will increase a counter variable until the pointer points
 * to NULL. Then it return this counter variable.
 */
int lengthList (IntList l) {
	int res = 0;
	while (l != NULL) {
		res += 1;
		l = l->next;
	}
	return res;
}
