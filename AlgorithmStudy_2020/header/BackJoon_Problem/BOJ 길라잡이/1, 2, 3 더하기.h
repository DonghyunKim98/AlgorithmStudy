#include <bits/stdc++.h>
//9095번 문제
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
	=> "N = (i) + (N-i)" 로 나타낼 수 있음 (단 i가 0일땐 제외??)
	ex) 5 = "4를 나타내는 경우의 수" + 1
	      = "3을 나타내는 경우의 수" + 2
*/