#include <bits/stdc++.h>
//9095�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[12] = { 0, };
	//base case
	arr[0] = 0, arr[1] = 1, arr[2] = 2, arr[3] = 4;
	//memoization
	for (int i = 4; i <= 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << arr[N] << '\n';
	}
}

/*
	DP
	=> "N = (i) + (N-i)" �� ��Ÿ�� �� ���� (�� i�� 0�϶� ����??)
	ex) 5 = "4�� ��Ÿ���� ����� ��" + 1
	      = "3�� ��Ÿ���� ����� ��" + 2
*/