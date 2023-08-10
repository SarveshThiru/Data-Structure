#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct GraphNode {
    int vertex;
    int weight;
    struct GraphNode* next;
};

struct Graph {
    struct GraphNode* adjLists[MAX_VERTICES];
};

struct GraphNode* createNode(int vertex, int weight) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct GraphNode* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void dijkstra(struct Graph* graph, int startVertex, int numVertices) {
    int distances[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    distances[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = 1;

        struct GraphNode* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from start vertex %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Distance %d\n", i, distances[i]);
    }
}

int main() {
    struct Graph* graph = createGraph();
    int numVertices = 5; // Number of vertices in the graph
    int startVertex = 0; // Starting vertex for Dijkstra's algorithm

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 2);

    dijkstra(graph, startVertex, numVertices);

    return 0;
}
