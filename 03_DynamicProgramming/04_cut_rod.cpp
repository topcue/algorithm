#include <iostream>
#include <vector>
#include <algorithm>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define MAX_SIZE 10000
#define MAX_INTEGER 2147483647

using namespace std;

int A[MAX_SIZE+2];

void cut(int A[], int l) {
	int j = 0;
	vector<vector<int>> dp(l, vector<int>(l));

	for (int t = 2; t < l; t++) {
		for (int i = 0; i + t < l; i++) {
			j = i + t;
			dp[i][j] = MAX_INTEGER;
			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j], A[j]-A[i] + dp[i][k] + dp[k][j]);
		}
	}

	printf("%d\n", dp[0][l-1]);
}

void solution(int n, int A[], int l) {
	// preprocess
	for (int i = l; i > 0; i--) {
		A[i] = A[i-1];
	}
	A[0] = 0;
	A[l+1] = n;
	l += 2;

	cut(A, l);
}

int main() {
	int nums = 0;
	int a, b;
	cin >> nums;
	
	for (int i = 0; i < nums; i++) {
		cin >> a;
		cin >> b;
		for (int j = 0; j < b; j++) {
			cin >> A[j];
		}
		solution(a, A, b);
	}

	return 0;
}

// EOF
