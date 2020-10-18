#include <bits/stdc++.h>
//2750번 문제
using namespace std;

void Sort() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//이 문제에선 O(n^2)을 이용해도 된다고 했으므로 Bubble sort를 해볼 예정
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i]<<'\n';
	}
}