// Graph BFS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bfs(int adj[MAX][MAX], int v, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = -1, rear = -1;

    // Mark start node as visited and enqueue it
    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < v; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int v = 5;
    int adj[MAX][MAX] = {0};

    // Creating a sample graph
    // 0-1, 0-2, 1-3, 1-4, 2-4
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    bfs(adj, v, 0);

    return 0;
}