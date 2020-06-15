#include <bits/stdc++.h>
//9020번 문제
using namespace std;
const int MAX = 10000 + 1;
void GoldBah() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	bool is_prime_number[MAX];
	fill_n(is_prime_number, MAX, true);
	//1은 소수가 아님
	is_prime_number[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (is_prime_number[i] == false) continue;
		for (int j = i * 2; j < MAX; j += i) {
			is_prime_number[j] = false;
		}
	}

	while (T > 0) {
		int N;
		cin >> N;
		int left = N / 2, right = N / 2;
		for (int i = 0; i <= N / 2; i++) {
			if (is_prime_number[left-i] && is_prime_number[right+i]) {
				cout << left - i << ' ' << right + i << endl;
				break;
			}
		}		
		T--;
	}
}