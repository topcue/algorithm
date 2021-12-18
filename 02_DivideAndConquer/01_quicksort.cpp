#include <stdio.h>
#include <iostream>

using namespace std;

int A[1001] = {};
int B[1001] = {};

int A_swp = 0;
int A_cmp = 0;
int B_swp = 0;
int B_cmp = 0;

void show_array(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	} cout << endl;
}

void swap(int* arr, int a, int b) {
	int tmp = arr[b];
	arr[b] = arr[a];
	arr[a] = tmp;
}


int partition_Hoare(int* A, int l, int h) {
	int p_val = A[l];
	int i = l - 1;
	int j = h + 1;
	
	while(true) {
		do {
			A_cmp++;
			i++;
		} while (A[i] < p_val);

		do {
			A_cmp++;
			j--;
		} while (A[j] > p_val);
		
		if (i < j) {
			A_swp++;
			swap(A, i, j);
		} else {
			return j;
		}
	}
}


void quicksort_Hoare(int* A, int l, int h) {
	if (l >= h) {
		return;
	}
	int p = partition_Hoare(A, l, h);
	quicksort_Hoare(A, l, p);
	quicksort_Hoare(A, p + 1, h);
}

int partition_Lomuto(int* B, int l, int h) {
	int p_val = B[l];
	int j = l;

	for (int i = l+1; i < h+1; i++) {
		B_cmp++;
		if (B[i] < p_val) {
			j++;
			B_swp++;
			swap(B, i, j);
		}	
	}
	int p_pos = j;
	B_swp++;
	swap(B, p_pos, l);
	
	return p_pos;
}

void quicksort_Lomuto(int* B, int l, int h) {
	if(l >= h) {
		return;
	}
	int p = partition_Lomuto(B, l, h);
	quicksort_Lomuto(B, l, p-1);
	// show_array(B, h);
	quicksort_Lomuto(B, p+1, h);
}

void solution(int length) {
	A_swp = 0, A_cmp = 0;
	B_swp = 0, B_cmp = 0;

	
	quicksort_Lomuto(B, 0, length-1);
	quicksort_Hoare(A, 0, length-1);

	cout << A_swp << ' ' << B_swp << ' ' << A_cmp << ' ' << B_cmp << endl;

	return;
}

int main() {
	int n = 0;
	int length;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> length;
		for (int j = 0; j < length; j++) {
			cin >> A[j];
			B[j] = A[j];
		}
		solution(length);
	}
		
	return 0;
}

// EOF
