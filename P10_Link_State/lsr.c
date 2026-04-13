#include <stdio.h>
#define INF 9999
#define MAX 10

int dist[MAX], visited[MAX], cost[MAX][MAX];
int n;

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
        }
    }
}

int main() {
    int src;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use 9999 for no link):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source node (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(src);

    printf("\nShortest paths from node %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To node %d: Unreachable\n", i);
        else
            printf("To node %d cost = %d\n", i, dist[i]);
    }
    return 0;
}
