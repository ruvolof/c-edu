#ifndef graph_lib
#define graph_lib

#include "../include/hash.h"
#include "../include/list.h"

typedef struct intGraphNode {
	int label;
	IntList adjacency_list;
} IntGraphNode;

typedef struct intGraph {
	int node_count;
	int arc_count;
	IntGraphNode** nodes;
} IntGraph;

extern IntGraph* newIntGraph();

extern void freeIntGraph(IntGraph* graph);

extern void addIntGraphNode(IntGraph* graph, int label);

extern void addIntGraphArc(IntGraph* graph, int src, int dst, int bidir);

extern void dumpIntGraph(IntGraph* graph);

extern void BFSIntGraph(IntGraph* graph, int src);

extern void DFSIntGraph(IntGraph* graph, int src, IntChainingHashSet* visited);

#endif
