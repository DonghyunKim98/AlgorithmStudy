#include <bits/stdc++.h>
//11053�� ����
using namespace std;

void LIS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int* arr = new int[N];
	vector<int> length(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		length.at(i)=1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				length.at(i) = max(length.at(i), length.at(j)+1);
		}
	}
	sort(length.rbegin(), length.rend());
	cout << length.at(0);
}

/*
	���� O(n^2) ���� ¥���� �˰���
	O(nlogn)���� ������ �� �ִ��� Ȯ��.
*/