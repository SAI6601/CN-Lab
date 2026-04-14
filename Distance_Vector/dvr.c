#include <stdio.h>
#define INF 9999
#define MAX 10

int dist[MAX][MAX], next_hop[MAX][MAX];
int n;

void dvr_algorithm() {
    int updated = 1;
    while (updated) {
        updated = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            next_hop[i][j] = k;
                            updated = 1;
                        }
                    }
                }
            }
        }
    }

    printf("\nFinal Routing Tables:\n");
    for (int i = 0; i < n; i++) {
        printf("State value for router %d is:\n", i + 1);
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("\tNode %d: Unreachable\n", j + 1);
            else
                printf("\tNode %d: Distance %d\n", j + 1, dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (9999 for no link):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    dvr_algorithm();
    return 0;
}
