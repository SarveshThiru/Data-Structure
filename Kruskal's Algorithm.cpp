#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    return graph;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void kruskalMST(struct Graph* graph) {
    int parent[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++)
        parent[i] = i;

    qsort(graph->edges, graph->numEdges, sizeof(struct Edge), compareEdges);

    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < graph->numEdges; i++) {
        int srcParent = findParent(parent, graph->edges[i].src);
        int destParent = findParent(parent, graph->edges[i].dest);

        if (srcParent != destParent) {
            printf("(%d, %d) Weight: %d\n", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
            parent[srcParent] = destParent;
        }
    }
}

int main() {
    int numVertices = 4; // Number of vertices in the graph
    int numEdges = 5; // Number of edges in the graph

    struct Graph* graph = createGraph(numVertices, numEdges);

    // Add edges with their weights
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    kruskalMST(graph);

    return 0;
}
