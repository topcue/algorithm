#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_SIZE  10001
#define BASE_CHAR 'A'

#define ATOI(X) X-BASE_CHAR

// int ATOI(int X) {
//  if(X < 'A' || X > 'C') {
//      printf("ATOI err!!\n");
//      printf("X: %c, %d\n", X, X);
//  }
//  return (X-BASE_CHAR);
// }

// ==================== String Match ====================

/*
3
ABABABAC ABCABAABABABACACA
AAAAA AAAAAAAAAA
ABCABCABC CBACBACBACBACBA

13 1
6 6
16 0
*/

int DFA[MAX_SIZE][MAX_SIZE] = {0x00, };

/* text character set size */
int R = 3;

void constructDFA(char pattern[]) {
	int X, j;
	int patLength = strlen(pattern);

	DFA[ATOI(pattern[0])][0] = 1;

	for (X=0, j=1; j < patLength; j++) {
		for (int c = 0; c < R; c++) {
			DFA[c][j] = DFA[c][X];
		}

		DFA[ATOI(pattern[j])][j] = j+1;
		X = DFA[ATOI(pattern[j])][X];
	}

	for (int c = 0; c < R; c++) {
		DFA[c][j] = DFA[c][X];
	}

	// print
	int cnt = 0;
	for (int i = 0; i <= strlen(pattern); i++) {
		for (int j = 0; j < R; j++) {
			// printf("%d ", DFA[j][i]);
			if(DFA[j][i] != 0) {
				cnt++;
			}
		}
		// printf("\n");
	}
	// printf("\n");
	printf("%d ", cnt);

}

// KMP w/ DFA
int kmp(char text[], char pattern[]) {
	int i, j, txtLength, patLength;

	txtLength = strlen(text);
	patLength = strlen(pattern);

	// i <= txtLength
	for (i=0, j=0; i < txtLength && j < patLength; i++) {
	// for (i=idx, j=0; i < txtLength && j < patLength; i++) {
		// text[i] to be modified
		j = DFA[ATOI(text[i])][j];
	}

	if(j == patLength) {
		return (i - patLength);
	} else {
		return -1;
	}
}


void solution() {
	int a=0, ret, cnt=0;
	char text[MAX_SIZE];
	char pattern[MAX_SIZE];

	cin >> pattern >> text;

	constructDFA(pattern);
	
#if 0
	int k = 0, answer=0;
	int result_1 = 0;
	int result = kmp(text, pattern, 0);

	if (result != -1)
		answer = 1;
	for (int k = 1; k <= strlen(text) - strlen(pattern); k++) {
		result_1 = kmp(text, pattern, k);
		//cout << "result : " << result << endl;
		if (result != result_1 && result_1 != -1)
			answer++;
		result = result_1;
	}
	printf("%d\n", answer);
#endif

#if 1
	ret = kmp(text, pattern);
	while(ret != -1) {
		a = a+ret+1;
		ret = kmp(&text[a], pattern);
		cnt++;
	}
	printf("%d\n", cnt);
#endif

	// clear DFA
	for (int i = 0; i <= strlen(pattern); i++) {
		for (int j = 0; j < R; j++) {
			DFA[j][i] = 0;
		}
	}
}


int main() {
	int num_test_case = 0;
	cin >> num_test_case;
	for (int i = 0; i < num_test_case; i++) {
		solution();
	}
	
	return 0;
}

// EOF
