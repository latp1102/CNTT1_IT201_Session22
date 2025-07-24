#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int vertex;
    struct Graph* next;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertex = vertices;
    graph->next = NULL;
    return graph;
}

Graph* addEdge(Graph* head, int v) {
    Graph* current = createGraph(v);
    if (head == NULL) {
        head = current;
    } else {
        Graph* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = current;
    }
}

void convert(int matrix[][100], Graph* graph[], int n) {
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                graph[i] = addEdge(graph[i], j);
            }
        }
    }
}

void printMatrix(Graph* graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Graph* temp = graph[i];
        while (temp != NULL) {
            printf(" %d ", temp->vertex);
            temp = temp->next;
        }
        printf("->NULL\n");
    }
}
int matrix[100][100];
int main() {
    Graph* graph[100];
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);

    printf("nhap ma tran: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    convert(matrix, graph, n);
    printMatrix(graph, n);
    return 0;
}