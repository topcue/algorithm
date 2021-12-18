#include <iostream>

using namespace std;

// ==================== N-Queen Problem ====================

#define N 4

int col[N];

int isPromising(int row);
void printNqueens(int row);

void nQueens(int row) {

	if(isPromising(row)) {
		if(row == N-1) {
			printNqueens(row);
		} else {
			for (int i = 0; i < N; i++) {
				col[row+1] = i;
				nQueens(row+1);
			}
		}
	}
}

int isPromising(int row) {
	int k = 0;
	int promising = 1;
	
	while(k < row && promising) {
		// 같은 열이거나 대각선인지 확인
		if(col[row] == col[k] || abs(col[row]-col[k]) == row-k)
			promising = 0;
		k++;
	}

	return promising;
}

void printNqueens(int row) {
	// 
}

int main() {
	for (int i = 0; i < N; i++) {
		col[0] = i;
		nQueens(0);
	}
}

// EOF
