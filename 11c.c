// Graph DFS
#include <stdio.h>

#define MAX 10

void dfs(int adj[MAX][MAX], int visited[MAX], int v, int current) {
    visited[current] = 1;
    printf("%d ", current);


    for (int i = 0; i < v; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(adj, visited, v, i);
        }
    }
}

int main() {
    int v = 5;
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};

    // Creating a sample graph
    // 0-1, 0-2, 1-3, 1-4, 2-4
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("DFS Traversal starting from vertex 0: ");
    dfs(adj, visited, v, 0);
    printf("\n");

    return 0;
}