#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = (i == j ? 0 : INF);
        }
    }

    printf("Enter each edge as: u v w (1-based indices)\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;  
        adj[u][v] = w;
        adj[v][u] = w;
    }


    int s, t;
    printf("Enter start and end vertices: ");
    scanf("%d %d", &s, &t);
    s--; t--;

    
    int dist[n], used[n], prev[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        used[i] = 0;
        prev[i] = -1;
    }
    dist[s] = 0;

    for (int it = 0; it < n; it++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        if (u == -1 || dist[u] == INF) {
            break;
        }
        used[u] = 1;
        for (int v = 0; v < n; v++) {
            int w = adj[u][v];
            if (w < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }


    if (dist[t] == INF) {
        printf("No path exists from %d to %d\n", s + 1, t + 1);
    } else {
        printf("Shortest path length: %d\n", dist[t]);
        int stack[n], top = 0;
        for (int cur = t; cur != -1; cur = prev[cur]) {
            stack[top++] = cur;
        }
        printf("Path: ");
        for (int i = top - 1; i >= 0; i--) {
            printf("%d", stack[i] + 1);
            if (i) printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}

