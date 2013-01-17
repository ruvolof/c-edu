#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/graph.h"

int main() {
	int action, src, dst;
	IntGraph g;
	
	g = newIntGraph();
	
	while (1) {
		printf("0 -> Exit.\n");
		printf("1 -> Add a nodes.\n");
		printf("2 -> Add an arc.\n");
		printf("3 -> Dump the graph.\n");
		printf("4 -> BFS.\n");
		printf("5 -> DFS.\n");
		printf("What do you want to do? [1, 2, 3, 4, 5] ");
		scanf("%d", &action);
		
		switch (action) {
			case 1:
				addIntGraphNode(&g);
				break;
			
			case 2:
				printf("Insert source and destination: ");
				scanf("%d", &src);
				scanf("%d", &dst);
				addIntGraphArc(&g, src, dst);
				break;
			
			case 3:
				dumpIntGraph(g, "GRAPH\0");
				break;
			
			case 4:
				printf("Insert the node to start: ");
				scanf("%d", &src);
				BFSIntGraph(g, src);
				break;
				
			case 5:
				DFSIntGraph(g);
				break;
			
			default:
				return 0;
		}
	}
}
