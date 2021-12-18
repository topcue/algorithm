#include <iostream>
#include <cstring>

using namespace std;

// ==================== LCS(Longest Common Subsequence) ====================

#define MAX_LENGTH 101
#define MAX(a, b) ((a)>(b)?(a):(b))

int L[MAX_LENGTH][MAX_LENGTH];
int S[MAX_LENGTH][MAX_LENGTH];

/*
	sequence s (len = m)
	sequence t (len = n)
*/
int lengthLCS(char s[], char t[], int m, int n) {
	/* base cases */
	for (int i = 0; i <= m; i++)
		L[i][0] = 0;
	for (int i = 0; i <= n; i++)
		L[0][i] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(s[i-1] == t[j-1]) {
				L[i][j] = L[i-1][j-1]+1;
				S[i][j] = 0;
			}
			else {
				L[i][j] = MAX(L[i][j-1], L[i-1][j]);
				if(L[i][j] == L[i][j-1])
					S[i][j] = 1;
				else
					S[i][j] = 2;
			}
		}
	}

	return L[m][n];
}

void printLCS(char s[], char t[], int m, int n) {
	if(m == 0 || n == 0)
		return;
	if(S[m][n] == 0) {
		printLCS(s, t, m-1, n-1);
		printf("%c", s[m-1]);
	} else if (S[m][n] == 1) {
		printLCS(s, t, m, n-1);
	} else if (S[m][n] == 2) {
		printLCS(s, t, m-1, n);
	}
}

int main() {
	int nums = 0;
	char s[MAX_LENGTH];
	char t[MAX_LENGTH];

	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> s >> t;
		printf("%d\n", lengthLCS(s, t, strlen(s), strlen(t)));
	}

	return 0;
}

// EOF
