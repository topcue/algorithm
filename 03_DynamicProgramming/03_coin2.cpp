#include <iostream>


#define MAX_SIZE 10000

using namespace std;

int arr[MAX_SIZE];
int N[MAX_SIZE][MAX_SIZE];

void countCoinExchange(int coins[], int numDiffCoins, int change) {
	int i, j, numComb;

	/* preprocess */
	for(i = numDiffCoins; i > 0; i--) {
		coins[i] = coins[i-1];
	}

	/* base cases */
	for (i = 1; i <= numDiffCoins; i++) {
		N[i][0] = 1;
	}
	for (i = 1; i <= change; i++) {
		N[0][i] = 0;
	}

	for (i = 1; i <= numDiffCoins; i++) {
		for(j = 1; j <= change; j++) {
			if (j - coins[i] < 0) { /* base case */
				numComb = 0;
			} else {
				numComb = N[i][j-coins[i]];
			}
			N[i][j] = N[i-1][j] + numComb;
			
		}
	}
	/* step 4. */
	// for(i = 0; i <= numDiffCoins; i++) {
	// 	for(j = 0; j <= change; j++) {
	// 		printf("%d ", N[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", N[numDiffCoins][change]);
}

void solution(int coins[], int numDiffCoins, int change) {
	countCoinExchange(coins, numDiffCoins, change);
}

int main() {
	int n = 0;
	int change;
	int numDiffCoins;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> change;
		cin >> numDiffCoins;
		for (int j = 0; j < numDiffCoins; j++) {
			cin >> arr[j];
		}
		solution(arr, numDiffCoins, change);
	}

	return 0;
}

// EOF
