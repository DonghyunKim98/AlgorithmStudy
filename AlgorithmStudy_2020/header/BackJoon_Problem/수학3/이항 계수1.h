#include <bits/stdc++.h>
//11050번 문제
using namespace std;

int Factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

void Binominal() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	cout << Factorial(N) / (Factorial(K) * Factorial(N - K));
}

/*
	단순 재귀로는 시간 초과가 떠서 반복문을 이용했다.
*/