#include <iostream>

#define MAX_SIZE 100001

using namespace std;
int A[MAX_SIZE];

class MaxHeap {
public:
	int size;
	int data[MAX_SIZE];

	MaxHeap() { 
		size = 0;
	}
	
	int parent(int pos) {
		return (pos-1)/2;
	}
	
	int leftchild(int pos) {
		return pos * 2 + 1;
	}
	
	int rightchild(int pos) {
		return pos * 2 + 2;
	}
	
	bool isleaf(int pos) {
		return pos * 2 + 1 >= size && pos < size;
	}

	void swap(int a, int b) {
		int t = data[a];
		data[a] = data[b];
		data[b] = t;
	}
	
	void siftdown(int n) {
		while(!isleaf(n)) {
			int l = leftchild(n);
			if((data[l] == 0) || (data[l+1] == 0)) {
				return;
			}
			if((l < size-1) && (data[l] < data[l+1])) {
				l++;
			}
			if(data[n] >= data[l]) {
				return;
			}
			swap(n, l);
			n = l;
		}
	}
	
	void insert(int e) {
		int curr = size++;
		data[curr] = e;
		while ((curr != 0)  && (data[curr] > data[parent(curr)])) {
			swap(curr, parent(curr));
		curr = parent(curr);
		}
	}
	
	int removeMax() {
		swap(0, --size);
		if (size != 0)
			siftdown(0);
		return data[size];

	}
	
	int getMax() {
		return data[0];
	}
	
	void clear() {
		size = 0;
	}
};


class MinHeap {
public:
	int data[MAX_SIZE];
	int max;
	int size;

	MinHeap() {
		size = 0;
	}

	int parent(int pos) {
		return (pos-1)/2;
	}

	int leftchild(int pos) {
		return pos * 2 + 1;
	}

	int rightchild(int pos) {
		return pos * 2 + 2;
	}

	bool isleaf(int pos) {
		return pos * 2 + 1 >= size && pos < size;
	}

	void swap(int a, int b) {
		int t = data[a];
		data[a] = data[b];
		data[b] = t;
	}

	void insert(int e) {
		int curr = size++;
		data[curr] = e;
		while ((curr != 0) && (data[curr] < data[parent(curr)])) {
			swap(curr, parent(curr));
			curr = parent(curr);
		}
	}

	void siftdown(int n) {
		while(!isleaf(n)) {
			int l = leftchild(n);
			if((l < size-1) && (data[l] > (data[l+1]))) {
				l++;
			}
			if(data[n] <= (data[l])) {
				return;
			}
			swap(n, l);
			n = l;
		}
	}

	int removeMin() {
		swap(0, --size);
		if (size != 0)
			siftdown(0);
		return data[size];
	}

	int getMin() {
		return data[0];
	}

	void clear() {
		size = 0;
	}
};


MaxHeap max_heap;
MinHeap min_heap;

void add(int num) {
	if ((min_heap.size != 0) && num < min_heap.getMin()) {
		max_heap.insert(num);
		if (max_heap.size > min_heap.size + 1) {
			min_heap.insert(max_heap.removeMax());
		}
	} else {
		min_heap.insert(num);
		if (min_heap.size > max_heap.size + 1) {
			max_heap.insert(min_heap.removeMin());
		}
	}
}

double getMedian() {
	int median;
	if (min_heap.size < max_heap.size) {
		median = max_heap.getMax();
	} else if (min_heap.size > max_heap.size) {
		median = min_heap.getMin();
	} else {
		median = (min_heap.getMin() + max_heap.getMax()) / 2; 
	}
	return median;
}

void solution(int length) {
	int sum;
	int median = 0;
	for (int i = 0; i < length; i++) {
		add(A[i]);
		median = getMedian();
		sum = (sum + median) % 10;
	}
	
	printf("%d\n", sum);

	max_heap.clear();
	min_heap.clear();
}

int main() {
	int n, length;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> length;
		for (int j = 0; j < length; j++) {
			cin >> A[j];
		}
		solution(length);
	}
		
	return 0;
}


// EOF
