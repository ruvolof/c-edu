#include <stdio.h>
#include "list.h"

int main() {
	IntList l = NULL;
	IntList search = NULL;
	int i, val, n, length;
	
	printf("Quanti elementi vuoi inserire in testa alla lista? ");
	scanf("%d", &n);
	printf("Inserisci gli elementi: ");
	for (i=0; i<n; i++) {
		scanf("%d", &val);
		l = insertIntListHead(l, val);
	}
	
	printf("Quanti elementi vuoi inserire in coda alla lista? ");
	scanf("%d", &n);
	printf("Inserisci gli elementi: ");
	for (i=0; i<n; i++) {
		scanf("%d", &val);
		l = insertIntListTail(l, val);
	}
	
	printf("Questa è la tua lista:\n");
	printIntList(l);
	
	printf("È lunga %d celle\n", lengthList(l));
	
	printf("Quanti elementi vuoi cercare nella lista? ");
	scanf("%d", &n);
	printf("Inserisci gli elementi: ");
	for (i=0; i<n; i++) {
		scanf("%d", &val);
		search = searchIntList(l, val);
		if (search) 
			printf("TROVATO\n");
		else
			printf("ASSENTE\n");
	}
	
	printf("Quanti elementi vuoi rimuovere? ");
	scanf("%d", &n);
	printf("Inserisci gli elementi da rimuovere: ");
	for (i=0; i<n; i++) {
		scanf("%d", &val);
		l = removeIntList(l, val);
	}
	
	printf("Questa è la lista modificata:\n");
	printIntList(l);
	
	return 0;
}
