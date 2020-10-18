#include <bits/stdc++.h>/
//6588번 문제
using namespace std;
const int MAX = 1000000 + 1;
bool is_prime[MAX];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fill_n(is_prime, MAX, true);
	for (int i = 2; i < MAX; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) is_prime[j] = false;
	}

	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		int a=3;
		while (1) {
			if (a > N) {
				cout << "Goldbach's conjecture is wrong.\n";
			}
			if (!is_prime[a]|| !is_prime[N-a]) {
				a++;
				continue;
			}
			//a가 소수인 경우
			cout << N << " = " << a << " + " << N - a << '\n';
			break;
		}
	}
}