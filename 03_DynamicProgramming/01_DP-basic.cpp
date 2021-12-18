#include <iostream>

// ==================== Fcatorial ====================

// factorial: Top-down
int fact1(int n) {
	if(n <= 1)  return 1;
	else        return n * fact1(n-1);
}

// factorial: Bottom-up
int fact2(int n) {
	int Fact[100];

	Fact[0] = 1; /* base case */

	for (int i = 1; i <= n; i++)
		Fact[i] = i * Fact[i-1];

	return Fact[n];
}

void ex_fact() {
	printf("%d\n", fact1(4));
	printf("%d\n", fact2(4));
}

// ==================== Fibonacci ====================

// fibonacci: Top-down
int fibo1(int n) {
	if (n <= 1) { /* base case */
		return n;
	} else { /* recursive step */
		return fibo1(n-1) + fibo1(n-2);
	}
}

// fibonacci: Bottom-up
int fibo2(int n) {
	int Fib[100];

	Fib[0] = 0; /* base case */
	Fib[1] = 1;

	for (int i = 2; i <= n; i++) {
		Fib[i] = Fib[i-1] + Fib[i-2];
	}

	return Fib[n];
}

void ex_fibo() {
	printf("%d\n", fibo1(4));
	printf("%d\n", fibo2(4));
}

int main() {
	// ex_fact();
	ex_fibo();

	return 0;
}

// EOF
