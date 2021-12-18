#include <iostream>

using namespace std;

// ==================== Knight's Toure Problem ====================

#define MAXSIZE 9
#define MARK    1
#define UNMARK  0

typedef struct Point {
	int x;
	int y;
} point;

point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2},
					 {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE];
int path[MAXSIZE][MAXSIZE];

int knightTour (int m, int n, point pos, int counter) {
	int i;
	point next;
	
	if (counter == m * n)
		return 1;

	for (i = 0; i < 8; i++) {
		next.x = pos.x + direction[i].x;
		next.y = pos.y + direction[i].y;
		if (next.x > 0 && next.x <= n &&
		 	next.y > 0 && next.y <= m &&
			board[next.y][next.x] != MARK )
		{
			board[next.y][next.x] = MARK;
			path[next.y][next.x] = counter+1;
			if (knightTour(m, n, next, counter+1) )
				return 1;
			board[next.y][next.x] = UNMARK;
		}
	}

	return 0;
}


int main() {
	int result = -1;

	point init = {0, 0};

	result = knightTour(8, 8, init, 64);
	printf("result: %d\n", result);

	return 0;
}

// EOF
