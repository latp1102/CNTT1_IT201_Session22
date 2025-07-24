#include <stdio.h>

int countEdge(int matrix[][100], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int matrix[100][100];
int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    printf("nhap ma tran: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int result = countEdge(matrix, n);
    printf("%d", result);
    return 0;
}