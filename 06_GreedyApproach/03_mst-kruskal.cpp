#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define edge pair<int, int>

class Graph {
private:
	vector<pair<int, edge> > T;  // Y
	vector<pair<int, edge> > G;  // V-Y
	int* pt;
	int* sz;
	int num_node;

public:
	Graph(int num_node);
	void add(int v1, int v2, int w);
	int Find(int i);
	void Union(int u, int v);
	void kruskal();
	void print();
	int mst();
};

Graph::Graph(int num_node) {

	// union-find init
	pt = new int[num_node];
	sz = new int[num_node];

	for (int i = 0; i < num_node; i++) {
		pt[i] = i;
		sz[i] = 1;
	}

	G.clear();
	T.clear();
}

void Graph::add(int v1, int v2, int w) {
	G.push_back(make_pair(w, edge(v1, v2)));
}

int Graph::Find(int i) {
	// find w/ path compression
	while(pt[i] != i) {
		pt[i] = pt[pt[i]];
		i = pt[i];
	}
	return i;
	// if (i == pt[i])
	// 	return i;
	// else
	// 	return Find(pt[i]);
}

void Graph::Union(int p, int q) {
	int i = Find(p);
	int j = Find(q);
	if(i != j) {
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

void Graph::kruskal() {
	int p, q;

	sort(G.begin(), G.end());

	for (int i = 0; i < G.size(); i++) {
		p = Find(G[i].second.first);
		q = Find(G[i].second.second);
		if (p != q) {
			T.push_back(G[i]);
			Union(p, q);
		}
	}
}

void Graph::print() {
	for (int i = 0; i < T.size(); i++) {
		printf("%d-%d:%d\n", T[i].second.first, T[i].second.second, T[i].first);
	}
}

int Graph::mst() {
	int sum = 0;
	for (int i = 0; i < T.size(); i++) {
		sum += T[i].first;
	}
	return sum;
}

void solution() {
	int num_node;
	int node, b;
	int v, w;

	cin >> num_node;
	Graph g(num_node);

	for (int j = 0; j < num_node; j++) {
		cin >> node >> b;
		for (int k = 0; k < b; k++) {
			cin >> v >> w;
			
			g.add(node-1, v-1, w);
			g.add(v-1, node-1, w);
		}
	}	
	
	g.kruskal();
	// g.print();
	printf("%d\n", g.mst());
}

int main() {
	int num_test_case;

	cin >> num_test_case;
	for (int i = 0; i < num_test_case; i++) {
		solution();
	}

	return 0;
}

// EOF
