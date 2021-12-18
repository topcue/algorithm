#include <iostream>

using namespace std;

#define MAX 100

int pt[MAX];
int sz[MAX];

// ==================== Union-find ====================

void init(int n) {
	for (int i = 0; i < n; i++) {
		pt[i] = i;
		// weighting
		sz[i] = 1;
	}
}

// path compression
int find(int i) {
	while(pt[i] != i) {
		pt[i] = pt[pt[i]];
		i = pt[i];
	}

	return i;
}

bool in_same_set(int p, int q) {
	return (find(p) == find(q));
}

void _union(int p, int q) {
	int i = find(p);
	int j = find(q);
	if(i != j) {
		/* pt[i] = j; */
		// weighting
		if(sz[i] < sz[j]) {
			pt[i] = j;
			sz[j] += sz[i];
		} else {
			pt[j] = i;
			sz[i] += sz[j];
		}
	}

}

int main() {

	return 0;
}

// EOF
