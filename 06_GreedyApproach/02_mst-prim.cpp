#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> parii;
typedef priority_queue<parii, vector<parii>, greater<parii>> mypq;

int sum;
vector<vector<parii>> edge(100001);
mypq pq;
bool visited[100001];

void prim(int n) {
	visited[n] = true;
	
	for(auto e: edge[n]) {
		if(!visited[e.second]) {
			pq.push({e.first, e.second});
		}
	}

	while(!pq.empty()) {
		parii w = pq.top();
		pq.pop();
		if(!visited[w.second]) {
			sum += w.first;
			prim(w.second);

			break;
		}
	}
}

void clearMyDS(int num_node) {
	sum = 0;
	
	// vector<vector<parii>>().swap(edge);	
	for (int i = 0; i < num_node; ++i) {
		edge[i].clear();
	}

	mypq empty;
	std::swap(pq, empty);

	for (int i = 0; i < 100001; ++i)	{
		visited[i] = false;
	}
}

void add(int v1, int v2, int w) {
	edge[v1-1].push_back(make_pair(w, v2-1));
}

void solution() {
	int num_node;
	int node, b, c;
	int v, w;

	cin >> num_node;
	for (int j = 0; j < num_node; j++) {
		cin >> node >> b;
		for (int k = 0; k < b; k++) {
			cin >> v >> w;
			
			add(node, v, w);
			add(v, node, w);
		}
	}

	prim(1);
	printf("%d\n", sum);

	clearMyDS(num_node);
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
