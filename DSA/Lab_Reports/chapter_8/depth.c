#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int n;             // Number of vertices

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, v1, v2, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1; // For undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Depth First Search starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}