#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int vertex;
    struct Graph *next;
} Graph;

Graph *createGraph(int vertex) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex = vertex;
    graph->next = NULL;
    return graph;
}

void addEdge(Graph* adjList[], int u, int v) {
    Graph* nodeV = createGraph(v);
    if (adjList[u] == NULL) {
        adjList[u] = nodeV;
    } else {
        Graph* current = adjList[u];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nodeV;
    }

    Graph* nodeU = createGraph(u);
    if (adjList[v] == NULL) {
        adjList[v] = nodeU;
    } else {
        Graph* current = adjList[v];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nodeU;
    }
}

void printGraph(Graph* adjList[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        Graph* current = adjList[i];
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    Graph* adjList[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 3, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);
    printGraph(adjList, n);
    return 0;
}