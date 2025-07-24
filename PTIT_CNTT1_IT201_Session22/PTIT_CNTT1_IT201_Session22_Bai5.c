#include <stdio.h>
int matrix[100][100];
void addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

int countV(int k, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[k][i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, v;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    printf("nhap so canh: ");
    scanf("%d", &v);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    printf("nhap canh: ");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }
    int k;
    printf("nhap k: ");
    scanf("%d", &k);
    int result = countV(k, n);
    printf("so lien ke voi %d la: %d", k, result);
    return 0;
}