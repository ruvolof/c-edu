/*      queue.h
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

/* NEEDED LIBRARIES */

/* We need 'list.h' because we are going to implement stack with list. */


/* PUSH AN ELEMENT TO STACK INT LIST */

/* As long as the stack is a LIFO (Last In First Out) structure, we can always add
 * an element to the head of the list. In this way we can use O(1) time for both
 * principal action on a stack: push and pop.
 */
IntList enqueueQueueIntList (IntList l, int val) {
	IntList new = insertIntListTail(l, val);
	return new;
}

/* POP AN ELEMENT FROM A STACK INT LIST */

/* We have to take the first element and we can achieve this purpose, thanks to
 * the function removeIntListByPosition. Remember that the head is the position 0.
 */
IntList dequeueQueueIntList (IntList l, IntList *ret) {
	IntList new = removeIntListByPosition(l, 0, ret);
	return new;
}

/* EMPTY */

/* Check if a stack is empty. It's empty if the pointer of the first element points to NULL. */
int emptyQueueIntList (IntList l) {
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* TOP */

/* Is similar to POP, but it doesn't remove the element. For us, this is simple as
 * return the first element of the list after setting its field 'next' to NULL.
 */
