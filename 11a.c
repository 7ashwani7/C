// Representation of Graph using Adjacency Matrix, Adjacency List
#include <stdio.h>

void initMatrix(int arr[5][5], int v) {
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            arr[i][j] = 0;
}

void addEdgeMatrix(int arr[5][5], int u, int v) {
    arr[u][v] = 1;
    arr[v][u] = 1; // For undirected graph
}

void printMatrix(int arr[5][5], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int v = 5;
    int adjMatrix[5][5];

    initMatrix(adjMatrix, v);
    addEdgeMatrix(adjMatrix, 0, 1);
    addEdgeMatrix(adjMatrix, 0, 4);
    addEdgeMatrix(adjMatrix, 1, 2);
    addEdgeMatrix(adjMatrix, 1, 3);
    addEdgeMatrix(adjMatrix, 3, 4);

    printf("Adjacency Matrix:\n");
    printMatrix(adjMatrix, v);

    return 0;
}