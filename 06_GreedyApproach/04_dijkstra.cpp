#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

// ==================== Dijkstra ====================



typedef struct {
	int weight;
	int v1;
	int v2;
} edge;

#define  MAX 10001
#define  INF 10000001

int n;
int W[MAX][MAX];
int f_index = -1;

void dijkstra(int n, edge *F) {
	int vnear;
	edge e;

	int touch[n + 1];
	int length[n + 1];

	for (int i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}

	int sum = 0;
	while (1) {
		int min = INF;
		for (int i=2; i <= n; i++) {
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		}
		e.v1 = touch[vnear];
		e.v2 = vnear;
		F[++f_index] = e;
		for (int i = 2; i <= n; i++) {
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}

		length[vnear] = -touch[vnear];

		if (f_index == n - 1)
			break;
	}
}

void add(int v1, int v2, int w) {
	W[v1][v2] = w;
}

void solution() {
	int num_node;
	int node, b, c;
	int v, w;

	cin >> num_node;
	n = num_node;
	edge F[n];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = INF;
		}
	}
	
	for (int j = 0; j < num_node; j++) {
		cin >> node >> b;
		for (int k = 0; k < b; k++) {
			cin >> v >> w;

			add(node, v, w);
		}
	}
	

	dijkstra(n, F);

	int sum = 0;
	for (int i = 0; i < f_index; i++) {
		// printf("%d -> %d: %d\n", F[i].v1, F[i].v2, W[F[i].v1][F[i].v2]);
		sum += W[F[i].v1][F[i].v2];
	}
	f_index = -1;
	printf("%d\n", sum);
}

int main() {
	int num_test_case = 0;
	cin >> num_test_case;
	for (int i = 0; i < num_test_case; i++)	{
		solution();
	}

	return 0;
}

// EOF
