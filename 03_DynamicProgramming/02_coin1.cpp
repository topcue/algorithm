#include <iostream>
#define MAX_SIZE 10000

using namespace std;

int arr[MAX_SIZE];
int lastCoin[MAX_SIZE];   // S[]: 이전에 추가된 코인의 종류.
int coinsUsed[MAX_SIZE];  // C[]: 이전에 추가된 코인의 개수.

/*
	coins[]: 동전 종류
	numDiffCoins: 동전 종류의 개수
	change: 거스름돈
*/
void coinExchange(int coins[], int numDiffCoins, int change) {
	/* coinsUsed = C, lastCoin = S */
	coinsUsed[0] = lastCoin[0] = 0;

	// Bottom-up
	for(int cents = 1; cents <= change; cents++) {
		int minCoins, newCoin;
		
		minCoins = cents;
		newCoin = 1;

		for (int j = 0; j < numDiffCoins; j++) {
			if(coins[j] > cents)
				continue;
			if (coinsUsed[cents-coins[j]] + 1 < minCoins) {
				minCoins = coinsUsed[cents-coins[j]] + 1;
				newCoin = coins[j];
			}
		}
		coinsUsed[cents] = minCoins;
		lastCoin[cents] = newCoin;
	}
	printf("%d\n", coinsUsed[change]);
}


/* coinsUsed = C, lastCoin = L */
void reconstruct(int change, int lastCoin[]) {
	if(change > 0) {
		reconstruct(change-lastCoin[change], lastCoin);
		printf("%d ", lastCoin[change]);
	}
}

void solution(int coins[], int numDiffCoins, int change) {
	coinExchange(coins, numDiffCoins, change);
	reconstruct(change, lastCoin);
	printf("\n\n");
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
