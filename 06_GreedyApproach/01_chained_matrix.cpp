#include <iostream>
#include <cstring>

using namespace std;

// ==================== Chained Matrix Mul ====================

#define MAX_LENGTH 101
#define MIN(a, b) ((a)<(b)?(a):(b))

int M[MAX_LENGTH][MAX_LENGTH];
int P[MAX_LENGTH][MAX_LENGTH];
int d[MAX_LENGTH];

int MM(int n, int d[]) {
	int i, j, k, diagonal;
	// int M[1..n][1..m]; // global variable

	int cmp;
	int min = 2147483647;
	int saved_k;

	for (i = 1; i <= n ; i++) {
		M[i][i] = 0;
	}
	for (diagonal = 1; diagonal <= n ; diagonal++) {
		for (i = 1; i <= n-diagonal; i++) {
			j = i + diagonal;
			/* find min */
			min = 2147483647;
			for (int k = i; k <= j-1 ; k++) {
				cmp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
				if(cmp < min) {
					min = cmp;
					saved_k = k;
				}
			}
			M[i][j] = min;
			P[i][j] = saved_k;
		}
	}

	return M[1][n];
}

void order(int i, int j) {
	if(i == j) {
		printf("A%d", i);
	} else {
		int k = P[i][j];
		printf("(");
		order(i, k);
		order(k+1, j);
		printf(")");
	}
}

int main() {
	int nums = 0;
	int len;

	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> len;
		for (int j = 0; j < len+1; j++) {
			cin >> d[j];
		}
		printf("%d\n", MM(len, d));
		order(0, len);
	}

	return 0;
}

// EOF
