#include <bits/stdc++.h>
//2750�� ����
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

	//�� �������� O(n^2)�� �̿��ص� �ȴٰ� �����Ƿ� Bubble sort�� �غ� ����
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i]<<'\n';
	}
}