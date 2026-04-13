#include <stdio.h>

int dist[50][50], n;

void dvr_algorithm() {

int i, j, k, changes;

do {

changes = 0;

for (k = 0; k < n; k++) {

for (i = 0; i < n; i++) {

for (j = 0; j < n; j++) {

if (dist[i][k] + dist[k][j] < dist[i][j]) {

dist[i][j] = dist[i][k] + dist[k][j];

changes = 1;

}

}

}

}

} while (changes);

printf("

Final Routing Tables:
");

for (i = 0; i < n; i++) {

printf("State value for router %d is:
", i + 1);

for (j = 0; j < n; j++) {

printf("\tNode %d: Distance %d
", j + 1, dist[i][j]);

}

printf("
");

}

}

int main() {

int i, j;

printf("
Enter the number of nodes: ");

scanf("%d", &n);

printf("
Enter the distance matrix:
");

for (i = 0; i < n; i++)

for (j = 0; j < n; j++)

scanf("%d", &dist[i][j]);

dvr_algorithm();

return 0;

}
