#ifndef graph
#define graph

typedef struct graphIntNode GraphIntNode;

typedef struct intGraph IntGraph;

IntGraph newIntGraph ();

void addIntGraphNode (IntGraph *g);

void addIntGraphArc (IntGraph *g, int src, int dst);

void dumpIntGraph (IntGraph g, char *name);

void BFSIntGraph (IntGraph g, int src);

void DFSIntGraph (IntGraph g);

#endif
