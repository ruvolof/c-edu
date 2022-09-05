#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/list.h"

int main() {
	IntGraph* graph = newIntGraph();

  printf("Adding nodes with label 0-9.\n");
  for (int i = 0; i < 10; i++) {
    addIntGraphNode(graph, i);
  }
  assert(graph->node_count == 10);
  for (int i = 0; i < 10; i++) {
    assert(graph->nodes[i]);
  }

  printf("Adding arcs from node 0 to x < 5.\n");
  for (int i = 1; i < 5; i++) {
    addIntGraphArc(graph, 0, i, 0);
    assert(searchIntList(graph->nodes[0]->adjacency_list, i));
  }
  assert(getListLength(graph->nodes[0]->adjacency_list) == 4);

  printf("Adding arcs from node 3 to 5 <= x < 10.\n");
  for (int i = 5; i < 10; i++) {
    addIntGraphArc(graph, 3, i, 0);
    assert(searchIntList(graph->nodes[3]->adjacency_list, i));
  }
  assert(getListLength(graph->nodes[3]->adjacency_list) == 5);

  dumpIntGraph(graph);

  BFSIntGraph(graph, 0);
  printf("\n");
  DFSIntGraph(graph, 0, NULL);
  printf("\n");

  freeIntGraph(graph);
}
