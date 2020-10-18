#include <bits/stdc++.h>
//1929번 문제
using namespace std;

void Prime() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool prime_number[1000001];
	fill_n(prime_number, 1000001, true);
	//1은 소수가 아님
	prime_number[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (prime_number[i] == false) continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			prime_number[j] = false;
		}
	}


	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (prime_number[i] == true) cout << i << '\n';
	}
}