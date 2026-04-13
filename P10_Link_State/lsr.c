#include <stdio.h>

#define INF 9999

#define MAX 10

int main() {

int n, i, j, src;

int cost[MAX][MAX], dist[MAX], visited[MAX];

printf("Enter number of nodes: ");

scanf("%d", &n);

printf("Enter cost matrix (use 9999 for no link):
");

for (i = 0; i < n; i++)

for (j = 0; j < n; j++)

scanf("%d", &cost[i][j]);

printf("Enter source node (0 to %d): ", n - 1);

scanf("%d", &src);

for (i = 0; i < n; i++) {

dist[i] = cost[src][i];

visited[i] = 0;

}

visited[src] = 1;

dist[src] = 0;

for (i = 1; i < n; i++) {

int min = INF, u = -1;

for (j = 0; j < n; j++) {

if (!visited[j] && dist[j] < min) {

min = dist[j];

u = j;

}

}

visited[u] = 1;

for (j = 0; j < n; j++) {

if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {

dist[j] = dist[u] + cost[u][j];

}

}

}

printf("
Shortest paths from node %d:
", src);

for (i = 0; i < n; i++) {

printf("To node %d cost = %d
", i, dist[i]);

}

return 0;

}
