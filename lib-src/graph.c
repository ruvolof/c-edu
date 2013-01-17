#include "queue.h"
#include "stack.h"

typedef struct graphIntNode {
	int out;
	IntList adjacency;
} *IntGraphNode;

typedef struct intGraph {
	int n;
	int a;
	IntGraphNode *nodes;
} *IntGraph;

IntGraph newIntGraph () {
	IntGraph new = (IntGraph) malloc(sizeof(IntGraph));
	new->n = 0;
	new->a = 0;
	new->nodes = NULL;
	return new;
}

void addIntGraphNode (IntGraph *g) {
	(*g)->n++;
	if ((*g)->nodes == NULL)
		(*g)->nodes = (IntGraphNode*) malloc(sizeof(IntGraphNode) * (*g)->n);
	else
		(*g)->nodes = (IntGraphNode*) realloc((*g)->nodes, sizeof(IntGraphNode) * (*g)->n);
	(*g)->nodes[(*g)->n - 1] = (IntGraphNode) malloc(sizeof(IntGraphNode));
	(*g)->nodes[(*g)->n - 1]->adjacency = NULL;
}

void addIntGraphArc (IntGraph *g, int src, int dst) {
	if (src <= (*g)->n - 1 && dst <= (*g)->n - 1 && src != dst) {
		IntList l = (*g)->nodes[src]->adjacency;
		while (l != NULL && l->next != NULL && l->info != dst)
			l = l->next;
		if (l == NULL) {
			(*g)->a++;
			(*g)->nodes[src]->adjacency = insertIntListTail((*g)->nodes[src]->adjacency, dst);
		}
		else if (l->info != dst) {
			(*g)->a++;
			l = insertIntListTail(l, dst);
		}
	}
}

void dumpIntGraph (IntGraph g, char *name) {
	printf("Graph %s (\n", name);
		if (g == NULL)
			printf("\tVOID\n)");
		else {
			int i;
			printf("\t#Node\t=\t%d\n", g->n);
			printf("\t#Arc\t=\t%d\n", g->a);
			printf("\tAdjacency Lists:\n");
			for (i = 0; i < g->n; i++) {
				printf("\t%d\t=>\t", i);
				printIntList(g->nodes[i]->adjacency);
			}
		}
	printf(")\n");
}

void BFSIntGraph (IntGraph g, int src) {
	IntList queue = NULL, temp = NULL, u = NULL;
	int *visited, i;
	visited = (int*) malloc(sizeof(int) * g->n);
	for (i = 0; i < g->n; i++)
		visited[i] = 0;
	queue = enqueueQueueIntList(queue, src);
	while (!emptyQueueIntList(queue)) {
		queue = dequeueQueueIntList(queue, &u);
		if (!visited[u->info]) {
			visited[u->info] = 1;
			printf("%d ", u->info);
			temp = g->nodes[u->info]->adjacency;
			while (temp != NULL) {
				queue = enqueueQueueIntList(queue, temp->info);
				temp = temp->next;
			}
		}
	}
	printf("\n");	
}

void DFSIntGraphRecursion(IntGraph g, int src, int *visited) {
	IntList temp = g->nodes[src]->adjacency;
	visited[src] = 1;
	printf("%d ", src);
	while (temp != NULL) {
		if (!visited[temp->info])
			DFSIntGraphRecursion(g, temp->info, visited);
		temp = temp->next;
	}
}

void DFSIntGraph (IntGraph g) {
	int *visited, i;
	visited = (int*) malloc(sizeof(int) * g->n);
	for (i = 0; i < g->n; i++)
		visited[i] = 0;
	for (i = 0; i < g->n; i++) {
		if (!visited[i]) DFSIntGraphRecursion(g, i, visited);
	}
	printf("\n");
}
	


