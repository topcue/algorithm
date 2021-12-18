#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_SIZE  10001
#define BASE_CHAR 'A'

// #define ATOI(X) X-BASE_CHAR

int ATOI(int X) {
	if(X < 'A' || X > 'C') {
		printf("ATOI err!!\n");
		printf("X: %c, %d\n", X, X);
	}
	return (X-BASE_CHAR);
}

// ==================== KMP-FAIL ====================

/*
3
ABABABAC ABCABAABABABACACA
AAAAA AAAAAAAAAA
ABCABCABC CBACBACBACBACBA


0 0 1 2 3 4 5 0
1
0 1 2 3 4
6
0 0 0 1 2 3 4 5 6
0
*/

vector<int> getFail(string pattern) {
	int m = (int)pattern.size();
	int j = 0;
	vector<int> fail(m, 0);

	for (int i = 1; i < m; i++) {
		while(j > 0 && pattern[i] != pattern[j])
			j = fail[j-1];
		if(pattern[i] == pattern[j])
			fail[i] = ++j;
	}

	/* Print fail function */
	for (const auto &item : fail) {
		cout << item << " ";
	}
	cout << endl;

	return fail;
}

vector<int> kmp_fail(string text, string pattern) {
	vector<int> ans;
	vector<int> fail = getFail(pattern); // fail function
	int n = (int)text.size();
	int m = (int)pattern.size();
	int i = 0; // i: index of text
	int j = 0; // j: index of pattern 

	for (i = 0; i < n; i++) {
		// sliding
		while(j > 0 && text[i] != pattern[j])
			j = fail[j-1];

		if(text[i] == pattern[j]) {
			// pattern matching is found
			if(j == m-1) {
				// save the matched position
				ans.push_back(i-j);
				j = fail[j];
			} else {
				j++;
			}
		}
	}
	return ans;
}

void solution() {
	vector<int> ret;
	string text, pattern;

	cin >> pattern >> text;
	ret = kmp_fail(text, pattern);

	/* Print number of patterns in text */
	cout << ret.size() << endl;
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
