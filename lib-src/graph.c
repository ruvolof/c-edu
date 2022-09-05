#include <stdlib.h>
#include <stdio.h>
#include "../include/graph.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/queue.h"

IntGraph* newIntGraph() {
	IntGraph* new = (IntGraph*)malloc(sizeof(IntGraph));
	new->node_count = 0;
	new->arc_count = 0;
	new->nodes = NULL;
	return new;
}

void freeIntGraph(IntGraph* graph) {
	for (int i = 0; i < graph->node_count; i++) {
		freeList(graph->nodes[i]->adjacency_list);
		free(graph->nodes[i]);
	}
	free(graph);
}

void addIntGraphNode(IntGraph* graph, int label) {
	graph->node_count++;
	if (graph->nodes) {
		graph->nodes = (IntGraphNode**)realloc(graph->nodes,
																				   sizeof(IntGraphNode*) * graph->node_count);
	}
	else {
		graph->nodes = (IntGraphNode**)malloc(sizeof(IntGraphNode*));
	}
	int last = graph->node_count - 1;
	graph->nodes[last] = (IntGraphNode*)malloc(sizeof(IntGraphNode));
	graph->nodes[last]->label = label;
	graph->nodes[last]->adjacency_list = NULL;
}

IntGraphNode* findIntGraphNode(IntGraph* graph, int label) {
	IntGraphNode* found = NULL;
	int i = 0;
	while (!found && i < graph->node_count) {
		if (graph->nodes[i]->label == label) {
			found = graph->nodes[i];
		}
		i++;
	}
	return found;
}

void addIntGraphArc(IntGraph* graph, int src, int dst, int bidir) {
	IntGraphNode* src_node = findIntGraphNode(graph, src);
	IntGraphNode* dst_node = findIntGraphNode(graph, dst);
	if (src_node && dst_node) {
		src_node->adjacency_list = insertIntListHead(src_node->adjacency_list, dst);
		if (bidir) {
			dst_node->adjacency_list = insertIntListHead(dst_node->adjacency_list, src);
		}
	}
}

void dumpIntGraph (IntGraph* graph) {
	for (int i = 0; i < graph->node_count; i++) {
		printf("%d -> ", graph->nodes[i]->label);
		printIntList(graph->nodes[i]->adjacency_list);
		printf("\n");
	}	
}

void BFSIntGraph(IntGraph* graph, int src) {
	IntChainingHashSet* visited = newIntChainingHashSet(graph->node_count * 10);
	IntQueue queue = NULL;
	pushIntQueue(&queue, src);
	while (!isEmptyQueue(queue)) {
		IntPtr current_node = popIntQueue(&queue);
		if (!searchIntChainingHashSet(visited, *current_node)) {
			printf("%d-", *current_node);
			addIntChainingHashSet(visited, *current_node);
			IntList neighbour = graph->nodes[*current_node]->adjacency_list;
			while (neighbour) {
				pushIntQueue(&queue, neighbour->val);
				neighbour = neighbour->next;
			}
		}
	}
	freeIntChainingHashSet(visited);
}

void DFSIntGraph(IntGraph* graph, int src, IntChainingHashSet* visited) {
	int free_visited = 0;
	if (!visited) {
		visited = newIntChainingHashSet(graph->node_count * 10);
		free_visited = 1;
	}
	addIntChainingHashSet(visited, src);
	printf("%d-", src);
	IntList src_neighbour = graph->nodes[src]->adjacency_list;
	while (src_neighbour) {
		if (!searchIntChainingHashSet(visited, src_neighbour->val)) {
			DFSIntGraph(graph, src_neighbour->val, visited);
		}
		src_neighbour = src_neighbour->next;
	}
	if (free_visited) {
		freeIntChainingHashSet(visited);
	}
}
	


