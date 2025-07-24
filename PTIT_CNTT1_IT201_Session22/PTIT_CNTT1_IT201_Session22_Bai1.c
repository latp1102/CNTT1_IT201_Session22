#include <stdio.h>

int printArr(int matrix[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int matrix[][100], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

int printMatrix(int matrix[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int matrix[100][100];
int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 3, 2);
    addEdge(matrix, 1, 3);
    addEdge(matrix, 3, 4);
    printMatrix(matrix, n);
    return 0;
}