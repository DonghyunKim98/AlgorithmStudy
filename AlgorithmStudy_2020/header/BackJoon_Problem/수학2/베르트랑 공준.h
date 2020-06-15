#include <bits/stdc++.h>
//4948번 문제
using namespace std;
const int MAX = 123456 * 2 + 1;

void Vertrang() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool prime_number[MAX];
	fill_n(prime_number, MAX, true);
	//1은 소수가 아님
	prime_number[1] = false;
	for (int i = 2; i <= MAX; i++) {
		if (prime_number[i] == false) continue;
		for (int j = i * 2; j <= MAX; j += i) {
			prime_number[j] = false;
		}
	}

	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		int Count = 0;
		for (int i = N; i <= 2 * N; i++) {
			if (prime_number[i] == true) Count++;
		}
		cout << Count << "\n";
	}
}
