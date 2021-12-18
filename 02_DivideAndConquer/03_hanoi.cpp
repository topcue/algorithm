#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int iint;

/*
	my_test:
	clang++ a.cpp -g -fsanitize=address -fno-omit-frame-pointer && ./a.out < a.txt
*/

void hanoi(iint n, iint k, iint a=1, iint b=2, iint c=3) {
	if (k == (iint)pow(2, n-1)) {
		printf("%llu %llu\n", a, c);
	}
	else if (k < (iint)pow(2, n-1)) {
		hanoi(n-1, k, a, c, b);
	}
	else {
		hanoi(n-1, k-(iint)pow(2, n-1), b, a, c);
	}
}

void solution(iint n, iint k) {
	hanoi(n, k);
}

int main() {
	iint n, k;
	int test_case_num;

	cin >> test_case_num;
	for (int i = 0; i < test_case_num; i++) {
		cin >> n >> k;
		solution(n, k);
	}
		
	return 0;
}


// EOF
