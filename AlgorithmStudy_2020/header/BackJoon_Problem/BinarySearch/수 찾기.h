#include <iostream>
#include <algorithm>

//1920번 -> 맞았음
using namespace std;
bool Find(int*, int, int);

void SearchNumber() {
	int N;
	cin >> N;
	int* Farray = new int[N];
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		Farray[i] = temp;
	}
	int M;
	cin >> M;
	int* Sarray = new int[M];
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		Sarray[i] = temp;
	}
	//O(n log n)
	sort(Farray, Farray + N);

	for (int i = 0; i < M; i++) {
		bool temp = Find(Farray, Sarray[i], N);
		if (temp == true) cout << "1\n";
		else cout << "0\n";
	}
}

bool Find(int* array, int element, int length) {
	int a = 0, b = length - 1;
	while (a <= b) {
		int k = (a + b) / 2;
		if (array[k] == element) return true;
		else {
			if (array[k] < element) a = k + 1;
			else b = k - 1;
		}
	}
	return false;
}